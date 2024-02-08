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
int h = 0;
int temp = 0;
int minClash = 10000000;
int sameCount = 0;
int inputSize = 0;
int objectUp[500500];
int objectDown[500500];
int clashCount[500500];

int main(){
    FAST_IO;

    cin>>n>>h;
    for(int i=1; i<=n; i++)
    {
        cin>>inputSize;
        if(i&1)
        {
            objectUp[0] += 1;
            objectUp[inputSize+1] += -1;
        }
        else
        {
            objectDown[h+1] += 1;
            objectDown[h-inputSize] += -1;
        }
    }
    for(int i=1; i<=h; i++)
    {
        objectUp[i] = objectUp[i-1] + objectUp[i];
    }
    for(int j=h; j>0; j--)
    {
        objectDown[j] = objectDown[j+1] + objectDown[j];
    }
    for(int i=1; i<=h; i++)
    {
        clashCount[i] = objectUp[i] + objectDown[i];
        //cout<<"objectUp"<<i<<" : "<<objectUp[i]<<endl;
        //cout<<"objectDown"<<i<<" : "<<objectDown[i]<<endl;
        //cout<<"clashCount"<<i<<" : "<<clashCount[i]<<endl;
        if(minClash > clashCount[i]  && clashCount[i] >= 0)
        {
            minClash = clashCount[i];
            sameCount = 1;
        }
        else if(minClash == clashCount[i])
        {
            sameCount++;
        }
    }

    cout<<minClash<<" "<<sameCount;
    
    return 0;
}