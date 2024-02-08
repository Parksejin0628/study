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

int n;

const string str1 = "\"재귀함수가 뭔가요?\"";
const string str2 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
const string str3 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
const string str4 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
const string str5 = "라고 답변하였지.";

void f(int depth = 0, string under_bar = "") {
    if(depth == n) {
        cout << under_bar + str1 << endl;
        cout << under_bar + "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
        cout << under_bar + str5<<endl;

        return;
    }
    cout<< under_bar + str1 << endl;
    cout<<under_bar + str2 << endl;
    cout<<under_bar + str3 << endl;
    cout<<under_bar + str4 << endl;
    f(depth + 1, under_bar + "____");
    cout<<under_bar + str5 << endl;
}

int main(){
    FAST_IO;
    
    cin >> n;
    cout<< "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."<<endl;

    f();

    return 0;
}