/** 
 * @File:   Parser.cpp
 * @Author: tinf100085
 *
 * Created on April 27, 2017
 */

#include <string>
#include <iostream>
#include <vector>
#include "Parser.hpp"
#include "LoadOperation.hpp"
#include "SaveOperation.hpp"
#include "NullFilter.hpp"
#include "ShowOperation.hpp"
#include "BrightnessFilter.hpp"
#include "FactorFilter.hpp"
#include "LinearFilter.hpp"
#include "MinMaxFilter.hpp"
#include "GammaFilter.hpp"
#include "TwoPicFilter.hpp"
#include "HistogramFilter.hpp"
#include "HistogramCheckFilter.hpp"


Parser::~Parser()
{
    this->opList.clear();
}

void Parser::addInput(const std::string & inputFileName)
{
    this->opList.push_back(new LoadOperation(inputFileName));
}



void Parser::addOutput(const std::string & outputFileName)
{
    this->opList.push_back(new SaveOperation(outputFileName));
}


void Parser::addShow()
{
    this->opList.push_back(new ShowOperation());
}

TwoPicFilterType Parser::getTwoPicFilterOperation(const std::string & typeString)
{
    TwoPicFilterType res = TwoPicFilterType::add;
            
    if (typeString.compare("add") == 0)
    {
        res = TwoPicFilterType::add;
    }
    else if (typeString.compare("sub") == 0)
    {
        res = TwoPicFilterType::sub;
    }
    else if (typeString.compare("mul") == 0)
    {
        res = TwoPicFilterType::mul;
    }
    else if (typeString.compare("adiff") == 0)
    {
        res = TwoPicFilterType::adiff;
    }
    
    return res;
}

FilterType Parser::getFilterByString(const std::string & typeString)
{
    FilterType res = null_Filter;
    
    if (typeString.compare("null") == 0)
    {
        res = FilterType::null_Filter;
    }
    else if (typeString.compare("brightness") == 0)
    {
        res = FilterType::brightness_Filter;
    }
    else if (typeString.compare("factor") == 0)
    {
        res = FilterType::factor_Filter;
    }
    else if (typeString.compare("linear") == 0)
    {
        res = FilterType::linear_Filter;
    }
    else if (typeString.compare("minmax") == 0)
    {
        res = FilterType::minMax_Filter;
    }
    else if (typeString.compare("gamma") == 0)
    {
        res = FilterType::gamma_Filter;
    }
    else if ((typeString.compare("add") == 0) || (typeString.compare("sub") == 0)
             ||
            (typeString.compare("mul") == 0) || (typeString.compare("adiff") == 0))
    {
        res = FilterType::twoPic_Filter;
    }
    else if (typeString.compare("histogram") == 0)
    {
        res = FilterType::histogram_Filter;
    }
    else if (typeString.compare("sum-histogram") == 0)
    {
        res = FilterType::sumHistogram_Filter;
    }
    else if (typeString.compare("histogram-check") == 0)
    {
        res = FilterType::histogramCheck_Filter;
    }
    return res;
}


unsigned Parser::getAmountOfFilterParameters(const FilterType & filter)
{
    unsigned res = 0;
    
    switch(filter)
    {
        case FilterType::linear_Filter:
            res = 2;
            break;
            
        case FilterType::brightness_Filter:
        case FilterType::factor_Filter:
        case FilterType::gamma_Filter:
        case FilterType::histogram_Filter:
        case FilterType::sumHistogram_Filter:
            res = 1;
            break;
            
        case FilterType::null_Filter:
        case FilterType::minMax_Filter:
        case FilterType::twoPic_Filter:
        case FilterType::histogramCheck_Filter:
        default :
            res = 0;
            break;
    }
      
    return res;
}


void Parser::createFilterOperation(const FilterType& filter, 
                                   const std::vector<std::string>& params)
{
    switch(filter)
    {
        case FilterType::null_Filter:
            this->opList.push_back(new NullFilter());
            break;
            
        case FilterType::brightness_Filter:
            this->opList.push_back(new BrightnessFilter(std::stof(params[0])));
            break;
            
        case FilterType::factor_Filter:
            this->opList.push_back(new FactorFilter(std::stof(params[0])));
            break;
            
        case FilterType::linear_Filter:
            this->opList.push_back(new LinearFilter(std::stof(params[0]), std::stof(params[1])));
            break;
            
        case FilterType::minMax_Filter:
            this->opList.push_back(new MinMaxFilter());
            break;
        
        case FilterType::gamma_Filter:
            this->opList.push_back(new GammaFilter(std::stof(params[0])));
            break;
            
        case FilterType::twoPic_Filter:
            this->opList.push_back(new TwoPicFilter(getTwoPicFilterOperation(params[0])));
            break;
            
        case FilterType::histogram_Filter:
            this->opList.push_back(new HistogramFilter(std::stoi(params[0]), false));
            break;
            
        case FilterType::sumHistogram_Filter:
            this->opList.push_back(new HistogramFilter(std::stoi(params[0]), true));
            break;
            
        case FilterType::histogramCheck_Filter:
            this->opList.push_back(new HistogramCheckFilter());
            break;
            
        default:
            break;
    }
}

std::vector<PictureOperation*> 
Parser::parseArgs(const std::vector<std::string> & args)
{
    // Lese-Index.
    unsigned readIndex = 0;
    unsigned i = 0;
    FilterType filter = FilterType::null_Filter;
    unsigned amountOfFilterParameter = 0;
    
    std::vector<std::string> params;
    
    // Bis alle Parameter gelesen wurden.
    while (readIndex < args.size())
    {
        // wenn (--input)
        if (args[readIndex].compare("--input") == 0)
        {
            // eine Bild-Laden-Operation wird mit dem nächsten Parameter
            // als Deteiname erzeugen und hizufügen.
            addInput(args[readIndex + 1]);
            readIndex += 2;
        }
        // wenn (--output) 
        else if (args[readIndex].compare("--output") == 0)
        {
            // eine Bild-Speichern-Operation wird mit dem nächsten Parameter
            // als Deteiname erzeugen und hizufügen.
            addOutput(args[readIndex + 1]);
            readIndex += 2;
        }
        // wenn (--show)
        else if (args[readIndex].compare("--show") == 0)
        {
            addShow();
            readIndex++;
        }
        // wenn (--filter))
        else if (args[readIndex].compare("--filter") == 0)
        {
            readIndex++;
            
            // nächstes Parameter zu FilterTyp umwandeln.
            filter = getFilterByString(args[readIndex]);
            // Anhand des Filtertyps wird die Anzahl der Optionen bestimmt.
            amountOfFilterParameter = getAmountOfFilterParameters(filter);
            // Liste der Parameter leeren.
            params.clear();

            // Optionen werden zu Parameter Liste hinzugefügt.
            for (i = 0; i < amountOfFilterParameter; i++)
            {
                readIndex++;
                params.push_back(args[readIndex]);
            }
            
            if (filter == FilterType::twoPic_Filter)
            {
                params.push_back(args[readIndex]);
            }
            
            // Filteroperation wird erzeugt und zu Operationsliste hinzugefügt.
            createFilterOperation(filter, params); 
            
            readIndex++;
        }
    }
    
    // Liste der Filteroperationen wird zurückgegeben.
    return this->opList;
};
