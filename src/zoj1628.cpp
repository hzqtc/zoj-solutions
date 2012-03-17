#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Diamond
{
public:
	friend istream& operator>>(istream& instream, Diamond& d)
	{
		d.matrix.clear();
		for(int i = 0; i < 8; i++)
		{
			string s = "";
			instream >> s;
			d.matrix.push_back(s);
		}
		return instream;
	}

	bool SwapElement(int row1, int col1, int row2, int col2)
	{
		if((row1 == row2 && abs(col1 - col2) == 1) || (col1 == col2 && abs(row1 - row2) == 1))
		{
			char c = matrix[row1][col1];
			matrix[row1][col1] = matrix[row2][col2];
			matrix[row2][col2] = c;
			return true;
		}
		else
			return false;
	}

	bool Valid()
	{
		for(int i = 0; i < 8; i++)
		{
			for(int j = 0; j < 6; j++)
			{
				if(matrix[i][j] == matrix[i][j + 1] && matrix[i][j] == matrix[i][j + 2])
					return true;
				else if(matrix[j][i] == matrix[j + 1][i] && matrix[j][i] == matrix[j + 2][i])
					return true;
			}
		}

		return false;
	}
private:
	vector<string> matrix;
};

int main()
{
	Diamond foo;
	while(cin >> foo)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		if(foo.SwapElement(r1, c1, r2, c2) && foo.Valid())
			cout << "Ok!" << endl;
		else
			cout << "Illegal move!" << endl;
	}
}
