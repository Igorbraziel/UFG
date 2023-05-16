#include <stdio.h>
int main(){
	int n, u, d, c;
	scanf("%d", &n);
	if(n >= 1000 || n < 100 || n % 10 == 0){
		return 0;
	}
	else{
		u = (n%10);
		d = ((n%100) - u)/10;
		c = (n - (u + d))/100; 
		printf("%d%d%d\n", u, d, c );
		return 0;
	}



	return 0;
}
