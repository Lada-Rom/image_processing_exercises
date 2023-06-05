#include <iostream>

#include <opencv2/opencv.hpp>

#include "quality.hpp"


void ideal_solution(const cv::Mat& src, std::vector<cv::Mat>& dst) {
  dst.resize(3);
  cv::cvtColor(src, dst[0], cv::COLOR_BGR2HSV);
  cv::cvtColor(src, dst[1], cv::COLOR_BGR2HLS);
  cv::cvtColor(src, dst[2], cv::COLOR_BGR2Lab);
}

void test_solution(const cv::Mat& src, std::vector<cv::Mat>& dst) {
  // load student solution here instead of using ideal solution
  // cv::Mat dst = cv::imread("path/to/student/image/result.png");
  ideal_solution(src, dst);
}

void main() {
  cv::Mat src = cv::imread("../../../data/src.01.png");

  std::vector<cv::Mat> result{};
  test_solution(src, result);

  std::vector<cv::Mat> ideal{};
  ideal_solution(src, ideal);

  measureQuality(src, ideal, result);
  cv::waitKey();
}
