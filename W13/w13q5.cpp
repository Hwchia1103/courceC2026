#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 記錄座標與步數的結構
typedef struct {
    int r, c, steps;
} Node;

// 將大陣列放在全域變數，避免堆疊溢位
char maze[105][105];
int visited[105][105];
Node queue[15000]; 

int main() {
    int n, m;
    
    // 應對多筆測資的標準寫法
    while (scanf("%d %d", &n, &m) == 2) {
        int start_r = -1, start_c = -1;
        
        // 【終極防彈讀取法】：一個字元一個字元抓，無視任何排版錯誤、空白或換行
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char ch;
                // scanf(" %c") 前面加一個空格，會自動忽略所有空白、tab和換行符號
                while (scanf(" %c", &ch) == 1) {
                    // 只接受這四個合法的迷宮字元
                    if (ch == 'S' || ch == 'E' || ch == '#' || ch == '.') {
                        maze[i][j] = ch;
                        if (ch == 'S') {
                            start_r = i;
                            start_c = j;
                        }
                        break; // 找到合法字元就跳出內部 while，繼續讀下一格
                    }
                }
            }
        }
        
        // 防呆機制：如果測資壞掉沒有 S，直接輸出 -1，避免陣列越界崩潰
        if (start_r == -1) {
            printf("-1\n");
            continue;
        }

        // 初始化 visited 陣列與 Queue
        memset(visited, 0, sizeof(visited));
        int head = 0, tail = 0;
        
        // 將起點放入 Queue
        queue[tail++] = (Node){start_r, start_c, 0};
        visited[start_r][start_c] = 1;
        
        // 上、下、左、右
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        int min_steps = -1;
        
        // 開始 BFS 搜尋
        while (head < tail) {
            Node curr = queue[head++];
            
            // 抵達終點
            if (maze[curr.r][curr.c] == 'E') {
                min_steps = curr.steps;
                break; // BFS 保證第一次碰到終點就是最短路徑，直接結束
            }
            
            // 探索四個方向
            for (int i = 0; i < 4; i++) {
                int nr = curr.r + dr[i];
                int nc = curr.c + dc[i];
                
                // 檢查是否超出邊界、是否撞牆、是否走過
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc] && maze[nr][nc] != '#') {
                    visited[nr][nc] = 1;
                    queue[tail++] = (Node){nr, nc, curr.steps + 1};
                }
            }
        }
        
        // 輸出結果 (包含找不到路徑的 -1)
        printf("%d\n", min_steps);
    }
    
    return 0;
}



