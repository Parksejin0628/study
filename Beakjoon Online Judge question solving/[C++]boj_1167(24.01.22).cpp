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

struct Edge
{
    vector<int> target;
    vector<int> weight;
    Edge() { }
};

vector<Edge*> edge;
vector<bool> isVisit;
int v;
int input;
int maxDistance;

int CheckVertex(int vertex);

int main(){
    FAST_IO;
    cin>>v;
    rep(i, 0, v)
    {
        edge.push_back(new Edge());
        cin>>input;
        while(true)
        {
            cin>>input;
            if(input == -1)
            {
                break;
            }
            isVisit.push_back(false);
            input--;
            edge[i]->target.push_back(input);
            cin>>input;
            edge[i]->weight.push_back(input);
        }
    }
    CheckVertex(0);
    cout<<maxDistance;

    return 0;
}

int CheckVertex(int vertex)
{
    int max1 = -1;
    int max2 = -1;
    int temp = 0;
    isVisit[vertex] = true;
    //cout<<"Debug0 "<<vertex;
    //cout<<"Debug1 "<<edge[vertex]->target.size()<<endl;
    rep(i, 0, edge[vertex]->target.size())
    {
        if(isVisit[edge[vertex]->target[i]] == true)
        {
            continue;
        }
        temp = CheckVertex(edge[vertex]->target[i]) + edge[vertex]->weight[i];
        if(temp > max1)
        {
            max2 = max1;
            max1 = temp;
        }
        else if(temp > max2)
        {
            max2 = temp;
        }
    }
    if(max1 == -1)
    {
        
        return 0;
    }
    if(max2 == -1)
    {
        
        maxDistance = (max1 > maxDistance) ? max1 : maxDistance;
    }
    else
    {
        //cout<<"Debug_max "<<vertex+1<<" : "<<max1 + max2<<endl;
        maxDistance = (max1 + max2 > maxDistance) ? max1 + max2 : maxDistance;
    }
    
    //cout<<"Debug_maxValue "<<vertex+1<<" : "<<max1<<endl;

    return max1;
}