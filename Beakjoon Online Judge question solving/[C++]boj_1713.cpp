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

struct Student
{
    int value;
    int candidateIndex;
    Student() : value(0), candidateIndex(-1) { }
};

Student student[101];
int candidate[20];
int temp = 0;
int candidateNum = -1;
int input;

int n, m;

int main(){
    FAST_IO;
    cin>>n;
    cin>>m;
    rep(t, 0, m)
    {
        if(t < n)
        {
            candidateNum++;
        }
        cin>>input;
        student[input].value++;
        if(student[input].candidateIndex < n && student[input].candidateIndex != -1)
        {
            rrep(i, student[input].candidateIndex, 0)
            {
                if(student[candidate[i]].value >= student[candidate[i - 1]].value)
                {
                    student[candidate[i]].candidateIndex = i-1;
                    student[candidate[i-1]].candidateIndex = i;
                    temp = candidate[i];
                    candidate[i] = candidate[i-1];
                    candidate[i-1] = temp;
                }
            }
        }
        else
        {
            RREP(i, candidateNum, 0)     
            {
                if(i==0 || student[candidate[i-1]].value >= student[input].value)
                {
                    student[candidateNum].candidateIndex = -1;
                    rrep(j, candidateNum, i)
                    {
                        student[candidate[j-1]].candidateIndex++;
                        candidate[j] = candidate[j-1];
                    }
                    candidate[i] = input;
                    student[input].candidateIndex = i;
                }
            }
        }
    }

    REP(i, 1, 100)
    {
        cout<<student[i].value << " ";
    }
    cout<<endl;
    REP(i, 1, 100)
    {
        cout<<student[i].candidateIndex << " ";
    }

    REP(i, 1, 100)
    {
        if(student[i].candidateIndex < n && student[i].candidateIndex != -1)
        {
            cout<<i;
        }
    }

    return 0;
}