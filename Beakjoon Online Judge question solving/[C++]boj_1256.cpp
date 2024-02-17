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

#define INF 1000000001
int n, m, k;
int dp[110][110];
int charCount;
bool answer[210]; // true == 'a', false == 'z'

int main(){
    FAST_IO;
    cin>>n>>m>>k;
    REP(i, 0, n)
    {
        REP(j, 0, m)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if(dp[i][j] >= INF)
            {
                dp[i][j] = INF;
            }
        }
    }
    if(k > dp[n][m])
    {
        cout<<"-1";
        return 0;
    }
    charCount = n + m;
    for(int i=0; i<charCount; i++)
    {
        if(n==0)
        {
            answer[i] = false;
            continue;
        }
        else if(m==0)
        {
            answer[i] = true;
            continue;
        }
        if(k<=dp[n-1][m])
        {
            answer[i] = true;
            n--;
        }
        else
        {
            answer[i] = false;
            k -= dp[n-1][m];
            m--;
        }
    }
    for(int i=0; i<charCount; i++)
    {
        if(answer[i])
        {
            cout<<'a';
        }
        else
        {
            cout<<'z';
        }
    }


    return 0;
}