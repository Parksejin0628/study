#include<iostream>
#define FAST_IO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define WATER 1
#define ICE 2
#define ICE_TO_WATER 3
#define TARGET 9


using namespace std;

int matrix[1505][1505];
int isCheck[1505][1505];
int r = 0;
int c = 0;
int day = 0;
int startColumn = -1;
int startRow = -1;

bool CheckIsConnect(int x, int y);
void MeltIce();
// void PrintMatrix();

int main(void)
{
    FAST_IO;
    string input;

    cin>>r>>c;
    for(int i=1; i<=r; i++)
    {
        cin>>input;
        for(int j=1; j<=c; j++)
        {
            if(input[j-1] == '.')
            {
                matrix[i][j] = WATER;
            }
            else if(input[j-1] == 'X')
            {
                matrix[i][j] = ICE;
            }
            else if(input[j-1] == 'L')
            {
                if(startColumn == -1)
                {
                    startColumn = j;
                    startRow = i;
                    matrix[i][j] = -1;
                }
                else
                {
                    matrix[i][j] = TARGET;
                }
            }
        }
    }
    while(!CheckIsConnect(startRow, startColumn))
    {
        // PrintMatrix();
        day++;
        MeltIce();
    }
    cout<<day;

    return 0;
}

bool CheckIsConnect(int row, int column)
{
    static bool isConnect = false;
    if(row < 1 || row > r || column < 1 || column > c)
    {   
        // cout<<"["<<row<<"]["<<column<<"] Out of range"<<endl;
        return false;
    }
    if(isCheck[row][column] > day) //This means this matrix was checked
    {
        // cout<<"["<<row<<"]["<<column<<"] Check duplication"<<endl;
        return false;
    }
    if(isConnect == true)
    {
        // cout<<"["<<row<<"]["<<column<<"] already connect"<<endl;
        return true;
    }
    if(matrix[row][column] == TARGET)
    {
        // cout<<"["<<row<<"]["<<column<<"] target"<<endl;
        isConnect = true;
        return true;
    }
    else if(matrix[row][column] == ICE)
    {
        // cout<<"["<<row<<"]["<<column<<"] is Ice"<<endl;
        return false;
    }
    // cout<<"["<<row<<"]["<<column<<"] Check"<<endl;
    isCheck[row][column] = day + 1;
    CheckIsConnect(row + 1, column);
    CheckIsConnect(row - 1, column);
    CheckIsConnect(row, column + 1);
    CheckIsConnect(row, column - 1);

    return isConnect;
}

void MeltIce()  
{
    for(int row = 1; row <= r; row++)
    {
        for(int column = 1; column <= c; column++)
        {
            if(matrix[row][column] == ICE)
            {
                if(matrix[row + 1][column] == WATER ||
                matrix[row - 1][column] == WATER ||
                matrix[row][column + 1] == WATER ||
                matrix[row][column - 1] == WATER)
                {
                    matrix[row][column] = ICE_TO_WATER;
                }
            }
        }
    }
    for(int row = 1; row <= r; row++)
    {
        for(int column = 1; column <= c; column++)
        {
            if(matrix[row][column] == ICE_TO_WATER)
            {
                matrix[row][column] = WATER;
            }
        }
    }
}

// void PrintMatrix()
// {
//     cout<<"----------Day "<<day<<"----------"<<endl;
//     for(int row = 1; row <= r; row++)
//     {
//         for(int column = 1; column <= c; column++)
//         {
//             if(row == startRow && column == startColumn)
//             {
//                 cout<<"★";
//             }
//             if(matrix[row][column] == WATER)
//             {
//                 cout<<"□";
//             }
//             else if(matrix[row][column] == ICE)
//             {
//                 cout<<"■";
//             }
//             else if(matrix[row][column] == TARGET)
//             {
//                 cout<<"★";
//             }
//             else if(matrix[row][column] == ICE_TO_WATER)
//             {
//                 cout<<"▣";
//             }
//         }
//         cout<<endl;
//     }
// }
