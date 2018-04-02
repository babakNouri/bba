/* 
 * @File:   Types.hpp
 * @Author: babak
 *
 * Created on April 27, 2017, 10:13 PM
 */

#ifndef TYPES_HPP
#define TYPES_HPP


enum OpTypeEnum {load, save, show, filter};
typedef OpTypeEnum OpType;

enum EnumFilter {null_Filter, 
                 brightness_Filter,
                 factor_Filter,
                 linear_Filter,
                 minMax_Filter,
                 gamma_Filter,
                 twoPic_Filter,
                 histogram_Filter,
                 sumHistogram_Filter,
                 histogramCheck_Filter};
                 
typedef EnumFilter FilterType;


enum EnumTwoPicFilter 
{
    add, sub, mul, adiff
};

typedef EnumTwoPicFilter TwoPicFilterType;

const float MAXIMUM_OF_8_BIT = 255.0;
const float MAXIMUM_OF_16_BIT = 65535.0;

#endif /* TYPES_HPP */

