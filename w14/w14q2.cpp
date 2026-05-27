#include<stdio.h>
#include<string.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		long long num;
		scanf("%lld", &num);
		
		if((num / 1000 > 0) && (num / 1000 <= 9)){
			int count[10]  = {0};
			long long temp = num;
			while(temp){
				count[temp%10]++;
				temp /= 10;
			}
			int flag = 0;
			for(int i=0; i<10; i++){
				//printf("count %d : %d\n", i, count[i]);
				if(count[i] == 2){
					flag++;
				}
			}
			if(flag == 1){
				printf("Good Number\n");
			}
			else{
				printf("Wrong Number\n");
			}
		}
		else{
			printf("Failure Input\n");
		}
		/*
		char num[50];
		scanf("%s", num);
		
		if(strlen(num) == 4 && str[0] != '0'){
			int count[10] = {0};
			
			for(int i=0; i<4; i++){
				count[num[i] - '0']++;
			}
			
			int flag = 0;
			for(int i=0; i<10; i++){
				if(count[i] == 2){
					flag++;
				}
			}
			
			if(flag == 1){
				printf("Good Number\n");
			}
			else{
				printf("Wrong Number\n");
		}
		else{
			printf("Failure Input\n");
		}
		*/
		
	}
	
	return 0;
} 
