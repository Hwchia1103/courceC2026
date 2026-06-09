#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Check if operator is right-associative
int isRightAssociative(char c) {
    return c == '^';
}

void infixToPostfix(char* exp) {
    int len = strlen(exp);
    char result[len + 1];
    char stack[len];
    int j = 0;
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = exp[i];

        // If operand, add to result
        if (isalnum(c)) {
            result[j++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            stack[++top] = '(';
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = stack[top--];
            }

            // pop '('
            top--;
        }

        // If operator
        else {
            while (top != -1 && stack[top] != '(' &&
                  (prec(stack[top]) > prec(c) ||
                  (prec(stack[top]) == prec(c) && !isRightAssociative(c)))) {
                result[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    // Pop remaining operators
    while (top != -1) {
        result[j++] = stack[top--];
    }

    result[j] = '\0';
    printf("%s\n", result);
}

int main() {
    char exp1[] = "a*(b+c)/d";
    infixToPostfix(exp1);
    return 0;
}
-----------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// stack implementation
char stack[100];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }
int isEmpty() { return top == -1; }

// precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

// check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// check if operator is right-associative
int isRightAssociative(char c) {
    return (c == '^');
}

// function to convert infix to prefix using reverse-trick
void infixToPrefix(char s[]) {
    int n = strlen(s);

    // reverse string
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
    }

    // swap '(' and ')'
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    char result[200];
    int k = 0;

    // infix to postfix conversion
    for (int i = 0; i < n; i++) {
        char c = s[i];

        if (isalnum(c)) {
            result[k++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                result[k++] = pop();
            }
            if (!isEmpty()) pop();
        }
        else if (isOperator(c)) {
            while (!isEmpty() && peek() != '(' &&
                  (precedence(peek()) > precedence(c) ||
                  (precedence(peek()) == precedence(c) && isRightAssociative(c)))) {
                result[k++] = pop();
            }
            push(c);
        }
    }

    while (!isEmpty()) {
        result[k++] = pop();
    }
    result[k] = '\0';

    // reverse result for prefix
    for (int i = 0; i < k / 2; i++) {
        char temp = result[i];
        result[i] = result[k - i - 1];
        result[k - i - 1] = temp;
    }

    printf("%s\n", result);
}

int main() {
    char s[] = "a*(b+c)/d";
    infixToPrefix(s);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 256

// ==========================================
// 1. 結構體定義與操作：字元堆疊 (CharStack)
// ==========================================
typedef struct {
    char data[MAX];
    int top;
} CharStack;

void initCharStack(CharStack* s) { s->top = -1; }
int isEmptyChar(CharStack* s) { return s->top == -1; }
void pushChar(CharStack* s, char c) { s->data[++(s->top)] = c; }
char popChar(CharStack* s) { return isEmptyChar(s) ? '\0' : s->data[(s->top)--]; }
char peekChar(CharStack* s) { return isEmptyChar(s) ? '\0' : s->data[s->top]; }

// ==========================================
// 2. 結構體定義與操作：字串堆疊 (StrStack)
// ==========================================
typedef struct {
    char data[MAX][MAX];
    int top;
} StrStack;

void initStrStack(StrStack* s) { s->top = -1; }
int isEmptyStr(StrStack* s) { return s->top == -1; }
void pushStr(StrStack* s, char* str) { strcpy(s->data[++(s->top)], str); }
void popStr(StrStack* s, char* out_str) {
    if (!isEmptyStr(s)) strcpy(out_str, s->data[(s->top)--]);
}

// ==========================================
// 3. 結構體定義與操作：整數堆疊 (IntStack) - 用於計算
// ==========================================
typedef struct {
    int data[MAX];
    int top;
} IntStack;

void initIntStack(IntStack* s) { s->top = -1; }
int isEmptyInt(IntStack* s) { return s->top == -1; }
void pushInt(IntStack* s, int val) { s->data[++(s->top)] = val; }
int popInt(IntStack* s) { return isEmptyInt(s) ? 0 : s->data[(s->top)--]; }


// --- 輔助函式 ---
int isOperand(char ch) { return isalnum(ch); }

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// ==========================================
// 轉換函式 (使用 Struct Stack 重寫)
// ==========================================

void infixToPostfix(char* infix, char* postfix) {
    CharStack s; initCharStack(&s);
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            pushChar(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                postfix[k++] = popChar(&s);
            }
            popChar(&s); // 彈出 '('
        } else {
            while (!isEmptyChar(&s) && precedence(peekChar(&s)) >= precedence(infix[i])) {
                postfix[k++] = popChar(&s);
            }
            pushChar(&s, infix[i]);
        }
        i++;
    }
    while (!isEmptyChar(&s)) postfix[k++] = popChar(&s);
    postfix[k] = '\0';
}

