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

#define EVEN 0
#define ODD 1

int n, m, s, e;
int input;
int beforeIndex;
int afterIndex;
int palindrome;
vector<int> sequence;
vector<int> palindromeCount[2];


int main(){
    FAST_IO;
    
    cin>>n;
    rep(i, 0, n)
    {
        cin>>input;
        sequence.push_back(input);
    }
    palindromeCount[0].push_back(-1);
    palindromeCount[1].push_back(-1);
    rep(i, 0, n-1)
    {
        beforeIndex = i;
        afterIndex = i + 1;
        palindrome = 0;
        rep(j, 0, n)
        {
            if(beforeIndex < 0 || afterIndex >= n)
            {
                break;
            }
            if(sequence[beforeIndex] != sequence[afterIndex])
            {
                break;
            }
            beforeIndex--;
            afterIndex++;
            palindrome++;
        }
        palindromeCount[0].push_back(palindrome);
    }
    rep(i, 0, n)
    {
        beforeIndex = i - 1;
        afterIndex = i + 1;
        palindrome = 0;
        rep(j, 0, n)
        {
            if(beforeIndex < 0 || afterIndex >= n)
            {
                break;
            }
            if(sequence[beforeIndex] != sequence[afterIndex])
            {
                break;
            }
            beforeIndex--;
            afterIndex++;
            palindrome++;
        }
        palindromeCount[1].push_back(palindrome);
    }
    // cout<<"palindromeCount[0] : ";
    // rep(i, 1, n)
    // {
    //     cout<<palindromeCount[0][i]<<" ";
    // }
    // cout<<endl;
    // cout<<"palindromeCount[1] : ";
    // rep(i, 1, n+1)
    // {
    //     cout<<palindromeCount[1][i]<<" ";
    // }
    // cout<<endl;

    cin>>m;
    rep(i, 0, m)
    {
        cin>>s>>e;
        // cout<<"palindromeCount["<<(e-s+1)%2<<"]["<<(s+e)/2<<"], "<<(e-s+1-(e-s+1)%2)/2<<endl;
        if(palindromeCount[(e-s+1)%2][(s+e)/2] >= (e-s+1-(e-s+1)%2)/2)
        {
            cout<<"1"<<endl;
        }
        else
        {
            cout<<"0"<<endl;
        }
    }

    return 0;
}