#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<math.h>

int main(){
	uint32_t a, b;
	
	while((scanf("%d,%d", &a, &b) != EOF) && (a != -1)){
		double len_b, len_a, len_c, sqr_c;
		
		len_a = round(sqrt(a / 4.0) * 100.0) / 100.0;
		//len_b = round(sqrt(b) * 100.0) / 100.0;
		sqr_c = b - (a/4.0);
		len_c = round(sqrt(b - a/4.0) * 100.0) / 100.0;
		
		double res = len_a * len_c;
		//printf("%lf $lf %lf\n", len_a, len_b, len_c);
		printf("%0.2lf\n", round((len_c * len_a / 2) * 100.0) / 100.0);
	}
	
	return 0;
} 
