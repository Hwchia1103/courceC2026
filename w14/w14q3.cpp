#include <stdio.h>
#include <string.h>
#include <ctype.h>

//int counts[10] = {0};

int get_max_digit(int counts[]) {
    for (int i = 9; i >= 0; i--) {
        if (counts[i] > 0) {
            counts[i]--;
            return i;
        }
    }
    return 0; 
}

int main() {
    char A[100], B[100], Pool[1000];
    
    scanf("%s", A);
    scanf("%s", B);
	scanf(" %[^\n]", Pool);
	
	//while(getchar() != '\n');
	//fgets(Pool, sizeof(Pool), stdin);
    //Pool[strcspn(Pool, "\n")] = '\0';
    
    int counts[10] = {0};

    for (int i = 0; Pool[i] != '\0'; i++) {
        if (isdigit(Pool[i])) {
            counts[Pool[i] - '0']++;
        }
    }

    for (int i = 0; i < 20; i++) {
        //if()
		if (A[i] == '?') A[i] = get_max_digit(counts) + '0';
        if (B[i] == '?') B[i] = get_max_digit(counts) + '0';
    }

    int sum[25] = {0};
    int carry = 0;
    int len = 20;
    
    for (int i = len - 1; i >= 0; i--) {
        int val = (A[i] - '0') + (B[i] - '0') + carry;
        sum[i + 1] = val % 10;
        carry = val / 10;
    }
    sum[0] = carry;

    int start_idx = (sum[0] == 0) ? 1 : 0;
    for (int i = start_idx; i <= len; i++) {
        printf("%d", sum[i]);
    }
    //printf("\n");

    return 0;
}

