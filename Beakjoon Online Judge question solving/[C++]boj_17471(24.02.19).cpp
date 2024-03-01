
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

#define DEFAULT 10007

int n;
int population[10];
bool edge[10][10];
int minValue = DEFAULT;
int electionDistrict[10];
bool DFSCheck[10];

void Backtracking(int index);
int DFS(int index, int electionIndex);


int main(){
    FAST_IO;
    int edgeCount = 0;
    int input;
    
    cin>>n;
    rep(i, 0, n)
    {
        cin>>population[i];
    }
    rep(i, 0, n)
    {
        cin>>edgeCount;
        rep(j, 0, edgeCount)
        {
            cin>>input;
            edge[i][input-1] = true;
            edge[input-1][i] = true;
        }
    }
    // cout<<"[edge]"<<endl;
    // rep(i, 0, n)
    // {
    //     rep(j, 0, n)
    //     {
    //         cout<<edge[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    Backtracking(0);
    if(minValue == DEFAULT)
    {
        cout<<"-1";
        return 0;
    }
    cout<<minValue;

    return 0;
}

void Backtracking(int index)
{
    // cout<<"Check Backtracking Index : "<<index<<endl;
    if(index == n)
    {
        int electionDistrictCount[2] = {0, 0};
        int totalPopulation[2] = {0, 0};
        int isCheck[2] = {false, false};
        int diff = 0;
        rep(i, 0, n)
        {
            totalPopulation[electionDistrict[i]] += population[i];
            electionDistrictCount[electionDistrict[i]]++;
        }
        diff = abs(totalPopulation[0] - totalPopulation[1]);
        // cout<<"Check Backtracking diff : "<<diff<<endl;
        if(diff >= minValue||electionDistrictCount[0] == 0||electionDistrictCount[1] == 0)
        {
            return;
        }
        // cout<<"현재 선거구 : ";
        // rep(i, 0, n)
        // {
        //     cout<<electionDistrict[i]<<' ';
        // }
        // cout<<endl;
        rep(i, 0, n)
		{
			if(!isCheck[electionDistrict[i]])
			{
                rep(j, 0, n)
                {
                    DFSCheck[j] = false;
                }
				if(electionDistrictCount[electionDistrict[i]] > DFS(i, electionDistrict[i]))
				{
					return;
				}
                isCheck[electionDistrict[i]] = true;
			}
		}
        if(!isCheck[0] || !isCheck[1])
        {
            return;
        } 
		minValue = diff;
        return;
    }
    electionDistrict[index] = 0;
    Backtracking(index+1);
    electionDistrict[index] = 1;
    Backtracking(index+1);
}

int DFS(int index, int electionIndex)
{
    if(DFSCheck[index])
    {
        return 0;
    }
    int rtn = 1;
    DFSCheck[index] = true;
    rep(i, 0, n)
    {
        if(edge[index][i] && electionDistrict[i] == electionIndex)
        {
            rtn += DFS(i, electionIndex);
        }
    }
    // cout<<index<<"에서 "<<rtn<<"리턴 "<<electionIndex<<"선거구인덱스"<<endl;

    return rtn;
}