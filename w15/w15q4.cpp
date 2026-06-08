#include<stdio.h>
#include<math.h>

#define pi 3.141

int main(){
	int r1, r2;
		
	while(scanf("%d", &r1) == 1 && r1 != -1){
		scanf(",%d", &r2);
		
		double x2 = sqrt((double)r1 * r1 + 2 * r1 * r2);
		
		double base = r1 + x2 + r2;
        double height = r2;
            
        double area = 0.5 * base * height;
		//double result = (double)(r1 * r1 * pi);
		printf("%.2lf\n", round(area * 100.0) / 100.0);
	}
	
	return 0;
} 
