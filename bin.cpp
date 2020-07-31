#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>

using namespace std;

/*
Problem: 
In the bin packing problem, items of different weights/sizes must be packed into a finite
number of bins each with the capacity C in a way that minimizes the number of bins used. 

Solution:
Since this problem is NP-complete, this program compares two greedy approximation algorithms: 
"First Fit" and "First Fit Decreasing"
"First Fit Decreasing" simply quicksorts the items into decreasing order before running the algorithm.
"First Fit Decreasing" typically provides more efficient output because it avoids wasting space 
by placing larger items in the bins first.

Example Input (bin.txt): 
The first line is the number of test cases, followed by the capacity of bins for that test case, 
the number of items and then the weight of each item. We will assume that no weight of any single item 
exceeds the capacity of the standard bin for that problem.

Input File Contents:
---
2
10
6
5 10 2 5 4 4 
10
20 
4 4 4 4 4 4 4 4 4 4 6 6 6 6 6 6 6 6 6 6
---

Sample Output:
---
Test Case 1 First Fit: 4 - First Fit Decreasing: 3
Test Case 2 First Fit: 15 - First Fit Decreasing: 10
---
*/

// The below function takes an array, the index of its first element, and the index of its last.
// It chooses the array's final element as a partition element, and places everything larger to the left,
// and everything smaller to the right (we are trying to sort in decreasing order).
int partition(int array [], int l, int h)
{
	int pivot = array[h];
	int x = (l-1);
	int temp;

	for (int k = l; k <= h-1; k++)
	{
		if (array[k] >= pivot)
		{
			x++;
			temp = array[x];
			array[x] = array[k];
			array[k] = temp;
		}
	}
	temp = array[x+1];
	array[x+1] = array[h];
	array[h] = temp;
	return (x+1);
}

// quickSort is a sorting function with an average performance of O(n log n)
// It takes three arguments: the array to be sorted, 
// the index of the first item, and the index of the last item.
// It partitions the array into two sections, and recursively calls itself on those parts of the array.
// The actual sorting is done by the "partition" function above.
void quickSort(int array [], int l, int h)
{
	if (l < h)
	{
		int partIndex = partition(array, l, h);
		quickSort(array, l, partIndex-1);
		quickSort(array, partIndex+1, h);
	}
}

// This function takes an array of items, the capacity of the bins, and the number of items.
// It goes through the bins in order until it finds one that the item will fit in.
// It adds bins whenever the item won't fit anywhere.
int firstFit(int items [], int sizeOfBins, int numberOfItems)
{
	int numberOfBins = 0;
	bool didItFit;
	int *bins = new int[numberOfItems]; // In the worst case, the number of bins will equal the number of items.
	for (int m = 0; m < numberOfItems; m++)
	{
		didItFit = false;
		for (int n = 0; n < numberOfBins; n++) // Go through all open bins
		{
			if (bins[n] >= items[m]) // If it fits in the bin
			{
				bins[n] -= items[m]; // Put it in the bin
				didItFit = true;
				break;
			}
		}
		if (didItFit == false) // If it didn't fit into any existing bin
		{
			numberOfBins++; // Add a bin. 
			bins[numberOfBins-1] = sizeOfBins-items[m]; // Put the item in the new bin.
		}
	}
	delete [] bins; // Clean up.
	return numberOfBins;
}

// We will just quicksort and then run the same function.
// The quicksort function sorts in decreasing order for this problem.
int firstFitDecreasing(int items [], int sizeOfBins, int numberOfItems)
{
	quickSort(items, 0, numberOfItems-1);
	return firstFit(items, sizeOfBins, numberOfItems);
}

// This function reads input from the file (described at the top of this file).
// Then, it calls firstFit and firstFitDecreasing for as many sets of input as the file has.
int main()
{
	ifstream inputfile("bin.txt"); // Set up input file.
	if (!inputfile.is_open()){
		cout << "Input file could not be opened." << endl;
		return 1;
	} // Spit out error if the file can't be opened.
	
	int numberOfCases;
	int sizeOfBins;
	int numberOfItems;
	
	inputfile >> numberOfCases; // The file says the number of test cases at the beginning, one time.
	// Afterward, we need to read in the rest of the data that number of times.
	for (int i = 1; i <= numberOfCases; i++)
	{
		inputfile >> sizeOfBins;
		inputfile >> numberOfItems;
		int* items = new int[numberOfItems]; // Make dynamic array
		for (int j = 0; j < numberOfItems; j++) // Read in the items
		{
			inputfile >> items[j];
		}
	
	    // Output (example shown at the top of this file) with function calls.
		cout << endl << "Test Case " << i << " First Fit: " << firstFit(items, sizeOfBins, numberOfItems);
		cout << " - First Fit Decreasing: " << firstFitDecreasing(items, sizeOfBins, numberOfItems) << endl;
		delete [] items; // Clean up.
	}
	
	inputfile.close(); // Close file.

	cout << endl;

	return 0;
}
