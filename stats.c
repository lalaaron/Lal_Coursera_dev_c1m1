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
 * @date Editted 12/05/2018
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
  unsigned char sorted[SIZE];
  //float hist[4];
  //float median;
  //float mean;
  //int max;
  //int min;
  
  /* Statistics and Printing Functions Go Here */
  sort_array(test, SIZE, sorted);  
  printf("Test data ");
  print_array(test, SIZE);
  printf("Sorted data ");
  print_array(sorted, SIZE);
  print_statistics(test, SIZE, sorted);
  
  /* Testing for sorting algorithm */
  //printf("test");
  //print_array(test, SIZE);
  //printf("sorted");
  //print_array(sorted, SIZE);
  
  /* Testing reverse sort */
  //reverse(test, SIZE, sorted);
  //printf("reversed");
  //print_array(sorted, SIZE);
  
  /* Median & Mean function testing */
  //median = find_median(sorted, SIZE);
  //printf("median = %f\n", median);
  //mean = find_mean(test, SIZE);
  //printf("mean = %f\n", mean);
  
  /* Max & Min testing */
  //min = find_minimum(sorted, SIZE);
  //max = find_maximum(sorted, SIZE);
  //printf("Minumum = %d\nMaximum = %d\n", min, max);
  
}

/* Add other Implementation File Code Here */

void print_statistics(char * ptrA, int count, char * ptrB)
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

void split(unsigned char * ptrB, int istart, int iend, unsigned char * ptrA)
{
  int imiddle;
  
  if(iend - istart < 2){return;}
  
  imiddle = (iend + istart) / 2;
  
  split(ptrA, istart, imiddle, ptrB);
  split(ptrA, imiddle, iend, ptrB);

  merge(ptrB, istart, imiddle, iend, ptrA);
  
}

void merge(unsigned char * ptrA, int istart, int imiddle, int iend, unsigned char * ptrB)
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
    ptr_i = ptrA + i;
    ptr_j = ptrA + j;
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


/*************** PSEUDOCODE *************/
/*
// Array A[] has the items to sort; array B[] is a work array.
TopDownMergeSort(A[], B[], n)
{
    CopyArray(A, 0, n, B);           // duplicate array A[] into B[]
    TopDownSplitMerge(B, 0, n, A);   // sort data from B[] into A[]
}

// Sort the given run of array A[] using array B[] as a source.
// iBegin is inclusive; iEnd is exclusive (A[iEnd] is not in the set).
TopDownSplitMerge(B[], iBegin, iEnd, A[])
{
    if(iEnd - iBegin < 2)                       // if run size == 1
        return;                                 //   consider it sorted
    // split the run longer than 1 item into halves
    iMiddle = (iEnd + iBegin) / 2;              // iMiddle = mid point
    // recursively sort both runs from array A[] into B[]
    TopDownSplitMerge(A, iBegin,  iMiddle, B);  // sort the left  run
    TopDownSplitMerge(A, iMiddle,    iEnd, B);  // sort the right run
    // merge the resulting runs from array B[] into A[]
    TopDownMerge(B, iBegin, iMiddle, iEnd, A);
}

//  Left source half is A[ iBegin:iMiddle-1].
// Right source half is A[iMiddle:iEnd-1   ].
// Result is            B[ iBegin:iEnd-1   ].
TopDownMerge(A[], iBegin, iMiddle, iEnd, B[])
{
    i = iBegin, j = iMiddle;
 
    // While there are elements in the left or right runs...
    for (k = iBegin; k < iEnd; k++) {
        // If left run head exists and is <= existing right run head.
        if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;
        }
    }
}

CopyArray(A[], iBegin, iEnd, B[])
{
    for(k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}
*/
