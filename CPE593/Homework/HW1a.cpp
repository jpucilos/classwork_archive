#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>
using namespace std;


vector<uint64_t> simpleSieve(uint64_t n){
	bool primes[n] = {0};
	vector<uint64_t> prime;
	for (uint64_t i = 2; i <= n; i++){
		if (!primes[i]){
			prime.push_back(i);
			for (int j = i*2; j <= n; j+=i)
				primes[j] = true;
		}
	}
	return prime;
}


int homework1a(uint64_t a, uint64_t b){
	int result = 0;
	
	uint64_t delta = sqrt(b);
	vector<uint64_t> primeSqrt = simpleSieve(delta);
	
	uint64_t lo = a;
	uint64_t hi = a + delta;
	if (a < delta)
		lo = delta;
		hi = 2 * delta;
	
	
	while(lo < b){
	//	cout << "lo:" << lo << " hi:" << hi <<'\n';
		bool temp[delta+1] = {0};
		for(int i = 0; i < primeSqrt.size(); i++){
			uint64_t loLim = lo / primeSqrt[i];
			loLim *= primeSqrt[i];
			if(loLim < lo)
				loLim +=primeSqrt[i];
		//	cout << "LoLim: " << loLim <<'\n';
			for(uint64_t j = loLim; j <= hi; j+= primeSqrt[i]){
				temp[j-loLim] = true;
		//		cout << j << '\n';
			}
		}	
		
		for(uint64_t i = 0; i <= delta; i++)
			if(!temp[i])
				result++;
		lo+=delta;
		hi+=delta;
		if(hi>b)
			hi = b;
		//cout << "result: " << result <<'\n';
	}
	for (auto x: primeSqrt)
		if (a < x)
			result++;
			
	return result;
}

int main(){
	uint64_t a,b= 0;
	cin >> a >> b;
	cout << homework1a(a,b);
}
