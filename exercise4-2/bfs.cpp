/*
input :
1 2 1 3 2 4 2 5 4 6 5 6 6 7 3 7
*/
#include <iostream>

#define MAX 10

using namespace std;

int main() {
    
    freopen("sample_input.txt", "r", stdin);

    int queue[MAX] = {0, };
    int visited[MAX] = {0, };
    int graph[MAX][MAX];
    int T;
    int i, j;
    int from, to;
    int head, tail;
    int vertex;
    int source, target;

    //initialize
    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; j++){
            graph[i][j] = 0;
        }
    }

    cin >> T;

    for (i = 0; i < T; i++){
        cin >> from;
        cin >> to;
        graph[from][to] = 1;
    }

    //BFS module start; G: graph[][] v: vertex(1)

    head = tail = 0;
    vertex = 1;
    queue[head] = vertex;
    head++;
    visited[vertex] = 1;

    while (head != tail) {
        source = queue[tail];
        cout << source << " ";
        tail++;

        for (i = 1; i <= MAX; i++) {
            if (graph[source][i] == 1) {
                target = i;
                if (visited[target] == 0) {
                    queue[head % MAX] = target;
                    head++;
                    visited[target] = 1;
                }
            }
        }
    }
    cout << endl;
    //BFS module end;
}

/*
output :
1 2 3 4 5 7 6
계속하려면 아무 키나 누르십시오 . . .
*/
