#include<stdio.h>

int prec(char ch){
	if(ch == '|')return 10;
	else if(ch == '^')return 9;
	else if(ch == ']')return 8;
	else if(ch == '[')return 7;
	else if(ch == '@')return 6;
	else if(ch == '>')return 5;
	else if(ch == '<')return 4;
	else if(ch == '$')return 3;
	else if(ch == '#')return 2;
	else if(ch == '!')return 1;

	return 0;
}

int main(){
	char line[505];
	fgets(line, 505, stdin);
	
	int code = 0;
	
	for(int i=0; i<strlen(line) - 1; i++){
		int count1 = 0;
		int bit[8];
		for(int i=0; i<8; i++){
			bit[i] = line[i] | (1 << i);
			if(bit[i] == 1){
				count1++;
			}
		}
		
		int code[4];
		int code[0] = !bit[0];
		int code[1] = bit[1] ^ bit[3] ^ bit[4] ^ bit[5];
		int code[2] = (count1%2) ? 1 : 0;
		int code[3] = bit[3];
		
		int result = 0;
		for(int j=0; j<4; j++){
			result |= (code[i] << i);
		}
		
	}
	
	return 0;
} 
