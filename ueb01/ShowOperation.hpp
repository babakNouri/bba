/*
 * @File:   ShowOperation.hpp
 * @Author: babak
 *
 * Created on March 29, 2018, 11:03 PM
 */

#ifndef SHOWOPERATION_HPP
#define SHOWOPERATION_HPP

#include "IoOperation.hpp"

/**
 * Die Klasse ist zuständig für Anzeige eines Bildes. 
 */
class ShowOperation : public IoOperation
{
    public:
        /**
         * Konstruktur.
         */
        ShowOperation();
       
        cv::Mat applyOperation(const cv::Mat & image);
        std::string toString();
        OpType getOperationType();
};


#endif /* SHOWOPERATION_HPP */

