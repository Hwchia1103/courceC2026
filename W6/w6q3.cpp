#include <stdio.h>

int main() {
    int k;
    if (scanf("%d", &k) != 1) return 0;
    while (k--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        
        int found = 0;
        for (int i = x + 1; i < y; i++) {
            if (i % z != 0) {
                if (found) printf(" ");
                printf("%d", i);
                found = 1;
            }
        }
        
        if (!found) {
            printf("null\n");
        } else {
            printf("\n");
        }
    }
    return 0;
}
