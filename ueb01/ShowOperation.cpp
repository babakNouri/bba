/*
 * @File:   ShowOperation.cpp
 * @Author: babak
 *
 * Created on April 30, 2017, 10:43 AM
 */

#include "ShowOperation.hpp"
#include "IoOperation.hpp"

ShowOperation::ShowOperation() 
{
}


OpType ShowOperation::getOperationType()
{
    return OpType::show;
}


std::string  ShowOperation::toString()
{
    return "Bild anzeigen";
}

cv::Mat ShowOperation::applyOperation(const cv::Mat& image)
{
    // Bild zeigen
    cv::imshow("Image", image);
    // warten auf Tastendruck
    cv::waitKey(0);
    // Bildfenster schließen.
    cv::destroyWindow("Image");
    
    return image;
}