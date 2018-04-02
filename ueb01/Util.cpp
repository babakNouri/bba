/* 
 * @File:   Util.cpp
 * @Author: tinf100085
 *
 * Created on April 27, 2017
 */


#include <string>
#include <vector>
#include <iostream>
#include "PictureOperation.hpp"
#include "Util.hpp"



void Util::pirntArguments(std::vector<std::string> & arguments)
{
    unsigned i = 1;
    std::cout << "------------------ Arguments ------------------" << std::endl;
    
    for(std::string s : arguments)
    {
        std::cout << i << ": " << s << std::endl;
        i++;
    }
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << std::endl;
}



void Util::printOperationList(std::vector<PictureOperation*> & opList)
{
   unsigned i = 1;
   std::cout << "---------------- Operations List ---------------" << std::endl;
    
   for(PictureOperation* op : opList)
   {
       std::cout << i << ": " << op->toString() << std::endl;
       i++;
   }
   
   std::cout << "------------------------------------------------" << std::endl;
   std::cout << std::endl;
}


void Util::printImage(const cv::Mat& image)
{
    std::vector<uchar> buffer;
    std::vector<int> params;
   
    // Ausgabeformat nicht Binär!
    params.push_back(CV_IMWRITE_PXM_BINARY);
    params.push_back(0);
    
    // Bildinformationen werden mit Ausgabeformat von .pgm-Dateien
    // in buffer gespeichert.
    cv::imencode(".pnm", image, buffer, params);
    
    buffer.push_back('\0');
    // buffer auf std-out schreiben.
    std::cout << buffer.data();
}



void Util::printOut(const std::string& text)
{
    std::cout << text << std::endl;
}

