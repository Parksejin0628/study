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
vector<int> permutation;
vector<bool> isUse(9, false);
void CalPermutation(int nowIndex, int maxIndex)
{
    if(nowIndex > maxIndex)
    {
        for(int i=0; i<=maxIndex; i++)
        {
            cout<<permutation[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<=n; i++)
    {
        if(isUse[i])
        {
            continue;
        }
        isUse[i] = true;
        permutation.push_back(i);
        CalPermutation(nowIndex+1, maxIndex);
        permutation.pop_back();
        isUse[i] = false;
    }
}

int main(){
    FAST_IO;
    cin>>n;
    CalPermutation(0, n-1);
    
    return 0;
}