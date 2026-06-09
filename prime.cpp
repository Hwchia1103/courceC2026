#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int16_t checkIsPrime(int16_t p) {
    int16_t loop;
    for(loop=2; loop*loop <=p; loop++) {
        if(!(p % loop)) {
            return 0;
        }
    }
    return 1;
}

int32_t isPrimeNumber(int32_t p) {
    if(p <= 1) return 0;
    if(p == 2) return 1;
    if(p == 3) return 1;
    if(!(p % 2)) return 0;
    if(!(p % 3)) return 0;
    for(int32_t loop=5, gap=2; loop*loop<=p; loop+=gap, gap=6-gap) {
        if(!(p % loop)) return 0;
    }
    return 1;
}
void eratosthenes(uint8_t prime[ARRAY_LENGTH]) {
//Prime table is initialized
    for(int32_t loop=0; loop<ARRAY_LENGTH; loop++) {
        prime[loop] = 1;
    }
    prime[0] = 0; //0 and 1 are labeled as non-prime numbers
    prime[1] = 0;
    for (int32_t iloop=2; iloop<ARRAY_LENGTH; iloop++) {
        if (prime[iloop]) {
            for (int32_t jloop=iloop+iloop; jloop<ARRAY_LENGTH; jloop+=iloop) {
                prime[jloop] = 0; //prime[jloop] is labeled as a non-prime number
            }
        }
    }
}
int main(int argc, char *argv[]) {
    int16_t p;
    while(scanf("%hd", &p) != EOF) {
        if(checkIsPrime(p)) {
            printf("%d is a prime number!\n",p);
        } else {
            printf("%d is not a prime number!\n",p);
        }
        }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define MY_EPSILON 1e-8
#define ARRAY_LENGTH 100
typedef struct {
    uint32_t r;
    double area;
} str_cc;
int main(int argc, char *argv[]) {
    int16_t k;
    str_cc arr[100];
    scanf("%hd", &k);
    for(uint8_t loop = 0; loop < k; loop++) {
        uint32_t r, a;
        scanf("%u", &r);
        arr[loop].r = r;
        double t1 = round(0.215 * r * r * 100.0);
        double t2 = round(0.215 * r * r * 100.0 + MY_EPSILON);
        if(abs(t1-t2) == 1) {
            arr[loop].area = t2 / 100.0;
        } else {
            arr[loop].area = t1 / 100.0;
        }
    }
    for(uint8_t loop = 0; loop < k; loop++) {
        printf("%.2f\n",arr[loop].area);
    }
    return 0;
}