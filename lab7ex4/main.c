#include <stdio.h>
#include <limits.h>

int findMinDistance(int n, int adj[][6], int values[]) {
    int minVal = INT_MAX, maxVal = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (values[i] < minVal) minVal = values[i];
        if (values[i] > maxVal) maxVal = values[i];
    }

    if (minVal == maxVal) return 0;

    int shortestDist = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (values[i] == minVal) {
            int dist[6];
            for(int j = 0; j < n; j++) dist[j] = -1;

            int q[100], f = 0, r = -1;
            q[++r] = i;
            dist[i] = 0;

            while (f <= r) {
                int curr = q[f++];

                if (values[curr] == maxVal) {
                    if (dist[curr] < shortestDist) shortestDist = dist[curr];
                    break;
                }

                for (int v = 0; v < n; v++) {
                    if (adj[curr][v] && dist[v] == -1) {
                        dist[v] = dist[curr] + 1;
                        q[++r] = v;
                    }
                }
            }
        }
    }

    if (shortestDist == INT_MAX) return -1;
    return shortestDist;
}

int main() {
    int n = 6;
    int values[6] = {10, 5, 20, 5, 20, 15};
    int adj[6][6] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0}
    };

    printf("%d\n", findMinDistance(n, adj, values));

    return 0;
}