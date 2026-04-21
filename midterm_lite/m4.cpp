#include<stdio.h>

int main(){
	int k;
	scanf("%d", &k);
		
	int score[101] = {0};
	/*
	for(int i=0; i<101; i++){
		score[i] = 0;
	}
	*/
	while(k--){
		int num;
		scanf("%d", &num);
		//score[num]++;
		
		// avoid array overflow
		if (num >= 0 && num <= 100) {
            score[num]++;
        }
	}
	
	for(int i=0; i<101; i++){
		//if(score[i] == 0) continue;
		//else printf("%d %d\n", i, score[i]);
		if(score[i] > 0) printf("%d %d\n", i, score[i]);
	}
	return 0;
}