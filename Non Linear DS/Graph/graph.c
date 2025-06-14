#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int numNodes;
int visited[MAX_NODES];

void addEdge(int from, int to, int weight) {
    graph[from][to] = weight;
    graph[to][from] = weight;
}

void initializeGraph() {
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter the edges in the graph (from to weight, -1 to stop): \n");
    int from, to, weight;
    while(1) {
        scanf("%d %d %d", &from, &to, &weight);
        if (from == -1 || to == -1 || weight == -1) break;
        addEdge(from, to, weight);
    }
}

void adjacencyMatrix() {
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%d  ", graph[i][j]);
        }
        printf("\n");
    }
}

void bfs(int startNode) {
    int queue[MAX_NODES], front = 0, rear = 0;

    queue[rear++] = startNode;
    visited[startNode] = 1;

    printf("BFS Traversal: ");
    while (front < rear) {
        int currentNode = queue[front++];
        printf("%d -> ", currentNode);

        for (int i = 0; i < numNodes; i++) {
            if (graph[currentNode][i] = 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\b\b\b\b    \n");
}

void dfs(int currentNode) {
    visited[currentNode] = 1;
    printf("%d -> ", currentNode);

    for (int i = 0; i < numNodes; i++) {
        if (graph[currentNode][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int findMinDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < numNodes; v++) {
        if(sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        return;
    }
    printPath(parent, parent[j]);
    printf("%d -> ", j);
}

void dijkstra(int startNode)  {
    int dist[MAX_NODES];
    int sptSet[MAX_NODES];
    int parent[MAX_NODES];

    for (int i = 0; i < numNodes; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[startNode] = 0;

    for (int count = 0; count < numNodes - 1; count++) {
        int u = findMinDistance(dist, sptSet);

        sptSet[u] = 1;

        for (int v = 0; v < numNodes; v++) {
            if (graph[u][v] && !sptSet[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 0; i < numNodes; i++) {
        printf("%d -> ", startNode);
        printPath(parent, i);
        printf("\b\b\b\b    \n");
    }
}

int main() {
    int choice, startNode;

    initializeGraph();

    do {
        printf("\nGraph Operations Menu:\n");
        printf("1. Adjacency Matrix\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Dijkstra's SPT\n");
        printf("0. Exit\n");
    
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adjacencyMatrix(numNodes);
                break;

            case 2:
                printf("Enter the starting node for BFS: ");
                scanf("%d", &startNode);
                for (int i = 0; i < numNodes; i++) {
                    visited[i] = 0;
                }
                bfs(startNode);
                break;

            case 3:
                printf("Enter the starting node for DFS: ");
                scanf("%d", &startNode);
                for (int i = 0; i < numNodes; i++) {
                    visited[i] = 0;
                }
                printf("DFS Traversal: ");
                dfs(startNode);
                break;

            case 4:
                printf("Enter the starting node for Dijkstra's Algorithm: ");
                scanf("%d", &startNode);
                dijkstra(startNode);
                break;
            
            case 0:
                printf("Exiting program. GoodBye!\n");
                break;

            default:
                printf("Invalid Choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

/*
4
0 1 1
0 2 1
1 2 1
2 3 1
-1 -1 -1

BFS, DFS

10
0 1 1
0 2 1
1 3 1
1 4 1
2 5 1
2 6 1
3 7 1
4 7 1
5 8 1
6 8 1
7 9 1
8 9 1
3 5 1
4 6 1
1 2 1
0 3 1
6 9 1
-1 -1 -1

for dijkstra

0 1 4
0 2 3
1 2 1
1 3 2
2 3 4
3 4 2
4 5 6
-1 -1 -1

*/