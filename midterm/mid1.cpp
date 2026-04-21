#include<stdio.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		unsigned int v1, v2;
		char m;
		
		scanf("%d %d", &v1, &v2);
		scanf(" %c", &m);
		
		int c1 = 0, c2 = 0;
		int i;
		
		if(m == 'a'){
			for (i=1; i<=16; i++) {
    			if (i % 2 != 0) {
        			c1 <<= 1;
        			if (v1 & (1 << (16 - i))) {
            			c1 |= 1;
        			}
    			}

    			if (i % 2 == 0) {
        			c2 <<= 1;
        			if (v2 & (1 << (16 - i))) {
            			c2 |= 1;
        			}
    			}
			}
			printf("%d\n", c1|c2);
		}
		else if(m == 'b'){
			for (i=1; i<=16; i++) {
    			if (i % 2 == 0) {
        			c1 <<= 1;
        			if (v1 & (1 << (16 - i))) {
            			c1 |= 1;
        			}
    			}

    			if (i % 2 != 0) {
        			c2 <<= 1;
        			if (v2 & (1 << (16 - i))) {
            			c2 |= 1;
        			}
    			}
			}
			printf("%d\n", c1^c2);
		}
		else if(m == 'c'){
			for (i=1; i<=16; i++) {
    			if (i % 2 != 0) {
        			c1 <<= 1;
        			if ((v1 & (1 << (16 - i))) == 0) {
            			c1 |= 1;
        			}
    			}

    			if (i % 2 != 0) {
        			c2 <<= 1;
        			if (v2 & (1 << (16 - i))) {
            			c2 |= 1;
        			}
    			}
			}
			printf("%d\n", c1&c2);
		}
		else if(m == 'd'){
			for(i=8; i<16; i++){
					c2 <<= 1;
					if(v2 & (1 << i)){
						c2 |= 1;
					}

					c1 <<= 1;
					if(v1 & (1 << i)){
						c1 |= 1;
					}
			}
			for(i=0; i<8; i++){
					c2 <<= 1;
					if(v2 & (1 << i)){
						c2 |= 1;
					}

					c1 <<= 1;
					if(v1 & (1 << i)){
						c1 |= 1;
					}
			}
			//printf("%d %d\n", c1, c2);
			int result = c1 + c2;
			//printf("%d\n", result);
			/*
			for(i=15; i>=0; i--){
				if(result & (1 << i)){
					printf("1");
				}
				else{
					printf("0");
				}
			}
			printf("\n");
			*/
			int low = 0, high = 0;
			for(i=15; i>=0; i--){
				if(i<8){
					low <<= 1;
					if(result & (1 << i)){
						low |= 1;
					}
				}
				else{
					high <<= 1;
					if(result & (1 << i)){
						high |= 1;
					}
				}
			}
			printf("%d\n", high^low);
		}
	}
	return 0;
} 
