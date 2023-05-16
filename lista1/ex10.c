#include <stdio.h>
int main(){
	int a, b, c;
	char x, y, z;
	scanf("%d %d %d\n", &a, &b, &c); scanf("%c%c%c", &x, &y, &z);
	if(a > 100 || b > 100 || c >100){
		return 0;
	}
	if(x < y && y < z && x < z){
		if(a < b && b < c && a < c){
			printf("%d %d %d\n", a, b, c);
		}
		if(a < b && c < b && a < c){
			printf("%d %d %d\n", a, c, b);
		}
		if(b < a && a < c && b < c){
			printf("%d %d %d\n", b, a, c);
		}
		if(c < a && a < b && c < b){
			printf("%d %d %d\n", c, a, b);
		}
		if(c < a && b < a && c < b){
			printf("%d %d %d\n", c, b, a);
		}
		if(b < a && c < a && b < c){
			printf("%d %d %d\n", b, c, a);
		}
	}
	if(x < y && z < y && x < z){
		if(a < b && b < c && a < c){
			printf("%d %d %d\n", a, c, b);
		}
		if(a < b && c < b && a < c){
			printf("%d %d %d\n", a, b, c);
		}
		if(b < a && a < c && b < c){
			printf("%d %d %d\n", b, c, a);
		}
		if(c < a && a < b && c < b){
			printf("%d %d %d\n", c, b, a);
		}
		if(c < a && b < a && c < b){
			printf("%d %d %d\n", c, a, b);
		}
		if(b < a && c < a && b < c){
			printf("%d %d %d\n", b, a, c);
		}
	}
	if(y < x && x < z && y < z){
		if(a < b && b < c && a < c){
			printf("%d %d %d\n", b, a, c);
		}
		if(a < b && c < b && a < c){
			printf("%d %d %d\n", c, a, b);
		}
		if(b < a && a < c && b < c){
			printf("%d %d %d\n", a, b, c);
		}
		if(c < a && a < b && c < b){
			printf("%d %d %d\n", a, c, b);
		}
		if(c < a && b < a && c < b){
			printf("%d %d %d\n", b, c, a);
		}
		if(b < a && c < a && b < c){
			printf("%d %d %d\n", c, b, a);
		}
	}
	if(z < x && x < y && z < y){
		if(a < b && b < c && a < c){
			printf("%d %d %d\n", c, a, b);
		}
		if(a < b && c < b && a < c){
			printf("%d %d %d\n", b, a, c);
		}
		if(b < a && a < c && b < c){
			printf("%d %d %d\n", c, b, a);
		}
		if(c < a && a < b && c < b){
			printf("%d %d %d\n", b, c, a);
		}
		if(c < a && b < a && c < b){
			printf("%d %d %d\n", a, c, b);
		}
		if(b < a && c < a && b < c){
			printf("%d %d %d\n", a, b, c);
		}
	}
	if(y < z && z < x && y < x){
		if(a < b && b < c && a < c){
			printf("%d %d %d\n", b, c, a);
		}
		if(a < b && c < b && a < c){
			printf("%d %d %d\n", c, b, a);
		}
		if(b < a && a < c && b < c){
			printf("%d %d %d\n", a, c, b);
		}
		if(c < a && a < b && c < b){
			printf("%d %d %d\n", a, b, c);
		}
		if(c < a && b < a && c < b){
			printf("%d %d %d\n", b, a, c);
		}
		if(b < a && c < a && b < c){
			printf("%d %d %d\n", c, a, b);
		}
	}
	if(z < y && y < x && z < x){
		if(a < b && b < c && a < c){
			printf("%d %d %d\n", c, b, a);
		}
		if(a < b && c < b && a < c){
			printf("%d %d %d\n", b, c, a);
		}
		if(b < a && a < c && b < c){
			printf("%d %d %d\n", c, a, b);
		}
		if(c < a && a < b && c < b){
			printf("%d %d %d\n", b, a, c);
		}
		if(c < a && b < a && c < b){
			printf("%d %d %d\n", a, b, c);
		}
		if(b < a && c < a && b < c){
			printf("%d %d %d\n", a, c, b);
		}
	}
	return 0;
}
