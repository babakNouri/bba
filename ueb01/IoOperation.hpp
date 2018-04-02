/* 
 * @File:   IoOperation.hpp
 * @Author: babak
 *
 * Created on April 27, 2017, 10:01 PM
 */

#ifndef IOOPERATION_HPP
#define IOOPERATION_HPP

#include <string>
#include "Types.hpp"
#include "PictureOperation.hpp"

/**
 * Die Klasse repräsentiert die IO-Operationen. 
 */
class IoOperation : public PictureOperation
{
    protected:
        /**
         * Dateiname der Datei ,auf die die Operationen
         * (Lesen oder Schreiben) angewendet wird.
         */
        std::string fileName;
        
        
    public:
        virtual cv::Mat applyOperation(const cv::Mat & image) = 0;
        virtual std::string toString() = 0;
        virtual OpType getOperationType() = 0;
};


#endif /* IOOPERATION_HPP */

