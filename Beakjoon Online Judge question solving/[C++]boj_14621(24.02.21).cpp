
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

#define MAN true
#define WOMAN false

struct Vertex
{
    bool property;
    int rootIndex;
};

struct Edge
{
    int vertexIndex[2];
    int distance;
};

vector<Vertex> vertex;
vector<Edge> edge;
int answer;
int n, m;
int roadCount;

bool Compare(Edge edge1, Edge edge2)
{ 
    return edge1.distance < edge2.distance; 
}


int main()
{
    FAST_IO;
    Edge temp;
    char input_char;
    int input_int;

    cin>>n>>m;
    rep(i, 0, n)
    {
        cin>>input_char;
        vertex.push_back({input_char=='M', i});
        // cout<<"정점 입력 - 성별 : "<<vertex[i].property<<", 루트노드 인덱스 : "<<vertex[i].rootIndex<<endl;
    }
    rep(i, 0, m)
    {
        cin>>input_int;
        temp.vertexIndex[0] = input_int-1;
        cin>>input_int;
        temp.vertexIndex[1] = input_int-1;
        cin>>input_int;
        temp.distance = input_int;
        if(vertex[temp.vertexIndex[0]].property != vertex[temp.vertexIndex[1]].property)
        {
            edge.push_back(temp);
        }
    }
    sort(edge.begin(), edge.end(), Compare);
    // rep(i, 0, edge.size())
    // {
    //     cout<<i<<"번째 간선 정보 - 정점 : "<<edge[i].vertexIndex[0]+1<<", "<<edge[i].vertexIndex[1]+1<<" / 길이 : "<<edge[i].distance<<endl;
    // }
    rep(i, 0, edge.size())
    {
        if(vertex[edge[i].vertexIndex[0]].rootIndex != vertex[edge[i].vertexIndex[1]].rootIndex)
        {
            rep(j, 0, vertex.size())
            {
                if(vertex[j].rootIndex == vertex[edge[i].vertexIndex[1]].rootIndex)
                {
                    vertex[j].rootIndex = vertex[edge[i].vertexIndex[0]].rootIndex;
                }
            }
            answer += edge[i].distance;
            roadCount++;
        }
    }
    if(roadCount != n-1)
    {
        cout<<"-1";
        return 0;
    }
    cout<<answer;

    return 0;
}
