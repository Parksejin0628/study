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

struct Dot
{
    int color;
    bool isVisit;
};

enum {NONE = 0, UP, DOWN, RIGHT, LEFT};

int n, m;
Dot dots[51][51];
string input;
bool isCycle = false;

void DFS(int r, int c, int preDir, int color);

int main(){
    FAST_IO;
    cin>>n>>m;
    for(int r=0; r<n; r++)
    {
        cin>>input;
        for(int c=0; c<m; c++)
        {
            dots[r][c].color = input[c] - 'A';
            // cout<<r<<", "<<c<<" : "<<dots[r][c].color<<endl;
            dots[r][c].isVisit = false;
        }
        
    }
    
    for(int r=0; r<n; r++)
    {
        for(int c=0; c<m; c++)
        {
            if(!dots[r][c].isVisit)
            {
                
                DFS(r, c, NONE, dots[r][c].color);
            }
        }
    }
    cout<<(isCycle ? "Yes":"No");

    return 0;
}

void DFS(int r, int c, int preDir, int color)
{
    if(dots[r][c].isVisit)
    {
        isCycle = true;
        return;
    }
    if(isCycle)
    {
        return;
    }
    // cout<<"Now Dot Pos : "<<r<<", "<<c<<endl;
    dots[r][c].isVisit = true;
    if(preDir != UP && r>0 && dots[r-1][c].color == color)
    {
        DFS(r-1, c, DOWN, color);
    }
    if(preDir != DOWN && r<n-1 && dots[r+1][c].color == color)
    {
        DFS(r+1, c, UP, color);
    }
    if(preDir != LEFT && c>0 && dots[r][c-1].color == color)
    {
        DFS(r, c-1, RIGHT, color);
    }
    if(preDir != RIGHT && c<m-1 && dots[r][c+1].color == color)
    {
        DFS(r, c+1, LEFT, color);
    }
}


