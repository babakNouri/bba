/**
 * @file:   HistogramFilter.cpp
 * @Author: babak
 *
 * Created on May 8, 2017, 10:14 PM
 */

#include "HistogramFilter.hpp"
#include "Util.hpp"
#include <iomanip>      // std::setprecision
#include <math.h>







HistogramFilter::HistogramFilter(const int& amountOfClasses, const bool& sum)
{
    this->amountOfClasses = amountOfClasses;
    this->sum = sum;
}


std::string HistogramFilter::toString()
{
    std::ostringstream res;
    if (this->sum)
    {
        res << "Summen-Histogram-Filter " << this->amountOfClasses;
    }
    else
    {
        res << "Histogram-Filter " << this->amountOfClasses;
    }

    return res.str();
}


FilterType HistogramFilter::getFilterType()
{
    return FilterType::histogram_Filter;
}

std::vector<float> HistogramFilter::calculateUnNormalHistogramInfo
                                                    (const cv::Mat& image)
{
    std::vector<unsigned long> histogramInfo = {0, 0, 0};
    std::vector<float> histogramRes = {0, 0, 0};
    float pixelValue = 0.0f;
    float amountOfPixels = image.rows * image.cols;
    
    for (int row = 0; row < image.rows; row++)
    {
        for (int col = 0; col < image.cols; col++)
        {
            pixelValue = image.at<float>(row, col);
            
            if (pixelValue <= 0.0f)
            {
                histogramInfo[0]++;
            }
            else if (pixelValue > 1.0f)
            {
                histogramInfo[2]++;
            }
            else
            {
                histogramInfo[1]++;
            }
        }
    }
    
    histogramRes[0] = histogramInfo[0] / amountOfPixels;
    histogramRes[1] = histogramInfo[1] / amountOfPixels;
    histogramRes[2] = histogramInfo[2] / amountOfPixels;
    
    return histogramRes;
}




std::vector<unsigned long> HistogramFilter::calculateHistogramInfo
                                                (const cv::Mat& image,
                                                 const int& amountOfClasses)
{
    std::vector<unsigned long> histogramInfo;
    float classInterval = 1.0f / ((float) amountOfClasses);
    int index = 0;
    

    for(int i = 0; i <= amountOfClasses; i++)
    {
        histogramInfo.push_back(0);
    }
    
    for (int row = 0; row < image.rows; row++)
    {
        for (int col = 0; col < image.cols; col++)
        {
            index = floor(image.at<float>(row, col) / classInterval);
            histogramInfo[index]++;
        }
    }
    
    histogramInfo[amountOfClasses -1] += histogramInfo[amountOfClasses];
    histogramInfo.pop_back();
    
    return histogramInfo;
}


std::vector<float> HistogramFilter::calculateHistogram
                                        (const cv::Mat& image, 
                                         const int& amountOfClasses)
{
    std::vector<unsigned long> histogramInfo = calculateHistogramInfo
                                                    (image, amountOfClasses); 
    
    std::vector<float> res;
    float amountOfPixels = image.cols * image.rows;
    
    for (int i = 0; i < amountOfClasses; i++)
    {
        res.push_back(0);
    }
    
    for (int i = 0; i < amountOfClasses; i++)
    {
        res[i] = (float)histogramInfo[i] / amountOfPixels;
    }
    
    return res;
}


std::vector<float> HistogramFilter::calculateSumHistogram
                                       (const cv::Mat& image, 
                                        const int& amountOfClasses)
{
    std::vector<float> res = calculateHistogram(image, amountOfClasses);
    
    for (int i = 1; i < amountOfClasses; i++)
    {
        res[i] += res[i -1];
    }
    
    return res;
}

void HistogramFilter::printHistogram(const std::vector<float> & info,
                                     const int & amountOfClasses)
{
    std::stringstream res;
    Util util;
    float temp = 0.0f;
    
    res << "[";
    for (int i = 0; i < amountOfClasses; i++)
    {
        temp = round(info[i] * 100.0f);
        res << std::setprecision(2) << temp / 100.0f;
        
        if (i < (amountOfClasses -1))
        {
            res << ", ";
        }
    }
    res << "]";
    
    util.printOut(res.str()); 
}


cv::Mat HistogramFilter::applyOperation(const cv::Mat& image)
{
    std::vector<float> info;
    
    if (this->sum)
    {
        info = calculateSumHistogram(image, this->amountOfClasses);
    }
    else
    {
        info = calculateHistogram(image, this->amountOfClasses);
    }
    
    printHistogram(info, this->amountOfClasses);
    
    return image;
}