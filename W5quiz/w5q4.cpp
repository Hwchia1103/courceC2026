#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

int main(){
	int k;
	char null;
	
	scanf("%d", &k);
	scanf("%c", &null);
	
	while(k--){

		char arr[102] = "";
		uint16_t sum = 0;

		fgets(arr, sizeof(arr), stdin);
		arr[strcspn(arr, "\n")] = '\0';
		int len = strlen(arr);

		for(int i=0; i<len; i++){
			sum += (int)arr[i];
		}
		printf("%d\n", 65535 - sum);
	}
	
	return 0;
} 
