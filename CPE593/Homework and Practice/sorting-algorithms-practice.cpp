//Sorting Algorithms
#include <time.h>  
#include <stdlib.h>  
#include <iostream>
#include <cmath>
using namespace std;

//naiveShuffle
//MergeSort
//HeapSort +
//QuickSort + 
//insertionSort +
//binarySearch +
//FisherYates +
//Linear Search +


int* insertionSort (int a[], int n){
	for (int j = 1; j < n; j++){
		int key = a[j];
		int i = j-1;
		while (i >= 0 && a[i] > key){
			a[i+1] = a[i];
			i= i-1;
		}
		a[i+1] = key;
	}
	return a;
}



void makeHeap(int a[],int n, int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	//left child larger than root
	if(l < n && a[l] > a[largest])
		largest = l;
	//right child larger than root
	if(r < n && a[r] > a[largest])
		largest = r;
	//largest is no longer root
	if(largest != i){
		swap(a[i], a[largest]);
		//recursively call to make the affected subtree a heap
		makeHeap(a,n,largest);
	}
}
int* heapSort(int a[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        makeHeap(a, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(a[0], a[i]);
 
        // call max heapify on the reduced heap
        makeHeap(a, i, 0);
    }
	return a;
}

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

void FisherYates(int arr[], int n){
	srand (time(NULL));
	int pick = 0;
	for (int i = n-1; i >= 1; i--){
		pick = rand() % i;
		swap(arr[i], arr[pick]);
	}
}

void binarySearch(int arr[], int n, int x){
	int L = 0;
	int R = n - 1;
	if( arr[L] > x || arr[R] < x){
		cout<<"Target not Found"<<'\n';
		return;
	}
	int pick = (L+R)/2;
	while(1){
		if(arr[pick] == x){
			cout<<"Target Found"<<'\n';
			return;
		}
		else if(arr[pick] > x){
			R = pick;
			pick = (L+R)/2;
		}
		else if( arr[pick] < x){
			L = pick;
			pick = (L+R)/2;
		}
		if (abs(L - R) <2 && arr[pick] != x){
			cout <<"Target not found"<<'\n';
			return;
		}
	}
}

void linearSearch (int arr[], int n, int x){
	for (int i = 0; i < n; i++){
		if (arr[i] == x){
			cout<<"Target Found" << '\n';
			return;
		}
	}
	cout << "Target Not Found" <<'\n';
}

void printSort(int* a, int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout<< '\n';
}

int main(){
	/*
	int a[6] = {6,2,4,1,5,3};
	int b[6] = {6,2,4,1,5,3};	
	int c[6] = {6,2,4,1,5,3};	
	int d[6] = {6,2,4,1,5,3};	
	
	printSort(insertionSort(a, 6), 6);
	
	printSort(heapSort(b, 6), 6);

	
	quickSort(d, 0, 5);
	for (int i = 0; i < 6; i++)
		cout << d[i] << '\n';
	*/
	
	int e[15] = {0,3,4,6,9,14,36,74,134,256,289,420,590,1090,2054};
	FisherYates(e, 15);
	for (int i = 0; i < sizeof(e)/sizeof(int); i++)
		cout << e[i] << ' ';
	cout << '\n';

	quickSort(e, 0, 14);
	for (int i = 0; i < sizeof(e)/sizeof(int); i++)
		cout << e[i] << ' ';
	cout << '\n';
	
	binarySearch(e, 15, 1090);
	binarySearch(e, 15, 4096);
	binarySearch(e, 15, -1000);
	binarySearch(e, 15, 0);
	
	linearSearch(e, 15, 1090);
	linearSearch(e, 15, 4096);
	linearSearch(e, 15, -1000);
	linearSearch(e, 15, 0);
}