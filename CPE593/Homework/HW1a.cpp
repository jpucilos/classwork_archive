/*
 * HW1a.cpp
 *
 *  Created on: October 7th, 2015
 *      Author: Joseph Puciloski
 *     Sources: https://turjachaudhuri.wordpress.com/2013/12/14/spoj-prime-1-segmented-sieve-of-eratosthenes/
 *				https://medium.com/@agilanbtdw/prime-number-generation-in-java-using-segmented-sieve-of-eratosthenes-187af1dcd051#.z8b28nx8x
 *				http://codeforces.com/blog/entry/3519
 *				http://www.geeksforgeeks.org/segmented-sieve/
 */


#include <iostream>
#include <cmath>
#include <vector>
#include <cstdint>
using namespace std;

/*
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
*/

uint64_t hw1a(uint64_t a, uint64_t b){
    uint64_t a_size = sqrt(b);
    int prime_count = 0;
    uint64_t primes = 0;
    //simple sieve
    vector<bool> sieve(a_size, true);
    vector<int> simple;
    sieve[0], sieve[1] = false;
    for (uint64_t i = 4; i <= a_size; i += 2)
    	sieve[i] = false;
    for (uint64_t i = 2; i <= a_size; i++){
        if (sieve[i]){ 
            if (i>=a)  
                prime_count++;
            simple.push_back(i);
            for (uint64_t j = i*i; j <= a_size; j += 2*i)
                sieve[j] = false;   //num is composite
            primes++;
        }
    }
    sieve.clear(); 
    uint64_t lo = a; 
    if (lo < a_size)
    	lo = a_size+1;
    uint64_t hi = lo+a_size;
    if (hi > b)
    	hi = b;
    while (lo < b){
    	vector<bool> seg(hi-lo+1, true);
        for (uint64_t i = 0; i < primes; i++){
            uint64_t first_mult = (lo/simple[i])*simple[i];
            if (first_mult<lo)
                first_mult+=simple[i];
            for (uint64_t j = first_mult; j <= hi; j += simple[i])
                seg[j-lo] = false; //num is composite
        }
        for (uint64_t i = lo; i <= hi; i++){
            if (seg[i-lo] && i>=a){
                prime_count++;
            }
        }
        lo += a_size+1;
        hi += a_size+1;
        if (hi >= b)
            hi = b;
    }
    return prime_count;
}

int main(){
	uint64_t a,b= 0;
	cin >> a >> b;
	cout << hw1a(a,b);
}
