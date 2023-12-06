#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct tree
{
	int x;
	tree* l;
	tree* r;
};
void Add(int x, tree** Node)
{
	if ((*Node == NULL))
	{
		(*Node) = new tree;
		(*Node)->l = (*Node)->r = NULL;
		(*Node)->x = x;
	}
	else
		if ((*Node)->l == NULL)
			Add(x, &(*Node)->l);
		else Add(x, &(*Node)->r);
}
void print(tree* Node)
{
	if (Node == NULL) return;
	cout << Node->x << " ";
	print(Node->l);
	print(Node->r);
}
void printInorder(struct tree* node)
{
	if (node == NULL)
		return;

	// First recur on left child
	printInorder(node->l);

	// Then print the data of node
	cout << node->x << " ";

	// Now recur on right child
	printInorder(node->r);
}
int main()
{
	srand(time(NULL));
	int i, N, showing;
	tree* head = NULL;
	do {
		cout << "Count of elements (0 <= N <= 100): ";
		cin >> N;
	} while (N > 101 || N < -1);
	cout << " random numbers: ";
	for (i = 0; i < N; i++)
	{
		showing = rand() % 201 - 100;
		cout << showing << " ";
		Add(showing, &head);
	}
	cout << "\nTree Inorder Traversal:";
	printInorder(head);
	delete[] head;
	return 0;
}
