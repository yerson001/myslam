#include <iostream>
#include <fstream>
#include <opencv2/viz.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>

using namespace std;
using namespace cv;
int main()
{
    viz::Viz3d window("window");
    Mat rvec = Mat::zeros(1, 3, CV_32F);
    while (!window.wasStopped()) {
        rvec.at<float>(0, 0) = 0.f;
        rvec.at<float>(0, 1) += CV_PI * 0.01f;
        rvec.at<float>(0, 2) = 0.f;
        Mat rmat;
        Rodrigues(rvec, rmat);
        Affine3f pose(rmat, Vec3f(0, 0, 0));
        window.showWidget("Coordinate", viz::WCoordinateSystem(), pose);
        window.spinOnce(1, false);
    }
    return 0;
}