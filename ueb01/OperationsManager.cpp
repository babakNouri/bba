/*
 * @File:   OperationsManager.cpp
 * @Author: babak
 *
 * Created on April 30, 2017, 10:43 AM
 */


#include <iostream>
#include "OperationsManager.hpp"
#include "PictureOperation.hpp"
#include "FilterOperation.hpp"
#include "TwoPicFilter.hpp"


void OperationsManager::applyOperations(const std::vector<PictureOperation*>& opList)
{
    // Für jede Operation ...
    for (PictureOperation* op : opList)
    {
        // anhand des Operationstyps ...
        switch ( op->getOperationType() )
        {
            
            case OpType::load :
                // Beim Laden, wird das eingelesenes Bild auf stack gelegt.
//                std::cout << "LOAD1: StackSize=" << this->imageStack.size() << std::endl << op->toString() << std::endl;
                this->imageStack.push_back(op->applyOperation(cv::Mat()));
//                std::cout << "LOAD2: StackSize=" << this->imageStack.size() << std::endl;
//                std::cout << "LOAD: ----------------------------------------------" << std::endl;
                break;
                
            case OpType::filter :
            {
                FilterOperation* filterOp = (FilterOperation*) op;
//                std::cout << "FILTER1: StackSize=" << this->imageStack.size() << std::endl << op->toString() << std::endl;
                // Filter wird ausgeführt und stack bleibt unverändert.
                if (filterOp->getFilterType() == FilterType::twoPic_Filter)
                {
                    TwoPicFilter* twoPicfilter = (TwoPicFilter*) filterOp;
                    cv::Mat firstImage = this->imageStack.back();
                    this->imageStack.pop_back();
                    this->imageStack.back() = twoPicfilter
                                                ->applyOperation(firstImage, 
                                                                 this->imageStack.back());
//                            CfilterOp->applyOperation(firstImage, this->imageStack.back());
                }
                else
                {
                    this->imageStack.back() = filterOp->applyOperation(this->imageStack.back());
                }
//                std::cout << "FILTER2: StackSize=" << this->imageStack.size() << std::endl;
//                std::cout << "FILTER: ----------------------------------------------" << std::endl;
                break;
            }   
            case OpType::save :
                // Beim Speichern, wird das Oberste Bild gespeichert und aus
                // dem Stack gelöscht.
//                std::cout << "SAVE1: StackSize=" << this->imageStack.size() << std::endl << op->toString() << std::endl;
                op->applyOperation(this->imageStack.back());
                this->imageStack.pop_back();
//                std::cout << "SAVE2: StackSize=" << this->imageStack.size() << std::endl;
//                std::cout << "SAVE: ----------------------------------------------" << std::endl;
                break;
                
            case OpType::show :
                op->applyOperation(this->imageStack.back());
                break;
        }
        
    }
}
