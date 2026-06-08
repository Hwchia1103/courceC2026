#include<stdio.h>
#include<string.h>

#define Max 51

typedef struct{
	char c1;
	char c2;
}charpair;

charpair c[] = {{'A', 'A'}, {'E', '3'}, {'H', 'H'}, 
				{'I', 'I'}, {'J', 'L'}, {'L', 'J'}, 
				{'M', 'M'}, {'b', 'd'}, {'d', 'b'},
				{'i', 'i'}, {'l', 'l'}, {'m', 'm'},
				{'O', 'O'}, {'S', '2'}, {'T', 'T'},
				{'U', 'U'}, {'V', 'V'}, {'W', 'W'},
				{'X', 'X'}, {'Y', 'Y'}, {'Z', '5'},
				{'n', 'n'}, {'o', 'o'}, {'p', 'q'},
				{'q', 'p'}, {'v', 'v'}, {'w', 'w'},
				{'x', 'x'}, {'0', '0'}, {'1', '1'},
				{'2', 'S'}, {'3', 'E'}, {'5', 'Z'},
				{'8', '8'}};

char getMirror(char ch) {
    int size = sizeof(c) / sizeof(c[0]);
    for (int i = 0; i < size; i++) {
        if (c[i].c1 == ch) {
            return c[i].c2; // 找到則回傳對應的鏡像字元
        }
    }
    return '\0'; // 如果在表裡找不到，回傳 null 字元代表無效
}
				
int main(){
	int l;
	scanf("%d", &l);
	
	while(l--){
		
		char line[Max];
		scanf("%s", line);
		//fget(str, sizeof(str), stdin);
		//gets(line);
		
		int len = strlen(line);
		int isMirrored = 1;
		
		for(int i=0; i<len/2; i++){
			int left = i;
			int right = len-1-i;
			
			if(getMirror(line[left]) != line[right]){
				isMirrored = 0;
				break;
			}
			//else if(line[left] == 'E' && line[right] == '3')
		}
		/*
		printf("%s", line);
		if(isMirrored) ? printf(" -- is a mirrored string.") : printf(" -- is only a string.");
		*/
		if(isMirrored) {
            printf("%s -- is a mirrored string.\n", line);
        } else {
            printf("%s -- is only a string.\n", line);
        }
	}
	
	return 0;
} 
