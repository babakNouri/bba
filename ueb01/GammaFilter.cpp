/**
 * @file:   GammaFilter.cpp
 * @Author: babak
 *
 * Created on May 6, 2017, 6:05 PM
 */

#include "GammaFilter.hpp"



GammaFilter::GammaFilter(const float & factor)
{
    this->factor = factor;
}

std::string GammaFilter::toString()
{
    std::ostringstream res;
    res << "Gamma-Filter " << this->factor;
    return res.str();
}


FilterType GammaFilter::getFilterType()
{
    return FilterType::gamma_Filter;
}

cv::Mat GammaFilter::applyOperation(const cv::Mat& image)
{
    cv::Mat res = image;
    
    for (int row = 0; row < res.rows; row++)
    {
        for (int col = 0; col < res.cols; col++)
        {
            res.at<float>(row, col) = std::pow((double)res.at<float>(row, col), 
                                               this->factor);
        }
    }
    
    return res;
}