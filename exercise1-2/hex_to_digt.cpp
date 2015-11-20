/*
6
0x0 0xF 0x9 0x7 0xA 0x3
7, 101, 116, 3
*/

#include<iostream>

using namespace std;

int exp(int a, int b)
{
	if (b == 0)
		return 1;
	else
		return a * exp(a, b-1);
}

int main(int argc, char** argv)
{	
    //freopen("sample_input.txt", "r", stdin);

	int numBit = 0;
	int T;
	int num;
	int div;
	int arr[100];
	int subArr[7];
	int i, j;
	int NUMHEX;

	cin >> NUMHEX;
	
	for( i = 0; i < NUMHEX; i++)
	{
		cin >> hex >> T;
		switch (T)
		{
		case 0x0: 
			{
				arr[numBit] = 0;
				arr[numBit+1] = 0;
				arr[numBit+2] = 0;
				arr[numBit+3] = 0;
				numBit += 4;
			}
			break;
		case 0x1: 
			{
				arr[numBit] = 0;
				arr[numBit+1] = 0;
				arr[numBit+2] = 0;
				arr[numBit+3] = 1;
				numBit += 4;
			}
			break;
		case 0x2: 
			{
				arr[numBit] = 0;
				arr[numBit+1] = 0;
				arr[numBit+2] = 1;
				arr[numBit+3] = 0;
				numBit += 4;
			}
			break;
		case 0x3: 
			{
				arr[numBit] = 0;
				arr[numBit+1] = 0;
				arr[numBit+2] = 1;
				arr[numBit+3] = 1;
				numBit += 4;
			}
			break;
		case 0x4:
			{
				arr[numBit] = 0;
				arr[numBit+1] = 1;
				arr[numBit+2] = 0;
				arr[numBit+3] = 0;
				numBit += 4;
			}
			break;
		case 0x5:
			{
				arr[numBit] = 0;
				arr[numBit+1] = 1;
				arr[numBit+2] = 0;
				arr[numBit+3] = 1;
				numBit += 4;
			}
			break;
		case 0x6:
			{
				arr[numBit] = 0;
				arr[numBit+1] = 1;
				arr[numBit+2] = 1;
				arr[numBit+3] = 0;
				numBit += 4;
			}
			break;
		case 0x7:
			{
				arr[numBit] = 0;
				arr[numBit+1] = 1;
				arr[numBit+2] = 1;
				arr[numBit+3] = 1;
				numBit += 4;
			}
			break;
		case 0x8:
			{
				arr[numBit] = 1;
				arr[numBit+1] = 0;
				arr[numBit+2] = 0;
				arr[numBit+3] = 0;
				numBit += 4;
			}
			break;
		case 0x9:
			{
				arr[numBit] = 1;
				arr[numBit+1] = 0;
				arr[numBit+2] = 0;
				arr[numBit+3] = 1;
				numBit += 4;
			}
			break;
		case 0xA:
			{
				arr[numBit] = 1;
				arr[numBit+1] = 0;
				arr[numBit+2] = 1;
				arr[numBit+3] = 0;
				numBit += 4;
			}
			break;
		case 0xB:
			{
				arr[numBit] = 1;
				arr[numBit+1] = 0;
				arr[numBit+2] = 1;
				arr[numBit+3] = 1;
				numBit += 4;
			}
			break;
		case 0xC:
			{
				arr[numBit] = 1;
				arr[numBit+1] = 1;
				arr[numBit+2] = 0;
				arr[numBit+3] = 0;
				numBit += 4;
			}
			break;
		case 0xD:
			{
				arr[numBit] = 1;
				arr[numBit+1] = 1;
				arr[numBit+2] = 0;
				arr[numBit+3] = 1;
				numBit += 4;
			}
			break;
		case 0xE:
			{
				arr[numBit] = 1;
				arr[numBit+1] = 1;
				arr[numBit+2] = 1;
				arr[numBit+3] = 0;
				numBit += 4;
			}
			break;
		case 0xF:
			{
				arr[numBit] = 1;
				arr[numBit+1] = 1;
				arr[numBit+2] = 1;
				arr[numBit+3] = 1;
				numBit += 4;
			}
			break;
		default:
			break;
		}
	}

	num = 0;
	div = 6;		

	for(i = 0; i < numBit; i++)
	{
		subArr[i%7] = arr[i];

		if(arr[i] == 1)
			num += exp(2, div);

		div--;

		if((i % 7) == 6)
		{
			cout << num << endl;
			num = 0;
			div = 6;
			for (j = 0; j < 6; j++)
			{
				subArr[j] = 0;
			}
		}		
	}
	
	if (numBit % 7 != 0)
	{
		num = 0;
		for(j = (numBit % 7 - 1); j >= 0 ; j--)
		{
			if(subArr[j] == 1)
				num += exp(2, ((numBit % 7 - 1) - j));			
		}
		cout << num << endl;
		
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}