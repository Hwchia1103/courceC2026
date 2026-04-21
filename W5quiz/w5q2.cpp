#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

int main(){
	int m, n;
	int change[7] = {1000, 500, 100, 50, 10, 5, 1};
	const char *pattern[7] = {"$", "#", "%", "+", "!", "^", "*"};

	scanf("%d %d", &m, &n);
	
	if(m>n){
		printf("Fail");
		return 0;
	}
	/*
	else{
		int i=0;
		int coin = n-m ;
		int temp = coin;
		
		while(temp>0){
			while(temp >= change[i]){
				printf("%s", pattern[i]);
				temp -= change[i];
			}
			i++;
		}
	}
	*/
	int remaining = n - m;
	for(int i=0; i<7; i++){
		int count = remaining / change[i];
		
		for(int j=0; j<count; j++){
			printf("%s", pattern[i]);
		}
		
		remaining %= change[i];
		
		if(remaining == 0) break;
	}
	
	// printf("\n");
	return 0;
} 
