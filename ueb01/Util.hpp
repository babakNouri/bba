/* 
 * @File:   Util.hpp
 * @Author: babak
 *
 * Created on April 29, 2017, 10:58 PM
 */

#ifndef UTIL_HPP
#define UTIL_HPP

/**
 * Die Klasse ist für sämltliche Hilffunktionen, 
 * insbesonderes für Schreiben auf Std-out.
 */
class Util
{
    public:
        /**
         * Eine Debug-Methode um eingelesene per Kommandozeile Parameter
         * aus std-out schreiben.
         * 
         * @param params Liste der eingelesene per Kommandozeile Parameter.
         */
        void pirntArguments(std::vector<std::string> & params);
        
        /**
         * Ruft toString-Methode jeder Operation auf und schreibt dammit
         * deren Informationen aud std-out.
         * 
         * @param opList Liste der Operationen.
         */
        void printOperationList(std::vector<PictureOperation*> & opList);
        
        /**
         * Schreibt das eingegebenes Bild auf Std-out.
         * 
         * @param image das Bild.
         */
        void printImage(const cv::Mat & image);
        
        
        /**
         * Schreibt einen Text auf standard-Output.
         * 
         * @param text Text.
         */
        void printOut (const std::string & text);
        
};


#endif /* UTIL_HPP */

