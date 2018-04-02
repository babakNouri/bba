/*
 * @File:   LoadOperation.cpp
 * @Author: babak
 *
 * Created on April 30, 2017, 10:43 AM
 */


#include "LoadOperation.hpp"
#include "IoOperation.hpp"
#include <sstream>

#include <iostream>



LoadOperation::LoadOperation(const std::string& fileName)
{
    this->fileName = fileName;
}


std::string LoadOperation::toString()
{
    std::ostringstream res;
    res << "Bild Laden:    Dateiname: " << this->fileName;
    
    return res.str();
}

OpType LoadOperation::getOperationType()
{
    return OpType::load;
}

cv::Mat LoadOperation::applyOperation(const cv::Mat & image)
{
    cv::Mat res;
    // Skalierungsfaktor für Bilder mit 8-Bit Tiefe inizialisieren. 
    double a = 1.0 / MAXIMUM_OF_8_BIT;
    
    // nur um UNUSED WARNING zu schweigen zu bringen!
    (void) image;

    // Bild mit ein Kanal (Graustufen) und mit jeder Tiefe laden.
    cv::Mat loaded = cv::imread(this->fileName, 
                                cv::IMREAD_ANYDEPTH | cv::IMREAD_UNCHANGED);
    
    // Falls Bildtife des geledenen Bildes 16 ist,
    // Skalierungsfaktor dementsprechend berechnen.
    if (loaded.depth() == CV_16U)
    {
        a = 1.0 / MAXIMUM_OF_16_BIT;
    }
    
    // Pixlewerte zu Floatwerte zwischen 0.0 und 1.0 konvertieren.
    loaded.convertTo(res, CV_32FC1, a, 0);
    
    return res;
}