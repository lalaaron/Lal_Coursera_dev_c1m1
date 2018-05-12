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
 * @file <stats.c> 
 * @brief <Analysis of basic stats on an array of values>
 *
 * Prints an data set with its median, mean maximum and minimum values.
 * Sorts dataset from smallest to largest value
 * 
 * @author Aaron Lal
 * @date Editted 25/04/2018
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
  /* Statistics and Printing Functions Go Here */
  
  /* testing functions*/
  printf("test\n");
  //print_array(&test, SIZE);

}

/* Add other Implementation File Code Here */

void print_statistics(char * ptr, int count)
{
  
}

void print_array(char * ptr, int count)
{
  int i;

  for(i=0; i<40; i++){
    printf("%c\n", *ptr);
    ptr++;
  }
}

int find_median(char * ptr, int count)
{
  return 0;
}

int find_mean(char * ptr, int count)
{
  return 0;
}

int find_maximum(char * ptr, int count)
{
  return 0;
}

int find_minimum(char * ptr, int count)
{
  return 0;
}

void sort_array(char * ptr, int count)
{

}
