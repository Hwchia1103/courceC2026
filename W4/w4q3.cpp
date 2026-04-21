#include<stdio.h>
#include<string.h>

int main(){
	char str[1001] = "";
	int cnt[4];
	
	for(int  i=0; i<4; i++){
		cnt[i] = 0;
	}
	
	fgets(str, sizeof(str), stdin);
	
	str[strcspn(str, "\n")] = '\0';
	int len = strlen(str);
	for(int i=0; i<len; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){
			cnt[0]++;
		}
		else if(str[i] >= 'a' && str[i] <= 'z'){
			cnt[1]++;
		}
		else if(str[i] >= '0' && str[i] <= '9'){
			cnt[2]++;
		}
		else{
			cnt[3]++;
		}
	}
	
	for(int i=0; i<4; i++){
		printf("%d\n", cnt[i]);
	}
	
	return 0;
}
