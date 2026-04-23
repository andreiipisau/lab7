#include <stdio.h>

int dfs_cycle(int curr, int parent, int n, int adj[][3], int viz[]) {
    viz[curr] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[curr][i]) {
            if (!viz[i]) {
                if (dfs_cycle(i, curr, n, adj, viz)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int hasCycle(int n, int adj[][3]) {
    int viz[3] = {0};

    for (int i = 0; i < n; i++) {
        if (!viz[i]) {
            if (dfs_cycle(i, -1, n, adj, viz)) return 1;
        }
    }
    return 0;
}

int main() {
    int n = 3;
    int adj[3][3] = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };

    printf("%d\n", hasCycle(n, adj));

    return 0;
}