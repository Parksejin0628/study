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
int s = 0;
int answer = 0;
vector<int> totalSet;
vector<int> subset;

int sum()
{
    int sum = 0;
    for(int i=0; i<subset.size(); i++)
    {
        sum += subset[i];
    }

    return sum;
}

void SelectNum(int nowIndex, int maxIndex, int preSelectIndex)
{
    if(nowIndex > maxIndex)
    {
        if(sum() == s)
        {
            answer++;
        }
        return;
    }
    for(int i=preSelectIndex + 1; i<n-maxIndex+nowIndex; i++)
    {
        subset.push_back(totalSet[i]);
        SelectNum(nowIndex+1, maxIndex, i);
        subset.pop_back();
    }
}

int main(){
    FAST_IO;
    int input;

    cin>>n>>s;
    for(int i=0; i<n; i++)
    {
        cin>>input;
        totalSet.push_back(input);
    }
    for(int i=0; i<n; i++)
    {
        SelectNum(0, i, -1);
    }
    cout<<answer;

    
    return 0;
}