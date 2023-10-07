#include <stdio.h>

int main(){
	int n, cont;	
	double s;
	scanf("%d", &n);
	cont = 1;
	s = 0;
	if( n <= 1 ){
		printf("Numero invalido!\n");
		return 0;
	} 
	while( cont <= n ){
		s += (double)1/cont;
		cont++;
	}
	printf("%lf\n", s);
	return 0;
}
