#include <iostream>

using namespace std;

#define INFINITY 9999999
#define MAX 10

int tr_atoi (char a)
{
	int result;
	switch(a)
    {
    	case 'a':
    	result = 1;
    	break;
    
    	case 'b':
    	result = 2;
    	break;
    
    	case 'c':
    	result = 3;
    	break;
    
    	case 'd':
    	result = 4;
    	break;
    
    	case 'e':
    	result = 5;
    	break;
    
    	case 'f':
    	result = 6;
    	break;
    
    	case 'g':
    	result = 7;
    	break;
    
    	case 'h':
    	result = 8;
    	break;
    
    	case 'i':
    	result = 9;
    	break;
    
    	default:
    	break;
    }

    return result;
}

int main()
{
    freopen("sample_input.txt", "r", stdin);

    int T;
    int i, j;
    char from_char, to_char;
    int from_int, to_int;
    int weight;
    int graph[MAX][MAX];

    //initialize
    for (i = 0; i < MAX; i++)    
    	for (j = 0; j < MAX; j++)
    		graph[i][j] = INFINITY;

    cin >> T;

    for (i = 0; i < T; i++)
    {
    	cin >> from_char;
    	cin >> to_char;
    	cin >> weight;

    	from_int = tr_atoi(from_char);
    	to_int = tr_atoi(to_char);

    	graph[from_int][to_int] = weight;
    }

    for (i = 1; i < MAX; i++)
    {
    	for (j = 1; j < MAX; j++)
    		cout << graph[i][j] << " ";

    	cout << endl;
    }

}
