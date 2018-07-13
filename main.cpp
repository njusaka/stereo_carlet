#include <iostream>
#include <cmath>
#include <sys/time.h>
#include "include/light_tracking.h"

#include <wiringPi.h>
#include <wiringSerial.h>

using namespace std;
using namespace cv;

inline float calc_Angle(float xl, float xr);
inline float calc_Distance(float xl, float xr);

int main(void) {

    const bool is_show_image = true;
    const bool is_show_data  = true;

    VideoCapture cap(0);
    Mat img_stereo_raw;
    Mat imgl, imgr;
    if (!cap.isOpened())
        return -1;

    unsigned char iLowR = 180, iHighR = 255;
    unsigned char iLowG = 50,  iHighG = 255;
    unsigned char iLowB = 50,  iHighB = 255;
    __light_tracking _t(iLowR, iHighR,
                        iLowG, iHighG,
                        iLowB, iHighB);

    vector<Point2f> temp;
    Point2f center_l = { 0. }, center_r = { 0. };
    double dist, angle;

    int fd;
    char text_2_send[30] = { 0 };
    if((fd = serialOpen ("/dev/ttyS0", 9600)) < 0) {
        printf("serial err\n");
        return -1;
    }

    struct timeval t = { 0 }, t_last = { 0 };
    double dt;

    while (true) {

        cap >> img_stereo_raw;
        //resize(img_stereo_raw, img_stereo_raw, Size(960, 360), 0, 0, INTER_NEAREST);  // 960, 360

        _t.update(img_stereo_raw, is_show_image);
        temp = _t.get_CenterPts();

       // cout<<"size:"<<temp<<endl;
        if (!temp.size()) {
            sprintf(text_2_send, "S%f %fE", 0., 0.);
            serialPuts(fd, text_2_send);
            continue;
        }
        center_l = temp[0];
        center_r = temp[1];

        center_l.x = center_l.x - img_stereo_raw.rows/2;
        //cout<<"center_l.x:"<<center_l.x<<"center_r.x:"<<center_r.x<<endl;
        //cout<<"center_l.y:"<<center_l.y<<"center_r.y:"<<center_r.y<<endl;

        dist  = calc_Distance(center_l.x, center_r.x);
        angle = calc_Angle(center_l.x, center_r.x);

        cout << "dist: " << dist << " angle: " << angle << endl;

        sprintf(text_2_send, "S%f %fE", dist, angle);
        serialPuts(fd, text_2_send);

        t_last = t;
        gettimeofday(&t, NULL);
        dt = (t.tv_usec - t_last.tv_usec) / 1e3;
        if (dt < 0)
            dt += 1e6;

        if (is_show_image) {
            imshow("stereo_raw_l", img_stereo_raw);
            waitKey(50);
        }

        if (is_show_data) {
            cout << "dt: " << dt << endl;
        }
    }

    serialClose(fd);
    return 0;
}

inline float calc_Angle(float xl, float xr) {
    float p00 = -183.3;
    float p10 = 1.015;
    float p01 = -0.8573;
    float p20 = -0.001553;
    float p11 = 0.003623;
    float p02 = -0.001979;

    float x = xl;
    float y = xr;

    return p00 + p10 * x + p01 * y + p20 * x*x + p11 * x*y + p02 * y*y;
}

inline float calc_Distance(float xl, float xr) {

    float p00, p10, p01, p20, p11, p02, p30, p21, p12, p03, p40, p31, p22, p13;
    p00 = 2052;
    p10 = 93.7;
    p01 = 218.3;
    p20 = -1.26;
    p11 = -0.9239;
    p02 = 1.743;
    p30 = 0.005087;
    p21 = -0.003054;
    p12 = -0.004999;
    p03 = 0.002659;
    p40 = -6.684e-06;
    p31 = 1.275e-05;
    p22 = -6.645e-06;
    p13 = 1.412e-06;

    float x, y;
    x = xl;
    y = xr;
    float rst;
    rst = p00 + p10 * x + p01 * y + p20 * x*x + p11 * x*y + p02 * y*y + p30 * x*x*x + p21 * x*x * y;
    rst = rst + p12 * x*y*y + p03 * y*y*y + p40 * x*x*x*x + p31 * x*x*x * y + p22 * x*x * y*y;
    rst = rst + p13 * x * y*y*y;
    if (rst < 80) {
        p00 = 6214;
        p10 = -64.56;
        p01 = 60.31;
        p20 = 0.2258;
        p11 = -0.4322;
        p02 = 0.2222;
        p30 = -0.000266;
        p21 = 0.0007869;
        p12 = -0.0008355;
        p03 = 0.000312;

        x = xl;
        y = xr;

        rst = p00 + p10 * x + p01 * y + p20 * x*x + p11 * x*y + p02 * y*y + p30 * x*x*x + p21 * x*x * y + p12 * x*y*y + p03 * y*y*y;
        cout<<"######"<<endl;
    }
    cout<<"&&&"<<endl;
    return rst;
}
