#include<stdio.h>

int main(){
	int k;
	scanf("%d", &k);

	char stack[105];
	int top = -1;

	for(int i=0; i<k; i++){
		int type;
		scanf("%d", &type);

		if(type == 1){
			char c;
			scanf(" %c", &c);

			if(top < 104){
				stack[++top] = c;
			}
			else if(type == 2){
				if(top >= 0){
					top--;
				}
			}
			else if(type == 3){
				if(top >= 0){
					printf("%c\n", stack[top]);
				}
				else{
					printf("null\n");
				}
			}
		}
	}

	return 0;
}
//
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 105

// 1. 定義堆疊的結構體
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// 2. 初始化堆疊
void initStack(Stack *s) {
    s->top = -1;
}

bool isFull(Stack *s) {
    return s->top >= MAX_SIZE - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

// 3. 封裝操作邏輯
void push(Stack *s, char c) {
    if (!isFull(s)) {
        s->data[++(s->top)] = c;
    }
}

void pop(Stack *s) {
    if (!isEmpty(s)) {
        s->top--;
    }
}

void printTop(Stack *s) {
    if (!isEmpty(s)) {
        printf("%c\n", s->data[s->top]);
    } else {
        printf("null\n");
    }
}

int main() {
    int k;
    if (scanf("%d", &k) != 1) return 0;

    Stack myStack;
    initStack(&myStack); // 傳入指標來修改狀態

    for (int i = 0; i < k; i++) {
        int type;
        scanf("%d", &type);
        
        if (type == 1) {
            char c;
            scanf(" %c", &c);
            push(&myStack, c);
        } else if (type == 2) {
            pop(&myStack);
        } else if (type == 3) {
            printTop(&myStack);
        }
    }
    return 0;
}
//
#include <iostream>
#include <stack>

using namespace std;

int main() {
    // 優化 C++ 的 I/O 速度，這在解題系統很常用
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    if (!(cin >> k)) return 0;

    // 直接宣告一個裝字元的堆疊
    stack<char> st;

    for (int i = 0; i < k; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            char c;
            cin >> c;
            st.push(c); // 直接推入
        } else if (type == 2) {
            if (!st.empty()) {
                st.pop(); // STL 的 pop 沒有回傳值，只負責移除
            }
        } else if (type == 3) {
            if (!st.empty()) {
                cout << st.top() << "\n"; // top() 負責讀取頂端元素
            } else {
                cout << "null\n";
            }
        }
    }
    return 0;
}
//
/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdint.h>
#include<float.h>

#define maxlen 105

int main(){
	int k, null;
	scanf("%d", &k);
	scanf("%c", &null);
	char stack[101];
	int count = -1;

	while(k--){
		int m;
		char line[11], c;
		fgets(line, 11, stdin);
		line[strcspn(line, "\r\n")] = '\0';

		m = (int)line[0] - '0';

		c = line[2];

		if(m == 1){
			count++;
			if(count <= maxlen){
				stack[count] = c;
			}
			//printf("m1 cnt = %d\n", count);
		}
		else if(m == 2){
			if(count > 0){
				stack[count] = '\0';
				count--;
			}

			//else{
			//	count = -1;
			//}


			//if(count >= 0){
			//	count--;
			//}

			//printf("m2 count =  %d\n", count);
		}
		else if(m == 3){
			//if(count == 0) continue;
			char item = stack[count];
			if(count >= 0){
				printf("%c\n", item);
				//count--;
			}
			else{
				//count = -1;
				printf("null\n");
			}

			//printf("m3 count =  %d\n", count);

		}
	}

	return 0;
}
*/