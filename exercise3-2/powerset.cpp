#include <iostream>

using namespace std;

void printAarr(int arr[], int n, int idx);
void Subsets(int arr[], int n);

int main(int argc, char argv[])
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	Subsets(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}
void Subsets(int arr[], int n) {
	int i, j;
	int sum = 0;
	for (i = 0; i < (1 << n); i++) {
		sum = 0;
		for (j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += arr[j];
			}
		}

		if(sum == 10)
		{
			printAarr(arr, n, i);
		}		
	}
}

void printAarr(int arr[], int n, int idx)
{
	int i;

	for (i = 0; i < n; i++) {
		if (idx & (1 << i)) {
			cout << arr[i] << " ";
		}
	}
	cout << endl;
}



//°á°ú
/*
1 2 3 4
2 3 5
1 4 5
1 3 6
4 6
1 2 7
3 7
2 8
1 9
10
*/