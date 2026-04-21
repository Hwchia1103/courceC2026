#include<stdio.h>

int main(){
	int k, num;
	int count[11] = {0};
	
	scanf("%d", &k); 
	while(k--){
		scanf("%d", &num);
		count[num]++;
	}
	
	int max_odd_freq = 0, max_even_freq = 0;
	int a = 0, b = 0;
	
	for(int i=0; i<=10; i++){
		if(count[i] == 0) continue;
		
		int current_sum = count[i] * i;
		
		if(i % 2 == 0){
			if(count[i] > max_even_freq){
				max_even_freq = count[i];
				b = current_sum;
			}
			else if(count[i] == max_even_freq){
				if(current_sum > b){
					b = current_sum;
				}
			}
		}
		else{
			if(count[i] > max_odd_freq){
				max_odd_freq = count[i];
				a = current_sum;
			}
			else if(count[i] == max_odd_freq){
				if(current_sum > a){
					a = current_sum;
				}
			}
		}
	}
	
	int result = a - b;
	if(result >= 0){
		printf("%d", result);
	}
	else{
		printf("%d", 0 - result);
	}
	return 0;
} 
