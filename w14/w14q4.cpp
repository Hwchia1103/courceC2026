#include<stdio.h>
#include<math.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		int a, b;
		scanf("%d,%d", &a, &b);
		
		int aa = b - a;
		double x = (double)a / sqrt(aa);
		printf("%.2lf\n", round(x * x * 100.0) / 100.0);
	}
	
	return 0;
} 
