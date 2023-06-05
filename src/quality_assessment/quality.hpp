#ifndef QUALITY_HPP
#define QUALITY_HPP


#include <iostream>

#include <opencv2/opencv.hpp>


void measureQuality(const cv::Mat& src, const cv::Mat& ideal, const cv::Mat& result) {
  cv::Mat result_gray{};
  cv::cvtColor(result, result_gray, cv::COLOR_BGR2GRAY);

  cv::Mat ideal_gray{};
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

#endif //QUALITY_HPP
