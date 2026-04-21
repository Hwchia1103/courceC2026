#include<stdio.h>
#include<math.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		double num;
		scanf("%lf", &num);

		double result = (num * num) / 2; 
		printf("%.2lf\n", round(result * 100.0) / 100.0);
	}
	return 0;
}
