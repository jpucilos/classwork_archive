#include<iostream>
#include<cmath>
#include<string>
using namespace std;

//Question 1
void q1_swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
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
		hashSum += (int)(*(str + i));
	}
	return hashSum;
}

//Question 4
unsigned long q4_diameter(unsigned int n, const double *x, const double *y){
	if (n == 0)
		return 0;
	unsigned long largestDistance = 0;
	for (int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			unsigned long distance = abs(sqrt(pow(*(x+i) - *(x+j), 2) + pow(*(y+i) - *(y+j), 2)));
			if (distance > largestDistance)
				largestDistance =  distance;
		}
	}
	return largestDistance;
}

//Question 5
unsigned int q5_rotate(unsigned int n, unsigned int r, char d){
	int t, temp = 0;
	while(n / (int)pow(10, t) != 0)
		t++;
	r = r % t;
	if(d =='r'){
		temp = n % (int) pow(10, r);
		n /= pow(10,r);
		n = n + temp * pow(10,t-r);
	}
	if(d == 'l'){
		temp = n / (int) pow(10,t-r);
		n = n % (int)pow(10,r+1);
		n = n * pow(10,r) + temp;
	}
	return n;
}

//Question 6
int q6_circular_prime(unsigned int a){
	int t, temp = 0;
	while(a / (int)pow(10, t) != 0)
		t++;
	for(int i = 0; i < t; i++){
		temp = a % 10;
		a /= 10;
		a = a + temp * pow(10,t-1);
		for (int i = 2; i <= sqrt(a); i++){
			if(a % i == 0)
				return 0;
		}
	}
	return 1;
}


int main(){
	int a1 = 100;
	int* a = &a1;
	int b1 = 50;
	int* b = &b1;
	q1_swap(a, b);
	cout << *a <<" " << *b <<'\n';
	cout << q2_positive_divisors(21)<<'\n';

	char test[4] = {'T','E','S','T'};
	cout << q3_string_hash(test) << '\n';
	
	double x[5] = {0,4,6,8,30};
	double y[5] = {0,4,6,8,40};
	cout << q4_diameter(5, x, y) << '\n';
	
	cout << q5_rotate(24579, 2, 'r')<<'\n';
	
	cout << q6_circular_prime(197);
	
}
