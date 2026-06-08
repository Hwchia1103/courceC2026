#include<stdio.h>
#include<string.h>

int main(){
	char line[10001];
	while(scanf("%s", line) == 1 && strcmp(line, "-1")){
		int flag = 1;
		int len = strlen(line);
		for(int i=0; i<len/2; i++){
			if(line[i] != line[len-1-i]){
				printf("NO\n");
				flag = 0;
				break;
			}	
		}
		if(flag) printf("YES\n");
	}	
	
	return 0;
} 
