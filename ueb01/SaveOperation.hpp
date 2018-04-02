/* 
 * @File:   SaveOperation.hpp
 * @Author: babak
 *
 * Created on April 30, 2017, 10:53 AM
 */

#ifndef SAVEOPERATION_HPP
#define SAVEOPERATION_HPP

#include "IoOperation.hpp"

/**
 * Die Klasse ist zuständig für Speichern eines Bild. 
 */
class SaveOperation : public IoOperation
{
    public:
        /**
         * Konstruktur.
         * 
         * @param fileName Name der Datei.
         */
        SaveOperation(const std::string & fileName);
        
        cv::Mat applyOperation(const cv::Mat & image);
        std::string toString();
        OpType getOperationType();
};

#endif /* SAVEOPERATION_HPP */

