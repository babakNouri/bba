/** 
 * @file:   MinMaxFilter.cpp
 * @Author: babak
 *
 * Created on May 4, 2017, 10:29 PM
 */

#include "MinMaxFilter.hpp"
#include "Util.hpp"


std::string MinMaxFilter::toString()
{
    return "MinMax-Filter";
}

FilterType MinMaxFilter::getFilterType()
{
    return FilterType::minMax_Filter;
}

cv::Mat MinMaxFilter::applyOperation(const cv::Mat& image)
{
    int row = 0;
    int col = 0;
    cv::Mat res = image;
    double imageMin = 0;
    double imageMax = 0;
    int minIdx = 0;
    int maxIdx = 0;

    // Min & Max ermitteln
    cv::minMaxIdx(image, &imageMin, &imageMax, &minIdx, &maxIdx);
    
    float iMin = (float) imageMin;
    float iMax = (float) imageMax;
    
    for (row = 0; row < res.rows; row++)
    {
        for (col = 0; col < res.cols; col++)
        {           
            res.at<float>(row, col) = (res.at<float>(row, col) - iMin)
                                       /
                                      (iMax - iMin); 
        }
    }

    return res;
}