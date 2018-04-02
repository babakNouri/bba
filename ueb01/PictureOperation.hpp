/**
 * @File:   PictureOperation.hpp
 * @Author: babak
 *
 * Created on April 29, 2017, 10:48 AM
 */

#ifndef PICTUREOPERATION_HPP
#define PICTUREOPERATION_HPP

#include <string>
#include <opencv2/highgui/highgui.hpp>
#include "Types.hpp"


/**
 * Eine abstrakte Klasse (Interface) die jede Operation,
 * die auf ein Bild ausgeführt wird, inklusiv IO-Operationen repräsentert. 
 */
class PictureOperation
{
        
    public:
        /**
         * Die Operationen (abhängig der Type der Object ) wird auf 
         * das eingegebene Bild angewendet. 
         * 
         * @param image das eingegebene Bild. 
         * @return das verändertes Bild.
         */
        virtual cv::Mat applyOperation(const cv::Mat & image) = 0;
        
        
        /**
         * Gibt Informationen der Objekt als String zurück.
         * 
         * @return Informationen der Operation als String.
         */
        virtual std::string toString() = 0;
        
        
        /**
         * Gibt Type der Operation zurück.
         * 
         * @return Type der Operationen (Save, Load, Filter).
         */
        virtual OpType getOperationType() = 0;
        
};


#endif /* PICTUREOPERATION_HPP */

