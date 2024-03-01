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

#define MOD 1000000007

int n;
ll dp[101][4][10];
ll answer;


int main(){
    FAST_IO;

    cin>>n;
    if(n==1)
    {
        cout<<"10";
        return 0;
    }
    REP(i, 0, 8)
    {
        dp[2][1][i] = 1;
    }
    REP(i, 1, 9)
    {
        dp[2][2][i] = 1;
    }
    REP(i, 3, n)
    {
        REP(j, 0, 9)
        {
            if(j+1 <= 9)
            {
                dp[i][0][j] = dp[i-1][1][j+1];
                dp[i][1][j] = (dp[i-1][2][j+1] + dp[i-1][3][j+1])%MOD;
            }
            if(j-1 >= 0)
            {
                dp[i][2][j] = dp[i-1][0][j-1] + (dp[i-1][1][j-1]) % MOD;
                dp[i][3][j] = dp[i-1][2][j-1];
            }
        }
    }
    REP(i, 0, 9)
    {
        REP(j, 0, 3)
        {
            answer += dp[n][j][i];
            answer %= MOD;
        }
    }
    cout<<answer;
    


    return 0;
}





