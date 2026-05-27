#include<stdio.h>

int main(){
	int m, n;
	scanf("%d,%d", &m, &n);
	
	int matrix[100][100] = {0};
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	int last = 1;
	for(int j=0; j<n; j++){
		for(int i=0; i<m; i++){
			if(i == n-1 && m == m-1)last = 0;
			printf("%d", matrix[i][j]);
			if(last)printf(" ");
		}
	}
	
	//printf("\n%d", matrix[m-1][n-1]);
	return 0;
}
