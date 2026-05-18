#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b){
	long long arg1 = *(const long long *)a;
	long long arg2 = *(const long long *)b;

	if(arg1 < arg2) return -1;
	if(arg1 > arg2) return 1;

	return 0;
}

int main(){
	long long arr[105];
	int n = 0;

	while(scanf("lld", &arr[n]) == 1){
		n++;
	}

	if(n == 0) return 0;

	qsort(arr, n, sizeof(long long), cmp);

	int found = 0;
	for(int i=0; i<n; i++){
		int is_unique = 1;

		if(i > 0 && arr[i] == arr[i-1]) is_unique = 0;
		if(i < n-1 && arr[i] == arr[i+1]) is_unique = 0;

		if(is_unique){
			if(found) printf(" ");
			printf("%lld", arr[i]);
			found = 1;
		}
	}

	if(!found){
		printf("null\n");
	}
	else{
		printf("\n");
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

typedef struct{
	long long num;
	long long count;
}NumCount;



int compare(const void *a, const void *b) {
    NumCount *nc1 = (NumCount *)a;
    NumCount *nc2 = (NumCount *)b;

    if (nc1->count != nc2->count) {
        return nc1->count - nc2->count;
    }
    return nc1->num - nc2->num;
}



int main(){
	long long num;
	int input_cnt = 0, real_num = 0;
	NumCount input[100] = {0};

	while(scanf("%lld", &num) && num != EOF){
		int flag = 0;
		input_cnt++;

		if(input_cnt == 1){
				input[0].num = num;
				input[0].count = 1;
				flag = 1;
				real_num = 1;
		}
		else{
			//real_num++;
			for(int i=0; i<=real_num; i++){
				if(num == input[i].num){
					input[i].count++;
					flag = 1;
				}
			}
		}

		if(!flag){
			real_num++;
			input[real_num].num = num;
			input[real_num].count++;
		}
	}


	//printf("input count = %d\n", input_cnt);
	//printf("real count = %d\n", real_num);
	//for(int i=0; i<input_cnt; i++){
	//	printf("%d %d\n", input[i].num, input[i].count);
	//}
	//printf("\n");

	//sort
	qsort(input, real_num, sizeof(NumCount), compare);

	//
	int has_1 = 0;
	for(int i=0; i<real_num; i++){
		if(input[i].count == 1){
			printf("%d ", input[i].num);
		}
	}

	if(input[real_num].count == 1){
		printf("%d ", input[real_num].num);
		has_1 = 1;
	}
	if(!has_1) printf("null");
	return 0;
}
*/