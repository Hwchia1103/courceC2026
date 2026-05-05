#include<stdio.h>
#include<string.h>

void read_matrix(int mat[25][25], int *rows, int *cols){
	char line[2000];
	
	if(!fgets(line, sizeof(line), stdin)) return;
	
	*rows = 0;
	*cols = 0;
	int i = 0, current_c = 0, num = 0, sign = 1, has_num = 0;
	while(line[i] != '\0'){
		if(line[i] == '}'){
			if(has_num){
				mat[*rows][current_c++] = sign * num;
				has_num = 0;
				num = 0;
				sign = 1;
			}
			if(current_c > 0){
				*cols = current_c;
				(*rows)++;
				current_c = 0;
			}
		}
		else if(line[i] == ','){
			if(has_num){
				mat[*rows][current_c++] = sign * num;
				has_num = 0;
				num = 0;
				sign = 1;
			}
		}
		else if(line[i] == '-'){
			sign = -1;
		}
		else if(line[i] >= '0' && line[i] <= '9'){
			has_num = 1;
			num = num * 10 + line[i] - '0';
		}
		i++;
	}	
}

int main(){
	int a[25][25], b[25][25], c[25][25];
	int m, n_a, n_b, p;
	read_matrix(a, &m, &n_a);
	read_matrix(b, &n_b, &p);
	
	if(n_a != n_b) return 0;
	
	for(int i=0; i<m; i++){
		for(int j=0; j<p; j++){
			c[i][j] = 0;
			for(int k=0; k<n_a; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	printf("{");
	for(int i=0; i<m; i++){
		printf("{");
		for(int j=0; j<p; j++){
			printf("%d", c[i][j]);
			if(j<p-1) printf(",");
		}
		printf("}");
		if(i<m-1) printf(",");
	}
	printf("}");
	
	return 0;
} 
