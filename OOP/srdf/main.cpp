#include <bits/stdc++.h>

using namespace std;
class A
{
     public:

    A(int n = 0)
    {
        m_n = n;
    }

    A(A& a)
    {
        m_n = a.m_n;
        ++m_copy_ctor_calls;
    }
    static int m_copy_ctor_calls;
    private:
    int m_n;
};

int A::m_copy_ctor_calls = 0;
A &f(A& a)
{
    return a;
}
A g(A a)
{
    return a;
}

int main()
{
    A a;
    A b = a, c(a);
    cout << A::m_copy_ctor_calls;
    b = g(c);
    cout << A::m_copy_ctor_calls;
    A d = f(c);
    cout << A::m_copy_ctor_calls <<endl;
    return 0;
}
