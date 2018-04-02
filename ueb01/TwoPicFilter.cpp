/** 
 * @file:   MinMaxFilter.cpp
 * @Author: babak
 *
 * Created on May 4, 2017, 10:29 PM
 */

#include "TwoPicFilter.hpp"
#include "Util.hpp"

#include <cmath>      // für abs
#include <cstdlib>
#include <functional> // für std::function

TwoPicFilter::TwoPicFilter(const TwoPicFilterType& filterType) 
{
    this->filtertype = filterType;
}


std::string TwoPicFilter::toString()
{
    return "TwoPic-Filter";
}


FilterType TwoPicFilter::getFilterType()
{
    return FilterType::twoPic_Filter;
}



float mulOp(const float& firstValue, const float& secondValue)
{
    return firstValue * secondValue;
}

float addOp(const float& firstValue, const float& secondValue)
{
    return firstValue + secondValue;
}

float subOp(const float& firstValue, const float& secondValue)
{
    return firstValue - secondValue;
}

float adiffOp(const float& firstValue, const float& secondValue)
{
    return std::abs(firstValue - secondValue);
}

cv::Mat TwoPicFilter::applyOperation(const cv::Mat& image)
{
    (void) image;
    return image;
}

cv::Mat TwoPicFilter::applyOperation(const cv::Mat& firstImage, 
                                     const cv::Mat& secondImage)
{
    int row = 0;
    int col = 0;
    cv::Mat res = firstImage;
    
    std::function<float(const float&, const float&)> op;
    
//    float (*op)(const float &, const float &);
    
    switch (this->filtertype)
    {
        case TwoPicFilterType::add :
            op = addOp;
            break;
        case TwoPicFilterType::sub :
            op = subOp;
            break;
        case TwoPicFilterType::mul :
            op = mulOp;
            break;
        case TwoPicFilterType::adiff :
            op = adiffOp;
            break;
        default:
            break;
    }
    
    for (row = 0; row < res.rows; row++)
    {
        for (col = 0; col < res.cols; col++)
        {           
            res.at<float>(row, col) = op(firstImage.at<float>(row,col),
                                         secondImage.at<float>(row,col)); 
        }
    }
    
    return res;
}