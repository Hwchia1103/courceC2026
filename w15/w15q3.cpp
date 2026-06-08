#include<stdio.h>
#include<math.h>

#define pi 3.141

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		int l, d;
		scanf("%d %d", &l, &d);
		double W = d + sqrt(d * d - pow(l - d, 2));
		//double result = (double)(r2 * r2 * pi) / 2.0;
		printf("%.2lf\n", round(W * 100.0) / 100.0);
	}
	
	return 0;
} 
