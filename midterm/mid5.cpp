#include<stdio.h>
#include<math.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		int l, w;
		scanf("%d %d", &l, &w);
		
		double r = (double)(l + w + sqrt(2*l*w));
		r = round(r * 100.0) / 100.0;
		printf("%.2lf\n", r);
	} 
	return 0;
}
