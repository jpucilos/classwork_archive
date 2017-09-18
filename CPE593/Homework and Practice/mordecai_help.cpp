#include<iostream>
#include<cmath>
#include<string>
using namespace std;



//Question 1
void q1_swap(int *a, int *b){
	int temp = *a;
	b = a;
	a = &temp;
}

//Question 2
int q2_positive_divisors(unsigned long int a){
	int pos_div_a = 0;
	int pos_div_aplus1 = 0;
	for(unsigned long int i = 1; i <= a; i++){
		if(a % i == 0)
			pos_div_a++;
	}
	for(unsigned long int i = 1; i <= a+1; i++){
		if((a+1) % i == 0)
			pos_div_aplus1++;
	}
	if(pos_div_a == pos_div_aplus1)
		return 1;
	else
		return 0;
}

//Question 3
unsigned long int q3_string_hash(const char *str){
	unsigned long int hashSum = 0;
	for (int i = 0; *(str + i) != '\0' && *(str + i) != 1; i++){
		cout << (int)(*(str + i)) <<'\n';
		hashSum += (int)(*(str + i));
	}
	return hashSum;
}

//Question 4
unsigned long q4_diameter(unsigned int n, const double *x, const double *y){
	unsigned long largestDistance = 0;
	for (int i = 0; i > n; i++){
		for(int j = 0; j > n; j++){
			unsigned long distance = sqrt(pow(*(x+i) - *(y+i), 2) + pow(*(x+j) - *(y+j), 2));
			if (distance > largestDistance)
				largestDistance =  distance;
		}
	}
	return largestDistance;
}

unsigned int q5_rotate(unsigned int n, unsigned int r, char d){
	int temp[r] = {0};
	if (d == 'r'){
		
	}
	
}

int main(){
	cout << q2_positive_divisors(21)<<'\n';
	cout << q2_positive_divisors(4)<<'\n';
	cout << q2_positive_divisors(103456)<<'\n';
	cout << q2_positive_divisors(234889)<<'\n';
	int a1 = 100;
	int* a = &a1;
	int b1 = 50;
	int* b = &b1;
	swap(a, b);
	cout << *a << "   " << *b <<'\n';
	char test[4] = {'T','E','S','T'};
	cout << q3_string_hash(test);
	
	
}
