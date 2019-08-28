/*
 * RadixSort.h
 *
 *  Created on: Jul 22, 2019
 *      Author: alex
 */

#ifndef RADIXSORT_H_
#define RADIXSORT_H_

#include <cmath>

template <typename E>
void RadixSort(E array[], int size, int numKeyDigits, int radix) {
	int j;
	E temp[size];
	int count[radix];

	for (int i = 0, rToI = 1; i < numKeyDigits; ++i, rToI *= radix) {
		// Init count
		for (j = 0; j < radix; ++j) {
			count[j] = 0;
		}

		// Count keys per bin for digit i
		for (j = 0; j < size; ++j) {
			count[(array[j]/rToI) % radix]++;
		}

		// Add up counts to get index
		for (j = 1; j < radix; j++) {
			count[j] += count[j-1];
		}

		for (j = size - 1; j >= 0; --j) {
			temp[--count[(array[j]/rToI) % radix]] = array[j];
		}

		for (j = 0; j < size; ++j) {
			array[j] = temp[j];
		}
	}
}

// Currently takes number of bits to look at (log2(radix)). Could also take radix itself.
template <typename E>
void RadixSort2(E array[], int size, int numKeyBits, int radixBits) {
	int j;
	E temp[size];
	int buckets = 1 << radixBits;
	int mask = buckets - 1;
	int count[buckets];

	for (int i = 0; i < numKeyBits; i += radixBits) {
		// Init count with correct number of buckets
		for (j = 0; j < buckets; ++j) {
			count[j] = 0;
		}

		// Count keys per bin
		for (j = 0; j < size; ++j) {
			count[(array[j] >> i) & mask]++;
		}

		// Add up counts to get index
		for (j = 1; j < buckets; j++) {
			count[j] += count[j-1];
		}

		for (j = size - 1; j >= 0; --j) {
			temp[--count[(array[j] >> i) & mask]] = array[j];
		}

		for (j = 0; j < size; ++j) {
			array[j] = temp[j];
		}
	}
}

#endif /* RADIXSORT_H_ */
