//현재 입력 값 가공까지 완 

#include<iostream>

using std::cin;
using std::cout;료 
using std::endl;

typedef struct Pos
{
	int x;
	int y;
}pos;

class Maze
{
private:
	int move_count;
	int** maze_val;
	pos* searchPos;
	char** maze_oriVal;
	int searchPos_frontIndex;
	int maze_row;
	int maze_column;
public:
	Maze(int n, int m);
	~Maze();
	bool input_mazeOriVal();
	bool BFS();
	bool printAnswer();
};

Maze::Maze(int n, int m) : move_count(-1), searchPos_frontIndex(0), maze_row(n), maze_column(m)
{
	maze_val = new int*[maze_row+2];
	for(int i=0; i<=maze_row+1; i++)
	{
		maze_val[i] = new int[maze_column+2];
	}
	
	searchPos = new pos[maze_row*maze_column];
	
	maze_oriVal = new char*[maze_row];
	for(int i=0; i<maze_row; i++)
	{
		maze_oriVal[i] = new char[maze_column+2];
	}
}
Maze::~Maze()
{
	for(int i=0; i<=maze_row+1; i++)
	{
		delete []maze_val[i];
	}
	for(int i=0; i<maze_row; i++)
	{
		delete []maze_oriVal[i];
	}
	delete[] maze_val;
	delete[] maze_oriVal;
}

bool Maze::input_mazeOriVal()
{
	for(int i=0; i<maze_row; i++)
	{
		cin>>maze_oriVal[i];
	}
	for(int i=0; i<maze_row; i++)
	{
		for(int j=0; j<maze_column; j++)
		{
			//cout<<(int)maze_oriVal[i][j]<<" ";
			maze_val[i+1][j+1] = (int)(maze_oriVal[i][j] - '0');
			cout<<maze_val[i+1][j+1]<<" ";
			
		}
		cout<<endl;
	}
	
}

bool Maze::printAnswer()
{
	
}

bool Maze::BFS()
{
	
}

int main(void)
{
	int n, m;
	
	cin>>n>>m;
	Maze maze(n, m);
	maze.input_mazeOriVal();
	maze.printAnswer();
	
	
	cin>>n;
	
	return 0;
}
