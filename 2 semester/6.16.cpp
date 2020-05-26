// Example program
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;


double prost(double x1, double l1){
    return l1*x1;
}

void zadacha_koshi(double a, double b, double y0, double dx, double l){

    double n=abs(b-a)/dx;
    double y_i=y0;
    double x=a;
    double k1, k2, k3, k4;

    ofstream ofile;
    ofile.open ("cppstudio.txt", ios_base::out);
    if(!ofile) cout<<"don't work";

    else{
        cout<<"ok";
        ofile<<"x="<<x<<"\t"<<"    y="<<y_i<<"\t"<<"   y_an="<<l*x*x/2+y0<<"\t"<<endl;

        for(int i=0; i<int(n); i++){

            k1=prost(x,l);
            k2=prost(x+dx/2.,l);
            k3=prost(x+dx/2.,l);
            k4=prost(x+dx,l);

            y_i+=dx/6*(k1+2*k2+2*k3+k4);
            x+=dx;

            ofile<<"x="<<x<<"\t"<<"    y="<<y_i<<"\t"<<"   y_an="<<l*x*x/2.+y0<<"\t"<<endl;
        }

    ofile.close();
    }
}



int main(){
  zadacha_koshi(0., 2.5, -1.5, 0.1, 2.);
  return 0;
}
