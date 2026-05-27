#include<stdio.h>
#include<math.h>

int main(){
	int k;
	scanf("%d", &k);
	
	while(k--){
		double d, bw, lrr, tds;
		scanf("%lf %lf %lf %lf", &d, &bw, &lrr, &tds);
		
		double tds_decimal = tds / 100.0;
		
		double bev = (bw - lrr * d) / (1.0 - tds_decimal);
		double m_bev = bev * tds_decimal;
		double ext = (m_bev / d) * 100.0;
		
		bev = round(bev * 100.0) / 100.0;
		ext = round(ext * 100.0) / 100.0;
		
		int quality = 0;
		if(ext < 19.0){
			if(tds > 1.5){
				quality = 1;
			}
			else if(tds >= 1.25){
				quality = 4;
			}
			else{
				quality = 7;
			}
		}
		else if(ext <= 24.0){
			if(tds > 1.5){
				quality = 2;
			}
			else if(tds >= 1.25){
				quality = 5;
			}
			else{
				quality = 8;
			}
		}
		else{
			if(tds > 1.5){
				quality = 3;
			}
			else if(tds >= 1.25){
				quality = 6;
			}
			else{
				quality = 9;
			}
		}
		printf("%.2lf %.2lf %d\n", ext, bev, quality);
	}
	
	
	return 0;
}
