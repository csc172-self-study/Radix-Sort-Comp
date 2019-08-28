/*
 * RadixSortComp.cpp
 *
 *  Created on: Aug 28, 2019
 *      Author: alex
 */

#include "RadixSort.h"
#include <ctime>
#include <random>
#include <iostream>
using std::cout;

int main() {
	const int SIZE = 1000;

	clock_t start;

	std::random_device rd;
	std::mt19937 eng(rd());

	std::uniform_int_distribution<> posDistr(0,SIZE);

	int array[SIZE]; int array1[SIZE]; int array2[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		array[i] = posDistr(eng);
		array1[i] = array[i];
		array2[i] = array[i];
	}

	start = clock();
	RadixSort<int>(array1, SIZE, log10(SIZE)+1, 10);
	double orig_radix_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	start = clock();
	RadixSort2<int>(array2, SIZE, (int) log2(SIZE)+1, 8);
	double new_radix_time = (clock() - start)/ (double) CLOCKS_PER_SEC;

	for (int i = 1; i < SIZE; ++i) {
		if (array1[i] < array1[i-1]) {
			cout << "Array1 was sorted incorrectly.\n";
		}
		if (array2[i] < array2[i-1]) {
			cout << "Array2 was sorted incorrectly.\n";
		}

		//		cout << "Arrays were not sorted the same. Something wrong.\n";
		//					cout << sortedArray1[i] << " != " << sortedArray2[i] << "\n";
	}

	cout << "Original division method took " << orig_radix_time << " s.\n";
	cout << "New bitshift method took " << new_radix_time << " s.\n";
}


