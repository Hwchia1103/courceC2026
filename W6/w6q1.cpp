#include<stdio.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		int x, y;
		scanf("%d,%d", &x, &y);
		
		if((x == 0) && (y == 0)){
			printf("0\n");
		}
		else if((x > 0) && (y > 0)){
			printf("1\n");
		}
		else if((x < 0) && (y > 0)){
			printf("2\n");
		}
		else if((x < 0) && (y < 0)){
			printf("3\n");
		}
		else if((x > 0) && (y < 0)){
			printf("4\n");
		}
		else if(y == 0){
			printf("5\n");
		}
		else if(x == 0){
			printf("6\n");
		}
	}
	
	return 0;
} 
