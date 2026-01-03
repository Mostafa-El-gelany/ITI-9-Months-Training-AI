#include<bits/stdc++.h>
#include <unordered_map>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll long long
#define ld long double
#define e "\n"
#define vc vector
#define IMX INT_MAX
#define IMN INT_MIN
#define mat vc<vc<ll>>
#define np string::npos
#define all(d) d.begin(),d.end()
#define mod(n) ((n%mod)+mod)%mod
#define zero(n,m) mat(n,vc<ll>(m))
#define sp(n) fixed<<setprecision(n)

//#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
//#define ordered_set adj<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

ll rr[] = { 0,0,1,-1 }, cc[] = { 1,-1,0,0 };
ll dx[] = { -1,0,0,1,-1,-1,1,1 };
ll dy[] = { 0,-1,1,-1,-1,1,1,0 };
ll knightx[] = { 2,2,-2,-2,1,1,-1,-1 }, knighty[] = { 1,-1,1,-1,2,-2,2,-2 };
ll tt = 1, OO = 0x3f3f3f3f, t = 1, LOG = 30;
ll mod = 1e9 + 7;
//ll mod = 998244353;
double eu = 2.71828182846, PI = acos(-1);

void El_Psy_Congroo()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void Accepted()
{
    ll n,m;cin>>n>>m;
    __int128 l=0,r=1e18,mid;
    ll ans=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if((mid*(mid+1))/2>=n+m)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<ans<<e;
}
int main()
{
	El_Psy_Congroo();
	cin >> t;
	while (t--)
	{
		Accepted();
	}
	return 0;
}
