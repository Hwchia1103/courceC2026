#include<stdio.h>
#include<stdbool.h>

int gcd(int a, int b){
	while(b != 0){
		int temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
int main(){
	int num;
	if(scanf("%d", &num) != 1 || num == -1) return 0;
	int result = num;
	while(scanf("%d", &num) != EOF && num != -1){
		result = gcd(result, num);
	}
	
	printf("%d", result);
	return 0;
} 
