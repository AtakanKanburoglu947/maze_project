#include <iostream>
#include <Windows.h>
#include <stack>
#include <locale.h>
using namespace std;

#define col 7
#define row 3

struct point {
	int x, y;
};

int main() {
	setlocale(LC_ALL, "Turkish");

	char maze[row][col] =
	{
		"# ####",
		"#    #",
		"#### #",
	};

	stack<point> stack;
	point entrance, exit;

	entrance.x = 0; entrance.y = 1;
	exit.x = 2; exit.y = 4;

	point currentPoint;
	currentPoint = entrance;

	char explored = '*';
	char wall = '#';
	char road = ' ';


	char tempMaze[row][col];
	char displayMaze[row][col];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			tempMaze[i][j] = maze[i][j];
			displayMaze[i][j] = maze[i][j];
		}
	}

	while (true)
	{
		if (currentPoint.x == exit.x && currentPoint.y == exit.y)
		{
			break;
		}
		char up = tempMaze[currentPoint.x - 1][currentPoint.y];
		char down = tempMaze[currentPoint.x + 1][currentPoint.y];
		char right = tempMaze[currentPoint.x][currentPoint.y + 1];
		char left = tempMaze[currentPoint.x][currentPoint.y - 1];



		if (up == road)
		{
			stack.push(currentPoint);
			tempMaze[currentPoint.x][currentPoint.y] = explored;
			currentPoint.x--;
		}

		else if ((down == road))
		{
			stack.push(currentPoint);
			tempMaze[currentPoint.x][currentPoint.y] = explored;
			currentPoint.x++;
		}
		else if ((right == road))
		{
			stack.push(currentPoint);
			tempMaze[currentPoint.x][currentPoint.y] = explored;
			currentPoint.y++;
		}
		else if ((left == road))
		{
			stack.push(currentPoint);
			tempMaze[currentPoint.x][currentPoint.y] = explored;
			currentPoint.y--;
		}
		else {
			tempMaze[currentPoint.x][currentPoint.y] = wall;
			currentPoint = stack.top();
			stack.pop();
		}


	}

	int size = stack.size();
	point* path = new point[row * col];
	for (int i = size - 1; i >= 0; i--)
	{
		path[i] = stack.top();
		stack.pop();
	}

	for (int i = 0; i < size; i++)
	{

		point tempPoint = path[i];
		displayMaze[tempPoint.x][tempPoint.y] = '*';
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << displayMaze[i][j];
			}
			cout << endl;
		}
		Sleep(200);
		system("cls");
		displayMaze[tempPoint.x][tempPoint.y] = ' ';

	}

	maze[exit.x][exit.y] = '*';
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << maze[i][j];
		}
		cout << endl;

	}
	cout << "Çýkýþ yapýldý" << endl;
}