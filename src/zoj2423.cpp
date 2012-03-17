#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Box
{
	vector<string> data;
};

ostream& operator<<(ostream& o, const Box& b)
{
	for(vector<string>::const_iterator iter = b.data.begin(); iter != b.data.end(); iter++)
		o << *iter << endl;
	return o;
}

Box boxes[7];

void GenBoxes()
{
	boxes[0].data.push_back("X");
	for(int i = 1; i < 7; i++)
	{
		int width = boxes[i - 1].data[0].length();
		int height = boxes[i - 1].data.size();
		for(int j = 0; j < height; j++)
			boxes[i].data.push_back
			(
				boxes[i - 1].data[j] +
				string(width * 2 - boxes[i - 1].data[j].length(), ' ') +
				boxes[i - 1].data[j]
			);
		for(int j = 0; j < height; j++)
			boxes[i].data.push_back(string(width, ' ') + boxes[i - 1].data[j]);
		for(int j = 0; j < height; j++)
			boxes[i].data.push_back
			(
				boxes[i - 1].data[j] +
				string(width * 2 - boxes[i - 1].data[j].length(), ' ') +
				boxes[i - 1].data[j]
			);
	}
}

int main()
{
	GenBoxes();
	int size;
	while(cin >> size, size > 0)
		cout << boxes[size - 1] << '-' << endl;
	return 0;
}
