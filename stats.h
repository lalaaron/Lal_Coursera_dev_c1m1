/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief Header file for stats.c
 *
 * @author Aaron Lal
 * @date Editted 10/06/2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

void print_statistics(unsigned char * ptr, int count);
/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return void
 */

void print_array(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return void
 */
 
float find_median(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, returns the median value
 *
 * If there is an even number of values, the returned value will be the average of the two median values
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return Median as a floating point value
 */
 
float find_mean(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, returns the mean
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return Mean as a floating point value
 */
 
int find_maximum(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return Maximum as an integer value
 */
 
int find_minimum(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return Minimum as an integer value
 */

void sort_array(unsigned char * ptrA, int count, unsigned char * ptrB);
/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest
 *
 * The zeroth Element should be the largest value, and the last element (n-1) should be the smallest valu
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return void
 */
 
#endif /* __STATS_H__ */
