#include <bits/stdc++.h>

using namespace std;

class Vec
{
    public:
    double x,y,z;

    Vec(double x=0,double y=0,double z=0)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }

    Vec(const Vec& a)
    {
        this->x=a.x;
        this->y=a.y;
        this->z=a.z;
    }

    double modul() const
    {
        return sqrt(x*x+y*y+z*z);
    }

    double operator ~() const
    {
        return modul();
    }

    bool operator ==(const Vec& a) const
    {
        return x==a.x && y==a.y && z==a.z;
    }

    bool operator !=(const Vec& a) const
    {
        return !(*this==a);
    }

    Vec& operator +=(const Vec& a)
    {
        x+=a.x;
        y+=a.y;
        z+=a.z;
        return *this;
    }

    Vec& operator -=(const Vec& a)
    {
        x-=a.x;
        y-=a.y;
        z-=a.z;
        return *this;
    }

    bool operator <(const Vec& a)const
    {
        if(modul()<a.modul())
        {
            return true;
        }
        return false;
    }

    bool operator >(const Vec& a) const /// mora da ima const
    {
        if(modul()>a.modul())
        {
            return true;
        }
        return false;
    }

    ///unit vec e za koga modulot mu e 1, a nasokata ista

    Vec operator+()
    {
        double mod=modul();
        if(mod==0)
        {
            return Vec(0,0,0);
        }
        return Vec(x/mod,y/mod,z/mod);
    }

    Vec operator-()
    {
        double mod=modul();
        if(mod==0)
        {
            return Vec(0,0,0);
        }
        return Vec(-x/mod,-y/mod,-z/mod);
    }

    Vec& operator++()//pref
    {
        x=x+1;
        y=y+1;
        z=z+1;
        return *this;
    }

    Vec operator++(int)//opst
    {
        Vec tmp=*this;
        ++(*this);
        return tmp;
    }

    Vec& operator--()//pref
    {
        x=x-1;
        y=y-1;
        z=z-1;
        return *this;
    }

    Vec operator--(int)//opst
    {
        Vec tmp=*this;
        --(*this);
        return tmp;
    }

    double& operator[](int idx)
    {
        if(idx==0)
        {
            return x;
        }
        if(idx==1)
        {
            return y;
        }
        return z;
    }

    friend ostream& operator<<(ostream &out,const Vec& a)
    {
        out<<"("<<a.x<< " "<<a.y<< " "<<a.z<<")";
        return out;
    }

    friend istream& operator>>(istream &in,Vec& a)/// ova ne smee da e const Vec& a
    {
        in>>a.x>>a.y>>a.z;
        return in;
    }
};

int main() {
    
    return 0;
}
