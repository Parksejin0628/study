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

int n, m, r;
int temp;
vector<int> borderElementCount;
int arr[305][305];
int rotateArr[305][305];

int RotateBorder(int borderIndex, int rocateCount);

int main(){
    FAST_IO;
    cin>>n>>m>>r;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin>>arr[i][j];
        }
    }
    rep(i, 0, min(n, m)/2)
    {
        borderElementCount.push_back((n-2*i)*(m-2*i) - (n-2*(i+1)) * (m-2*(i+1)));
    }
    rep(i, 0, min(n, m)/2)
    {
        temp = 0;
        rep(j, i, m-i)
        {
            rotateArr[i][j] = RotateBorder(i, r+temp);
            temp++;
        }
        rep(j, i+1, n-i)
        {
            rotateArr[j][m-i-1] = RotateBorder(i, r+temp);
            temp++;
        }
        RREP(j, m-i-2, i)
        {
            rotateArr[n-i-1][j] = RotateBorder(i, r+temp);
            temp++;
        }
        rrep(j, n-i-2, i)
        {
            rotateArr[j][i] = RotateBorder(i, r+temp);
            temp++;
        }
    }
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout<<rotateArr[i][j]<<' ';
        }
        cout<<endl;
    }
    

    return 0;
}

int RotateBorder(int borderIndex, int rocateCount)
{
    rocateCount %= borderElementCount[borderIndex];
    // cout<<"rocateCount : "<<rocateCount<<endl;
    int I = borderIndex;
    int R = rocateCount;
    int C = borderElementCount[borderIndex];
    // cout<<"Debug : "<<I<<", "<<R<<", "<<C<<endl;
    if(R < m-2*I-1)
    {
        // cout<<"[up]return ["<<I<<"]["<<I+R<<"]"<<endl;
        return arr[I][I + R];
    }
    else if(R < C/2)
    {
        // cout<<"[right]return ["<<I+R-(m-2*I-1)<<"]["<<m-I-1<<"]"<<endl;
        return arr[I+R-(m-2*I-1)][m-I-1];
    }
    else if(R < C-(n-2*I-1))
    {
        // cout<<"[down]return ["<<n-I-1<<"]["<<(m-I-1) - (R-C/2)<<"]"<<": "<<arr[n-I-1][(m-I-1) - (R-C/2)]<<endl;
        return arr[n-I-1][(m-I-1) - (R-C/2)];
    }
    else if(R < C)
    {
        // cout<<"[left]return ["<<I+(C-R)<<"]["<<I<<"]"<<endl;
        return arr[I+(C-R)][I];
    }
}




