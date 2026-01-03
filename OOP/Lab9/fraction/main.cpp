#include <iostream>

using namespace std;

class fraction
{
    int numerator,denominator;
    int gcd(int a,int b)
    {
        if(!b)return a;
        return gcd(b,a%b);
    }
    void simplify()
    {
        int g=gcd(numerator,denominator);
        numerator/=g;
        denominator/=g;
    }
public:
    fraction()
    {
        numerator=0;
        denominator=1;
    }
    fraction(int numerator,int denominator)
    {
        if(denominator==0)
        {
            cout<<"denominator can't be zero\n";
            this->numerator=0;
            this->denominator=1;
        }
        else
        {
            this->numerator=numerator;
            this->denominator=denominator;
        }
        simplify();
    }
    void add(fraction f)
    {
        int num=0,den=0;
        den=f.denominator*denominator;
        num=f.numerator*denominator+f.denominator*numerator;
        numerator=num;
        denominator=den;
        simplify();
    }
    void set_numerator(int n)
    {
        numerator=n;
        simplify();
    }
    void set_denominator(int n)
    {
        if(n==0)cout<<"denominator can't be zero\n";
        else denominator=n;
        simplify();
    }
    void set_fraction(int n,int d)
    {
        if(d==0)cout<<"denominator can't be zero\n";
        else
        {
            numerator=n;
            denominator=d;
        }
        simplify();
    }
    int get_numerator()
    {
        return numerator;
    }
    int get_denominator()
    {
        return denominator;
    }
    void print()
    {
        cout<<numerator<<'/'<<denominator<<'\n';
    }
};
int main()
{
    fraction f1(0,100),f2(1,2);
    f1.add(f2);
    f1.print();
    return 0;
}
