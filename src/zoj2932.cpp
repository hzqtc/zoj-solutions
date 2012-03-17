#include <iostream>
#include <string>

using namespace std;

class URI
{
public:
	URI(): uri("") {}

	URI(const string& s): uri(s) {}

	friend string operator>>(istream& i, URI& u)
	{
		string s;
		getline(i, s);
		u.uri = s;
		u.Encode();
		return s;
	}

	friend ostream& operator<<(ostream& o, URI& u)
	{
		o << u.uri;
		return o;
	}
private:
	void Encode()
	{
		string newstr = "";
		for(int i = 0; i < uri.length(); i++)
		{
			switch(uri[i])
			{
				case ' ':
					newstr += "%20";
					break;
				case '!':
					newstr += "%21";
					break;
				case '$':
					newstr += "%24";
					break;
				case '%':
					newstr += "%25";
					break;
				case '(':
					newstr += "%28";
					break;
				case ')':
					newstr += "%29";
					break;
				case '*':
					newstr += "%2a";
					break;
				default:
					newstr += uri[i];;
					break;
			}
		}
		uri = newstr;
	}
	string uri;
};

int main()
{
	URI u;
	while((cin >> u) != "#")
		cout << u << endl;

	return 0;
}

