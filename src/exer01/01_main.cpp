#include <iostream>

#include <opencv2/opencv.hpp>


void ideal_solution(const cv::Mat& src, cv::Mat& dst) {
  cv::resize(src, dst, cv::Size(), 1.5, 0.7);
}

void test_solution(const cv::Mat& src, cv::Mat& dst) {
  // load student solution here instead of using ideal solution
  // cv::Mat dst = cv::imread("path/to/student/image/result.png");
  ideal_solution(src, dst);
}

void measureQuality(const cv::Mat& src, const cv::Mat& result) {
  cv::Mat result_gray{};
  cv::cvtColor(result, result_gray, cv::COLOR_BGR2GRAY);

  cv::Mat ideal{};
  cv::Mat ideal_gray{};
  ideal_solution(src, ideal);
  cv::cvtColor(ideal, ideal_gray, cv::COLOR_BGR2GRAY);

  cv::Mat abs_error = cv::abs(ideal_gray - result_gray);
  uint32_t abs_error_sum = cv::sum(abs_error)[0];
  float mae = 1.0 * abs_error_sum / (ideal.rows * ideal.cols);
  float normalized_mae = mae / 255;

  cv::imshow("src image", src);
  cv::imshow("custom solution", result);
  cv::imshow("ideal solution", ideal);
  std::cout << std::fixed << std::setprecision(2)
            << "Quality: " << 1 - normalized_mae << std::endl;
}

void main() {
  cv::Mat src = cv::imread("../../../data/src.01.jpg");

  cv::Mat dst{};
  test_solution(src, dst);

  measureQuality(src, dst);
  cv::waitKey();
}
