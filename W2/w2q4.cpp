#include<stdio.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		char s;
		int m, n;
		
		scanf(" %c", &s);
		scanf("%d %d", &m, &n);
		
		if(m == 1){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=i; j++){
					printf("%c", s);
				}
				printf("\n");
			}
		}
		else if(m == 2){
			for(int i=n; i>0; i--){
				for(int j=i; j>0; j--){
					printf("%c", s);
				}
				printf("\n");
			}
		}
	}
	
	return 0;
}
