#include <stdio.h>

int hasPath(int start, int end, int n, int adj[][4]) {
    if (start == end) return 1;

    int viz[4] = {0};
    int q[100], f = 0, r = -1;

    q[++r] = start;
    viz[start] = 1;

    while (f <= r) {
        int curr = q[f++];

        for (int i = 0; i < n; i++) {
            if (adj[curr][i]) {
                if (i == end) return 1;
                if (!viz[i]) {
                    viz[i] = 1;
                    q[++r] = i;
                }
            }
        }
    }
    return 0;
}

int main() {
    int n = 4;
    int adj[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    printf("%d\n", hasPath(0, 3, n, adj));
    printf("%d\n", hasPath(2, 3, n, adj));

    return 0;
}