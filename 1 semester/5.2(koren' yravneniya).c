#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun(double n){
    return cos(n*n);
}

double dix( double f(double),double a0, double b0, double e){

    double a=a0;
    double b=b0;
    double c, N;
    int n;

    if(f(a0)==0){
        N=1.0;
        printf("\n\nN_dix=%lf\n", ceil(N));
        return a0;
    }

    if(f(b0)==0){
        N=1.0;
        printf("\n\nN_dix=%lf\n", ceil(N));
        return b0;
    }


    for(n=1; fabs(b-a)>e; n++){
        c=(b+a)/2;
        if(f(c)==0){
            printf("\n\nN_dix=%d\n", n);
            return c;
        }
        else{
            if(f(a)*f(c)<0) b=c;
            else a=c;
        }
        printf("n=%d a=%lf b=%lf\n", n,a,b);
    }
    N=log2((b0-a0)/e);
    printf("\n\nN_dix=%lf\n", ceil(N));
    return (a+b)/2;
}

double dfun(double n){
    return (-sin(n*n)*2*n);
}

double cas(double g(double), double dg(double), double a,double b, double e){
    double x1=a;
    double x2=x1-g(x1)/dg(x1);
    double x3;
    int n;

    for(n=2; ; n++){
        x3=x2-g(x2)/dg(x2);
        if(fabs(x3-x2)<e&&x3>a&&x3<b) break;
        x1=x2;
        x2=x3;
    }
    printf("\n\nN_cas=%d", n);
    return x3;
}


int main()
{
    double eps=0.000001;
    double x_an=sqrt(M_PI/2);
    double x_nm_d=dix(fun, 1.0, 1.5, eps);
    printf("dix:\nx_nm=%.16lf\nx_an=%.16lf\n eps=%.16lf\n",x_nm_d,x_an,eps);
    double x_nm_c=cas(fun,dfun,1.0, 1.5,eps);
    printf("\ncas:\nx_nm=%.16lf\nx_an=%.16lf\n eps=%.16lf\n",x_nm_c,x_an,eps);
    return 0;
}
