#include<stdio.h>
#include<math.h>

#define pi 3.14

int main(){
	int p, d;
	while(scanf("%d", &p) == 1 && p != -1){
		scanf("%d", &d); 
		//double x = (double)
		
		double r = (double)p + d - p * p / 2.0;


		double w = sqrt(pow(p - d, 2) - 2.0 * p * d);
		double result = w * w * pi;
		printf("%.1lf\n", round(result * 10.0) / 10.0);
	}
	
	return 0;
} 
