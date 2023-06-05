#include <iostream>

#include <opencv2/opencv.hpp>

#include "quality.hpp"


void ideal_solution(const cv::Mat& src, cv::Mat& dst) {
  cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
}

void test_solution(const cv::Mat& src, cv::Mat& dst) {
  // load student solution here instead of using ideal solution
  // cv::Mat dst = cv::imread("path/to/student/image/result.png");
  ideal_solution(src, dst);
}

void main() {
  cv::Mat src = cv::imread("../../../data/src.02.png");

  cv::Mat result{};
  test_solution(src, result);

  cv::Mat ideal{};
  ideal_solution(src, ideal);

  measureQuality(src, ideal, result);
  cv::waitKey();
}
