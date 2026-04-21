#include<stdio.h>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void permutation(int arr[], int n, int i, int j){
	for(int k=0; k<n; k++){
		printf("%d ", arr[k]);
	}
	
	swap(arr, i, j);
	permutation(arr, n, i+1, j);
	swap(arr, i, j);
}

int main(){
	int arr[] = {1,2,3};
	permutation(arr, 3, 0, 0);
	/*
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			
		}
	}
	*/
}
