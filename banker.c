#include <stdio.h>
#define P 5
#define R 3
int alloc[P][R] = {{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
int max[P][R]   = {{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
int avail[R]    = {3,3,2};
int need[P][R];
int is_safe(int show)
{
    int work[R], finish[P] = {0}, seq[P], cnt = 0, i, j;
    for (j = 0; j < R; j++) work[j] = avail[j];
    while (cnt < P)
    {
        int found = 0;
        for (i = 0; i < P; i++)
        {
            if (finish[i]) continue;
            int ok = 1;
            for (j = 0; j < R; j++) if (need[i][j] > work[j]) { ok = 0; break; }
            if (ok)
            {
                for (j = 0; j < R; j++) work[j] += alloc[i][j];
                finish[i] = 1; seq[cnt++] = i; found = 1;
            }
        }
        if (!found) { if (show) printf("System is NOT in safe state\n"); return 0; }
    }
    if (show)
    {
        printf("System is in SAFE state.\nSafe sequence: ");
        for (i = 0; i < P; i++) printf("P%d%s", seq[i], i < P - 1 ? " -> " : "\n");
    }
    return 1;
}
int main()
{
    int i, j;
    for (i = 0; i < P; i++)
        for (j = 0; j < R; j++) need[i][j] = max[i][j] - alloc[i][j];
    printf("Need matrix:\n");
    for (i = 0; i < P; i++)
    {
        printf("P%d: ", i);
        for (j = 0; j < R; j++) printf("%d ", need[i][j]);
        printf("\n");
    }
    printf("\nAvailable: 3 3 2\n\n");
    is_safe(1);
    int p = 1, req[R] = {1, 0, 2}, ok = 1;
    printf("\nP1 requests: 1 0 2\n");
    for (j = 0; j < R; j++) if (req[j] > need[p][j] || req[j] > avail[j]) ok = 0;
    if (!ok) printf("Request cannot be granted now.\n");
    else
    {
        for (j = 0; j < R; j++) { avail[j] -= req[j]; alloc[p][j] += req[j]; need[p][j] -= req[j]; }
        if (is_safe(0)) { printf("Request GRANTED. "); is_safe(1); }
        else printf("Request DENIED (would be unsafe).\n");
    }
    return 0;
}
