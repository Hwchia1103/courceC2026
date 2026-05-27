#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	int t;
	scanf("%d", &t);
	
	for(int i=0; i<t; i++){
		int bet;
		char s1[5], s2[5], s3[5];
		scanf("%d %s %s %s", &bet, s1, s2, s3);
		//printf("%d %c %c %c\n", bet, s1, s2, s3);
		
		double prize = 0.0;
		if(s1[0] == s2[0] && s2[0] == s3[0]){
			switch(s1[0]){
				case 'C' : prize = 2.0 * bet; break;
				case 'L' : prize = 3.0 * bet; break;
				case 'G' : prize = 5.0 * bet; break;
				case 'S' : prize = 10.0 * bet; break;
				case '7' : prize = 20.0 * bet; break;
			}
		}
		else if(s1[0] == s2[0] || s2[0] == s3[0] || s3[0] == s1[0]){
			prize = 1.5 * bet;
		}
		else{
			prize = 0.0;
		}
		if(i == t-1) printf("%d", (int)prize);
		else printf("%d ", (int)prize);
	}
	
	return 0;
} 
