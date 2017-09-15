/*
Complete the program given out in class to convert numbers to strings.  In order to do this you will have to pull digits off the number.  
Remember that for an integer n:
n % 10 would be the last digit.  To turn that digit into a character you will need:
char x = n % 10 + '0';
This will result in '0', '1', '2', etc.  Your job is to build a string equivalent to your number and print it out.
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
	int n;
	cout << "Enter a number to convert to a string: " << endl;
	cin >> n;
	string str = "";
	if (n == 0){
		str = "0";
	}
	else{
		while (n > 0){
			char x = n % 10 + '0';
			str.insert(str.begin(), x);
			n = n / 10;
		}
	}
	cout << "Here it is as a string (trust me it's a string I promise): " << endl;
	cout << str << '\n';
	return 0;
}
