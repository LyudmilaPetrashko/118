#include <stdio.h>

int sign(double x){
	if (x>=0){
		if(x==0) return 0;
		else return 1;
	}
	else{
		return -1;
	}
}

double calc(double x, double y, char op){
	switch(op){
		case '+': return x+y;
		case '-': return x-y;
		case '*': return x*y;
		case '/': if (y!=0) return x/y;
				  else return 0;
	}
}

unsigned int ufactorial(unsigned int x){
	if(x==0||x==1) return 1;
	else return x=x*ufactorial(x-1);
}

double dfactorial(double x){
	if(x==0||x==1) return 1;
	else return x=x*dfactorial(x-1);
}



int main(void) {
	
	double a1=0, a2=1, a3=-7, m=10, n=5, val_c;
	char p1='+', p2='-', p3='*', p4='/';
	unsigned int b1=5, val_uf;
	int val_s;
	double b2=6.0, val_df;
	
	val_s=sign(a1);
	printf("val_s=%d\n", val_s);
	val_s=sign(a2);
	printf("val_s=%d\n", val_s);
	val_s=sign(a3);
	printf("val_s=%d\n", val_s);
	
	val_c=calc(m,n,p1);
	printf("val_c=%lf\n", val_c);
	val_c=calc(m,n,p2);
	printf("val_c=%lf\n", val_c);
	val_c=calc(m,n,p3);
	printf("val_c=%lf\n", val_c);
	val_c=calc(m,n,p4);
	printf("val_c=%lf\n", val_c);
	val_c=calc(m,a1,p4);
	printf("val_c=%lf\n", val_c);
	
	val_uf=ufactorial(b1);
	printf("val_uf=%d\n", val_uf);
	
	val_df=dfactorial(b2);
	printf("val_df=%lf\n", val_df);
	
	return 0;
}
