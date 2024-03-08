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
int itemCount[110];
int road[110][110];
int nowItemCount;
int maxItemCount;
int area1, area2, length;

void Dijkstra(int index);


int main(){
    FAST_IO;
    cin>>n>>m>>r;
    REP(i, 1, n)
    {
        cin>>itemCount[i];
    }
    rep(i, 0, r)
    {
        cin>>area1>>area2>>length;
        if(road[area1][area2] > 0 || road[area2][area1] > 0)
        {
            length = min(road[area1][area2], length);
        }
        road[area1][area2] = length;
        road[area2][area1] = length;
    }
    REP(i, 1, n)
    {
        Dijkstra(i);
    }
    cout<<maxItemCount;

    return 0;
}

void Dijkstra(int index)
{
    bool isSearch[110] = {false};
    int areaLength[110] = {0};
    int minLength = 100000;
    int minLengthArea = 0;

    nowItemCount = itemCount[index];
    isSearch[index] = true;
    REP(i, 1, n)
    {
        areaLength[i] = road[index][i]; 
    }
    areaLength[index] = 0;
    while(true)
    {
        minLength = 100000;
        minLengthArea = 0;
        REP(i, 1, n)
        {
            if(isSearch[i] == false && areaLength[i] > 0 && minLength > areaLength[i] )
            {
                minLength = areaLength[i];
                minLengthArea = i;
            }
            isSearch[minLengthArea] = true;
            REP(j, 1, n)
            {
                if(road[minLengthArea][j] > 0 && isSearch[j] == false)
                {
                    if(areaLength[j] == 0)
                    {
                        areaLength[j] = areaLength[minLengthArea] + road[minLengthArea][j];
                    }
                    else
                    {
                        areaLength[j] = min(areaLength[j], areaLength[minLengthArea] + road[minLengthArea][j]);
                    }
                }
            }
        }
        if(minLengthArea == 0)
        {
            break;
        }
    }
    // cout<<index<<"에서 다른 정점까지의 거리 : ";
    // REP(i, 1, n)
    // {
    //     cout<<areaLength[i]<<" ";
    // }
    // cout<<endl;
    REP(i, 1, n)
    {
        if(areaLength[i] <= m && areaLength[i] != 0)
        {
            nowItemCount += itemCount[i];
        }
    }
    maxItemCount = max(maxItemCount, nowItemCount);
}

