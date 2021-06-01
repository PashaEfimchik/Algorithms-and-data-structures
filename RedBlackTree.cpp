#include <iostream>
#include "RedBlackTree.h"
using namespace std;

void menu(RedBlackTree<int> RBTree);
void askForMenu(RedBlackTree<int> RBTree);
void insert(RedBlackTree<int> RBTree);
void remove(RedBlackTree<int> RBTree);
void search(RedBlackTree<int> RBTree);
void destroyTree(RedBlackTree<int> RBTree);
void print(RedBlackTree<int> RBTree);

void askForMenu(RedBlackTree<int> RBTree)
{
	char ch = '\0';
	cin.ignore();
	cout << "\nDo you want to go back to the menu? Y/N: ";
	cin.get(ch);
	if (ch == 'y' || ch == 'Y')
		menu(RBTree);
	else
		exit(0);
	cin.ignore();
}

void insert(RedBlackTree<int> RBTree)
{
	unsigned int size = 0;
	int val = 0;
	system("CLS");
	cout << "\nInserting Value\n";
	cout << "1. Manual insert\n2. Auto insert" << endl;
	int k = 0;
	cin >> k;
	double timee = 0;
	if (k == 1) {
		system("CLS");
		cout << "Enter the number of values: ";
		cin >> size;
		cout << "\nEnter the values:\n";
		for (int i = 0; i < size; i++) {
			cin >> val;
			RBTree.insert(val);
		}
	}
	else if (k == 2) {
		system("CLS");
		cout << "Enter number of num: ";
		cin >> size;
		srand(time(0));
		clock_t start = clock();
		for (int i = 0; i < size; i++) {
			RBTree.insert(i);
		}
		clock_t end = clock();
		timee = (double)(end - start) / CLOCKS_PER_SEC;
	}
	system("CLS");
	cout << endl;
	cout << "\nTime of inserting: " << timee << " seconds";
	cout << "\nValues have been inserted\n";
	cout << endl;
	askForMenu(RBTree);
}

void remove(RedBlackTree<int> RBTree)
{
	int val = 0;

	system("CLS");
	cout << "\nDeleting Value\n";
	cout << "Enter the value to delete: ";
	cin >> val;
	system("CLS");
	cout << endl;
	RBTree.remove(val);
	cout << endl;
	RBTree.print();
	askForMenu(RBTree);
}

void search(RedBlackTree<int> RBTree)
{
	int val = 0;
	system("CLS");
	cout << "\nSearching Value\n";
	cout << "Enter the value to find: ";
	cin >> val;
	system("CLS");
	cout << endl;
	RBTree.search(val);
	cout << endl;
	RBTree.print();

	askForMenu(RBTree);
}

void destroyTree(RedBlackTree<int> RBTree)
{
	system("CLS");
	cout << endl;
	cout << "\tRed Black Tree Destroyed!\n";
	cout << endl;
	RBTree.~RedBlackTree();
	askForMenu(RBTree);
}

void print(RedBlackTree<int> RBTree)
{
	system("CLS");
	cout << endl;
	RBTree.print();
	cout << endl;
	askForMenu(RBTree);
}

void menu(RedBlackTree<int> RBTree)
{
	system("CLS");
	int ch = 0;
	cout << "\n1. Insert a Value\n";
	cout << "2. Delete a Value\n";
	cout << "3. Search for a Value\n";
	cout << "4. Destroy the Tree\n";
	cout << "5. Print Red Black Tree\n";
	cout << "6. Exit the Program\n";
	
	cout << "\nEnter your option: ";
	cin >> ch;
	switch (ch) {
	case 1:
		insert(RBTree);
		break;
	case 2:
		remove(RBTree);
		break;
	case 3:
		search(RBTree);
		break;
	case 4:
		destroyTree(RBTree);
		break;
	case 5:
		print(RBTree);
		break;
	default:
		exit(0);
		break;
	}
}

int main()
{
	RedBlackTree<int> RBTree;
	menu(RBTree);
	return 0;
}
