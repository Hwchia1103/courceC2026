#include<stdio.h>
#include<string.h>
#include<math.h>
//#include<stdbool.h>

int main(){
	int m, n;
	char c;
	char str[500];
	
	scanf("%d,%d", &m, &n);
	scanf("%c", &c);
	//while((c == getchar()) != '\n' && c != EOF);
	
	if(!fgets(str, sizeof(str), stdin)) return 0;
	
	
	//scanf("%c", &c);
	//scanf("%s", str);
	//printf("%d %d\n", m, n);
	str[strcspn(str, "\n")] = 0;
	str[strcspn(str, "\r")] = 0;
	
	double p = log2(m) + log2(n);

	int count = 0;
	int len = strlen(str);
	//printf("%d\n", len);
	
	for(int i=0; i<len; i++){
		putchar(str[i]);
		
		if(str[i] == '#' && i+1 < len && str[i+1] == '#'){
			putchar(str[i+1]);
			i++;
			
			count++;
			if(count == 1) printf("%d", m);
			else if(count == 2) printf("%d", n);
			else if(count == 3) printf("%.2lf", round(p * 100.0) / 100.0);
		} 
	}
		 
	
	return 0;
} 
