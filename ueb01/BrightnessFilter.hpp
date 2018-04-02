/** 
 * @file:   BrightnessFilter.hpp
 * @Author: babak
 *
 * Created on May 3, 2017, 11:59 PM
 */

#ifndef BRIGHTNESSFILTER_HPP
#define BRIGHTNESSFILTER_HPP

#include "FilterOperation.hpp"

/**
 * Repräsentiert den Brightness-Filter.
 * Der Brightness-Filter erhöht die Helligkeit des Bildes.
 */
class BrightnessFilter : public FilterOperation
{
    private:
        /** 
         * Parameter des Brightness-Filters.
         */
        float param;
        
    public:
        /**
         * Konstruktor.
         * 
         * @param param Parameter des Brightness-Filters.
         */
        BrightnessFilter(const float & param);

        cv::Mat applyOperation(const cv::Mat& image);
        std::string toString();
        FilterType getFilterType();
};

#endif /* BRIGHTNESSFILTER_HPP */

