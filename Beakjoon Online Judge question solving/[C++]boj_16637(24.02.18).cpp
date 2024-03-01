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

#define ADD 0
#define SUB 1
#define MUL 2


int n;
string input;
int inputNumber[10];
int inputOperator[9];
int maxValue = -2147483648;

vector<int> operationCase[10];

void CalculateOperationCase(int numberIndex);
int CalculateOperation(int num1, int num2, int oper);


int main(){
    FAST_IO;
    
    cin>>n;
    cin>>input;
    rep(i, 0, n)
    {
        if(i&1)
        {
            if(input[i] == '+')
            {
                inputOperator[i/2] = ADD;
            }
            else if(input[i] == '-')
            {
                inputOperator[i/2] = SUB;
            }
            else if(input[i] == '*')
            {
                inputOperator[i/2] = MUL;
            }
        }
        else
        {
            inputNumber[i/2] = input[i] - '0';
        }
    }
    // cout<<"input : ";
    // rep(i, 0, n)
    // {
    //     if(i&1)
    //     {
    //         if(inputOperator[i/2] == ADD)
    //         {
    //             cout<<'+';
    //         }
    //         else if(inputOperator[i/2] == SUB)
    //         {
    //             cout<<'-';
    //         }
    //         else if(inputOperator[i/2] == MUL)
    //         {
    //             cout<<'*';
    //         }
    //     }
    //     else
    //     {
    //         cout<<inputNumber[i/2];
    //     }
    // }
    // cout<<endl;
    CalculateOperationCase(n/2);
    rep(i, 0, operationCase[n/2].size())
    {
        maxValue = max(maxValue, operationCase[n/2][i]);
    }
    REP(i, 0, n/2)
    {
        cout<<i<<"번까지의 경우의 수 : ";
        rep(j, 0, operationCase[i].size())
        {
            cout<<operationCase[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<maxValue;


    return 0;
}

void CalculateOperationCase(int numberIndex)
{
    int temp;
    if(numberIndex == 0)
    {
        operationCase[0].push_back(inputNumber[0]);
        return;
    }
    if(numberIndex == 1)
    {
        CalculateOperationCase(numberIndex - 1);
        operationCase[1].push_back(CalculateOperation(inputNumber[0], inputNumber[1], inputOperator[0]));
        return;
    }
    CalculateOperationCase(numberIndex - 1);
    temp = CalculateOperation(inputNumber[numberIndex-1], inputNumber[numberIndex], inputOperator[numberIndex-1]);
    rep(i, 0, operationCase[numberIndex-2].size())
    {
        operationCase[numberIndex].push_back(CalculateOperation(operationCase[numberIndex-2][i], temp, inputOperator[numberIndex-2]));
    }
    rep(i, 0, operationCase[numberIndex-1].size())
    {
        operationCase[numberIndex].push_back(CalculateOperation(operationCase[numberIndex-1][i], inputNumber[numberIndex], inputOperator[numberIndex-1]));
    }
}

int CalculateOperation(int num1, int num2, int oper)
{
    // cout<<num1<<"과 "<<num2<<"의";
    // switch(oper)
    // {
    //     case ADD:
    //         cout<<" + ";
    //         break;
    //     case SUB:
    //         cout<<" - ";
    //         break;
    //     case MUL:
    //         cout<<" * ";
    //         break;
    // }
    // cout<<"연산 수행"<<endl;
    switch(oper)
    {
        case ADD:
            return num1 + num2;
        case SUB:
            return num1 - num2;
        case MUL:
            return num1 * num2;
    }
}