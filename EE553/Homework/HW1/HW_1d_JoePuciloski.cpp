/*
do this as float and as double
sum1= 1/1 + 1/2 + ... + 1/100
sum2= 1/100 + 1/99 + .... + 1/1
print out sum1
print out sum2
print out sum1 - sum2
You should see that the two sums are not quite equal, which leads to the question, which is more correct?
We will review that in class.
*/

#include<iostream>
using namespace std;

int main(){
	float sum1 = 0.0;
	for (float i = 1.0; i <= 100.0; i++){
		sum1 = sum1 + (1.0 / i);
	}
	double sum2 = 0.0;
	for (double i = 1.0; i <= 100.0; i++){
		sum2 = sum2 + (1.0 / i);
	}
	cout << "Float : " << sum1 << endl;
	cout << "Double: " << sum2 << endl;
	cout << "Double - Float: " << sum2 - sum1 << endl;
	return 0;
}
