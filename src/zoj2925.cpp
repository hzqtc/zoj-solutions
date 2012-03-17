#include <iostream>
#include <queue>

#define North		'N'
#define South		'S'
#define East		'E'
#define West		'W'
#define NorthEast	'Y'
#define NorthWest	'V'
#define SouthEast	'Q'
#define SouthWest	'J'

// North, South, East, West, NorthEast, NorthWest, SouthEast, SouthWest
//     N,     S,    E,    W,         Y,         V,         Q,         J

using namespace std;

const int DOMINO_MAX = 512;
char domino[DOMINO_MAX][DOMINO_MAX];
int m, n;

struct piece
{
	piece(int a, int b, char c): x(a), y(b), dir(c) {}
	int x, y;
	char dir;
};

void Fall(piece first);

int main()
{
	int i, j;
	char c;
	bool firstCase = true;

	while(cin >> m >> n)
	{
		if(firstCase == true)
			firstCase = false;
		else
			cout << endl;

		for(i = 0; i < m; i++)
			for(j = 0; j < n; j++)
				cin >> domino[i][j];				// this will skip whitespace automaticly

		cin >> i >> j;
		cin >> c;
		Fall(piece(i - 1, j - 1, c));

		for(i = 0; i < m; i++)
		{
			for(j = 0; j < n; j++)
				cout << domino[i][j];
			cout << endl;
		}
	}

	return 0;
}

void Fall(piece first)
{
	queue<piece> q;
	q.push(first);
	while(q.empty() == false)
	{
		int i = q.front().x;
		int j = q.front().y;
		char dir = q.front().dir;
		q.pop();

		if(i >= 0 && i < m && j >= 0 && j < n && domino[i][j] == 'X')
		{
			domino[i][j] = dir;
			switch(dir)
			{
				case North:
					q.push(piece(i - 1, j - 1, NorthWest));
					q.push(piece(i - 1, j, North));
					q.push(piece(i - 1, j + 1, NorthEast));
					break;
				case South:
					q.push(piece(i + 1, j - 1, SouthWest));
					q.push(piece(i + 1, j, South));
					q.push(piece(i + 1, j + 1, SouthEast));
					break;
				case East:
					q.push(piece(i - 1, j + 1, NorthEast));
					q.push(piece(i, j + 1, East));
					q.push(piece(i + 1, j + 1, SouthEast));
					break;
				case West:
					q.push(piece(i - 1, j - 1, NorthWest));
					q.push(piece(i, j - 1, West));
					q.push(piece(i + 1, j - 1, SouthWest));
					break;
				case NorthEast:
					q.push(piece(i - 1, j, North));
					q.push(piece(i - 1, j + 1, NorthEast));
					q.push(piece(i, j + 1, East));
					break;
				case NorthWest:
					q.push(piece(i - 1, j, North));
					q.push(piece(i - 1, j - 1, NorthWest));
					q.push(piece(i, j - 1, West));
					break;
				case SouthEast:
					q.push(piece(i, j + 1, East));
					q.push(piece(i + 1, j + 1, SouthEast));
					q.push(piece(i + 1, j, South));
					break;
				case SouthWest:
					q.push(piece(i, j - 1, West));
					q.push(piece(i + 1, j - 1, SouthWest));
					q.push(piece(i + 1, j, South));
					break;
			}
		}
	}
}
