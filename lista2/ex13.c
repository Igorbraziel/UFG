#include <stdio.h>
void ip( int n ) {
	int n1 = n*n*n;
	int i=1, k;
	int soma;

	while(1){
		soma = 0;
		for(k=0;k<n;k++) { // 0,1,2,3,...,n-1
			soma += (2*k)+i;
		}
		if(soma == n1) {
			for(k=0;k<n;k++){
				if(k!=0){
                    printf("+");
                }
				printf("%d", (2*k)+i);
                
			}
			return;
		}
		i+=2;
	}
}

int main(){
	int l;
	int i;

	scanf("%d", &l);

	for(i=1;i<=l;i++){
		printf("%d*%d*%d = ", i,i,i);
		ip(i);
		printf("\n");
	}
	return 0;
}