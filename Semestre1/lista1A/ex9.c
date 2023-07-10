#include <stdio.h>
int main(){
	int n, u, d, c, m, mm;
	
	scanf("%d", &n);
	
		u = n%10;
		d = (n%100) - u;
		c = (n%1000) - (u + d);
		m = (n%10000) - (u + d + c);
		mm = (n%100000) - (u + d + c + m);
		d = d/10;
		c = c/100;
		m = m/1000;
		mm = mm/10000;
	if(n < 0 || n > 99999){
		printf("NUMERO INVALIDO\n");
		return 0;
	}
	
	if(n >= 0 && n < 10){
		printf("PALINDROMO\n");
		return 0;
	}
	
	if(n >=10 && n < 100){
		if(u == d){
			printf("PALINDROMO\n");
			return 0;
		}else{
			printf("NAO PALINDROMO\n");
			return 0;
		}
		return 0;
	}
	
	if(n >= 100 && n < 1000){

		if(u == c){
			printf("PALINDROMO\n");
			return 0;
		}else{
			printf("NAO PALINDROMO\n");
			return 0;
		}
		return 0;
	}
	
	if(n >= 1000 && n < 10000){
		if(u == m && d == c){
			printf("PALINDROMO\n");
			return 0;
		}else{
			printf("NAO PALINDROMO\n");
			return 0;
		}
		return 0;
	}
	
	if(n >= 10000 && n < 100000){
		if(u == mm && d == m){
			printf("PALINDROMO\n");
			return 0;
		}else{
			printf("NAO PALINDROMO\n");
			return 0;
		}
		return 0;
		
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
