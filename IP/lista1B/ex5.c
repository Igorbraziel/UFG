#include <stdio.h>

int main(){
	int n, cont;
	long int fat;
	fat = 1;
	scanf("%d", &n);
	cont = n;
	while(cont > 0){
		fat = fat * cont;
		cont--;
	}
	printf("%d! = %ld\n", n, fat);
	
	return 0;
}
