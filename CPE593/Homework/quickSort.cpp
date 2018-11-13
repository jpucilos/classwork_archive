/*
	Author: Joseph Puciloski
	cite: 
*/
#include <stdlib.h>  
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
using namespace std;

void quickSort(int arr[], int L, int R) {
      int i = L, j = R;
      int pivot = (L + R) / 2;
      /* partition */
      while (i <= j) {
		while (arr[i] < arr[pivot])
			i++;
		while (arr[j] > arr[pivot])
			j--;
		if (i <= j) {
			swap(arr[i],arr[j]);
		i++;
		j--;
		}
      }
      /* recursion */
      if (L < j)
            quickSort(arr, L, j);
      if (i < R)
            quickSort(arr, i, R);
}


int main(){

	ifstream f ("hw2a.dat");
	int num;
	f >> num;

	for (int i = 0; i < num; i++){
		int n;
		f >> n;
		int a[n];
		for (int i = 0; i < n; i++){
			f >> a[i];
		}
		quickSort(a,0,n-1);
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout <<'\n';
	}
	f.close();
}