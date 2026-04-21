#include<stdio.h>
#include<math.h>

int main(){
	int k;
	scanf("%d", &k);
	
	int num;
	int score[101] = {0};
	int max = 0;
	for(int i=0; i<k; i++){
		scanf("%d", &num);
		score[num]++;
		if(score[num] > max){
			max = score[num];
		}
	}
	//printf("%d\n", max);
	int sum = 0, count = 0;
	for(int i=0; i<101; i++){
		if(score[i] == max){
			sum += (i * max);
			count += max;
		}
	}
	//printf("%d %d\n", sum, count);
	double result = (double)sum / count;
	result = round(result * 10.0) / 10.0;
	printf("%.1lf", result);
	
	return 0;
}
