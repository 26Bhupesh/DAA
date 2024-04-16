#include <iostream>
using namespace std;

#define max 100
#define initial 1
#define visited 2

int n; // Number of vertices in the graph
int adj[max][max]; // Adjacency matrix to represent the graph
int state[max]; // Array to track the state of each vertex during DFS traversal

// Function prototypes
void create_graph();
void df_traversal();
void dfs(int v);
void push(int v);
int pop();
int isEmpty_stack();

int stack[max];
int top = -1;

int main() {
    create_graph();
    df_traversal();
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

// Depth-first traversal function
void df_traversal() {
    int v;
    for (v = 0; v < n; v++) {
        state[v] = initial; // Initialize all vertices to initial state
    }
    cout << "Enter starting node for DFS: ";
    cin >> v;
    dfs(v);
}

// Depth-first search algorithm
void dfs(int v) {
    int i;
    push(v); // Push the starting vertex onto the stack
    while (!isEmpty_stack()) {
        v = pop(); // Pop a vertex from the stack
        if (state[v] == initial) {
            cout << v << " "; // Print the visited vertex
            state[v] = visited; // Update its state to visited
        }
        // Explore adjacent vertices
        for (i = n - 1; i >= 0; i--) {
            if (adj[v][i] == 1 && state[i] == initial)
                push(i); // Push adjacent vertices onto the stack
        }
    }
}

// Function to pop an item from the stack
int pop() {
    int v;
    if (top == -1) {
        cout << "Stack underflow" << endl;
        exit(1);
    } else {
        v = stack[top];
        top = top - 1;
        return v;
    }
}

// Function to push an item onto the stack
void push(int v) {
    if (top == (max - 1)) {
        cout << "Stack is Overflow" << endl;
        return;
    }
    top += 1;
    stack[top] = v;
}

// Function to check if the stack is empty
int isEmpty_stack() {
    if (top == -1)
        return 1;
    else
        return 0;
}


/*
Output :-
bhupesh@bhupesh-IdeaPad-Gaming-3-15ACH6:~/DAA$ g++ 10.dfs.cpp
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
Enter starting node for DFS: 0
0 1 2 
*/
