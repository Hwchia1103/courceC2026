#include<stdio.h>
#include<math.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		int a, b;
		scanf("%d,%d", &a, &b);
		
		
		printf("%d\n", (a*b+1) / 2);
	}
	
	return 0;
}
