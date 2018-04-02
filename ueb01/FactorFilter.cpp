/*
 * @file:   FactorFilter.cpp
 * @Author: babak
 *
 * Created on May 3, 2017, 11:59 PM
 */


#include "FactorFilter.hpp"
#include "Util.hpp"

FactorFilter::FactorFilter(const float& param)
{
    this->param = param;
}

//std::string FactorFilter::toString()
//{
//   return "Factor-Filter";
//}

std::string FactorFilter::toString()
{
    std::ostringstream res;
    res << "Factor-Filter " << this->param;
    return res.str();
}

FilterType FactorFilter::getFilterType()
{
    return FilterType::factor_Filter;
}

cv::Mat FactorFilter::applyOperation(const cv::Mat& image)
{
    int row = 0;
    int col = 0;

    cv::Mat res = image;
    
    for (row = 0; row < image.rows; row++)
    {
        for (col = 0; col < image.cols; col++)
        {

            res.at<float>(row, col) *= this->param; 
        }
    }

    return res;
}
