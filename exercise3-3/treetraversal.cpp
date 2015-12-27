#include <iostream>

using namespace std;

#define MAX 100

struct _node{
	int data;
	int left;
	int right;
} typedef node;

void preorder(node arr[], int idx)
{
	if(arr[idx].data == 0)
		return;

	cout << arr[idx].data << " " ;
	preorder(arr, arr[idx].left);
	preorder(arr, arr[idx].right);
}

void inorder(node arr[], int idx)
{	
	if(arr[idx].data == 0)
		return;

	inorder(arr, arr[idx].left);
	cout << arr[idx].data << " " ;
	inorder(arr, arr[idx].right);
}

void postorder(node arr[], int idx)
{
	if(arr[idx].data == 0)
		return;

	postorder(arr, arr[idx].left);
	postorder(arr, arr[idx].right);
	cout << arr[idx].data << " " ;
}

int main()
{
	freopen("sample_input.txt", "r", stdin);

	int T;
	int i;
	int tmp1, tmp2;
	node tmpNode;
	node treeArr[MAX] = {0,};

	cin >> T;

	for ( i = 1; i <= T; i++)
	{
		cin >> tmp1;
		cin >> tmp2;
		
		tmpNode.data = tmp1;
		tmpNode.left = 0;
		tmpNode.right = 0;

		if(treeArr[tmp1].data == 0) {
			treeArr[tmp1].data = tmpNode.data;
			treeArr[tmp1].left = tmpNode.left;
			treeArr[tmp1].right = tmpNode.right;
        }

		tmpNode.data = tmp2;
		tmpNode.left = 0;
		tmpNode.right = 0;

		if(treeArr[tmp2].data == 0) {
			treeArr[tmp2].data = tmpNode.data;
			treeArr[tmp2].left = tmpNode.left;
			treeArr[tmp2].right = tmpNode.right;
        }


		if(treeArr[tmp1].left == 0)
		{
			treeArr[tmp1].left = tmp2;
		}
		else if(treeArr[tmp1].right == 0)
		{
			treeArr[tmp1].right = tmp2;
		}
	}

	cout << "preorder : " << " ";
	preorder(treeArr, 1);
	cout << endl;
	cout << "inorder : " << " ";
	inorder(treeArr, 1);
	cout << endl;
	cout << "postorder : " << " ";
	postorder(treeArr, 1);
	cout << endl;

	return 0;
}

/*
result
preorder :  1 2 4 7 12 3 5 8 9 6 10 11 13
inorder :  12 7 4 2 1 8 5 9 3 10 6 13 11
postorder :  12 7 4 2 8 9 5 10 13 11 6 3 1
계속하려면 아무 키나 누르십시오 . . .
*/