#include<stdio.h>
#include<stdbool.h>

const int month[12] = {3, -1, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
const int q_month[12] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};

void swap(int arr[], int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

int permutation(int arr[], int n, int i, int j){
	int possible = 0;
	int res_normal = arr[0];
	int res_q = arr[0];
	
	for(int k=0; k<n-1; k++){
		res_normal = ((res_normal + month[k]) % 7);
		res_q = ((res_q + month[k]) % 7);
	}
	if(res_normal == arr[11] || res_q == arr[11]){
		possible = 1;
		return possible;	
	}
	else{
		possible = 0;
		return possible;	
	} 
		
	swap(arr, i, j);
	permutation(arr, n, i+1, j);
	swap(arr, i, j);

	
	
}
int main(){
	//const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	//const int q_month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	//const int month[12] = {4, 0, 4, 3, 4, 3, 4, 4, 3, 4, 3, 4};
	//const int q_month[12] = {4, 1, 4, 3, 4, 3, 4, 4, 3, 4, 3, 4};
	
	

	int num[12];
	int possible = false;
	
	for(int i=0; i<12; i++){
		scanf("%d", &num[i]);
	}
	
	//normal
	for(int i=0; i<12; i++){
		for(int j=0; j<12; j++){
			possible = permutation(num, 12, i, j);
			if(possible)break;
		}
		if(possible)break;
	}
	//q
	if(!possible){
		
	}
	//print
	if(possible){
		for(int i=0; i<11; i++){
			printf("%d ", num[i]);
		}
		printf("%d", num[11]);
	}
	else{
		printf("impossible\n");
	}
	return 0;
}
