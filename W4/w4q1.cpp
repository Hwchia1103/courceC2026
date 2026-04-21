#include<stdio.h>
#include<math.h>

typedef struct{
	double capacity;
	double rate;
}TaxBracket;

int main(){
	TaxBracket brackets[] = {{8350.0, 0.10},
							{33950.0-8350.0, 0.15},
							{82250.0-33950.0, 0.25},
							{171550.0-82250.0, 0.28},
							{372950.0-171550.0, 0.33},
							{INFINITY, 0.35}};
	int num = sizeof(brackets) / sizeof(brackets[0]);
	double income = 0;
	
	scanf("%lf", &income);
	
	double total_tax = 0;
	double remain_income = income;
	
	for(int i=0; i<num; i++){
		if(remain_income <= 0){
			break;
		}
		double taxable_amount = 0;
		
		if(remain_income > brackets[i].capacity){
			taxable_amount = brackets[i].capacity;
		}
		else{
			taxable_amount = remain_income;
		}
		
		total_tax += (taxable_amount * brackets[i].rate);
		
		remain_income -= taxable_amount;
	}
	
	printf("%.2f", round(total_tax * 100.0) / 100.0);
	
	return 0;
}
