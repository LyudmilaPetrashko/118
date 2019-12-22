#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define l 1



double dy(double x, double y){
    return 2*l*x*y;
}

void euler(double a, double b, double y0, double dx){
        double x=a, y=y0;
        int n=(b-a)/dx, i;
        FILE* f;

        f=fopen("rezults.txt", "w");

        if(f==NULL){
            printf("don't work");
            return;
        }

        for(i=0; i<=n; i++){
            fprintf(f, "%lf  %lf  %lf\n", x, y, y0*exp(l*x*x));
            x+=dx;
            y+=dy(x,y)*dx;
        }
        fprintf(f, "%lf  %lf  %lf\n", x, y, y0*exp(l*x*x));
        fclose(f);

}

double euler_eps(double a, double b,double y0, int n, int open){
        double dx=(b-a)/n, x=a, y=y0;
        if(open==0){
            int i;
            for(i=0; i<=n; i++){
                y+=dy(x,y)*dx;
                x+=dx;
            }
        }
        else{
            FILE* f=fopen("rezults2.txt", "w");

            if(f==NULL){
                printf("don't work");
                return 0;
            }
            int i;
            for(i=0; i<=n; i++){
                fprintf(f, "%lf  %lf  %lf\n", x, y, y0*exp(l*x*x));
                y+=dy(x,y)*dx;
                x+=dx;
            }
            fclose(f);
        }
        return y;
}

void el_koshi(double a, double b, double y0, double dx){
        double x=a, y_i=y0, y=y0;
        int n=(b-a)/dx, i;
        FILE* f=fopen("rezults3.txt", "w");

        for(i=0; i<=n; i++){
           fprintf(f, "%lf  %lf  %lf\n", x, y, y0*exp(l*x*x));
           y_i+=dy(x,y)*dx;
           y+=(dy(x,y)+dy(x+dx, y_i))*dx/2;
           x+=dx;
        }
        fprintf(f, "%lf  %lf  %lf\n", x, y, y0*exp(l*x*x));
        fclose(f);
}


double el_koshi_eps(double a, double b, double y0, int n, int open){
        double dx=(b-a)/n, x=a, y=y0, y_i=y0;
        if(open==0){
            int i;
            for(i=0; i<=n; i++){
                y_i+=dy(x,y)*dx;
                y+=(dy(x,y)+dy(x+dx, y_i))*dx/2;
                x+=dx;
            }
        }
        else{
            FILE* f=fopen("rezults4.txt", "w");

            if(f==NULL){
                printf("don't work");
                return 0;
            }
            int i;
            for(i=0; i<=n; i++){
                fprintf(f, "%lf  %lf  %lf\n", x, y, y0*exp(l*x*x));
                y_i+=dy(x,y)*dx;
                y+=(dy(x,y)+dy(x+dx, y_i))*dx/2;
                x+=dx;
            }
            fclose(f);
        }
        return y;
}


int main()
{
    double a=0, b=0.5, y0=1;
    double eps=1e-2;

    // Euler's algorithm - step
    euler(a, b, y0, 0.05);

    int j=5;
    double i1, i2=0;

    // Euler's algorithm - epsilon
    do{
        i1=i2;
        j*=2;
        i2=euler_eps(a, b, y0, j, 0);
    } while(fabs(i1-i2)>eps);

    i2=euler_eps(a, b, y0, j, 1);

    // Euler-Cauchy's algorithm - step
    el_koshi( a, b, y0, 0.05);

    // Euler-Cauchy's algorithm - epsilon

    j=5;
    i2=0;
    do{
        i1=i2;
        j*=2;
        i2=el_koshi_eps(a, b, y0, j, 0);
    } while(fabs(i1-i2)>eps);

    i2=el_koshi_eps(a, b, y0, j, 1);

    return 0;
}
