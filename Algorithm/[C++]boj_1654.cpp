#include <bits/stdc++.h>
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
    if constexpr (!ndebug) cout << "[DEBUG] " << #x << " == " << x << '\n';
#define debugf(...) \
    if constexpr (!ndebug) { cout << "[DEBUG] "; printf(__VA_ARGS__); }
#define debugc(c) \
    if constexpr (!ndebug) { cout << "[DEBUG] "<< #c << ": "; for (const auto& elem : c) cout << elem << ", "; cout << '\n'; }
#define MAX numeric_limits<int>::max()
typedef long long ll;
typedef unsigned long long ull;

ll k;
ll n;
ll line[10010];
ll lo;
ll hi;
ll mid;

int check(ll cutLength)
{
    ll temp = 0;
    rep(i, 0, k) temp += line[i] >= cutLength ? line[i] / cutLength : 0;
    return temp >=n;
}

int main(){
    FAST_IO;
    cin>>k>>n;
    rep(i, 0, k)    cin>>line[i];
// k = 10000, n = 10000
// 2^31 - 1, lo = ? hi = ?
// 2 ^ 31
// 
// x ... x 10000개
// 10000개

// lo 2 ^ 31 - 2, hi 2 ^ 31 - 1
    lo = 1;
    hi = MAX;
    while(lo + 1 < hi)
    {
        mid = lo + hi >> 1;
        if(check(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo;
    
    
    return 0;
}