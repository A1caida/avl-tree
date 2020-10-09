#include <iostream>
#include <ctime>

using namespace std;

struct owo
{
	int elem;
	owo* left;
	owo* right;
	int height;
};

int max(int Kurisu, int Maki)
{
	return((Kurisu > Maki) ? Kurisu : Maki);
}

void insert(owo*& root, int x)
{
	if (root == NULL)
	{
		root = new owo;
		root->elem = x;
		root->left = NULL;
		root->right = NULL;
		root->height = 0;
	}
	else
	{
		if (x < root->elem)
		{
			insert(root->left, x);

		}
		else if (x > root->elem)
		{
			insert(root->right, x);
		}
	}
}

void print_Tree(owo*& node, int level)
{
	if (node)
	{
		print_Tree(node->right, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << node->elem << endl;
		print_Tree(node->left, level + 1);
	}
}

int main()
{
	owo* root = NULL;
	int a;
	for (size_t i = 0; i < 5; i++)
	{
		cout << "dsfdsf" << endl;
		cin >> a;
		insert(root, a);
	}
	print_Tree(root, a);


}

