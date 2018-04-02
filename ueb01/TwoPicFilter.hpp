/* 
 * @File:   TwoPicFilter.hpp
 * @Author: babak
 *
 * Created on April 2, 2018, 12:10 PM
 */

#ifndef TWOPICFILTER_HPP
#define TWOPICFILTER_HPP

#include "FilterOperation.hpp"

/**
 * Die Klasse ist zuständig für Laden eines Bild. 
 */
class TwoPicFilter : public FilterOperation
{
    private:
        /**
         * filterType Typ des Filters (add, sub, mul, adiff). 
         */
        TwoPicFilterType filtertype;
    
    public:
        /**
         * Konstruktur.
         * 
         * @param filterType Typ des Filters (add, sub, mul, adiff).
         */
        TwoPicFilter(const TwoPicFilterType & filterType);
        
        cv::Mat applyOperation(const cv::Mat & image);
        /**
         * Apply Operation nur für Filter mit zwei Bilder.
         * 
         * @param firstImage das erste Bild.
         * @param secondImage das zweite Bild.
         * 
         * @return Resulatbild. 
         */
        cv::Mat applyOperation(const cv::Mat & firstImage,
                               const cv::Mat & secondImage);
        std::string toString();
        FilterType getFilterType();
};

#endif /* TWOPICFILTER_HPP */

