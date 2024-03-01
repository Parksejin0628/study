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

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<ll> s(10);
vector<ll> b(10);

ll f(int idx = 0, int S = 1, int B = 0) {
    if(idx == n) {
        if(S==0 || B==0)    return numeric_limits<ll>::max();
        return (S>B) ? S-B : B-S;
    }
    ll ret = min(f(idx+1, S, B), f(idx+1, S*s[idx], B+b[idx]));
    return ret;
}

int main(){
    FAST_IO;

    cin>>n;
    rep(i, 0, n) {
        cin>>s[i];
        cin>>b[i];
    }
    cout<<f();
    
    return 0;
}