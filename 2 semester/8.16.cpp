#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <list>


using namespace std;


double prost(double x1, double l1){
    return l1*x1;
}

void zadacha_koshi_vector(double a, double b, double y0, double dx, double l){

    vector<double> c;
    double n=abs(b-a)/dx;
    double y_i=y0;
    double x=a;
    double k1, k2, k3, k4;

    ofstream ofile1;
    ofile1.open ("cpp 1.txt", ios_base::out);
    if(!ofile1) cout<<"don't work vector";

    else{
        c.push_back(x);
        c.push_back(y_i);
        c.push_back(l*x*x/2+y0);
        cout<<"ok_vector";
        ofile1<<c[0]<<"\t"<<c[1]<<"\t"<<c[2]<<"\t"<<endl;

        for(int i=1; i<int(n)+1; i++){

            k1=prost(x,l);
            k2=prost(x+dx/2.,l);
            k3=prost(x+dx/2.,l);
            k4=prost(x+dx,l);

            y_i+=dx/6*(k1+2*k2+2*k3+k4);
            x+=dx;

            c.push_back(x);
            c.push_back(y_i);
            c.push_back(l*x*x/2+y0);

            ofile1<<c[i*3]<<"\t"<<c[i*3+1]<<"\t"<<c[i*3+2]<<"\t"<<endl;

        }

    ofile1.close();
    }
}



void zadacha_koshi_list(double a, double b, double y0, double dx, double l){

    list<double> s;
    double n=abs(b-a)/dx;
    double y_i=y0;
    double x=a;
    double k1, k2, k3, k4;

    ofstream ofile2;
    ofile2.open ("cpp 2.txt", ios_base::out);
    if(!ofile2) cout<<"don't work list";

    else{
        s.push_back(x);
        s.push_back(y_i);
        s.push_back(l*x*x/2+y0);

        cout<<endl<<"ok_list";

        ofile2<<s.front()<<"\t";
        s.pop_front();
        ofile2<<s.front()<<"\t";
        s.pop_front();
        ofile2<<s.front()<<"\t"<<endl;
        s.pop_front();


        for(int i=1; i<int(n)+1; i++){

            k1=prost(x,l);
            k2=prost(x+dx/2.,l);
            k3=prost(x+dx/2.,l);
            k4=prost(x+dx,l);

            y_i+=dx/6*(k1+2*k2+2*k3+k4);
            x+=dx;

            s.push_back(x);
            s.push_back(y_i);
            s.push_back(l*x*x/2+y0);

            ofile2<<s.front()<<"\t";
            s.pop_front();
            ofile2<<s.front()<<"\t";
            s.pop_front();
            ofile2<<s.front()<<"\t"<<endl;
            s.pop_front();

         }

    ofile2.close();
    }
}


int main(){
  zadacha_koshi_vector(0., 2.5, -1.5, 0.1, 2.);
  zadacha_koshi_list(0., 2.5, -1.5, 0.1, 2.);
  return 0;
}
