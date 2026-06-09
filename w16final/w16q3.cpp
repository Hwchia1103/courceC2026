#include<stdio.h>

int main(){
	int x, y, z;
	while(scanf("%d %d %d", &x, &y, &z) == 3 && (x > 0) && (y > 1) && (z > 0)){
		int mask_count = z / x;
		int money_remain = z - x * mask_count;
		int dot_remain = mask_count;
		
		//printf("%d %d %d\n", mask_count, money_remain, dot_remain);
		
		while(dot_remain >= y){
			int dot_plus = dot_remain / y;
			mask_count += dot_plus;
			
			dot_remain %= y;
			
			dot_remain += dot_plus;
		}
		
		printf("%d %d %d\n", mask_count, money_remain, dot_remain);
	}
	
	return 0;
} 
