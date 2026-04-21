#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

int main(){
	int k;
	const char *patern[6] = {"x", "$", "%", "@", "&", "*"};
	
	scanf("%d", &k);
	int len1, len2, len3;
	
	while(k--){
		scanf("%d %d %d", &len1, &len2, &len3);
		bool flag1 = false, flag2 = false;
		//yes
		if(((len1+len2) > len3) &&
			((len1+len3) > len2) &&
			((len2+len3) > len1)){
				//triangle
				printf("$");
				
				//equilateral triangle 
				/*
				if((len1 == len2) && (len2 == len3) && (len1 == len3)){
					printf("%s", patern[2]);
				*/
				// a = b && b = c, then a = c
				if(len1 == len2 && len2 == len3){
					// in C, print % needs to write %%
					printf("%%");
				}
				
				//isosceles triangle
				/*
				if((len1 == len2) || (len2 == len3) || (len1 == len3)){
					printf("@");
					flag1 = true;
				}
				*/
				bool is_isosceles = (len1 == len2 || len2 == len3 || len3 == len1);
				if(is_isosceles){
					printf("@");
				}
				
				//right triangle
				bool is_right = ((len1*len1 + len2*len2) == len3*len3) || 
								((len2*len2 + len3*len3) == len1*len1) ||
								((len1*len1 + len3*len3) == len2*len2);
				
				if(is_right){
					printf("&");
				}
				
				//isosceles right triangle
				if(is_isosceles && is_right){
					printf("*");
				} 
		}   
		else{
			//not
			printf("x");
		}
			
		printf("\n");
	}
	
	
	
	return 0;
} 
