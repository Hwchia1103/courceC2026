#include<stdio.h>
#include<string.h>

int main(){
	char str[1001] = "";
	fgets(str, sizeof(str), stdin);
	
	int len = strlen(str);
	
	for(int i=len-1; i>=0; i--){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			printf("%c", (str[i] - 'A' + 'a'));
		}
		else if(str[i] >= 'a' && str[i] <= 'z'){
			printf("%c", (str[i] - 'a' + 'A'));
		}
	}	
	return 0;
}
