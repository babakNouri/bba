/**
 * @File:   MinMaxFilter.hpp
 * @Author: babak
 *
 * Created on April 1, 2018, 12:43 AM
 */

#ifndef MINMAXFILTER_HPP
#define MINMAXFILTER_HPP

#include "FilterOperation.hpp"

/**
 * Repräsentiert den MinMax-Filter.
 * Der MinMax-Filter normiert die Intensitäten des Bildes.
 */
class MinMaxFilter : public FilterOperation
{   
    public:
        cv::Mat applyOperation(const cv::Mat& image);
        std::string toString();
        FilterType getFilterType();
};


#endif /* MINMAXFILTER_HPP */

