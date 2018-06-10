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
 * @file stat.c
 * @brief Analysis of basic stats on an array of values
 *
 * Prints an data set with its median, mean maximum and minimum values.
 * Sorts dataset from smallest to largest value
 *
 * @author Aaron Lal
 * @date Editted 10/06/2018
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char sorted[SIZE];  // sorted dataset
  /* Statistics and Printing Functions Go Here */

}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char * ptr, int count)
{

}

void print_array(unsigned char * ptr, int count)
{

}
 
float find_median(unsigned char * ptr, int count)
{

}
 
float find_mean(unsigned char * ptr, int count)
{

}
 
int find_maximum(unsigned char * ptr, int count)
{

}
 
int find_minimum(unsigned char * ptr, int count)
{

}

void sort_array(unsigned char * ptrA, int count, unsigned char * ptrB)
{

}
