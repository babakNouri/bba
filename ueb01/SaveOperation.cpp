/*
 * @File:   SaveOperation.cpp
 * @Author: babak
 *
 * Created on April 30, 2017, 10:43 AM
 */

#include "SaveOperation.hpp"
#include "Util.hpp"
#include <sstream>


SaveOperation::SaveOperation(const std::string & fileName)
{
    this->fileName = fileName;
}

std::string SaveOperation::toString()
{
    std::ostringstream res;
    res << "Bild Speichern:    Dateiname: " << this->fileName;
    
    return res.str();
}

OpType SaveOperation::getOperationType()
{
    return OpType::save;
}


cv::Mat SaveOperation::applyOperation(const cv::Mat & image)
{
    Util util;
    cv::Mat output;
    
    // Pixelwerte von 0 bis 1 zu Ucharwerte zwischen 0 und 255 reskalieren.
    image.convertTo(output, CV_8UC1, MAXIMUM_OF_8_BIT,0.0);
    
    // falls --output = - , bild aud std-out ausgeben.
    if (this->fileName.compare("-") == 0)
    {
        util.printImage(output);
    }
    // sonst Bild speichern.
    else
    {
        cv::imwrite(this->fileName, output, {cv::IMWRITE_PXM_BINARY, 0});
    }
    
    return image;
}
