#include<stdio.h>

int main(){
	int win_num[6], special;

	scanf("%d %d %d %d %d %d %d", &win_num[0], &win_num[1], &win_num[2], &win_num[3], &win_num[4], &win_num[5], special);

	int n;
	scanf("%d", &n);

	long long total_prize = 0;

	for(int i=0; i<n; i++){
		int ticket[6];
		int match_count = 0;
		int special_match = 0;

		for(int j=0; j<6; j++){
			scanf("%d", &ticket[j]);

			if(ticket[j] == special){
				special_match = 1;
			}

			for(int k=0; k<6; k++){
				if(ticket[j] == win_num[k]){
					match_count++;
					break;
				}
			}
		}

		if(match_count == 6) total_prize += 1000000;
		else if (match_count == 5 && special_match) total_prize += 100000;
        else if (match_count == 5) total_prize += 10000;
        else if (match_count == 4) total_prize += 1000;
        else if (match_count == 3) total_prize += 100;
	}

	if(total_prize > 0){
		printf("%lld\n", total_prize);
	}
	else{
		printf("null\n");
	}

	return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>
#include<float.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int main(){
	int num[6] = {0}, special;
	for(int i=0; i<6; i++){
		scanf("%d", &num[i]);
	}
	qsort(num, 6, sizeof(int), cmp);
	scanf("%d", &special);

	int n, sum = 0;

	scanf("%d", &n);
	while(n--){
		int input[6] = {0}, count = 0, count_special = 0;
		for(int i=0; i<6; i++){
			scanf("%d", &input[i]);
		}

		qsort(input, 6, sizeof(int), cmp);

		for(int i=0; i<6; i++){
			for(int j=0; j<6; j++){
				if(num[i] == input[j]){
					count++;
				}
				if(input[i] == special){
					count_special = 1;
				}
			}
		}
		if(count == 6){
			sum += 1000000;
		}
		else if(count == 5 && count_special == 1){
			sum += 100000;
		}
		else if(count == 5){
			sum += 10000;
		}
		else if(count == 4)sum += 1000;
		else if(count == 3)sum += 100;

	}
	if(sum){
		printf("%d", sum);
	}
	else printf("null");


	return 0;
}
*/