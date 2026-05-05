#include<stdio.h>

int main(){
	int fib[45];
	fib[0] = 0;
	fib[1] = 1;
	
	int fib_size = 2;
	while(1){
		fib[fib_size] = fib[fib_size-1] + fib[fib_size-2];
		if(fib[fib_size] > 100000000){
			fib_size++;
			break;
		}
		fib_size++;
	}
	/*
	for(int i=2; i<45; i++){
		fib[i] = fib[i-1] + fib[i-2];
		
		if(fib[i] > 100000000){
			i++;
			break;
		}
	}
	*/
	int m, n;
	while(scanf("%d", &m) == 1 && m != -1){
		scanf("%d", &n);
		int found = 0;
		int is_first = 1;
		
		for(int i=1; i<fib_size; i++){
			if(fib[i] >= m && fib[i] <= n){
				if(!is_first)printf(" ");
				printf("%d", fib[i]);
				is_first = 0;
				found = 1;
			}
		}
		
		if(!found)printf("null");
		printf("\n");
	}

	return 0;
} 
