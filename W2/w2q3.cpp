#include<stdio.h>

int main(){
	int k;
	scanf("%d", &k);
	while(k--){
		int m, n;
		char c;
		scanf("%d %d", &m, &n);
		scanf(" %c", &c);
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				printf("%c", c);
			}
			printf("\n");
		}
	}
	return 0;
}
