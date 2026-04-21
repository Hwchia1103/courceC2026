#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){

	int input[12];
	bool possible = false;
	// input
	for(int i=0; i<12; i++){
		scanf("%d", &input[i]);
	}
	// sort input
	int sort_input[12];
	for(int i=0; i<12; i++){
		sort_input[i] = input[i];
	}
	qsort(sort_input, 12, sizeof(int), cmp);

	int norm_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap_days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// create table
	int month_table[14][12];
	// norm
	for(int i = 0; i < 7; i++){
        month_table[i][0] = i + 1;
        for(int j = 1; j < 12; j++){
            // 推算下個月：(這個月起始日 + 這個月天數 - 1) % 7 + 1
            month_table[i][j] = (month_table[i][j-1] + norm_days[j-1] - 1) % 7 + 1;
        }
    }
	//leap
	for(int i = 0; i < 7; i++){
        month_table[i+7][0] = i + 1;
        for(int j = 1; j < 12; j++){
            month_table[i+7][j] = (month_table[i+7][j-1] + leap_days[j-1] - 1) % 7 + 1;
        }
    }
	// compare
	for(int i = 0; i < 14; i++){
		int temp_row[12];
		for(int j=0; j<12; j++){
			temp_row[j] = month_table[i][j];
		}

		qsort(temp_row, 12, sizeof(int), cmp);

		bool match = true;
        for(int j = 0; j < 12; j++){
            if(temp_row[j] != sort_input[j]){
                match = false;
                break;
            }
        }

		if(match){
            possible = true;
            for(int j = 0; j < 11; j++){
                printf("%d ", month_table[i][j]);
            }
            printf("%d\n", month_table[i][11]);
            break; // 找到了就不用再往下找了
        }
	}
	// print
	if(!possible){
		printf("Impossible\n");
	}
	return 0;
}
