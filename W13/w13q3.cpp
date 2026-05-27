#include<stdio.h>

long long gcd(long long a, long long b){
	while(b > 0){
		long long temp = b;
		b = a%b;
		a = temp;
	}
	
	return a;
}

long long lcm(long long a, long long b){
	if(a == 0 || b == 0) return 0;
	return (a / gcd(a, b)) * b;
}
int main(){
	long long num, current_lcm = 1;
	int is_first = 1;
	
	while(scanf("%lld", &num) == 1 && num != -1){
		if(is_first){
			current_lcm = num;
			is_first = 0;
		}
		else{
			current_lcm = lcm(current_lcm, num);
		}
	}
	
	if(!is_first){
		printf("%lld", current_lcm);
	}
	/*
	//printf("%d\n", lcm(12, 25));
	scanf("%lld", &a);
	if(a == -1) return 0;
	
	lcm_num = 1;
	
	while(1){
		scanf("%lld", &b);
		if(b == -1) break;
		lcm_num = lcm(a, b);
	}
	
	printf("%lld", lcm_num);
	*/
	return 0;
}
