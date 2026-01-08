#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define vc vector
#define ll long long
#define e "\n"

int tt=1;

void El_Psy_Congroo()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
}
bool sorted(vc<ll>&v)
{
    for(int i=1;i<v.size();i++)
    {
        if(v[i]<v[i-1])return 0;
    }
    return 1;
}

void Accepted()
{
    ll n,m,num=0;cin>>n>>m;
    vc<string>v(n);
    vc<ll>sum_row(n),sum_col(m);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            num+=(v[i][j]=='*');
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ll sum=0;
            for(int k=0;k<n;k++)
            {
                sum+=(v[k][j]=='*');
            }
            for(int k=0;k<m;k++)
            {
                sum+=(v[i][k]=='*');
            }
            sum-=(v[i][j]=='*');
            if(sum==num)
            {
                cout<<"YES\n";
                cout<<i+1<<' '<<j+1;
                return;
            }
        }
    }
    cout<<"NO";

}

int main()
{
    El_Psy_Congroo();
    //cin>>tt;
    while(tt--)
    {
        Accepted();
    }

    return 0;
}
