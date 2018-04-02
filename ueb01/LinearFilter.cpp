/** 
 * @file:   LinearFilter.cpp
 * @Author: babak
 *
 * Created on May 4, 2017, 10:29 PM
 */

#include "LinearFilter.hpp"
#include "Util.hpp"

LinearFilter::LinearFilter(const float & a, const float & b) {
    this->a = a;
    this->b = b;
}


std::string LinearFilter::toString()
{
    std::ostringstream res;
    res << "Linear-Filter " << this->a << "  " << this->b;
    return res.str();
}

FilterType LinearFilter::getFilterType()
{
    return FilterType::linear_Filter;
}

cv::Mat LinearFilter::applyOperation(const cv::Mat& image)
{
    int row = 0;
    int col = 0;
    cv::Mat res = image;
    
    for (row = 0; row < res.rows; row++)
    {
        for (col = 0; col < res.cols; col++)
        {
            // res(i) = image(i) * a + b
            res.at<float>(row, col) = res.at<float>(row, col) * this->a + this->b; 
        }
    }

    return res;
}
