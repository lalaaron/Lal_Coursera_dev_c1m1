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

void main() 
{
  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned char sorted[SIZE];  // sorted dataset
  
  /* Statistics and Printing Functions Go Here */
  sort_array(test, SIZE, sorted);  
  printf("Test data ");
  print_array(test, SIZE);
  printf("Sorted data ");
  print_array(sorted, SIZE);
  print_statistics(test, SIZE, sorted);
  
}

/* Add other Implementation File Code Here */

void print_statistics(unsigned char * ptrA, int count, unsigned char * ptrB)
{
  float med; float mean;
  int max; int min;
  
  /* Calculate median */
  med = find_median(ptrB, count);
  /* Calculate mean */
  mean = find_mean(ptrA, count);
  /* Calculate maximum */
  max = find_maximum(ptrA, count);
  /* Calculate minimum */
  min = find_minimum(ptrA, count);
  
  /* Print summary */
  printf("Median = %f\nMean = %f\nMaximum = %d\nMinimum = %d\n", med, mean, max, min);
  
  
}

void print_array(unsigned char * ptr, int count)
{
  int i;
  printf("[");
  for(i=0; i<count; i++){
    printf("%d", *ptr);
    if(i < count-1){printf(", ");}
    ptr++;
  }
  printf("]\n");
}

float find_median(unsigned char * ptr, int count)
{
  double a;
  double b;
  
  ptr = ptr + ((count-1)/2);
  /* Check if element count is odd */
  if(count%2 == 1)	//return middle element if odd
  {
    return *ptr;
  }
  else	//return average of 2 middle elements if even
  {
    a = *ptr;
    ptr++;
    b = *ptr;
    //printf("midL = %f, midR = %f\n", a, b);	//test output
    return (a + b)/2;
  }
}

float find_mean(unsigned char * ptr, int count)
{
  float total;
  int i;
  for(i = 0; i < count; i++)
  {
    total += *ptr;
    ptr++;
  }
  return total/count;
}

int find_maximum(unsigned char * ptr, int count)
{
  /* Max from unsorted array */
  int max = *ptr;
  int i;
  for(i = 0; i < count; i++)
  {
    if(*ptr > max){max = *ptr;}
    ptr++;
  }
  return max;
  /* Max from sorted array */
  /*ptr = ptr + count - 1;
  return *ptr;*/
}

int find_minimum(unsigned char * ptr, int count)
{
  /* Max from unsorted array */
  int min = *ptr;
  int i;
  for(i = 0; i < count; i++)
  {
    if(*ptr < min){min = *ptr;}
    ptr++;
  }
  return min;
  /* Min from sorted array */
  /*return *ptr;*/
}

void sort_array(unsigned char * ptrA, int count, unsigned char * ptrB)
{
  unsigned char swap[count];
  unsigned char * ptrC = swap;

  copy_array(ptrA, count, ptrB);
  copy_array(ptrA, count, ptrC);
  split(ptrC, 0, count, ptrB);
}

void copy_array(unsigned char * ptrA, int count, unsigned char * ptrB)
{
  int i;
  for(i = 0; i < count; i++)
  {
    *ptrB = *ptrA;
    ptrA++;
    ptrB++;
  }
}

void split(unsigned char * ptrC, int istart, int iend, unsigned char * ptrB)
{
  int imiddle;
  
  if(iend - istart < 2){return;}
  
  imiddle = (iend + istart) / 2;
  
  split(ptrB, istart, imiddle, ptrC);
  split(ptrB, imiddle, iend, ptrC);

  merge(ptrC, istart, imiddle, iend, ptrB);
  
}

void merge(unsigned char * ptrC, int istart, int imiddle, int iend, unsigned char * ptrB)
{

  unsigned char * ptr_k;
  unsigned char * ptr_i;
  unsigned char * ptr_j;
  int i = istart;
  int j = imiddle;
  int k;
 
  // While there are elements in the left or right runs...
  for (k = istart; k < iend; k++)
  {
    ptr_i = ptrC + i;
    ptr_j = ptrC + j;
    ptr_k = ptrB + k;
    // If left run head exists and is >= existing right run head.
    if (i < imiddle && (j >= iend || *ptr_i >= *ptr_j))
    {
      *ptr_k = *ptr_i;
      i = i + 1;
    }
    else 
    {
      *ptr_k = *ptr_j;
      j = j + 1;
    }
  }
}

