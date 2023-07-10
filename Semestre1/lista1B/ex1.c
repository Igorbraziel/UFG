#include <stdio.h>
int main(){
	double C, F;
	int n, i;
	scanf("%d", &n);
	i = 0;
	while(i < n){ // p/n==3 => i = 0, 1, 2
		scanf("%lf", &F);
		C = 5 * (F-32)/9;
		printf("%.2lf FAHRENHEIT EQUIVALE A %.2lf CELSIUS\n", F, C);
		i++;
	}
	return 0;
}
