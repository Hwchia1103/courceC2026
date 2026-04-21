#include<stdio.h>
#include<string.h>
	
int main(){
	char num[12] = "";

	while(1){
		scanf("%s", num);
		if(strcmp(num, "-1") == 0){
			break;
		}
		
		if(strcmp(num, "0") == 0){
			printf("0\n");
			continue;
		}
		
		int len = strlen(num);
		int end = len -1;
		
		while(end >= 0 && num[end] == '0'){
			end--;
		}
		
		for(int i=end; i>=0; i--){
			printf("%c", num[i]);
		}
		printf("\n");
	}
	return 0;	
}
/*
int main(){
	
	long long int n, div = 1000000000;
	
	while(scanf("%lld", &n) && n != -1){
		long long int reversed = 0;
				
		if(n == 0){
			reversed = 0;
		}
		else{
			while(n > 0){
				reversed = (reversed * 10) + (n % 10);
				n /= 10;
			}
			
		}
		printf("%lld\n", reversed);
	}
	return 0;
}
*/
