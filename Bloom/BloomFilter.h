/*
 * =====================================================================================
 *
 *       Filename:  BloomFilter.hpp
 *
 *    Description:  implementation of bloom flter.
 *
 *        Version:  1.0
 *        Created:  05/27/2017 09:34:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  david M., 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <bitset>

template <class T, unsigned int L>
class BloomFilter{
    public:
        BloomFilter();
        ~BloomFilter();
        void insert(T val);
        bool exists(T val);

    private:
        std::bitset<L> *vector;
        void hash();
};
