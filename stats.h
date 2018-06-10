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

void print_statistics(unsigned char * ptrA, int count, unsigned char * ptrB);
/**
 * @brief A function that prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * Calls the following fuctions with unsorted data array: find_mean(), find_maximum() and find_minimum(),
 * find_median() must be called with sorted data array.
 *
 * @param * ptrA is a character pointer to array of unsorted test data
 * @param count is an interger variable for array size
 * @param * prtB is a character pointer to sorted data array
 *
 * @return void
 */

void print_array(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, prints the array to the screen
 *
 * The array is printed as "array_name[element1, element2, ... elementn]
 *
 * @param * ptr is a pointer to characters in the array being printed
 * @param count is an integer variable for number of array elements
 *
 * @return void
 */
 
float find_median(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, returns the median value
 *
 * If there is an even number of values, the returned value will be the average of the two median values
 * This function works only with a sorted array
 *
 * @param * ptr is a pointer to characters in the sorted data array
 * @param count is an integer variable for number of array elements
 *
 * @return Median as a floating point value
 */
 
float find_mean(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, returns the mean
 *
 * Works by dividing the sum of all elements by the array size
 *
 * @param * ptr is a pointer to characters in data array being averaged
 * @param count is an integer variable for number of array elements
 *
 * @return Mean as a floating point value
 */
 
int find_maximum(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, returns the maximum
 *
 * Scans the array comparing each value to highest value encountered
 *
 * @param * ptr is a pointer to characters in data array being searched
 * @param count is an integer variable for number of array elements
 *
 * @return Maximum as an integer value
 */
 
int find_minimum(unsigned char * ptr, int count);
/**
 * @brief Given an array of data and a length, returns the minimum
 *
 * Scans the array comparing each value to lowest value encountered
 *
 * @param * ptr is a pointer to characters in data array being searched
 * @param count is an integer variable for number of array elements
 *
 * @return Minimum as an integer value
 */

void sort_array(unsigned char * ptrA, int count, unsigned char * ptrB);
/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest
 *
 * The zeroth element is the largest value, and the last element (n-1) is the smallest value
 * This function used the merge-sort algorithm which also calls the following functions:
 * copy_array() and split() which calls the merge() function
 *
 * @param * ptrA is a pointer to characters in the origninal data array
 * @param count is an integer variable for number of array elements in dataset
 * @param * ptrB is a pointer to characters in the array designated for the sorted data
 * @param swap[] is a local character array for sorting values
 * @param * ptrC is a local pointer to charactters in the swap array
 *
 * @return void
 */
 
void copy_array(unsigned char * ptrA, int count, unsigned char * ptrB);
/**
 * @brief Copies one array of a given size into another array of equal size
 *
 * @param * ptrA is a pointer to characters in the origninal data array
 * @param count is an integer variable for number of array elements in dataset
 * @param * ptrB is a pointer to characters in the array designated for the copy
 *
 * @return void
 */
 
void split(unsigned char * ptrC, int istart, int iend, unsigned char * ptrB);
/**
 * @brief Split is a recursive function which carries out the sorting using the merge-sort algorithm
 *
 * The split funtion splits the array half and then merges the the two halves in order of 
 * highest to lowest using the merge() function 
 *
 * @param * ptrC is a pointer to characters in the swap array 
 * @param istart is an integer variable for the left bound index of array to be split
 * @param iend is an integer variable for the right bound index of array to be split 
 * @param * ptrB is a pointer to characters in the sorted data array
 * @param imiddle is a local integer variable for the index at which to split the array
 *
 * @return void
 */
 
void merge(unsigned char * ptrC, int istart, int imiddle, int iend, unsigned char * ptrB);
/**
 * @brief Merges the split array in order of highest to lowest value
 *
 * <Add Extended Description Here>
 *
 * @param * ptrC is a pointer to characters in the swap array
 * @param istart is an integer variable for the left bound index of split array
 * @param imiddle is an integer variable for the index at which array is split
 * @param iend is an integer variable for the righ bound index of split array
 * @param * ptrB is a pointer to characters in the sorted data array
 * @param * ptr_k is a local pointer to the characters in array being merged
 * @param * ptr_i is a local pointer to the characters in left portion of swap array
 * @param * ptr_j is a local pointer to the characters in right portion of swap array
 * @param i is a local integer index variable for counting through left portion of swap array
 * @param j is a local integer index variable for counting through right portion of swap array
 * @param k is a local integer index variable for counting through full portion of sorted array
 *
 * @return <void
 */
 
#endif /* __STATS_H__ */
