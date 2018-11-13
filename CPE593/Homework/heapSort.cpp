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

void makeHeap(int a[],int n, int i){
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	//left larger than root
	if(l < n && a[l] > a[largest])
		largest = l;
	//right larger than root
	if(r < n && a[r] > a[largest])
		largest = r;
	//largest is no longer root
	if(largest != i){
		swap(a[i], a[largest]);
		makeHeap(a,n,largest);
	}
}
void heapSort(int a[], int n)
{
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        makeHeap(a, n, i);
    for (int i=n-1; i>=0; i--){
        swap(a[0], a[i]);
        makeHeap(a, i, 0);
    }
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
		heapSort(a,n);
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout <<'\n';
	}
	f.close();
}