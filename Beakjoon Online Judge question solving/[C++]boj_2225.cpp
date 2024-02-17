#include<bits/stdc++.h>
#define endl "\n"
#define rep(i, a, b) for(auto i = a; i < b; ++i)
#define rrep(i, a, b) for(auto i = a; i > b; --i)
#define REP(i, a, b) for(auto i = a; i <= b; ++i)
#define RREP(i, a, b) for(auto i = a; i >= b; --i)
#define pii pair<int, int>
#define tii tuple<int, int, int>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define INF numeric_limits<int>::max()
#define PIV (1 << 20)
using namespace std;

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif
#define FAST_IO \
    if constexpr (ndebug) { cin.tie(nullptr); ios::sync_with_stdio(false); }
#define debug(x) \
    if constexpr (!ndebug)* cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugf(...) \
    if constexpr (!ndebug) { cout << "[DEBUG] "; printf(VA_ARGS); }
#define debugc(c) \
    if constexpr (!ndebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }

typedef long long ll;
typedef unsigned long long ull;

#define MOD 1000000000
ll n;
ll k;
ll dpTable[205][205];

ll dp(ll n, ll k)
{
    ll rtn = 0;
    if(k == 1)
    {
        return 1;
    }
    if(k == 2)
    {
        return n+1;
    }
    if(dpTable[n][k] != 0)
    {
        return dpTable[n][k];
    }
    for(int i=0; i<=n; i++)
    {
        rtn += dp(n-i, k-1);
    }
    rtn %= MOD;
    dpTable[n][k] = rtn;
    return rtn;
}

int main(){
    FAST_IO;


    cin>>n>>k;
    cout<<dp(n, k);

    return 0;
}