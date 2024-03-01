
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

ll dp[101][10];
ll answer;
int n;

int main()
{
    FAST_IO;
    cin>>n;
    REP(i, 1, n)
    {
        rep(j, 0, 10)
        {
            if(i==1)
            {
                if(j==0)
                {
                    continue;
                }
                dp[i][j] = 1;
                continue;
            }
            if(j-1 >= 0)
            {
                dp[i][j] += dp[i-1][j-1];
            }
            if(j+1 <= 9)
            {
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j]%=MOD;
        }
    }
    rep(i, 0, 10)
    {
        answer += dp[n][i];
        answer%=MOD;
    }
    cout<<answer;

    

    return 0;
}
