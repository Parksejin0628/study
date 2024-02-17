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

#define NONE 10001
int n, m;
int input;
vector<int> num;
vector<int> diff;
vector<int> accumulatedSum;
int maxAccumulatedSumIndex = -1;

void PrintAccumulatedSum()
{
    cout<<"AccumulatedSum : ";
    for(int i=0; i<n-1; i++)
    {
        cout<<accumulatedSum[i]<<' ';
    }
    cout<<endl;
}

int main(){
    FAST_IO;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>input;
        num.push_back(input);
    }
    for(int i=0; i<n-1; i++)
    {
        diff.push_back(num[i+1] - num[i]);
    }
    
    for(int i=0; i<n-1; i++)
    {
        if(i==0)
        {
            accumulatedSum.push_back(diff[0]);
            maxAccumulatedSumIndex = 0;   
            continue;  
        }
        accumulatedSum.push_back(accumulatedSum[i-1] + diff[i]);
        if(abs(accumulatedSum[maxAccumulatedSumIndex]) < abs(accumulatedSum[i]))
        {
            maxAccumulatedSumIndex = i;
        }
    }
    if(maxAccumulatedSumIndex != -1)
    {
        diff[maxAccumulatedSumIndex] = NONE;    
    }
    // PrintAccumulatedSum();
    for(int i=0; i<m-1; i++)
    {
        if(diff[0] == NONE)
        {
            accumulatedSum[0] = 0;
        }
        else
        {
            accumulatedSum[0] = diff[0];
        }
        maxAccumulatedSumIndex = 0;
        for(int j=1; j<n-1; j++)
        {   
            if(diff[j] == NONE)
            {
                accumulatedSum[j] = 0;
                continue;
            }
            else
            {
                accumulatedSum[j] = accumulatedSum[j-1] + diff[j];
                if(abs(accumulatedSum[maxAccumulatedSumIndex]) < abs    (accumulatedSum[j]))
                {
                    maxAccumulatedSumIndex = j;
                }
            }
        }
        diff[maxAccumulatedSumIndex] = NONE;
        // PrintAccumulatedSum();
    }
    if(maxAccumulatedSumIndex != -1)
    {
        cout<<abs(accumulatedSum[maxAccumulatedSumIndex]);  
    }
    else
    {
        cout<<'0'<<endl;
    }
    


    return 0;
}