#include<stdio.h>

int main(){
	int count[11] = {0};
	int num;
	
	while(1){
		scanf("%d", &num);
		if(num == -1) break;
		
		if(num == 100){
			count[10]++;
		}
		else{
			count[num/10]++;
		}
	}
	for(int i=0; i<=10; i++){
		char flag = 'A';
		printf("%c_%d\n", (flag+i), count[i]);
	}
	
	return 0;
}
