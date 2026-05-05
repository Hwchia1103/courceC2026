#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<math.h>

bool is_prime(long long n){
	if(n <= 1) return false;
	if(n <= 3) return true;
	
	if((n%2 == 0) || (n%3) == 0) return false;
	for(long long i=5; i*i<=n; i+=6){
		if((n%i == 0) || (n%(i+2) == 0)) return false;
	}
	return true;
}
int main(){
	unsigned long long k;
	while(1){
		scanf("%llu", &k);
		if(k == -1) break;
		bool is_prime_num = is_prime(k);
		
		if(is_prime_num) printf("%llu\n", k);
		else printf("Not a prime number\n");
		
		
	}
	
	return 0;
} 
