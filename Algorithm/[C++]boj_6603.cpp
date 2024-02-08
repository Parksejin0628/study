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

int k=0;
vector<int> s(13);
vector<int> lotto;

void SelectNum(int nowIndex, int preSelectIndex)
{
    if(nowIndex > 6)
    {
        for(int i=0; i<6; i++)
        {
            cout<<lotto[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=preSelectIndex+1; i<k-6+nowIndex; i++)
    {
        lotto.push_back(s[i]);
        SelectNum(nowIndex+1, i);
        lotto.pop_back();
    }
}

int main(){
    FAST_IO;
    
    while(true)
    {
        cin>>k;
        if(k==0)
        {
            break;
        }
        for(int i=0; i<k; i++)
        {
            cin>>s[i];
        }
        SelectNum(1, -1);
        cout<<endl;
    }
    
    return 0;
}