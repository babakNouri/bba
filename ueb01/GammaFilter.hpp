/**
 * @file:   GammaFilter.hpp
 * @Author: babak
 *
 * Created on May 6, 2017, 6:05 PM
 */

#ifndef GAMMAFILTER_HPP
#define GAMMAFILTER_HPP

#include "FilterOperation.hpp"

/**
 * Gamma-Filter.
 */
class GammaFilter : public FilterOperation
{
    private :
        /**
        * Gamma-Faktor.
        */
        float factor;
        
    public:
        /**
         * Konstruktor Methode.
         * 
         * @param faktor Gamma-Faktor.
         */
        GammaFilter(const float & factor);

        cv::Mat applyOperation(const cv::Mat& image);
        std::string toString();
        FilterType getFilterType();
            
};

#endif /* GAMMAFILTER_HPP */

