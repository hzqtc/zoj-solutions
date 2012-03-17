#include <iostream>
#include <string>

using namespace std;

void list_tree(const string& preorder, const string& inorder);

int main()
{
	string preorder_tree, inorder_tree;

	while(cin >> preorder_tree >> inorder_tree)
	{
		list_tree(preorder_tree, inorder_tree);
		cout << endl;
	}

	return 0;
}

void list_tree(const string& preorder, const string& inorder)
{
	if(preorder.length() > 1)
	{
		char root = preorder[0];
		int pos = inorder.find(root);

		string left_in = inorder.substr(0, pos);
		string right_in = inorder.substr(pos + 1, inorder.length() - pos - 1);
		string left_pre = preorder.substr(1, pos);
		string right_pre = preorder.substr(1 + pos, preorder.length() - pos - 1);

		list_tree(left_pre, left_in);
		list_tree(right_pre, right_in);
		cout.put(root);
	}
	else if(preorder.length() == 1)
		cout.put(preorder[0]);
}
