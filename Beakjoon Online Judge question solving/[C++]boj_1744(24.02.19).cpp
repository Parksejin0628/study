
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

int n;
int input;
int answer;
vector<int> positiveNum;
vector<int> negativeNum;
bool isZero;


int main()
{
    FAST_IO;

    cin>>n;
    rep(i, 0, n)
    {
        cin>>input;
        if(input > 0)
        {
            positiveNum.push_back(input);
        }
        else if(input < 0)
        {
            negativeNum.push_back(input);
        }
        else if(input == 0)
        {
            isZero = true;
        }
    }
    sort(positiveNum.begin(), positiveNum.end());
    sort(negativeNum.begin(), negativeNum.end());
    for(int i = positiveNum.size()-1; i>=0; i--)
    {
        // cout<<"for i : "<<i<<endl;
        if(positiveNum[i] == 1)
        {
            answer+=1;
        }
        else if(i-1 < 0)
        {
            answer += positiveNum[i];
        }
        else if(positiveNum[i-1] == 1)
        {
            answer += positiveNum[i];
        }
        else
        {
            answer += positiveNum[i] * positiveNum[i-1];
            i--;
        }
        // cout<<"answer : "<<answer<<endl;
    }
    rep(i, 0, negativeNum.size())
    {
        if(i+1 >= negativeNum.size())
        {
            if(isZero)
            {
                continue;
            }
            answer+=negativeNum[i];
            continue;
        }
        answer += negativeNum[i] * negativeNum[i+1];
        i++;
        // cout<<"answer : "<<answer<<endl;
    }
    cout<<answer;
    

    return 0;
}
