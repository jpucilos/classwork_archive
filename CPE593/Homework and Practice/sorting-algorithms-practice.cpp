//Sorting Algorithms


#include <iostream>
using namespace std;


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
void myQuickSort (int arr[], int L, int R){
	if(L >= R)
		return;
	int i = L;
	int j = R;
	int pivot = (L+R)/2;
	while(i <= j){
		while(i < j && arr[i] < arr[pivot])
			i++;
		while(i < j && arr[j] > arr[pivot])
			j--;
		if(i <= j){
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if(L < j)
		myQuickSort(arr, L, i);
	if(i < R)
		myQuickSort(arr, i+1, R);
}

void quickSort(int arr[], int L, int R) {
      int i = L, j = R;
      int tmp;
      int pivot = arr[(L + R) / 2];
 
      /* partition */
      while (i <= j) {
		while (arr[i] < pivot)
			  i++;
		while (arr[j] > pivot)
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



void printSort(int* a, int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout<< '\n';
}

int main(){
	int a[6] = {6,2,4,1,5,3};
	int b[6] = {6,2,4,1,5,3};	
	int c[6] = {6,2,4,1,5,3};	
	int d[6] = {6,2,4,1,5,3};	
	
	printSort(insertionSort(a, 6), 6);
	
	printSort(heapSort(b, 6), 6);
	
	myQuickSort(c, 0, 5);
	for (int i = 0; i < 6; i++)
		cout << c[i] << '\n';
	
	quickSort(d, 0, 5);
	for (int i = 0; i < 6; i++)
		cout << d[i] << '\n';
}