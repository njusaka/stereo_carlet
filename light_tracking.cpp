#include "include/light_tracking.h"

static inline bool ContoursSortFun(vector<cv::Point> contour1,vector<cv::Point> contour2);

size_t __light_tracking::update(Mat in) {

    set_Img(in);

    return update(false);
}

size_t __light_tracking::update(Mat in, bool is_show) {

    set_Img(in);

    return update(is_show);
}


size_t __light_tracking::update(bool is_show) {

    int stat;

    find_Targets(is_show);

    stat = calc_Centers(is_show);

    return (size_t)stat;
}

void __light_tracking::find_Targets(bool is_show) {

    inRange(img, Scalar(iLowB, iLowG, iLowR), Scalar(iHighB, iHgihG, iHighR),
            imgThresholded); //Threshold the image

    //开操作 (去除一些噪点)  如果二值化后图片干扰部分依然很多，增大下面的size
    Mat element = getStructuringElement(MORPH_RECT, Size(3, 3));	// Size(5, 5)
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);

    //闭操作 (连接一些连通域)
   // morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);

    if (is_show) {
        namedWindow("Thresholded Image",CV_WINDOW_NORMAL);
        imshow("Thresholded Image", imgThresholded);
    }
}

size_t __light_tracking::calc_Centers(bool is_show) {

    vector<vector<Point> > contours;//contours的类型，双重的vector
    vector<Vec4i> hierarchy;//Vec4i是指每一个vector元素中有四个int型数据。

    //寻找轮廓，这里注意，findContours的输入参数要求是二值图像，二值图像的来源大致有两种，第一种用threshold，第二种用canny
    findContours(imgThresholded.clone(), contours, hierarchy,CV_RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
    std::sort(contours.begin(),contours.end(),ContoursSortFun);
    /// 计算矩
    vector<Moments> mu(contours.size());
    for (int i = 0; i < contours.size(); i++)
    {
        mu[i] = moments(contours[i], false);
    }
    ///  计算中心矩:
    vector<Point2f> mc(contours.size());
    for (int i = 0; i < contours.size(); i++)
    {
        mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
    }
    mc_out.clear();
    for (int i = 0; i < mc.size(); i++)
        mc_out.push_back(mc[i]);

    /// 绘制轮廓
    if (is_show) {
        Mat drawing = Mat::zeros(imgThresholded.size(), CV_8UC1);
        for (int i = 0; i < contours.size(); i++)
        {
            Scalar color = Scalar(255);
            drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
            circle(drawing, mc[i], 4, color, -1, 8, 0);
        }
        imshow("outImage",drawing);
    }
}

static inline bool ContoursSortFun(vector<cv::Point> contour1,vector<cv::Point> contour2)
{
    return (cv::contourArea(contour1) > cv::contourArea(contour2));
}


