#include <stdio.h>
int main(){
	int n; // limite superior
	int i; // contador par
	scanf("%d", &n); //leio o limite superior
	i = 2;
	while( i <= n){
		printf("%d^2 = %d\n", i, i*i);
		i+=2; // i = i + 2
	}

	return 0;
}
