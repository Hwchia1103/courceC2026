#include <stdio.h>

int main() {
    long long area, oc;

    // 讀取直到輸入 -1 為止 [cite: 279]
    while (scanf("%lld", &area) == 1 && area != -1) {
        // 讀取 OC 長度 (雖然推導後發現計算面積用不到它，但還是必須將其讀出以消耗輸入流) [cite: 268]
        scanf("%lld", &oc);

        // 斜線三角形 EBC 面積恆等於正方形面積的一半 [cite: 268, 281]
        // 使用 (area + 1) / 2 達到四捨五入取至整數的效果
        long long result = (area + 1) / 2;

        printf("%lld\n", result);
    }
    return 0;
}
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>
#include<float.h>

int main(){
	int a, b;
	while(scanf("%d", &a) && a != -1){
		scanf("%d", &b);

		double height = sqrt(a);
		double width = (double)b;

		double result = height * height / 2.0;

		result = round(result * 1.0) / 1.0;
		printf("%.0lf\n", result);
	}

	return 0;
}
*/