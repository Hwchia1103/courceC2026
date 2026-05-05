#include<stdio.h>
#include<stdbool.h>

bool isPrime(int n){
	if(n <= 1)return false;
	if(n == 2 || n == 3)return true;
	
	if(n%2 == 0 || n%3 == 0)return false;
	
	for(int i=5; i*i<n; i+=2){
		if(n%i == 0 || n % (i+2) == 0){
			return false;
		}
	}
	return true;
}

bool get_closest_prime(int sum, int *p1, int *p2){
	for(int i=sum/2; i>=2; i--){
		if(isPrime(i) && isPrime(sum - i)){
			*p1 = i;
			*p2 = sum - i;
			return true;		
		}
	}
	return false;
}

void solve(int n){
	if(isPrime(n)){
		printf("1 %d\n", n);
		return;
	}
	
	if(n%2 == 0){
		int p1, p2;
		get_closest_prime(n, &p1, &p2);
		printf("2 %d %d\n", p1, p2);
		return;
	}
	
	if(isPrime(n-2)){
		printf("2 2 %d\n", n-2);
		return;
	}
	
	long long max_prod = -1;
	int best_p1 = 0, best_p2 = 0, best_p3 = 0;
	for(int p1=n/3; p1>=2; p1--){
		if(isPrime(p1))continue;
		int rem_half = (n-p1) / 2;
		long long theoretical_max = (long long)p1 * rem_half * rem_half;
		if(theoretical_max < max_prod)break;
		
		int p2, p3;
		if(get_closest_prime(n-p1, &p2, &p3)){
			long long prod = (long long)p1 * p2 * p3;
			if(prod > max_prod){
				max_prod = prod;
				best_p1 = p1;
				best_p2 = p2;
				best_p3 = p3;

			}
		}
	}
	int arr[3] = {best_p1, best_p2, best_p3};
	for(int i=0; i<2; i++){
		for(int j=0; j<2-i; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	printf("3 %d %d %d\n", arr[0], arr[1], arr[2]);
}
int main(){
	int n;
	
	scanf("%d", &n);
	solve(n);
	
	
	return 0;
} 
