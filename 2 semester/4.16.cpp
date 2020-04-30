#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class ok{

    double x, y, r;

    public:

    ok();


    ok( double x1, double y1, double r1);


    ok(const ok &other);

    ok& operator = (const ok &st){
        x=st.x;
        y=st.y;
        r=st.r;
        return *this;
    }

    double length() const{
        return 2*M_PI*r;
    }

    ok& move(double dx, double dy){
        x+=dx;
        y+=dy;
        return *this;
    }


    ok& change_xy(double x0, double y0){
        x=x0;
        y=y0;
        return *this;
    }

    ok& change_r(double r0){
        r=r0;
        return *this;
    }


    void show() const{
        cout<<endl<<"x="<<x<<"  y="<<y<<"  r="<<r<<endl<<endl;
    }


    ok& operator *=(double dz){
        r*=dz;
        return *this;
    }

    ok operator *(double z) const{
         ok l (*this);
         l *= z;
         return l;
     }

    friend ok operator*(double a, const ok& m){
        ok n=m;
        return n*=a;
    }

    bool operator==(const ok& oke ) const{
	    return ((x==oke.x)&&(y==oke.y)&&(r==oke.r));
    }

    bool operator!=(const ok& okey ) const{
	    return  !((*this)==(okey));
    }

    double get_x() const{
        return x;
    }

    double get_y() const{
        return y;
    }

    double get_r() const{
        return r;
    }


    friend ostream &operator<<( ostream &output, const ok &k ){
         output << "x=" << k.x << "  y=" << k.y<< "  r=" << k.r;
         return output;
      }
      
    virtual void print() const{
        cout<<endl<<"okr: "<<*this;
    }
    
    ~ok(){
        cout<<endl<<"destructor 1";
    }
    
};

ok :: ok(): x(0), y(0), r(1){};
ok :: ok(double xx,double yy,double rr): x(xx), y(yy), r(rr){};
ok :: ok(const ok &other): x(other.x), y(other.y), r(other.r){};

class sf: public ok{

    double *z;

    public:

    sf (double x1, double y1, double z1, double r1);

    sf();

    sf(const sf &other);

    sf& operator = (const sf &st){
        ok::operator = ((const ok& )(st));
        *z=*st.z;
        return *this;
    }

    double area() const{
        return length()*length()/M_PI;
    }

    sf& move_sf(double dx, double dy, double dz){
        move(dx,dy);
        *z+=dz;
        return *this;
    }


    sf& change_xyz(double x0, double y0, double z0){
        change_xy(x0,y0);
        *z=z0;
        return *this;
    }

    sf& change_rs(double r0){
        change_r(r0);
        return *this;
    }



    sf& operator *=(double dr){
        ok::operator*=(dr);
        return *this;
    }

    sf operator *(double t) const{
        sf l(*this);
        l*=t;
        return l;
     }

    friend sf operator*(double a, const sf& m){
        sf n=m;
        return n*=a;
    }

    bool operator==(const sf& sfe ) const{
        return (((const ok&)(*this))==((const ok&)(sfe))&&(*z==*sfe.z));
    }

    bool operator!=(const sf& sfer ) const{
	    return  !((*this)==(sfer));
    }

    double get_xs() const{
        return get_x();
    }

    double get_ys() const{
        return get_y();
    }

    double get_zs() const{
        return *z;
    }

    double get_rs() const{
        return get_r();
    }


    friend ostream &operator<<( ostream &output, const sf &k ){
         output <<(const ok&)(k)<<"  z="<<*k.z;
         return output;
      }
      
    void print() const{
        cout<<endl<<"sfera: "<<*this<<endl;
    }

    ~sf(){
        delete z;
        cout<<endl<<"desructor 2";
    }
};


sf :: sf(const sf &other): ok((const ok &)(other)), z(new double(*other.z)){};

sf :: sf(): ok(), z(new double(0)){};

sf :: sf (double xx , double yy , double zz, double rr ) : ok ( xx , yy, rr ) , z (new double ( zz ) ) {};


 int main(){

  sf s1, s2(2,2,2,3);

  cout<<"s1: "<<s1<<endl<<"s2: "<<s2<<endl;

  s1=s2;
  cout<<endl<<"s1(=): "<<s1<<endl;

  cout<<endl<<endl<<"area="<<s1.area()<<endl;

  cout<<endl<<"s1(move): "<<s1.move_sf(1,1,1)<<endl;

  cout<<endl<<"s1(ch_xyz): "<<s1.change_xyz(2,2,2)<<endl;

  cout<<endl<<"s1(ch_r): "<<s1.change_rs(2)<<endl;

  cout<<endl<<"s1(get): "<<"x="<<s1.get_xs()<<"  y="<<s1.get_ys()<<"  z="<<s1.get_zs()<<"  r="<<s1.get_rs();

  s1*=5;
  cout<<endl<<"s1(*=): "<<s1<<endl;

  s1=s1*0.2;
  cout<<endl<<"s1(*): "<<s1<<endl;

  bool f;
  f=(s1==s2);
  cout<<endl<<"s1==s2?: "<<f<<endl;

  f=(s1!=s2);
  cout<<endl<<"s1!=s2?: "<<f<<endl;

  s1.print();    

  return 0;
}
