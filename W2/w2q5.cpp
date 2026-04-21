/*
example
T112663836
T 11266383 6
 *87654321
T = 27
SUM = 2 + 7*9 + 1*8 + 1*7 + 2*6 + 6*5 + 6*4 + 3*3 + 8*2 + 3*1 + 6 = 180
*/
#include<stdio.h>
#include<string.h>

int main(){
	int k, value;
	int AlphatoNum[] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
	char str[12];
	
	scanf("%d", &k);
	while(k--){
		int sum = 0;
		scanf("%s", str);
		
		int first = AlphatoNum[str[0] - 'A'];
		sum = (first / 10) + (first % 10) * 9;
		
		for(int i=1; i<=8; i++){
			sum += ((str[i] - '0') * (9 - i));
		}
		sum += (str[9] - '0');
		
		//printf("%d", sum);
		if(sum % 10 == 0){
			printf("real\n");
		}
		else{
			printf("fake\n");
		}
	}
	return 0;
} 
