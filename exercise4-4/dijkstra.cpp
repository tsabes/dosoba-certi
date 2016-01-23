#include <iostream>

using namespace std;

#define MAXIMUM(x, y) ((x>y)?(x):y)
#define MINIMUM(x, y) ((x>y)?(y):x)

#define INFINITY 9999999
#define MAX 10

int tr_atoi (char a);
char tr_itoa (int a);

int main()
{
    freopen("sample_input.txt", "r", stdin);

    int T;
    int i, j;
    char from_char, to_char;
    int from_int, to_int;
    int weight;
    int graph[MAX][MAX];
    int num_vertex, num_path;
    int path[MAX];
    int distance[MAX];
    int min_vertex, min_distance;
    int value;

    // init start
    for (i = 0; i < MAX; i++)    
    	for (j = 0; j < MAX; j++)
    		graph[i][j] = INFINITY;

    num_vertex = 0;
    num_path = 0;
    value = 0;
    min_distance = INFINITY;    

    for (i = 0; i < MAX; i++)
    {
        path[i] = 0;
        distance[i] = 0;
    }    

    cin >> T;

    for (i = 0; i < T; i++)
    {
    	cin >> from_char;
    	cin >> to_char;
    	cin >> weight;

    	from_int = tr_atoi(from_char);
    	to_int = tr_atoi(to_char);

    	graph[from_int][to_int] = weight;
        num_vertex = MAXIMUM(num_vertex, from_int);
    }
    // init end

    // Dijkstra module start

    path[1] = 1;
    num_path++;

    for (i = 1; i <= num_vertex; i++)
    {
        distance[i] = graph[path[1]][i];
    }

    for (i = 1; i <= num_vertex; i++)
    {
        if (MINIMUM(min_distance, distance[i]) == distance[i])
        {
            min_distance = distance[i];
            min_vertex = i;
        }
    }

    while (num_path < num_vertex)
    {
        path[++num_path] = min_vertex;
        
        for (i = 1; i <= num_vertex; i++)
        {
            
        }
    }

    // Dijkstra module end
    
    cout << "path : ";
    for (i = 1; i <= num_vertex; i++)
    {
        cout << tr_itoa(path[i]) << " ";
    }
    cout << endl;
    cout << "weight : " << value << endl;

    return 0;
}

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

char tr_itoa (int a)
{
	char result;
	switch(a)
    {
    	case 1:
    	result = 'a';
    	break;
    
    	case 2:
    	result = 'b';
    	break;
    
    	case 3:
    	result = 'c';
    	break;
    
    	case 4:
    	result = 'd';
    	break;
    
    	case 5:
    	result = 'e';
    	break;
    
    	case 6:
    	result = 'f';
    	break;
    
    	case 7:
    	result = 'g';
    	break;
    
    	case 8:
    	result = 'h';
    	break;
    
    	case 9:
    	result = 'i';
    	break;
    
    	default:
    	break;
    }

    return result;
}