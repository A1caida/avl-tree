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

int blheight(owo*& root)
{
	if (root == NULL){ return -1; }
	else { return root->height;	}
}

owo* rrs(owo*& root)//правый поворот
{
	owo* root1;
	root1 = root->right;//root1=3
	root->right = root1->left;//right = 0
	root1->left = root;//root1->left = 2
	root->height = max(blheight(root->left), blheight(root->right)) + 1;
	root1->height = max(root->height, root->height) + 1;
	return root1;
}

owo* lls(owo*& root)//левый поворот
{
	owo* root1;
	root1 = root->left;//root1=1
	root->left = root1->right;//right = 0
	root1->right = root;//root1->left = 2
	root->height = max(blheight(root->left), blheight(root->right)) + 1;
	root1->height = max(blheight(root1->left), root->height) + 1;
	return root1;
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
			if ((blheight(root->left) - blheight(root->right)) == 2)
			{
				root = lls(root);
			}

		}
		else if (x > root->elem)
		{
			
			insert(root->right, x);
			if ((blheight(root->right) - blheight(root->left)) == 2)
			{
				root = rrs(root);
			}
		}
	}
	
	root->height = max(blheight(root->left), blheight(root->right)) + 1;
}

void print_Tree(owo*& root, int level)
{
	if (root)
	{
		print_Tree(root->right, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << root->elem <<"("<< root->height<<")"<< endl;
		print_Tree(root->left, level + 1);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	owo* root = NULL;
	int a, level = 0;
	for (size_t i = 0; i < 10; i++)
	{
		cout << "dsfdsf" << endl;
		cin >> a;
		insert(root, a);
	}
	print_Tree(root, a);


}

