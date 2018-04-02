/** 
 * @file:   LinearFilter.hpp
 * @Author: babak
 *
 * Created on May 4, 2017, 10:29 PM
 */

#ifndef LINEARFILTER_HPP
#define LINEARFILTER_HPP

#include "FilterOperation.hpp"


/**
 * Linear Filter.
 */
class LinearFilter : public FilterOperation
{
    private:
        /**
         * Parameter A. 
         */ 
        float a;
        
        /**
         * Parameter B.
         */
        float b;
        
    public:
        /**
         * Konstruktor Methode.
         * 
         * @param a Parameter A.
         * @param b parameter B.
         */
        LinearFilter(const float & a, const float & b);

        cv::Mat applyOperation(const cv::Mat& image);
        std::string toString();
        FilterType getFilterType();
};


#endif /* LINEARFILTER_HPP */

