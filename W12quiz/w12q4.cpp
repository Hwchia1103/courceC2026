#include<stdio.h>
#include<stdint.h>

int main(){
	int k;
	scanf("%d", &k);

	for(int i=0; i<k; i++){
		float f;
		scanf("%f", &f);

		uint32_t bits = *(uint32_t *)&f;

		uint32_t exponent = (bits >> 23) & 0xFF;

		uint32_t mantissa = bits & 0x7FFFFF;

		// 以 16 進位大寫格式印出
		printf("%X %X\n", exponent, mantissa);
	}

	return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>
#include<float.h>

int main(){
	int k;
	scanf("%d", &k);

	while(k--){
		float num;
		scanf("%f", &num);

		uint32_t *ptr = (uint32_t *) &num;

		int first = 1;
		for(int i=0; i<4; i++){
			printf("%hd", ptr[i]);
			if(first){
				printf(" ");
				first = 0;
			}
		}
	}

	return 0;
}
*/