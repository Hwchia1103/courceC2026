#include<stdio.h>
#include<stdbool.h>

int main(){
	int n;
	scanf("%d", &n);
	
	int region;
	if(n == 0){
		printf("1");
	}else{
		printf("%d", n*n - n + 2);
	}
	
	
	return 0;
} 
