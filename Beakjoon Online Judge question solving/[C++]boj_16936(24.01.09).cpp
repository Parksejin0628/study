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

struct Node
{
    ll value;
    int nextIndex;
    Node() : value(0), nextIndex(-1) { }
    Node(ll num) : value(num), nextIndex(-1) { }
};

int n;
int startIndex;
bool isStart = false;
ll input;
vector<Node*> graph;
vector<ll> answer;

int main(){
    FAST_IO;
    //입력
    cin>>n;
    rep(i, 0, n)
    {
        cin>>input;
        graph.push_back(new Node(input));
    }
    //간선 연결
    rep(i, 0, n)
    {
        isStart = true;
        rep(j, 0, n)
        {
            // cout<<"graph["<<i<<"] : "<<graph[i]->value<<", graph["<<j<<"] : "<<graph[j]->value<<endl;
            if(graph[i]->value*2 == graph[j]->value ||
             (graph[i]->value % 3 == 0 && graph[i]->value/3 == graph[j]->value))
            {
                graph[i]->nextIndex = j;
            }
            if((graph[i]->value % 2 == 0 && graph[i]->value/2 == graph[j]->value) ||
             graph[i]->value*3 == graph[j]->value)
            {
                isStart = false;
            }
        }
        if(isStart == true)
        {
            startIndex = i;
        }
    }
    for(int i = startIndex; i!=-1; i = graph[i]->nextIndex)
    {
        cout<<graph[i]->value<<" ";
    }

    return 0;
}