/*
	Author: Joseph Puciloski
	cite: http://www.passionatelycurious.com/files/combinations.html
*/

#include <cstdlib>
#include <ctime>
using namespace std;

unsigned long long choose(int n, int r){

	static unsigned long long memo[400][400] = {0};

	if( r > n)
		return 0;
	if(r == 0 || n == 0)
		return 1;
	if(memo[n][r] != 0)
		return memo[n][r];

	memo[n][r] = choose(n-1,r-1) + choose(n-1,r);
	return  memo[n][r];
}



int main(){
	
	cout << choose(39, 7) <<'\n';
	srand((int)time(0));
	int i = 0;
	while(i++ < 100000000) {
		int n = (rand() % 52) + 1;
		int r = (rand() % n) + 1;
		choose(52,25);
	}
}
