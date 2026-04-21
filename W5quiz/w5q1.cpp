#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<math.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
	int k;
	char null;
	
	scanf("%d", &k);
	
	while(k--){
		int m, z;
		scanf("%d", &m);
		int num[m], ans[5];
		
		for(int i=0; i<m; i++){
			scanf("%c", &null);
			scanf("%d", &num[i]);

		}

		qsort(num, m, sizeof(int), cmp);
		
		for(int j=0; j<5; j++){
			ans[j] = num[m-1-j];
		}
		
		for(z=4; z>0; z--){
			printf("%d ", ans[z]);
		}
		printf("%d\n", ans[z]);
	}
	
	return 0;
} 
