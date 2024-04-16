#include<iostream>
using namespace std;

# define MAX 100
# define initial 1
#define waiting 2
#define visited 3

int n; // Number of vertices in the graph
int adj[MAX][MAX]; // Adjacency matrix to represent the graph
int state[MAX]; // Array to track the state of each vertex during BFS traversal

// Function prototypes
void create_graph();
void BF_Traversal();
void BFS(int v);
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

int queue[MAX], front = -1, rear = -1; // Queue for BFS traversal

int main() {
    create_graph();
    BF_Traversal();
    return 0;
}

// Function to create a graph
void create_graph() {
    int max_e, i, origin, destination, j;
    cout << "Enter number of vertices in the graph: ";
    cin >> n;
    max_e = n * (n - 1);
    for (i = 0; i < max_e; i++) {
        cout << "Enter the origin and destination of edge " << i + 1 << ": ";
        cin >> origin >> destination;
        adj[origin][destination] = 1;
    }
    // Print the adjacency matrix
    cout << "Adjacency matrix of the graph:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << adj[i][j] << "  ";
        }
        cout << endl;
    }
}

// Function to perform breadth-first traversal
void BF_Traversal() {
    int v;
    // Initialize all vertices to initial state
    for (v = 0; v < n; v++)
        state[v] = initial;
    cout << "Enter starting vertex for breadth-first search: ";
    cin >> v;
    BFS(v);
}

// Breadth-first search algorithm
void BFS(int v) {
    int i;
    insert_queue(v); // Insert the starting vertex into the queue
    state[v] = waiting; // Update its state to waiting
    while (!isEmpty_queue()) {
        v = delete_queue(); // Remove a vertex from the queue
        cout << v; // Print the visited vertex
        state[v] = visited; // Update its state to visited
        // Explore adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && state[i] == initial) {
                insert_queue(i); // Insert adjacent vertex into the queue
                state[i] = waiting; // Update its state to waiting
            }
        }
    }
    cout << endl;
}

// Function to insert an item into the queue
void insert_queue(int vertex) {
    if (rear == MAX - 1)
        cout << "Queue is overflow" << endl;
    else {
        if (front == -1)
            front = 0;
        rear += 1;
        queue[rear] = vertex;
    }
}

// Function to check if the queue is empty
int isEmpty_queue() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

// Function to delete an item from the queue
int delete_queue() {
    int del_item;
    if (front == -1 || front > rear) {
        cout << "Queue is underflow" << endl;
        exit(1);
    }
    del_item = queue[front];
    front += 1;
    return del_item;
}


/*
Output:-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 9.bfs.cpp
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ ./a.out
Enter number of vertices in the graph: 3
Enter the origin and destination of edge 1: 0 0
Enter the origin and destination of edge 2: 0 1
Enter the origin and destination of edge 3: 0 2
Enter the origin and destination of edge 4: 1 1
Enter the origin and destination of edge 5: 1 2
Enter the origin and destination of edge 6: 2 0
Adjacency matrix of the graph:
1  1  1  
0  1  1  
1  0  0  
Enter starting vertex for breadth-first search: 0
012
*/
