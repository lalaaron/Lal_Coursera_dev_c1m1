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
 * <Add Extended Description Here>
 *
 * @author Aaron Lal
 * @date Editted 25/04/2018
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

void print_statistics(char * ptr, int count);

void print_array(unsigned char * ptr, int count);
/**
 * @brief print_array prints all elements of the array to terminal
 *
 * The array is printed as the array name followed by comma separated varialbles inside square brackets
 *
 * @param * ptr <add description here>
 * @param count is an integer variable for number of array elements
 *
 * @return No return variables
 */

int find_median(char * ptr, int count);
int find_mean(char * ptr, int count);
int find_maximum(char * ptr, int count);
int find_minimum(char * ptr, int count);
void sort_array(char * ptr, int count);

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


#endif /* __STATS_H__ */
