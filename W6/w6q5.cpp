#include<stdio.h>
#include<math.h>
int main(){
	int T, n;
	double sum = 0.0;

	scanf("%d %d", &T, &n);
	
	int arr[T] = {0};
	for(int i=0; i<T;i++){
		scanf("%d", &arr[i]);
		if(i < (n-1)){
			printf("-1\n");
		}
		else if(i == (n-1)){
			for(int j=0; j<n; j++){
				sum += arr[j];
			}
			double result = (double)sum / n;
			printf("%.2lf\n", round(result * 100.0) / 100.0);
		}
		else{
			sum = sum + arr[i] - arr[i-n];
			double result = (double)sum / n;
			printf("%.2lf\n", round(result * 100.0) / 100.0);		
		}
	}
	
	return 0;
}
/*
int main(){
	int T, n;
	scanf("%d %d", &T, &n);
	
	int arr[T] = {0};
	for(int i=0; i<T;i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=1; i<n; i++){
		printf("-1\n");
	}

	int loop = 0;
	for(int i=n; i<=T; i++){
		//printf("a\n");
		double sum = 0.0;
		for(int j=0; j<n; j++){
			sum += (double)arr[j+loop];
		}
		double result = (double)sum / n;
		printf("%.2lf\n", round(result * 100.0) / 100.0);
		loop++;
	}
	
	//time complexit = O(T)
	double sum = 0.0;
	for(int i=0; i<n; i++){
		sum += arr[i];
	}
	double result = (double)sum / n;
	printf("%.2lf\n", round(result * 100.0) / 100.0);
	
	for(int i=n; i<T;i++){
		sum = sum + arr[i] - arr[i-n];
		result = (double)sum / n;
		printf("%.2lf\n", round(result * 100.0) / 100.0);
	}
	return 0;
}
*/
