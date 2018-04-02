/* 
 * @File:   NullFilter.cpp
 * @Author: tinf100085
 *
 * Created on April 27, 2017
 */

#include <sstream>
#include "NullFilter.hpp"



std::string NullFilter::toString()
{
    return "Null-Filter";
}

FilterType NullFilter::getFilterType()
{
    return FilterType::null_Filter;
}

cv::Mat NullFilter::applyOperation(const cv::Mat & image)
{
    return image;
}

