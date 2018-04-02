/* 
 * @File:   OperationsManager.hpp
 * @Author: babak
 *
 * Created on April 30, 2017, 11:54 AM
 */

#ifndef OPERATIONSMANAGER_HPP
#define OPERATIONSMANAGER_HPP

#include "PictureOperation.hpp"

/**
 * Die Klasse führt die eingegebenen Operationen aus.
 */
class OperationsManager 
{
    private:
        /**
         * Ein Vektor (Stack) von Bilder.
         */
        std::vector<cv::Mat> imageStack;
        
    public:
        /**
         * führt die eingegebenen Operationen aus.
         * 
         * @param opList eine Liste aus Zeiger auf Operationen.
         */
        void applyOperations(const std::vector<PictureOperation*> & opList);
    
};

#endif /* OPERATIONSMANAGER_HPP */

