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

int boardSize;
int board[11][11];
int bishopCount;
int maxBishopCount;
int dr[4] = {1, 1, -1, -1};
int dc[4] = {1, -1, 1, -1};
int operationCount;

int CheckWeight(int r, int c);
void PutBishop(int r, int c);
void PrintBoard();
void Backtracking(int r, int c);

int main(){
    FAST_IO;

    cin>>boardSize;
    rep(i, 0, boardSize)
    {
        rep(j, 0, boardSize)
        {
            cin>>board[i][j];
        }
    }
    Backtracking(-1, -1);
    // cout<<operationCount;
    cout<<maxBishopCount;

    return 0;
}

void Backtracking(int r, int c)
{
    operationCount++;
    int originBoard[11][11];
    int boardWeight[11][11];
    int minWeight = -1;
    //기존 보드판 모양을 기억한다.
    rep(i, 0, boardSize)
    {
        rep(j, 0, boardSize)
        {
            originBoard[i][j] = board[i][j];
        }
    }
    //r, c위치에 비숍을 놓는다. 단, 맨 처음 함수를 호출하는 경우는 제외한다.
    if(r!=-1&&c!=-1)
    {
        PutBishop(r, c);   
        bishopCount++;
        maxBishopCount = max(bishopCount, maxBishopCount);
    }

    rep(i, 0, boardSize)
    {
        rep(j, 0, boardSize)
        {
            if(board[i][j] == 0)
            {
                boardWeight[i][j] = -1;
                continue;
            }
            boardWeight[i][j] = CheckWeight(i, j); // (i, j)의 가중치를 계산한다. 가중치는 그 위치에 비숍이 놓일 경우 없앨 수 있는 1인 칸의 개수이다.
            
            if(minWeight == -1 || boardWeight[i][j] < minWeight)
            {
                minWeight = boardWeight[i][j];
            }
        }
    }
    rep(i, 0, boardSize)
    {
        //minWeight == -1 즉, 모든 보드판이 0이어서 비숍을 둘 수 없는 경우 재귀 호출을 하지 않는다.
        if(minWeight == -1)
        {
            break;
        }
        rep(j, 0, boardSize)
        {
            if(boardWeight[i][j] == minWeight)
            {
                Backtracking(i, j);
            }
        }
    }
    //기존 보드 모양으로 board를 변경한 후 함수를 호출한 곳으로 돌아간다.
    rep(i, 0, boardSize)
    {
        rep(j, 0, boardSize)
        {
            board[i][j] = originBoard[i][j];
        }
    }
    bishopCount--;

    return;
}

int CheckWeight(int r, int c)
{
    int weight = 0;
    rep(i,1,boardSize)
    {
        rep(j, 0, 4)
        {
            //인덱스 값을 넘어가는지 확인
            if(r+dr[j]*i < 0 || r+dr[j]*i > boardSize-1 || c+dc[j]*i < 0 || c+dc[j]*i > boardSize-1)
            {
                continue;
            }
            if(board[r+dr[j]*i][c+dc[j]*i] == 1)
            {
                weight++;
            }
        }
    }
    return weight;
}

void PutBishop(int r, int c)
{
    board[r][c] = 0;
    rep(i,1,boardSize)
    {
        rep(j, 0, 4)
        {
            //인덱스 값을 넘어가는지 확인
            if(r+dr[j]*i < 0 || r+dr[j]*i > boardSize-1 || c+dc[j]*i < 0 || c+dc[j]*i > boardSize-1)
            {
                continue;
            }
            // cout<<"Check PutBishop ("<<r<<", "<<c<<")"<<endl;
            board[r+dr[j]*i][c+dc[j]*i] = 0;
        }
    }   
}

void PrintBoard()
{
    rep(i, 0, boardSize)
    {
        rep(j, 0, boardSize)
        {
            cout<<board[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}

