#include <stdio.h>

int main(){
	float n1, n2, n3, n4;
	float menor1, menor2, menor3, menor4;
	int i;
	scanf("%f", &n1);
	scanf("%f", &n2);
	scanf("%f", &n3);
	scanf("%f", &n4);
	if(n1 < 0 || n2 < 0 || n3 < 0 || n4 < 0){
		return 0;
	}
	
	if( n1 <= n2 && n2 <= n3 && n3 <= n4){
		printf("%.2f, %.2f, %.2f, %.2f\n", n1, n2, n3, n4);
		return 0;
	}
	if( n1 <= n2 && n2 <= n4 && n4 <= n3){
		printf("%.2f, %.2f, %.2f, %.2f\n", n1, n2, n4, n3);
		return 0;
	}
	if( n1 <= n3 && n3 <= n2 && n2 <= n4){
		printf("%.2f, %.2f, %.2f, %.2f\n", n1, n3, n2, n4);
		return 0;
	}
	if( n1 <= n3 && n3 <= n4 && n4 <= n2){
		printf("%.2f, %.2f, %.2f, %.2f\n", n1, n3, n4, n2);
		return 0;
	}
	if( n1 <= n4 && n4 <= n2 && n2 <= n3){
		printf("%.2f, %.2f, %.2f, %.2f\n", n1, n4, n2, n3);
		return 0;
	}
	if( n1 <= n4 && n4 <= n3 && n3 <= n2){
		printf("%.2f, %.2f, %.2f, %.2f\n", n1, n4, n3, n2);
		return 0;
	}
	
	
	if( n2 <= n1 && n1 <= n3 && n3 <= n4){
		printf("%.2f, %.2f, %.2f, %.2f\n", n2, n1, n3, n4);
		return 0;
	}
	if( n2 <= n1 && n1 <= n4 && n4 <= n3){
		printf("%.2f, %.2f, %.2f, %.2f\n", n2, n1, n4, n3);
		return 0;
	}
	if( n2 <= n3 && n3 <= n1 && n1 <= n4){
		printf("%.2f, %.2f, %.2f, %.2f\n", n2, n3, n1, n4);
		return 0;
	}
	if( n2 <= n3 && n3 <= n4 && n4 <= n1){
		printf("%.2f, %.2f, %.2f, %.2f\n", n2, n3, n4, n1);
		return 0;
	}
	if( n2 <= n4 && n4 <= n1 && n1 <= n3){
		printf("%.2f, %.2f, %.2f, %.2f\n", n2, n4, n1, n3);
		return 0;
	}
	if( n2 <= n4 && n4 <= n3 && n3 <= n1){
		printf("%.2f, %.2f, %.2f, %.2f\n", n2, n4, n3, n1);
		return 0;
	}
	
	
	if( n3 <= n1 && n1 <= n2 && n2 <= n4){
		printf("%.2f, %.2f, %.2f, %.2f\n", n3, n1, n2, n4);
		return 0;
	}
	if( n3 <= n1 && n1 <= n4 && n4 <= n2){
		printf("%.2f, %.2f, %.2f, %.2f\n", n3, n1, n4, n2);
		return 0;
	}
	if( n3 <= n2 && n2 <= n1 && n1 <= n4){
		printf("%.2f, %.2f, %.2f, %.2f\n", n3, n2, n1, n4);
		return 0;
	}
	if( n3 <= n2 && n2 <= n4 && n4 <= n1){
		printf("%.2f, %.2f, %.2f, %.2f\n", n3, n2, n4, n1);
		return 0;
	}
	if( n3 <= n4 && n4 <= n1 && n1 <= n2){
		printf("%.2f, %.2f, %.2f, %.2f\n", n3, n4, n1, n2);
		return 0;
	}
	if( n3 <= n4 && n4 <= n2 && n2 <= n1){
		printf("%.2f, %.2f, %.2f, %.2f\n", n3, n4, n2, n1);
		return 0;
	}
	
	
	if( n4 <= n1 && n1 <= n2 && n2 <= n3){
		printf("%.2f, %.2f, %.2f, %.2f\n", n4, n1, n2, n3);
		return 0;
	}
	if( n4 <= n1 && n1 <= n3 && n3 <= n2){
		printf("%.2f, %.2f, %.2f, %.2f\n", n4, n1, n3, n2);
		return 0;
	}
	if( n4 <= n2 && n2 <= n1 && n1 <= n3){
		printf("%.2f, %.2f, %.2f, %.2f\n", n4, n2, n1, n3);
		return 0;
	}
	if( n4 <= n2 && n2 <= n3 && n3 <= n1){
		printf("%.2f, %.2f, %.2f, %.2f\n", n4, n2, n3, n1);
		return 0;
	}
	if( n4 <= n3 && n3 <= n1 && n1 <= n2){
		printf("%.2f, %.2f, %.2f, %.2f\n", n4, n3, n1, n2);
		return 0;
	}
	if( n4 <= n3 && n3 <= n2 && n2 <= n1){
		printf("%.2f, %.2f, %.2f, %.2f\n", n4, n3, n2, n1);
		return 0;
	}
	
	
	return 0;
}
