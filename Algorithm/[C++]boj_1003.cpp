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

class v2
{
public:
    int zero;
    int one;
    v2 operator+(v2& other)
    {
        return {zero + other.zero, one + other.one};
    }
};

vector<v2> dp;
int testcase;
int n;

int main(){
    FAST_IO;
    cin>>testcase;
    rep(t, 0, testcase)
    {
        dp.push_back({1, 0});
        dp.push_back({0, 1});
        cin>>n;
        REP(i, 2, n)
        {
            dp.push_back(dp[i-1] + dp[i-2]);
        }
        cout<<dp[n].zero<<" "<<dp[n].one<<endl;

        dp.clear();
    }
    
    
    return 0;
}