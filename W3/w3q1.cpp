#include<stdio.h>
#include<string.h>

int main(){
	char num[10] = "";
	
	
	while(1){
		scanf("%s", num);
		if(strcmp(num, "-1") == 0) break;
		
		int count = strlen(num);
		bool flag = true;
		
		for(int i=0; i<count/2; i++){
			if(num[i] != num[count-1-i]){
				flag = false;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
} 
