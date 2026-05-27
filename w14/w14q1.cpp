#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int i;
	int a[50] = {0};

	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	/*
	int b[50] = {0};
	int is_first = 1;
	for(i=0; i<n; i++){
		int left = (i - 1 + n) % n;
		int right = (i + 1) % n;
		b[i] = a[left] ^ a[right];
	}
	for(i=0; i<n; i++){
		if(i == n-1){
			printf("%d", b[i]);
		}
		else{
			printf("%d ", b[i]);
		}
		
	}
	*/
	/*
	int result;
	for(int i=0; i<n; i++){
		if(i == 0){
			result = a[n-1] ^ a[i+1];
		}
		else if(i == n-1){
			result = a[i-1] ^ a[0];
		}
		else{
			result = a[i-1] ^ a[i+1];
		}
		
		if(i == n-1){
			printf("%d", result);
		}
		else{
			printf("%d ", result);
		}
	}
	*/
	int result;
	for(int i=0; i<n; i++){
		int left = (i - 1 + n) % n;
		int right = (i + 1) % n;
		result = a[left] ^ a[right];
		
		if(i == n-1){
			printf("%d", result);
		}
		else{
			printf("%d ", result);
		}
	}
	return 0;
} 
