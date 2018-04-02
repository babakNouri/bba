/* 
 * @File:   FilterOperation.hpp
 * @Author: babak
 *
 * Created on April 30, 2017, 1:25 PM
 */

#ifndef FILTEROPERATION_HPP
#define FILTEROPERATION_HPP

#include "PictureOperation.hpp"

/**
 * Die Klasse repräsentiert die Filter-Operationen. 
 */
class FilterOperation : public PictureOperation
{       
    public:
        virtual cv::Mat applyOperation(const cv::Mat & image) = 0;
        virtual std::string toString() = 0;
        /**
         * Gibt Typ des Filters zurück.
         * 
         * @return Typ des Filters.
         */
        virtual FilterType getFilterType() = 0;
        OpType getOperationType();        
};

#endif /* FILTEROPERATION_HPP */

