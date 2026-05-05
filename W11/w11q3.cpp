#include<stdio.h>
#include<math.h>
//#define my_pi 3.141;

int main(){
	int k;
	double pi = 3.141;
	scanf("%d", &k);
	
	while(k--){
		int a;
		
		scanf("%d", &a);
		
		double square = (double)a * a;
		double circle = (double)a * a * pi / 4;
		
		//double result = square - circle;
		double result = (double)a * a * (1.0 - pi/4);
		//printf("%lf %lf\n", square, circle);
		printf("%.2lf\n", round(result * 100.0) / 100.0);
	}
	
	return 0;
} 
