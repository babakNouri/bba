/* 
 * @File:   ueb01.cpp
 * @Author: babak
 *
 * Created on May 3, 2017, 11:39 PM
 */


#include <iostream>
#include <vector> 
#include <string>
#include "Parser.hpp"
#include "Util.hpp"
#include "OperationsManager.hpp"





/**
 * Main-Methode derAufgabe 2.
 * 
 * @param argc Anzahl der eingegebenen Parametern. 
 * @param argv einegegebene Parameter als String-Array.
 * 
 * @return 0.
 */
int main(int argc, char** argv) {

    bool debug = 0;
    
    Util util;
    Parser parser;
    OperationsManager opManager;
    
    // argv-Array zu Vector umwandeln.
    std::vector<std::string> arguments(argv + 1 , argv + argc);
    
    // Kommandozeile Parameter wird gelesen und zu eine Lieste von 
    // Bildoperationen umgewandelt.    
    std::vector<PictureOperation*>  opList = parser.parseArgs(arguments);
   
    if (debug)
    {
        util.pirntArguments(arguments);
        util.printOperationList(opList);
    }
    
    // Operationen durchführen.
    opManager.applyOperations(opList);
    
    return 0;
}

