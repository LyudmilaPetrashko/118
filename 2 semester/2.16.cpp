#include <iostream>
#include <cmath>

using namespace std;


class ok{
    double x, y, r;
    
    public:
    
    ok( double x1, double y1, double r1){
        x=x1;
        y=y1;
        r=r1;
    }
    
    ok(){
        cout<<"enter x:";
        cin>>x;
        cout<<"enter y:";
        cin>>y;
        cout<<"enter r:";
        cin>>r;
    }
    
    ok(const ok &other){
        x=other.x;
        y=other.y;
        r=other.r;
    }
    
    ok& operator = (const ok &st){
        x=st.x;
        y=st.y;
        r=st.r;
        return *this;
    }
    
    double length(){
        return 2*M_PI*r;
    }

    ok move(double dx, double dy){
        x+=dx;
        y+=dy;
        return *this;
    }
    
    
    ok change_xy(double x0, double y0){
        x=x0;
        y=y0;
        return *this;
    }
    
    ok change_r(double r0){
        r=r0;
        return *this;
    }
    

    void show(){
        cout<<endl<<"x="<<x<<"  y="<<y<<"  r="<<r<<endl<<endl;
    }
    
    
    ok& operator *=(double dz){
        r*=dz;
        return *this;
    }
    
    ok operator *(double z){
        r*=z;
        return *this;
    }
    
    bool operator==(const ok& oke ){
	    return ((x==oke.x)&&(y==oke.y)&&(r==oke.r));
    }
    
    bool operator!=(const ok& okey ){
	    return ((x!=okey.x)||(y!=okey.y)||(r!=okey.r));
    }
    
    friend ostream &operator<<( ostream &output, const ok &k )
      { 
         output << "x=" << k.x << "  y=" << k.y<< "  r=" << k.r;
         return output;            
      }
};



int main()
{
    ok p1, p2(1,2,3);
    cout<<endl<<"p1: ";    p1.show();
    cout<<"p2: ";    p2.show();
    
    p1=p2;
    cout<<"p1: ";    p1.show();
    
    double l=p1.length();
    cout<<"length="<<l<<endl;
    
    p1.move(2,5);
    cout<<endl<<"p1_move: ";    p1.show();
    
    p1.change_xy(1,1);
    cout<<endl<<"p1_ch_xy: ";    p1.show();
    
    p1.change_r(10);
    cout<<endl<<"p1_ch_r: ";    p1.show();
    
    p1*=0.5;
    cout<<endl<<"p1_*=: ";    p1.show();
    p1=p1*0.2;
    cout<<endl<<"p1_*: ";    p1.show();
    
    bool i;
    i=(p1==p2);
    cout<<"i_==: "<<i;
    
    i=(p1!=p2);
    cout<<endl<<"i_!=: "<<i;
    
    cout<<endl<<endl<<"p1_<<: "<<endl<<p1;
    return 0;
    
    
}
