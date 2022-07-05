//현재 입력 값 가공까지 완 

#include<iostream>

void printMaze();

using std::cin;
using std::cout;
using std::endl;

typedef struct Pos
{
	int row;
	int column;
}pos;

class Maze
{
private:
	int move_count;
	int** maze_val;
	pos* searchPos;
	char** maze_oriVal;
	int maze_row;
	int maze_column;
public:
	Maze(int n, int m);
	~Maze();
	bool input_mazeOriVal();
	bool BFS();
	bool printAnswer();
	void printMaze();
};

Maze::Maze(int n, int m) : move_count(0), maze_row(n), maze_column(m)
{
	maze_val = new int*[maze_row+2]{};
	for(int i=0; i<=maze_row+1; i++)
	{
		maze_val[i] = new int[maze_column+2]{};
	}
	
	searchPos = new pos[maze_row*maze_column +1]{};
	
	maze_oriVal = new char*[maze_row]{};
	for(int i=0; i<maze_row; i++)
	{
		maze_oriVal[i] = new char[maze_column+2]{};
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
		}
	}
	searchPos[0] = {1, 1};
	maze_val[1][1] = 2;
	/*for(int i=0; i<=maze_row+1; i++)
	{
		for(int j=0; j<=maze_column+1; j++)
		{
			cout<<maze_val[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
	return true;
}

bool Maze::printAnswer()
{
	if(BFS()==false)
	{
		cout<<"BFS 에러"<<endl;
	}
	cout<<move_count; 
	
	return true;
}

bool Maze::BFS()
{
	int row;
	int column;
	int frontIndex = 0;
	int rearIndex = 0;
	int nextIndex = 1;
	while(frontIndex < maze_row * maze_column)
	{
		move_count++;
		//cout<<"현재 이동칸개수 : "<<move_count<<endl;
		//printMaze();
		while(frontIndex <= rearIndex)
		{
			row = searchPos[frontIndex].row;
			column = searchPos[frontIndex].column;
			//cout<<"현재 탐색 좌표 : "<<row<<" "<<column<<endl;
			if(row == maze_row && column == maze_column)
			{
				return true;
			}
			if(maze_val[row-1][column] == 1)
			{
				searchPos[nextIndex] = {row-1, column};
				nextIndex++;
				maze_val[row-1][column] = 2;
			}
			if(maze_val[row+1][column] == 1)
			{
				searchPos[nextIndex] = {row+1, column};
				nextIndex++;
				maze_val[row+1][column] = 2;
			}
			if(maze_val[row][column-1] == 1)
			{
				searchPos[nextIndex] = {row, column-1};
				nextIndex++;
				maze_val[row][column-1] = 2;
			}
			if(maze_val[row][column+1] == 1)
			{
				searchPos[nextIndex] = {row, column+1};
				nextIndex++;
				maze_val[row][column+1] = 2;
			}
			frontIndex++;
		}
		rearIndex = nextIndex - 1;
	}
	
	return false;
}

void Maze::printMaze()
{
	for(int i=0; i<=maze_row+1; i++)
	{
		for(int j=0; j<=maze_column+1; j++)
		{
			cout<<maze_val[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
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
