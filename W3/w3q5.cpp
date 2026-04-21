#include<stdio.h>
#include<string.h>

#ifdef _WIN32
#include<windows.h>
#endif

int main(){

#ifdef _WIN32
	SetConsoleOutputCP(65001);
#endif

	int t;
	const char *animal[] = {"鼠", "牛", "虎", "兔",
					"龍", "蛇", "馬", "羊",
					"猴", "雞", "狗", "豬"};
					
	scanf("%d", &t);
	while(t--){
		int year;
		
		scanf("%d", &year);
		
		int adjust;
		
		if(year > 0){
			adjust = year - 1;
		}
		else{
			adjust = year;
		}
		int index = (adjust % 12 + 12) % 12;
		printf("%s", animal[index]);
		printf("年\n");
	}
	
	return 0;
} 
