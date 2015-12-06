#include <iostream>

using namespace std;

int* selectSort(int *arr, int size)
{
	int n = size;
	int i;
	int* tmpArr;
	int min;
	int tmp;
		
	if (size == 1)
		return arr;
	else
	{
		min = 0;
		for( i = 0; i < n; i++)
		{
			if(arr[i] < arr[min])
			{
				min = i;
			}
		}

		tmp = arr[0];
		arr[0] = arr[min];
		arr[min] = tmp;

		tmpArr = arr+1;

		return selectSort(tmpArr, n-1);
	}
	
}

int main()
{
	int n;
	int i;
	int list[] = {3, 2, 4, 6, 9, 1, 8, 7, 5};
	int *afterArr;

	n = 9;

	cout << "before: " ;
	for (int i = 0; i < n; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;

	afterArr = selectSort(list, n);

	cout << "after: " ;
	for (int i = 0; i < n; i++)
	{
		cout << afterArr[i] << " ";
	}
	cout << endl;

	return 0;
}