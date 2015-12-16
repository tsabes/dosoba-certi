#include <iostream>

using namespace std;

#define MAX 10
#define ABS(x) ((x > 0) ? (x) : -(x))

typedef struct __node {
	int row;
	int col;
} node;

node solPath[MAX];

bool promising (node v, int size, int idx)
{
	int i;
	bool isPromising = true;


	for (i = 0; i < v.row; i++)
	{
		if (v.col == solPath[i].col)
		{
			isPromising = false;
			break;
		}
	}
	if (isPromising)
	{
		for (i = 0; i < v.row; i++)
		{
			if (ABS(solPath[i].row - v.row) == ABS(solPath[i].col - v.col))
			{
				isPromising = false;
				break;
			}
		}
	}
	return isPromising;
}

void checknode (node v, int size, int idx)
{
	int i;
	if (promising(v, size, idx))
	{
		if(idx == -1)
		{

		}
		if (idx == size - 1)
		{
			for(i = 0; i < size; i++)
			{
				cout << "(" << solPath[i].row << ", " << solPath[i].col << ")" << " ";
			}
			cout << endl;
		}
        else
		{
			for (i = 0; i < size; i++)
			{
				solPath[idx].col = i;
				solPath[idx].row = idx;
				checknode(solPath[idx], size, idx);
			}
		}
	}
}


int main()
{
	int T;
	int i;
	int n;
	node v;

	cin >> T;

	for (i = 0; i < T; i++)
	{
		cin >> n;

		v.row = -1;
		v.col = -1;

		checknode(v, n, -1);		
	}

	return 0;
}