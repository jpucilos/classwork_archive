#include<iostream>
using namespace std;



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


int main(){
	cout << q2_positive_divisors(21)<<'\n';
	cout << q2_positive_divisors(4)<<'\n';
	cout << q2_positive_divisors(103456)<<'\n';
	cout << q2_positive_divisors(234889)<<'\n';
	
}