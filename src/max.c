#include <stdio.h>
#include <assert.h>

int max(int* numbers, int size)
{
    // Exercise 2 code.
    assert(size > 0);
    int highest = numbers[0]; // Initialize the "highest" variable as the first element in the given array to start.
	for(int i = 1; i < size; i++){ // Run through the array from 0 -> n-1
		if(numbers[i] > highest){ // Test whether the current slot in the array has a higher value than the current saved highest value.
			highest = numbers[i]; // If above is true, highest is reassigned as the value of the current spot in the array.
        }
    }
    return highest;
}
