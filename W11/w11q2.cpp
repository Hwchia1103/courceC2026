#include<stdio.h>
/*
int factor(int a){
	int is_first = 1; // control trailing space
	
	if(a <= 1) return 0;
	
	if(a == 2){
		printf("2 ");
		a /= 2;
		return 0;
	}
	if(a == 3){
		printf("3 ");
		a /= 3;
		return 0;
	}
	
	while(!(a%2)){
		if(!is_first)printf(" ");
		printf("2");
		is_first = 0;
		a /= 2;
	}
	while(!(a%3)){
		if(!is_first)printf(" ");
		printf("3");
		is_first = 0;
		a /= 3;
	}
	
	for(int i=5; i<=a; i+=2){
		
		if(!(a%i)){
			printf("%d ", i);
			a /= i;
		}
		
	}
	return a;
}
*/
void factor(int a){
	int is_first = 1; // control trailing space
	
	if(a <= 1) return;
	/*
	if(a == 2){
		printf("2 ");
		a /= 2;
		return 0;
	}
	if(a == 3){
		printf("3 ");
		a /= 3;
		return 0;
	}
	*/
	while(!(a%2)){
		if(!is_first)printf(" ");
		printf("2");
		is_first = 0;
		a /= 2;
	}
	while(!(a%3)){
		if(!is_first)printf(" ");
		printf("3");
		is_first = 0;
		a /= 3;
	}
	
	for(int i=5; i<=a; i+=2){
		/*
		if(!(a%i)){
			printf("%d ", i);
			a /= i;
		}
		*/
		while(!(a%i)){
			if(!is_first)printf(" ");
			printf("%d", i);
			is_first = 0;
			a /= i;
		}
	}
	//return a;
}
int main(){
	int k;
	
	scanf("%d", &k);
	
	while(k--){
		int m;
		
		scanf("%d", &m);
		
		factor(m);
		printf("\n");
	}
	
	return 0;
} 
