#include<stdio.h>
#include<math.h>

int main(){
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	
	//int D = b*b - 4*a*c;
	double D = (double)b *b - 4.0 * a * c;
	
	if(D > 0){

		//int sq = (int)(sqrt(D) + 0.5);
		int sq = (int)(round((sqrt(D) * 100.0) / 100.0));
		//int sq = (int)sqrt(D);
		
		int x1 = (-b + sq) / (2*a);
		int x2 = (-b - sq) / (2*a);
		if(x1 < x2){
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}
		printf("Two different roots x1=%d, x2=%d", x1, x2);		
	}
	else if(D == 0){
		int root = -b / (2*a);
		printf("Two same roots x=%d", root);
	}
	else{
		printf("No real root");	
	}
	
	return 0;
}
