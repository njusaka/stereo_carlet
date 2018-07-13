#ifndef LIGHT_TRACKING_H
#define LIGHT_TRACKING_H

#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

class __light_tracking {
public:
    __light_tracking(unsigned char lowR_in, unsigned char highR_in,
                     unsigned char lowG_in, unsigned char highG_in,
                     unsigned char lowB_in, unsigned char highB_in) {
        mc_out.clear();

        iLowR = lowR_in, iHighR = highR_in;
        iLowG = lowG_in, iHgihG = highG_in;
        iLowB = lowB_in, iHighB = highB_in;

    }

    void set_Img(Mat in) { img = in.clone(); }

    vector<Point2f> get_CenterPts() { return mc_out; }

    size_t update(Mat in);
    size_t update(Mat in, bool is_show);
    size_t update(bool is_show);

private:

    unsigned char iLowR, iHighR;
    unsigned char iLowG, iHgihG;
    unsigned char iLowB, iHighB;

    Mat img;
    Mat imgThresholded;

    vector<Point2f> mc_out;

    void   find_Targets(bool is_show);

    size_t calc_Centers(bool is_show);

};

#endif // LIGHT_TRACKING_H
