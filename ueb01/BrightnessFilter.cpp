/** 
 * @file:   BrightnessFilter.cpp
 * @Author: babak
 *
 * Created on May 3, 2017, 11:59 PM
 */


#include "BrightnessFilter.hpp"
#include "Util.hpp"

BrightnessFilter::BrightnessFilter(const float & param) {
    this->param = param;
}


std::string BrightnessFilter::toString()
{
    std::ostringstream res;
    res << "Brightness-Filter " << this->param;
    return res.str();
}

FilterType BrightnessFilter::getFilterType()
{
    return FilterType::brightness_Filter;
}

cv::Mat BrightnessFilter::applyOperation(const cv::Mat& image)
{
    int row = 0;
    int col = 0;

    cv::Mat res = image;
    
    for (row = 0; row < image.rows; row++)
    {
        for (col = 0; col < image.cols; col++)
        {

            res.at<float>(row, col) += this->param; 
        }
    }

    return res;
}