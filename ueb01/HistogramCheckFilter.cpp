/** 
 * @file:   HistogramCheckFilter.cpp
 * @Author: babak
 *
 * Created on May 9, 2017, 9:00 PM
 */

#include "HistogramCheckFilter.hpp"
#include "HistogramFilter.hpp"
#include "Util.hpp"


HistogramCheckFilter::HistogramCheckFilter()
{
}

std::string HistogramCheckFilter::toString()
{
    std::ostringstream res;
    res << "Histogram Check-Filter ";
    
    return res.str();
}

FilterType HistogramCheckFilter::getFilterType()
{
    return FilterType::histogramCheck_Filter;
}


cv::Mat HistogramCheckFilter::applyOperation(const cv::Mat& image)
{
    Util util;
    
    HistogramFilter hf = HistogramFilter(4, false);
    std::vector<float> histogram = hf.calculateHistogram(image, 4);
    
    if ( (histogram[2] + histogram[3]) < 0.3f)
    {
        util.printOut("Bild ist dunkel.");
    }
    else if ( (histogram[0] + histogram[1]) < 0.3f)
    {
        util.printOut("Bild ist hell.");
    }
    else if ( (histogram[0] + histogram[3]) > 0.8f)
    {
        util.printOut("Kontrast ist hoch.");
    }
    else if ( (histogram[0] + histogram[3]) < 0.2f)
    {
        util.printOut("Kontrast ist niedrig.");
    }
    else
    {
        util.printOut("Kontrast ist gut.");
    }
    
    return image;
}