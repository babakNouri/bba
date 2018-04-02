/** 
 * @File:   FactorFilter.hpp
 * @Author: babak
 *
 * Created on March 31, 2018, 11:57 PM
 */

#ifndef FACTORFILTER_HPP
#define FACTORFILTER_HPP

#include "FilterOperation.hpp"

/**
 * Repräsentiert den Factor-Filter.
 * Der Facter-Filter multipliziert jedes Pixel des Bildes mit dem Faktor.
 */
class FactorFilter : public FilterOperation {
    private:
        /** 
         * Parameter des Factor-Filters.
         */
        float param;
        
    public:
        /**
         * Konstruktor.
         * 
         * @param param Parameter des Brightness-Filters.
         */
        FactorFilter(const float & param);

        cv::Mat applyOperation(const cv::Mat& image);
        std::string toString();
        FilterType getFilterType();
};


#endif /* FACTORFILTER_HPP */