void infixToPrefix(char* infix, char* prefix) {
    char tempInfix[MAX];
    strcpy(tempInfix, infix);
    reverseString(tempInfix);

    for (int i = 0; tempInfix[i] != '\0'; i++) {
        if (tempInfix[i] == '(') tempInfix[i] = ')';
        else if (tempInfix[i] == ')') tempInfix[i] = '(';
    }

    CharStack s; initCharStack(&s);
    int i = 0, k = 0;

    while (tempInfix[i] != '\0') {
        if (isOperand(tempInfix[i])) {
            prefix[k++] = tempInfix[i];
        } else if (tempInfix[i] == '(') {
            pushChar(&s, tempInfix[i]);
        } else if (tempInfix[i] == ')') {
            while (!isEmptyChar(&s) && peekChar(&s) != '(') {
                prefix[k++] = popChar(&s);
            }
            popChar(&s);
        } else {
            while (!isEmptyChar(&s) && precedence(peekChar(&s)) > precedence(tempInfix[i])) {
                prefix[k++] = popChar(&s);
            }
            pushChar(&s, tempInfix[i]);
        }
        i++;
    }
    while (!isEmptyChar(&s)) prefix[k++] = popChar(&s);
    prefix[k] = '\0';
    reverseString(prefix);
}

void postfixToInfix(char* postfix, char* infix) {
    StrStack s; initStrStack(&s);
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) {
            char op[2] = {postfix[i], '\0'};
            pushStr(&s, op);
        } else {
            char op1[MAX], op2[MAX], temp[MAX];
            popStr(&s, op2);
            popStr(&s, op1);
            sprintf(temp, "(%s%c%s)", op1, postfix[i], op2);
            pushStr(&s, temp);
        }
    }
    popStr(&s, infix);
}

// ==========================================
// 求值函式 (Evaluation)
// ==========================================

// 1. 評估 Postfix (由左至右掃描)
int evaluatePostfix(char* postfix) {
    IntStack s; initIntStack(&s);
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            pushInt(&s, ch - '0'); // 將字元轉為整數
        } else {
            int val2 = popInt(&s); // Postfix 先彈出的是右運算元
            int val1 = popInt(&s); // 後彈出的是左運算元
            switch (ch) {
                case '+': pushInt(&s, val1 + val2); break;
                case '-': pushInt(&s, val1 - val2); break;
                case '*': pushInt(&s, val1 * val2); break;
                case '/': pushInt(&s, val1 / val2); break;
                case '^': pushInt(&s, (int)pow(val1, val2)); break;
            }
        }
    }
    return popInt(&s);
}

// 2. 評估 Prefix (由右至左掃描)
int evaluatePrefix(char* prefix) {
    IntStack s; initIntStack(&s);
    int len = strlen(prefix);
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];
        if (isdigit(ch)) {
            pushInt(&s, ch - '0');
        } else {
            int val1 = popInt(&s); // Prefix 由右至左掃描，先彈出的是左運算元
            int val2 = popInt(&s); // 後彈出的是右運算元
            switch (ch) {
                case '+': pushInt(&s, val1 + val2); break;
                case '-': pushInt(&s, val1 - val2); break;
                case '*': pushInt(&s, val1 * val2); break;
                case '/': pushInt(&s, val1 / val2); break;
                case '^': pushInt(&s, (int)pow(val1, val2)); break;
            }
        }
    }
    return popInt(&s);
}

// 3. 評估 Infix (先轉成 Postfix 再評估)
int evaluateInfix(char* infix) {
    char postfix[MAX];
    infixToPostfix(infix, postfix);
    return evaluatePostfix(postfix);
}

// --- 主程式測試 ---
int main() {
    // 測試轉換
    char vars_infix[] = "A+B*C-D";
    char vars_postfix[MAX], vars_prefix[MAX];
    printf("=== 轉換測試 ===\n");
    printf("Original Infix: %s\n", vars_infix);
    infixToPostfix(vars_infix, vars_postfix);
    printf("Infix to Postfix: %s\n", vars_postfix);
    infixToPrefix(vars_infix, vars_prefix);
    printf("Infix to Prefix:  %s\n\n", vars_prefix);

    // 測試求值 (使用實際數字)
    // 算式： (3+5)*2-8/4 = 8*2 - 2 = 16 - 2 = 14
    char math_infix[] = "(3+5)*2-8/4";
    char math_postfix[MAX], math_prefix[MAX];

    printf("=== 數學求值測試 ===\n");
    printf("Math Infix: %s\n", math_infix);

    // Infix 評估
    printf("Result (Infix):   %d\n\n", evaluateInfix(math_infix));

    // Postfix 評估
    infixToPostfix(math_infix, math_postfix);
    printf("Math Postfix: %s\n", math_postfix);
    printf("Result (Postfix): %d\n\n", evaluatePostfix(math_postfix));

    // Prefix 評估
    infixToPrefix(math_infix, math_prefix);
    printf("Math Prefix:  %s\n", math_prefix);
    printf("Result (Prefix):  %d\n", evaluatePrefix(math_prefix));

    return 0;
}