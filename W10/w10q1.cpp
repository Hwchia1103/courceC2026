#include<stdio.h>
#include<stdbool.h>
#include<stdint.h>
#include<math.h>

bool is_prime(long long n){
	if(n <= 1) return false;
	if(n <= 3) return true;
	
	if((n%2 == 0) || (n%3) == 0) return false;
	for(long long i=5; i*i<=n; i+=6){
		if((n%i == 0) || (n%(i+2) == 0)) return false;
	}
	return true;
}
int main(){
	unsigned long long k;
	while(1){
		scanf("%llu", &k);
		if(k == -1) break;
		bool is_prime_num = is_prime(k);
		
		if(is_prime_num) printf("%llu\n", k);
		else printf("Not a prime number\n");
		
		
	}
	
	return 0;
} 
/*
你遇到的「資料型別限制」問題，其實是因為 C 語言中 **無號整數 (`unsigned long long` 或 `uint64_t`) 無法正確儲存與判斷負數 `-1`** 所導致的。

當你嘗試將 `-1` 讀取進 `unsigned long long` 時，它會發生溢位（Underflow），變成一個極大的正數（通常是 18446744073709551615），這會讓 `if(k == -1)` 的判斷變得不可靠或產生邏輯漏洞。

根據你的題目要求，輸入的範圍落在 10000000000 到 1000000000000000 之間，並且必須以 `-1` 作為輸入結束的信號[cite: 1]。要同時滿足「接收負數」以及「支援極大正數判斷」的**最佳實踐 (Best Practice)** 如下：

1. **先用有號的 64-bit 整數 (`int64_t`) 讀取輸入**，這樣可以完美捕捉到 `-1` 的結束訊號[cite: 1]。
2. **確認不是 `-1` 後，將數字強制轉型為無號的 64-bit 整數 (`uint64_t`)**，再交給質數判斷函式。這樣就能徹底釋放 64-bit 變數在正整數上的最大儲存空間。

### 修正後的最佳實踐程式碼

```c
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h> // 引入 stdint.h 以使用 uint64_t 和 int64_t

// 將參數改為 uint64_t，讓傳入的數值不會受到負數符號位元的限制
bool is_prime(uint64_t n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    
    if ((n % 2 == 0) || (n % 3 == 0)) return false;
    for (uint64_t i = 5; i * i <= n; i += 6) {
        if ((n % i == 0) || (n % (i + 2) == 0)) return false;
    }
    return true;
}

int main() {
    int64_t k; // 宣告為「有號」整數，這是為了確保能正確捕捉到 -1

    while (1) {
        // 使用 %lld 讀取有號的 64-bit 整數
        scanf("%lld", (long long*)&k);
        
        // 題目規定讀取到 -1 代表輸入資料結束
        if (k == -1) break;[cite: 1]
        
        // 確定輸入的不是 -1 後，將其轉為 uint64_t
        // 這樣可以保證 is_prime 函式能處理的最大值達到 2^64 - 1
        uint64_t unsigned_k = (uint64_t)k;
        
        bool is_prime_num = is_prime(unsigned_k);
        
        // 根據判斷結果輸出該整數或 "Not a prime number"
        if (is_prime_num) {
            printf("%llu\n", (unsigned long long)unsigned_k);[cite: 1]
        } else {
            printf("Not a prime number\n");[cite: 1]
        }
    }
    
    return 0;
}
```

### 為什麼這是一個更好的做法？
* **語意明確**：在 `stdint.h` 函式庫中，`int64_t` 與 `uint64_t` 明確定義了變數就是 64-bit，這比使用 `long long` 更有跨平台的一致性。
* **避開溢位陷阱**：我們將「系統控制訊號 (結束符號 `-1`)」與「業務邏輯 (質數判斷)」切割開來。先處理訊號，再處理邏輯，確保資料型別不會互相衝突。

目前的 `for` 迴圈跑到 $\sqrt{n}$ 已經足以應付多數狀況。如果未來需要處理更頻繁、數字大到逼近 `uint64_t` 極限的測試資料，你會想了解如何實作速度更快的**米勒-拉賓 (Miller-Rabin) 質數測試演算法**嗎？
*/
