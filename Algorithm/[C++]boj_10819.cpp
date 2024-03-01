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

int n = 0;
vector<int> num(8);
vector<bool> isUse(8);

int calMax(int cur_depth, int max_depth, int pre_index)
{
    int max = -1;
    int temp = 0;

    if(cur_depth == max_depth)
    {
        return 0;
    }
    for(int i=0; i<n; i++)
    {
        if(isUse[i] == true)   
        {
            continue;
        }
        isUse[i] = true;
        if(pre_index == -1)
        {
            temp = calMax(cur_depth+1, max_depth, i);
        }
        else
        {
            temp = abs(num[pre_index] - num[i]) + calMax(cur_depth+1, max_depth, i);
        }
        if(max < temp)  
        {
            max = temp;
        }
        isUse[i] = false;
    }
    return max;
}

int main(){
    FAST_IO;

    cin>>n;
    rep(i, 0, n)
    {
        cin>>num[i];
    }
    cout<<calMax(0, n, -1)<<endl;
    
    return 0;
}