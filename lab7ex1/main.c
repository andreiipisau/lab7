#include <stdio.h>

int q[100], front = -1, rear = -1;

void push(int x) {
    if(front == -1) front = 0;
    q[++rear] = x;
}

int pop() {
    return q[front++];
}

int is_empty() {
    return front == -1 || front > rear;
}

void reset_q() {
    front = -1;
    rear = -1;
}

void bfs(int start, int n, int adj[][5]) {
    int viz[5] = {0};
    reset_q();
    push(start);
    viz[start] = 1;

    while(!is_empty()) {
        int curr = pop();
        printf("%d ", curr);

        for(int i = 0; i < n; i++) {
            if(adj[curr][i] && !viz[i]) {
                viz[i] = 1;
                push(i);
            }
        }
    }
    printf("\n");
}

void dfs_util(int curr, int n, int adj[][5], int viz[]) {
    viz[curr] = 1;
    printf("%d ", curr);

    for(int i = 0; i < n; i++) {
        if(adj[curr][i] && !viz[i]) {
            dfs_util(i, n, adj, viz);
        }
    }
}

void dfs(int start, int n, int adj[][5]) {
    int viz[5] = {0};
    dfs_util(start, n, adj, viz);
    printf("\n");
}

int main() {
    int n = 5;
    int adj[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    bfs(0, n, adj);
    dfs(0, n, adj);

    return 0;
}