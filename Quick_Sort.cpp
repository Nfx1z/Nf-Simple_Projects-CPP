//      BY : VKEY
// =========================================== PURPOSE OF THIS PROGRAM =================================================
/*
					QUICK SORT ALGORTIHM
			arr[] = {10,76,93,8,39,81,23,31,45,52}
1)	Determine the pivot, can be at the beginning, at the end, at the tengha, or randomly
		pivot = 10	-> {8,'10',93,76,39,81,23,31,45,52}
2)	take the left and the right part of the pivot
		left = {8}
		right = {93,76,39,81,23,31,45,52}
3)	now do the left part or the right part with step 1
	// left part
		pivot = 8	-> {'8',10,93,76,39,81,23,31,45,52}
	// right part
		pviot = 93	-> {8,10,52,76,39,81,23,31,45,'93'}
4)	repeat steps one through three untill the array is sorted
*/

// ================================================== LIBRARY ==========================================================
#include <iostream> // std::cout, std::cin, std::endl
using namespace std;

// ================================================= FUNCTIONS ========================================================
// function to partition the array
int partition(int arr[], int firstIndex, int lastIndex){

	int pivot = arr[firstIndex]; // value of the pivot
	int count = 0; // count n numbers in the left of the pivot

    // search for the true position of the pivot
	for (int i = firstIndex + 1; i <= lastIndex; i++)
		if (arr[i] <= pivot)
			count++;

	// swap the pivot to its position
	int pivotIndex = firstIndex + count;
	swap(arr[firstIndex], arr[pivotIndex]);

	// index for left and right parts
	int left = firstIndex, right = lastIndex;
    // Sort the array where the smaller one is on the left and the larger one is on the right
	while (left < pivotIndex and right > pivotIndex) {
        // check the left parts
		while (arr[left] <= pivot)
			left++;
        // check the right parts
		while (arr[right] > pivot)
			right--;
        // swap to get the smaller one is on the left and the larger one is on the right
		if (arr[left] > pivot and arr[right] < pivot)
			swap(arr[left++], arr[right--]); // auto increase and decrease the variable
	}
    // return the position of the pivot
	return pivotIndex;
}

// function quick sort with recursive function
void quickSort(int arr[], int firstIndex, int lastIndex){

	// base case of recursive function
	if (firstIndex >= lastIndex)
		return;

	// partitioning the array and to get its position
	int position = partition(arr, firstIndex, lastIndex);
	// Sorting the left part
	quickSort(arr, firstIndex, position - 1);
	// Sorting the right part
	quickSort(arr, position + 1, lastIndex);
}

// function to print the entire array
void printArray(int (&arr)[], int &size){
    for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

// =============================================== MAIN PROGRAM ========================================================
int main(){
    
	int arr[] = {31,93,76,8,45,81,10,23,39,52}; // main array
	int size = sizeof(arr)/sizeof(int); // size of the main array
    // call the function
	quickSort(arr, 0, size - 1);
    // to print the array
	printArray(arr, size);

	return 0;
}
