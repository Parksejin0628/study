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
int k = 0;
char inputInequality;
bool minExist = false;
bool maxExist = false;
string maxList;
string minList;
vector<int> inequality(10);
vector<int> answerList(10);
vector<bool> isUse(10);


bool minAnswer(int cur_depth, int max_depth, int pre_num)
{
    if(minExist == true)    return true;
    if(cur_depth == max_depth)
	{
		if(!minExist)
		{
            rep(i, 0, max_depth)
            {
                minList += to_string(answerList[i]);
            }
            minExist = true;
		}
        return false;
	}
	REP(i, 0, 9)
	{
		if(isUse[i] == true)
		{
			continue;
		}
		isUse[i] = true;
        answerList[cur_depth] = i;
		if(pre_num == -1)
		{
			minAnswer(cur_depth+1, max_depth, i);
		}
		else
		{
			if((i-pre_num) * inequality[cur_depth-1] > 0)
			{
				minAnswer(cur_depth+1, max_depth, i);
			}
		}
		isUse[i] = false;
    }

    return true;
}

bool maxAnswer(int cur_depth, int max_depth, int pre_num)
{
    if(maxExist == true)    return true;
    if(cur_depth == max_depth)
	{
		if(!maxExist)
		{
            rep(i, 0, max_depth)
            {
                maxList += to_string(answerList[i]);
            }
            maxExist = true;
		}
        return false;
	}
	RREP(i, 9, 0)
	{
		if(isUse[i] == true)
		{
			continue;
		}
		isUse[i] = true;
        answerList[cur_depth] = i;
		if(pre_num == -1)
		{
			maxAnswer(cur_depth+1, max_depth, i);
		}
		else
		{
			if((i-pre_num) * inequality[cur_depth-1] > 0)
			{
				maxAnswer(cur_depth+1, max_depth, i);
			}
		}
		isUse[i] = false;
    }

    return true;
}

int main()
{
    FAST_IO;
    cin>>k;
    string str = "testStr";
    for(int i=0; i<k; i++)
    {
        cin>>inputInequality;
        if(inputInequality == '<')
        {
            inequality[i] = 1;
        }
        else   
        {
            inequality[i] = -1;
        }
    }
    minAnswer(0, k+1, -1);
    maxAnswer(0, k+1, -1);
    
    cout<<maxList<<endl<<minList<<endl;

    return 0;
}