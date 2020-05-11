#include <iostream>
#include <cmath>

using namespace std;

template <typename F>
class ok{
    
    F x, y, r;
    
    public:
    
    ok(F x1, F y1, F r1);
    
    ok();
    
    ~ok();
    
    ok(const ok<F> &other);
    
    ok<F>& operator = (const ok<F> &st){
        if (*this==st) return *this;
        x=st.x;
        y=st.y;
        r=st.r;
        return *this;
    }
    
    F length() const{
        return 2*M_PI*r;
    }

    ok<F>& move(const F &dx, const F &dy){
        x+=dx;
        y+=dy;
        return *this;
    }
    
    
    ok<F>& change_xy( const F &x0, const F &y0){
        x=x0;
        y=y0;
        return *this;
    }
    
    ok<F>& change_r(const F &r0){
        r=r0;
        return *this;
    }
        
    
    ok<F>& operator *=(const F &dz){
        r*=dz;
        return *this;
    }
    
    ok<F> operator *(const F &z) const{
         ok<F> l (*this);
         l *= z;
         return l;
     }
    
    template <typename X> 
    friend ok<X> operator*(const X &a, const ok<X>& m){
        ok<X> n=m;
        return n*=a;
    }
    
    bool operator==(const ok<F>& oke ) const{
	    return ((x==oke.x)&&(y==oke.y)&&(r==oke.r));
    }
    
    bool operator!=(const ok<F>& okey ) const{
	    return  !((*this)==(okey));
    }
    
    F get_x() const{
        return x;
    }
    
    F get_y() const{
        return y;
    }
    
    F get_r() const{
        return r;
    }
    
    template <typename G>
    friend ostream &operator<<( ostream &output, const ok<G> &k );
};



template <typename F>
ok<F>::ok(): x(0), y(0), r(1){};

template <typename F>
ok<F>::ok(F xx, F yy, F rr): x(xx), y(yy), r(rr){};

template <typename F>
ok<F>::~ok(){
    cout<<endl<<"destructor";
}

template <typename F>
ok<F>::ok(const ok<F>& src): x(src.x), y(src.y), r(src.r){}

template <typename G>
ostream &operator<<( ostream &output, const ok<G> &k ){ 
         output << "x=" << k.x << "  y=" << k.y<< "  r=" << k.r;
         return output;            
      }





int main(){
    
    
    ok<double> p1, p2(1,2,3);
    cout<<endl<<"p1: "<<p1<<endl;
    cout<<"p2: "<<p2<<endl;
    
    p1=p2;
    cout<<endl<<"p1(=): "<<p1<<endl;
    
    double l=p1.length();
    cout<<endl<<"length="<<l<<endl;
    
    p1.move(2,5);
    cout<<endl<<"p1_move: "<<p1<<endl;
    
    p1.change_xy(1,1);
    cout<<endl<<"p1_ch_xy: "<<p1<<endl;
    
    p1.change_r(10);
    cout<<endl<<"p1_ch_r: "<<p1<<endl;
    
    p1*=0.5;
    cout<<endl<<"p1_*=: "<<p1<<endl;
    p1=p1*0.2;
    cout<<endl<<"p1_*: "<<p1<<endl;
    
    bool i;
    i=(p1==p2);
    cout<<endl<<"i_==: "<<i;
    
    i=(p1!=p2);
    cout<<endl<<"i_!=: "<<i;
    
    
    cout<<endl<<endl<<"x="<<p1.get_x()<<"  y="<<p1.get_y()<<"  r="<<p1.get_r();
    
    
    return 0;
}

