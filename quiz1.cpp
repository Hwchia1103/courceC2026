/*1*/
#include <stdio.h>

int main() {
    int k;
    if (scanf("%d", &k) != 1) return 0;
    while (k--) {
        int x, y;
        scanf("%d,%d", &x, &y);
        if (x == 0 && y == 0) {
            printf("0\n");
        } else if (x > 0 && y > 0) {
            printf("1\n");
        } else if (x < 0 && y > 0) {
            printf("2\n");
        } else if (x < 0 && y < 0) {
            printf("3\n");
        } else if (x > 0 && y < 0) {
            printf("4\n");
        } else if (y == 0) {
            printf("5\n");
        } else if (x == 0) {
            printf("6\n");
        }
    }
    return 0;
}
/*2*/
#include <stdio.h>
#include <stdlib.h>

// compare qsort
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[200];
    int val;
    int n = 0;
    
    while (scanf("%d", &val) != EOF) {
        if (val == -1) {
            if (n == 0) continue;
            
            // mean
            double sum = 0;
            for (int i = 0; i < n; i++) {
                sum += arr[i];
            }
            double mean = sum / n;
            
            // sort and median
            qsort(arr, n, sizeof(int), cmp);
            double median;
            if (n % 2 == 1) {
                median = arr[n / 2];
            } else {
                median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
            }
            
            printf("%.1f %.1f\n", mean, median);
            n = 0; // 重置計數器以讀取下一筆測資
        } else {
            arr[n++] = val;
        }
    }
    return 0;
}
/*3*/
#include <stdio.h>

int main() {
    int k;
    if (scanf("%d", &k) != 1) return 0;
    while (k--) {
        int m, n;
        scanf("%d,%d", &m, &n);
        
        if (m == 1) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) printf("$");
                printf("\n");
            }
        } else if (m == 2) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n - i; j++) printf(" ");
                for (int j = 1; j <= i; j++) printf("$");
                printf("\n");
            }
        } else if (m == 3) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n - i; j++) printf(" ");
                for (int j = 1; j <= 2 * i - 1; j++) printf("$");
                printf("\n");
            }
        }
    }
    return 0;
}
/*4*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[20];
    while (scanf("%s", str) != EOF) {
        if (strcmp(str, "-1") == 0) {
            printf("\n");
            continue;
        }
        
        int val = 0;
        for (int i = 0; i < 8 && str[i] != '\0'; i++) {
            if (str[i] == '1') {
                val |= (1 << i);
            }
        }
        printf("%c", val);
    }
    return 0;
}
/*5*/
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
/*l 代表 long，f 代表 float。合在一起 %lf 專門用來對應 double (雙精度浮點數) 這個資料型態*/

小數點後第 1 位：round(num * 10.0) / 10.0

小數點後第 2 位：round(num * 100.0) / 100.0

小數點後第 3 位：round(num * 1000.0) / 1000.0

小數點後第 4 位：round(num * 10000.0) / 10000.0

#include <stdio.h>
#include <stdlib.h> // qsort is defined in this header file

// Comparison function 1: Sort from smallest to largest (Ascending)
int cmp_asc(const void *a, const void *b) {
    // Cast void* to int*, dereference them, and then subtract
    return (*(int*)a - *(int*)b);
}

// Comparison function 2: Sort from largest to smallest (Descending)
int cmp_desc(const void *a, const void *b) {
    // Note that the order is reversed here, subtracting a from b
    return (*(int*)b - *(int*)a);
}

// Helper function to print the contents of the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Declare an unsorted array
    int my_array[] = {42, 7, 19, 3, 88, 55};
    
    // Calculate the total number of elements in the array (Total bytes / Bytes of a single int)
    int n = sizeof(my_array) / sizeof(my_array[0]);

    printf("--- Before Sorting ---\n");
    print_array(my_array, n);

    // 1. Call qsort for ascending sort
    // Parameters: (Array name, Number of elements, Size of a single element, Comparison function)
    qsort(my_array, n, sizeof(int), cmp_asc);
    
    printf("\n--- Ascending Order ---\n");
    print_array(my_array, n);

    // 2. Call qsort for descending sort
    qsort(my_array, n, sizeof(int), cmp_desc);
    
    printf("\n--- Descending Order ---\n");
    print_array(my_array, n);

    return 0;
}