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
	int idx_i;
	bool result = true;

	if (v.row == -1) {
		return result;
	}
	// check vertical line
	for (idx_i = 0; idx_i < v.row; idx_i++) {
		if (v.col == solPath[idx_i].col) {
			result = false;
			break;
		}
	}
	if (result) {
		// check diagonal lines(right, left)
		for (idx_i = 0; idx_i < v.row; idx_i++) {
			if (ABS(solPath[idx_i].row - v.row) == ABS(solPath[idx_i].col - v.col)) {
				result = false;
				break;
			}
		}
	}

	return result;
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