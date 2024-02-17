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

struct App
{
    int cost;
    int memory;
    App(int c = 0, int m = 0) : cost(c), memory(m) { }
};

vector<App> app;
int maxSumCost;
int n, m;
int temp;
int dp[110][10010];

int main(){
    FAST_IO;
    
    cin>>n>>m;
    app.push_back(App(0, 0));
    REP(i, 1, n)
    {
        app.push_back(App(0, 0));
        cin>>app[i].memory;
    }
    REP(i, 1, n)
    {
        cin>>app[i].cost;
        maxSumCost += app[i].cost;
    }

    REP(appIndex, 1, n)
    {
        REP(cost, 0, maxSumCost)
        {
            if(cost < app[appIndex].cost)
            {
                dp[appIndex][cost] = dp[appIndex-1][cost];
                continue;
            }
            temp = dp[appIndex-1][cost - app[appIndex].cost] + app[appIndex].memory;
            if(dp[appIndex-1][cost] >= temp)
            {
                dp[appIndex][cost] = dp[appIndex-1][cost];
            }
            else
            {
                dp[appIndex][cost] = temp;
            }
        }
    }
    // REP(appIndex, 0, n)
    // {
    //     REP(cost, 0, maxSumCost)
    //     {
    //         cout<<dp[appIndex][cost]<<"\t";
    //     }
    //     cout<<endl;
    // }
    REP(cost, 0, maxSumCost)
    {
        if(dp[n][cost] >= m)   
        {
            cout<<cost;
            return 0;
        }
    }
    

    return 0;
}