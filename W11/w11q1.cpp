#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
	int num1 = *(const int *)a;
	int num2 = *(const int *)b;
	
	int d2_1 = num1 / 100, d1_1 = (num1/10) % 10, d0_1 = num1 % 10;
	int d2_2 = num2 / 100, d1_2 = (num2/10) % 10, d0_2 = num2 % 10;
	
	if(d2_1 != d2_2){
		return d2_1 - d2_2;
	} 
	
	if(d1_1 != d1_2){
		return d1_2 - d1_1;
	}
	
	int even1 = (d0_1 % 2 == 0);
	int even2 = (d0_2 % 2 == 0);
	
	if(even1 != even2){
		return even2 - even1;
	}
	
	return d0_1 - d0_2;
}
/*
void radix_sort(int a[], int k){
	int count = 0;
	int b[k] = {0};
	for(int i=0; i<k; i++){
		if(a[i] )
	}
}
*/
int main(){
	int k;
	scanf("%d", &k);
	
	int num[k] = {0};
	for(int i=0; i<k; i++){
		scanf("%d", &num[i]);
		//char c;
		int c;
		while((c = getchar()) != EOF){
			if(c == ',' || c == ' ')continue;
			//if(c == ',' || c == ' ' || c == '\n')continue;
			ungetc(c, stdin);
			break;
		}
	}
	qsort(num, k, sizeof(int), cmp);
	
	for(int i=0; i<k; i++){
		printf("%d", num[i]);
		if(i<k-1)printf(",");
	}
	//printf("\n");
	//radix_sort(num, k);
	
	return 0;
} 
