#include<stdio.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		int v1, v2;
		char m;
		
		scanf("%d %d", &v1, &v2);
		scanf(" %c", &m);
		
		int i;
		int res1 = 0, res2 = 0;
		if(m == 'a'){
			for (i=1; i<=16; i++) {
    			if (i % 2 != 0) {
        			res1 <<= 1;
        			if (v1 & (1 << (16 - i))) {
            			res1 |= 1;
        			}
    			}

    			if (i % 2 == 0) {
        			res2 <<= 1;
        			if (v2 & (1 << (16 - i))) {
            			res2 |= 1;
        			}
    			}
			}
			printf("%d\n", res1&res2);
		}
		else if(m == 'b'){
			for(i=0; i<16; i++){
				if(i<8){
					res2 <<= 1;
					if(v2 & (1 << i)){
						res2 |= 1;
					}
				}
				else{
					res1 <<= 1;
					if(v1 & (1 << i)){
						res1 |= 1;
					}
				}
			}
			printf("%d", res1|res2);
		}
	}
	return 0;
}