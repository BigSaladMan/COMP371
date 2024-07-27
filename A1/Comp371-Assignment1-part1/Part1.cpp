#include <iostream>

namespace {
	int* createArray(int size) {

		int* array = new int[size];

		return array;
	}

	void initializeArray(int* array, int size) {
		for (int i = 0; i < size; ++i) {
			array[i] = i;
		}
	}

	void printArray(int* array, int size) {
		for (int i = 0; i < size; ++i) {
			std::cout << array[i] << "\n";
		}
	}

	void deleteArray(int* array) {
		delete[] array;
	}
}
