#include<stdio.h>
#include<string.h>

int main(){
	int k;
	scanf("%d", &k);
	
	char null;
	scanf("%c", &null); 
	//if(null == '\n')printf("enter\n");
	while(k--){
		char line[201];
		fgets(line, 201, stdin);
		
		char stack[201];
		int top = -1;
		int is_balanced = 1;
		
		int len = strlen(line);
		//if(len >= 1)is_balanced = 0;
		//printf("length = %d\n", len);
		/*
		for(int i=0; i<len; i++){
			if(line[i] == '\n')printf("enter");
			else printf("%c", line[i]);
		}
		*/
		for(int i=0; i<len-1; i++){
			char ch = line[i];
			if(top == -1 && (ch == ')' || ch == ']' || ch == '}')){
				is_balanced = 0;
				break;
			}
			if(ch == '(' || ch == '[' || ch == '{'){
				stack[++top] = ch;
			}
			else if(ch == ')'){
				char check = stack[top--];
				if(check != '('){
					is_balanced = 0;
					break;
				}
			}
			else if(ch == ']'){
				char check = stack[top--];
				if(check != '['){
					is_balanced = 0;
					break;
				}
			}
			else if(ch == '}'){
				char check = stack[top--];
				if(check != '{'){
					is_balanced = 0;
					break;
				}
			}
			/*
			for(int j=top; j>-1; j--){
				printf("%c,", stack[j]);
			}
			*/
		}
		if(top != -1) is_balanced = 0;
		if(is_balanced){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
	
	return 0;
} 
