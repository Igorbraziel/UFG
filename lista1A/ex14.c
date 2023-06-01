#include <stdio.h>

int main(){
	int i;
	float a, b, c;
	scanf("%d", &i);
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);

	if( i < 1 || i > 3 ){
		return 0;
	}
	if( i == 1 ){
		if( a <= b && b <= c ){
			printf("%.2f %.2f %.2f\n", a, b, c);
			return 0;
		}
		if( a <= c && c <= b ){
			printf("%.2f %.2f %.2f\n", a, c, b);
			return 0;
		}
		if( b <= a && a <= c ){
			printf("%.2f %.2f %.2f\n", b, a, c);
			return 0;
		}
		if( b <= c && c <= a ){
			printf("%.2f %.2f %.2f\n", b, c, a);
			return 0;
		}
		if( c <= a && a <= b ){
			printf("%.2f %.2f %.2f\n", c, a, b);
			return 0;
		}
		if( c <= b && b <= a ){
			printf("%.2f %.2f %.2f\n", c, b, a);
			return 0;
		}
	}

	if( i == 2 ){
		if( a >= b && b >= c ){
			printf("%.2f %.2f %.2f\n", a, b, c);
			return 0;
		}
		if( a >= c && c >= b ){
			printf("%.2f %.2f %.2f\n", a, c, b);
			return 0;
		}
		if( b >= a && a >= c ){
			printf("%.2f %.2f %.2f\n", b, a, c);
			return 0;
		}
		if( b >= c && c >= a ){
			printf("%.2f %.2f %.2f\n", b, c, a);
			return 0;
		}
		if( c >= a && a >= b ){
			printf("%.2f %.2f %.2f\n", c, a, b);
			return 0;
		}
		if( c >= b && b >= a ){
			printf("%.2f %.2f %.2f\n", c, b, a);
			return 0;
		}
	}

	if( i == 3 ){
		if( a <= b && b <= c ){
			printf("%.2f %.2f %.2f\n", b, c, a);
			return 0;
		}
		if( a <= c && c <= b ){
			printf("%.2f %.2f %.2f\n", c, b, a);
			return 0;
		}
		if( b <= a && a <= c ){
			printf("%.2f %.2f %.2f\n", a, c, b);
			return 0;
		}
		if( b <= c && c <= a ){
			printf("%.2f %.2f %.2f\n", c, a, b);
			return 0;
		}
		if( c <= a && a <= b ){
			printf("%.2f %.2f %.2f\n", a, b, c);
			return 0;
		}
		if( c <= b && b <= a ){
			printf("%.2f %.2f %.2f\n", b, a, c);
			return 0;
		}
	}


	return 0;
}
