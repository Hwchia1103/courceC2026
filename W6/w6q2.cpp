#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
	int value, num[101] = {0}, sum = 0;
	int count = 0;
	
	while(scanf("%d", &value) != EOF){
		if(value == -1){
			for(int i=0; i<count; i++){
				sum += num[i];
			}
		
			double mean = (double)sum / count;
			qsort(num, count, sizeof(int), cmp);
			
			double median;
			if((count % 2) == 0){
				median = (double)(num[count / 2 - 1] + num[count / 2]) / 2.0;
			}
			else{
				median = (double)num[count / 2];
			}
	
			printf("%.1f %.1f\n", round(mean * 10.0) / 10.0, round(median * 10.0) / 10.0);
			break;
		}
		else{
			num[count++] = value;
		}
	}
	return 0;
}
