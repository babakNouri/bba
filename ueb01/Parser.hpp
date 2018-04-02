/* 
 * @File:   Parser.hpp
 * @Author: tinf100085
 *
 * Created on April 27, 2017
 */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "IoOperation.hpp"
#include "NullFilter.hpp"


/**
 * In dieser klasse wird aus per Kommandezeile eingegebenen Parameter,
 * eine Liste aus Operationen erzeugt.
 * Jegliche Syntaxfehler wird zu einem Programmabsturz führen. 
 */
class Parser 
{
    private:
        /**
         * Liste der Operationen.
         */
        std::vector<PictureOperation*> opList;
        
        /**
         * Erzeugt einen Instanz der Klasse LoadOperation und fügt den 
         * zu der Operationsliste.
         * 
         * @param inputFileName Name der Datei.
         */
        void addInput(const std::string & inputFileName);
        
        /**
         * Erzeugt einen Instanz der Klasse LoadOperation und fügt
         * den zu der Operationsliste.
         * 
         * @param inputFileName Name der Datei.
         */
        void addOutput(const std::string & outputFileName);
        
        /**
         * Erzeugt einen Instanz der Klasse ShowOperation und fügt
         * den zu der Operationsliste.
         */
        void addShow();
        
        /**
         * Erzeugt einen Instanz der Klasse TwoPicFilter und fügt
         * den zu der Operationsliste.
         * 
         * @param typeString FilterTyp(add, sub. mul und adiff) als String. 
         */
        TwoPicFilterType getTwoPicFilterOperation(const std::string & typeString);
        
        /**
         * Wandelt die eingegebene String zu einem FilterType (FilterType).
         * 
         * @param typeString Filtername als String.
         * 
         * @return aus dem String erzeugte FilterTyp. 
         */
        FilterType getFilterByString(const std::string & typeString);
        
        /**
         * Gibt an, wieviele Optionen hat jedes Filter.
         * 
         * @param filter Filtertyp (FilterType).
         * @return Anzahl der OPtionen.
         */
        unsigned getAmountOfFilterParameters(const FilterType & filter);
        
        /**
         * Anhand des Filtertyps wird eine Instanz von einem Filteropration 
         * erzeugt und zu Operationsliste hinzugefügt.
         * 
         * @param filter Filtertyp (FilterType).
         * @param params Optionen der Filteroperation als eine Liste von Strings.
         */
        void createFilterOperation(const FilterType & filter, 
                                   const std::vector<std::string> & params);

        
    public:
        /**
         * Liest die per Kommandezeile eingegebenen Parameter, wandelt sie in
         * Liste aus Bildoperationen und gibt sie zurück.
         * 
         * @param args er Kommandezeile eingegebenen Parameter. 
         * @return Eine Liste aus Operationen.
         */
        std::vector<PictureOperation*> 
                parseArgs(const std::vector<std::string> & args);
        
       
        /**
         * Destruktor.
         */
        ~Parser();
};


#endif /* PARSER_HPP */

