/*
 * @File:   LoadOperation.hpp
 * @Author: babak
 *
 * Created on April 30, 2017, 10:43 AM
 */

#ifndef LOADOPERATION_HPP
#define LOADOPERATION_HPP

#include "IoOperation.hpp"

/**
 * Die Klasse ist zuständig für Laden eines Bild. 
 */
class LoadOperation : public IoOperation
{
    public:
        /**
         * Konstruktur.
         * 
         * @param fileName Name der Datei.
         */
        LoadOperation(const std::string & fileName);
        
        cv::Mat applyOperation(const cv::Mat & image);
        std::string toString();
        OpType getOperationType();
};



#endif /* LOADOPERATION_HPP */

