/* 
 * @File:   FilterOperation.hpp
 * @Author: babak
 *
 * Created on April 28, 2017, 11:29 PM
 */

#ifndef NULLFILTER_HPP
#define NULLFILTER_HPP

#include <vector>
#include "Types.hpp"
#include "FilterOperation.hpp"

/**
 * Repräsentiert den Null-Filter.
 * Der Null-Filter verändert das Bild nicht.
 */
class NullFilter : public FilterOperation
{
        
    public:      
        cv::Mat applyOperation(const cv::Mat & image);
        std::string toString();
        FilterType getFilterType();
};


#endif /* FILTEROPERATION_HPP */

