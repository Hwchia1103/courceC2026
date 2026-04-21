#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		int m;
		scanf("%d", &m);
		
		int8_t val = (int8_t)m;
		bool is_palindrome = true;
		
		for(int i=0; i<4; i++){
			int left_bit = (val >> (7 - i)) & 1;
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

#include <stdio.h>

int main() {
    int k, m;
    scanf("%d", &k);
    
    while (k--) {
        scanf("%d", &m);
        
        // turn int to 8-bit array(range -128 ~ 127)
        // in C, negative num is 2 complement, 
		// can be present by bit operation to get the correct bit
        int bits[8];
        for (int i = 0; i < 8; i++) {
            // get i th bit (from LSB)
            bits[i] = (m >> i) & 1;
        }
        
        // check if bit array is palindrome
        int isPalindrome = 1;
        for (int i = 0; i < 4; i++) {
            if (bits[i] != bits[7 - i]) {
                isPalindrome = 0;
                break;
            }
        }
        
        // if is palindrome, print original number
        if (isPalindrome) {
            printf("%d\n", m);
        }
    }
    
    return 0;
}