/**
 * @file:   HistogramFilter.hpp
 * @Author: babak
 *
 * Created on May 8, 2017, 10:14 PM
 */

#ifndef HISTOGRAMFILTER_HPP
#define HISTOGRAMFILTER_HPP

#include "FilterOperation.hpp"

/**
 *  Erzeugt Histogramm.
 */
class HistogramFilter : public FilterOperation
{
    private:
        /**
         * Anzahl der Klassen des Histogrammes.
         */
        int amountOfClasses;
        
        /**
         * true, wenn Summen-Histogramm, sonst false.
         */
        bool sum;
        
        
        /**
         * Berechnet das Histogram des Bildes.
         * 
         * @param image das Bild.
         * @return Histogram als Vektor von long.
         */
        std::vector<unsigned long> calculateHistogramInfo
                                        (const cv::Mat& image,
                                         const int & amountOfClasses);
        
    public:
        /**
         * Konstruktor Methode.
         * 
         * @param amountOfClasses Anzahl der Klassen des Histogrammes.
         * @param true, wenn Summen-Histogramm, sonst false.
         */
        HistogramFilter(const int & amountOfClasses, const bool & sum );
        
        
        
        /**
         * Rechnet Histogram von ein Unnormaliziert Bild, mit 3 Klassen.
         * negative PixelWerte werden in Erste Klasse und Pixelwerte größer als
         * eins werden in der letzten Klasse einsortiert. 
         * 
         * @param image das Bild.
         * @return Histogram als Vector von Float mit der Länge 3.
         */
        std::vector<float> calculateUnNormalHistogramInfo(const cv::Mat& image);
        
        
        /**
         * Berechnet das prozentuale Histogram des Bildes.
         * 
         * @param image das Bild.
         * @return Histogram als Vektor von float.
         */
        std::vector<float> calculateHistogram(const cv::Mat& image,
                                              const int & amountOfClasses);
        
        /**
         * Berechnet das Summenhistogram des Bildes.
         * 
         * @param image das Bild.
         * @return Summnehistogram als Vektor von float.
         */
        std::vector<float> calculateSumHistogram(const cv::Mat& image,
                                                 const int & amountOfClasses);
        
        /**
         * Druckt das eingegebene Histogram aud std-out aus.
         * 
         * @param info Das Histogramm.
         * @param amountOfClasses Anzahl der Klassen des Histogrames.
         */
        void printHistogram(const std::vector<float> & info,
                                     const int & amountOfClasses);
        
        
        cv::Mat applyOperation(const cv::Mat& image);
        std::string toString();
        FilterType getFilterType();
};



#endif /* HISTOGRAM_HPP */

