#include<stdio.h>
#include<stdint.h>

int main(){
	int m;
	uint32_t input;
	
	scanf("%d", &m);
	while(m--){
		scanf("%x", &input);
		
		for(int i=0; i<32; i++){
			if(input & 0x80000000){
				printf("1");
			}
			else{
				printf("0");
			}
			if(!((i+1) % 4)){
				printf(" ");
			}
			input <<= 0x01;
		}
		printf("\n");
	}
	
	return 0;
}
