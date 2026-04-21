#include<stdio.h>
#include<stdint.h>
int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		int m;
		scanf("%d", &m);
		
		int16_t val = (int16_t)m;
		bool is_palindrome = true;
		
		for(int i=0; i<8; i++){
			int left_bit = (val >> (15 - i)) & 1;
			int right_bit = (val >> i) & 1;
			
			if(left_bit != right_bit){
				is_palindrome = false;
				break;
			}
		}
		if(is_palindrome) printf("%d\n", m);
	}
	return 0;
}
