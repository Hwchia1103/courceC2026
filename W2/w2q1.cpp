#include<stdio.h>

int main(){
	int i, num, odd = 0, even = 0;
	for(i=0; i<10; i++){
		scanf("%d", &num);
		if((num % 2) == 0){
			even += num;
		}
		else{
			odd += num;
		}
	}
	printf("%d", odd - even);
	
	return 0;
} 
