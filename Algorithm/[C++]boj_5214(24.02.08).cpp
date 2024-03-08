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

int n, k, m;
int hipertube[1000][1001];
bool isConnectHipertube[100001][1000];
int input;
queue<int> hipertubeQueue;
queue<int> stationQueue;
bool isSearchHipertube[1000];
bool isSearchStation[100001];
int answer = 2;
int nowSearch;
int nowStation;


int main(){
    FAST_IO;
    cin>>n>>k>>m;
    rep(i, 0, m)
    {
        rep(j, 0, k)
        {
            cin>>input;
            isConnectHipertube[input][i] = true;
            hipertube[i][j] = input;
        }
    }
    if(n == 1)
    {
        cout<<"1";
        return 0;
    }
    rep(i, 0, m)
    {
        
        if(isConnectHipertube[1][i])
        {
            hipertubeQueue.push(i);
            isSearchHipertube[i] = true;
        }
    }
    isSearchStation[1] = true;
    while(true)
    {
        if(hipertubeQueue.empty())
        {
            cout<<"-1";
            return 0;
        }
        while(!hipertubeQueue.empty())
        {
            //cout<<"hipertube pop : "<<hipertubeQueue.front()<<endl;
            nowSearch = hipertubeQueue.front();
            hipertubeQueue.pop();
            isSearchHipertube[nowSearch] = true;

            REP(i, 0, k)
            {
                nowStation = hipertube[nowSearch][i];
                if(!isSearchStation[nowStation])
                {
                    if(nowStation == n)
                    {
                        cout<<answer;
                        return 0;
                    }
                    stationQueue.push(nowStation);
                }
            }
        }
        while(!stationQueue.empty())
        {
            //cout<<"station pop : "<<stationQueue.front()<<endl;
            nowSearch = stationQueue.front();
            stationQueue.pop();
            isSearchStation[nowSearch] = true;
            rep(i, 0, m)
            {
                if(!isSearchHipertube[i]&&isConnectHipertube[nowSearch][i])
                {
                    hipertubeQueue.push(i);
                }
            }
        }
        answer++;
    }


    return 0;
}





