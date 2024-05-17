#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
void swap(int& x, int& y) {

	int temp;

	temp = x;
	x = y;
	y = temp;
}
void selectionSort(int* x, int n) {
	int min, i, j;
	for (i = 0; i < (n - 1); i++) {
		min = i; 
		for (j = i + 1; j < n; j++) {
			
			if (x[j] < x[min]) min = j;
		}
		if (min != i) swap(x[i], x[min]);
	}
}

void bubbleSorting (int* x , int n){

	int i, j, swapped;

	for ( i = 1; i < n; i++) {
		swapped = 0;

			for (j = 0; j < n-1; j++) {

				if (x[j] > x[j + 1]) {
					swap(x[j], x[j + 1]);
					swapped = 1;
				}
		}
			if (swapped == 0) break;
	}
}
/*
	void insertionSortMine(int* a, int n) {
		int i, j;

		for (i = 1; i < n; i++) {

			for (j = 0; j < i; j++) {

				if (a[i] < a[j]) {

					swap(a[i], a[j]);
				}
			}
		}
	}
*/
void insertionSort(int* a, int n) {

	int value, i, j;

	for (i = 1; i < n; i++) {

		j = i - 1;
		value = a[i];

		while (j >= 0 && a[j] > value) {

			a[j + 1] = a[j];
			j--;
		}

		a[j + 1] = value;

	}
}
int sequentialSearch(int* a, int n, int num) {

	int i = 0 , found = 0;

	while ((i < n) && (!found)) {
		if (a[i] == num) {
			found = 1;
		}
		else i++;
	}

	if (found) return i;
	else return -1;
 }
int binarySearch(int* a, int n, int num) {
	int low = 0,
		high = n,
		found = 0,
		mid;
	while ((low <= high) && !found) {

		mid = (high + low) / 2;

		if (a[mid] > num)

			high = mid - 1;

		else if (a[mid] < num)

			low = mid + 1;

		else
			found = 1;
	}

	if (found)
		return mid;
	else
		return -1;


}
int main() {

	vector < int > x = { 10 ,4,2,7,3,9,10,18,30,5,7,3 };
	//selectionSort(&x.front(), size(x));
	//bubbleSorting(&x.front(), x.size());

	insertionSort(&x.front(), x.size());
	for (int i = 0; i < size(x); i++) {
		cout << x[i] <<  endl;
	}

	cout << sequentialSearch(&x.front(), x.size(), 10) << endl;
	cout << binarySearch(&x.front(), x.size(), 9) << endl;


	return 0;
}