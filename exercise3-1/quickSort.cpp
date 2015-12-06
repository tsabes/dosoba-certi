#include<iostream>

using namespace std;

int partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int i, j;
	int tmp;

	i = left;
	j = right;

	while(i <= j)
	{
		while(arr[i] <= pivot)
		{
			i++;
		}
		while(arr[j] > pivot)
		{
			j--;
		}

		if (i < j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}

	tmp = arr[left];
	arr[left] = arr[j];
	arr[j] = tmp;

	return j;	
}

void quicksort(int arr[], int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}

int main(int argc, char** argv)
{	
	int i;
	int arr1[6] = {11, 45, 23, 81, 28, 34};
	int arr2[10] = {11, 45, 22, 81, 23, 34, 99, 22, 17, 8};
	int arr3[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

	for (i = 0; i < 6; i++)
	{
		cout << arr1[i] << " ";
	}

	cout << endl;

	for (i = 0; i < 10; i++)
	{
		cout << arr2[i] << " ";
	}

	cout << endl;

	for (i = 0; i < 10; i++)
	{
		cout << arr3[i] << " ";
	}

	cout << endl;

	quicksort(arr1, 0, 5);
	quicksort(arr2, 0, 9);
	quicksort(arr3, 0, 9);

	for (i = 0; i < 6; i++)
	{
		cout << arr1[i] << " ";
	}

	cout << endl;

	for (i = 0; i < 10; i++)
	{
		cout << arr2[i] << " ";
	}

	cout << endl;

	for (i = 0; i < 10; i++)
	{
		cout << arr3[i] << " ";
	}

	cout << endl;

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}