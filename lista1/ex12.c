#include <stdio.h>

int main(){
	float r;
	int c, e, q;
	
	scanf("%f %d %d %d", &r, &q, &e, &c);
	
	if( e == 2 && (r/q) <= 1405.5 && c == 4 ){
		printf("ALUNO COTISTA (L1)\n");
	}
	if( e == 2 && (r/q) <= 1405.5 && c != 4 ){
		printf("ALUNO COTISTA (L2)\n");
	}
	if( e == 2 && (r/q) > 1405.5 && c == 4){
		printf("ALUNO COTISTA (L3)\n");
	}
	if( e == 2 && (r/q) > 1405.5 && c != 4){
		printf("ALUNO COTISTA (L4)\n");
	}
	if( e == 1 ){
		printf("ALUNO NAO COTISTA\n");
	}
	
	
	
	
	
	
	
	
	return 0;
}
