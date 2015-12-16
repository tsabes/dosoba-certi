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

	for (i = 0; i < v.row; i++) {
		if (v.col == solPath[i].col) {
			isPromising = false;
			break;
		}
	}
	if (isPromising) {	
		for (i = 0; i < v.row; i++) {
			if (ABS(solPath[i].row - v.row) == ABS(solPath[i].col - v.col)) {
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
        if (idx == size - 1)
		{
			for(i = 1; i < size; i++)
			{
				cout << "(" << solPath[i].row << ", " << solPath[i].col << ")" << " ";
			}
			cout << endl;
		}
         
        else 
		{
            for (i = 0; i < size; i++) {
				solPath[idx+1].col = i;
				solPath[idx+1].row = idx + 1;
				checknode(solPath[idx+1], size, idx+1);
            }
		}
	}
}


int main() {
	int T;
	int i, j;
	int n;
	node v;

	cin >> T;

	for (i = 0; i < T; i++)
	{
		cin >> n;

		v.row = 0;
		v.col = 0;

		checknode(v, n, 0);		
	}

	return 0;
}