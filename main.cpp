#include <bits/stdc++.h>
using namespace std;

class Frac
{
    int n,d;
    public:
    Frac(const int n=0,const int d=1)
    {
        this->n=n;
        this->d=d;
    }

    Frac(const Frac& orig)///copy
    {
        this->n=orig.n;
        this->d=orig.d;
    }

    Frac& operator=(const Frac& orig)
    {
        if (this!=&orig)
        {
            this->n=orig.n;
            this->d=orig.d;
        }
        return *this;
    }

    int getN()const
    {
        return this->n;
    }
    int getD()const
    {
        return this->d;
    }
    void setN(int n)
    {
        this->n=n;
    }
    void setD(int d)
    {
        this->d=d;
    }

    void print()const
    {
        cout<<this->n<<"/"<<this->d<<endl;
    }

    Frac operator*(const Frac& b) const
    {
        Frac nval;
        nval.n=n*b.n;
        nval.d=d*b.d;
        return nval;
    }

    Frac operator+(const Frac& b)const
    {
        Frac nval;
        nval.n=n*b.d+d*b.n;
        nval.d=d*b.d;
        return nval;
    }

    Frac operator-(const Frac& b) const
    {
        Frac nval;
        nval.n=n*b.d-d*b.n;
        nval.d=d*b.d;
        return nval;
    }

    Frac operator/(const Frac& b) const
    {
        Frac nval;
        nval.n=n*b.d;
        nval.d=d*b.n;
        return nval;
    }

    bool operator<(const Frac& b) const
    {
        if(d*b.d>0)
        {
            return n*b.d<d*b.n;
        }
        return n*b.d>d*b.n;
    }

    bool operator>(const Frac& b) const
    {
        if(d*b.d>0)
        {
            return n*b.d>d*b.n;
        }
        return n*b.d<d*b.n;
    }

    bool operator==(const Frac& b)const
    {
        return (n*b.d==d*b.n);
    }

    void skrati()
    {
        int t=__gcd(n,d);
        n/=t;
        d/=t;
    }
};



int main()
{

}
