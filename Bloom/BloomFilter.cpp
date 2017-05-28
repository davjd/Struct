/*
 * =====================================================================================
 *
 *       Filename:  BloomFilter.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2017 10:09:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  david M, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "BloomFilter.h"

template <class T, unsigned int L>
void BloomFilter::BloomFilter(){
   vector = new bitset<L>(); 
}

template<class T>
void insert(T val){
    
}

template<class T>
bool exists(T val){
    return false;
}
