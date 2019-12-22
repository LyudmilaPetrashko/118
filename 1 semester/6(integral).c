#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun(double x){
    return x/(1+x*x*x*x);
}

double trap(double f(double), double a, double b, int n){

        double s=0;
        double h=(b-a)/n, x;

        int i; x = a + h;
        for(i=1; i<n; i++){
            s=s+f(x); x += h;
        }
        return h*((f(a)+f(b))/2.+s);
}

double simp(double f(double), double a, double b, int n){

        double s=0;
        double h=(b-a)/n;
        double x=a, y=a+2*h;

        int i;
        for(i=0; i<n; i++){
            s=s+f(x)+4*f(x+h/2)+f(x + h);
            x+=h;
//            y+=h;
        }
        s*=h/6.;
        return s;
}



int main()
{
    double eps=0.000001;
    double A=-1, B=2;
    double I_an=0.270209750135292;
    int k1=10, s1=30;

    for (k1 = 1; k1 < 20; k1++)
        printf ("%d %f\n", k1, simp (fun, 1., 2., k1));
//    return 0;
    double I1t=trap(fun, A, B, k1), I2t=trap(fun, A, B, k1*2);
    k1*=2;

    while(fabs(I2t-I1t)>eps){
        I1t=I2t;
        k1*=2;
        s1+=k1;
        I2t=trap(fun, A, B, k1);

    }

    int k2=10, s2=30;
    double I1s=simp(fun, A, B, k2), I2s=simp(fun, A, B, k2*2);
    k2*=2;
    while(fabs(I2s-I1s)>eps){
        I1s=I2s;
        k2*=2;
        s2+=k2;
        I2s=trap(fun, A, B, k2);

    }


    printf("\ntrap:\n  eps=%.16lf\n I_nm=%.16lf\n I_an=%.16lf\n kolvo=%d\n\n",eps, I2t, I_an, k1);
    printf("\nsimp:\n  eps=%.16lf\n I_nm=%.16lf\n I_an=%.16lf\n kolvo=%d\n\n",eps, I2s, I_an, k2);
    return 0;
}
