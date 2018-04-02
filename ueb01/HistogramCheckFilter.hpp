/** 
 * @file:   HistogramCheckFilter.hpp
 * @Author: babak
 *
 * Created on May 9, 2017, 9:00 PM
 */

#ifndef HISTOGRAMCHECKFILTER_HPP
#define HISTOGRAMCHECKFILTER_HPP

#include "FilterOperation.hpp"

/**
 * Histogramcheck.
 */
class HistogramCheckFilter : public FilterOperation
{
    public:
        /**
         * Konstruktor Methode.
         */
        HistogramCheckFilter();
        
        cv::Mat applyOperation(const cv::Mat& image);
        std::string toString();
        FilterType getFilterType();
};


#endif /* HISTOGRAMCHECKFILTER_HPP */

