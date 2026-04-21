#include<stdio.h>
#include<stdint.h>

int main(){
	int k;
	scanf("%d", &k);
	
	int32_t max_palindrome = -1;
	
	while(k--){
		int32_t num;
		scanf("%d", &num);
		
		int32_t temp = num;
		int32_t reversed_num = 0;
		
		while(temp > 0){
			reversed_num = reversed_num * 10 + (temp%10);
			temp /= 10;
		}
		
		if(num == 0 || num == reversed_num){
			if(num > max_palindrome){
				max_palindrome = num;
			}
		}
	}
	
	if(max_palindrome == -1){
		printf("ERROR");
	}
	else{
		printf("%d", max_palindrome);
	}
	
	return 0;
}
