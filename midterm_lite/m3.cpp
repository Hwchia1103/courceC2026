#include<stdio.h>
#include<math.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		int l, w;
		scanf("%d %d", &l, &w);
		
		// (r-L)^2 + (r-W)^2 = r^2
		// r = (L+W) +- sqrt(2*L*W)	
		//according to the graph, r should large than L and W
		// r = (L+W) + sqrt(2*L*W)
		double r = (double)((l+w) + sqrt(2*l*w));
		double result = round(r *100.0) / 100.0;
		printf("%.2lf\n", result);
	}
	return 0;
}