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