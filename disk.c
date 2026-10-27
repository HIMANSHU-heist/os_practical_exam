#include <stdio.h>
#include <stdlib.h>
#define N 8
#define MAXC 199
int cmp(const void *a, const void *b) { return *(int*)a - *(int*)b; }
int main()
{
    int req[N] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53, i, total, cur;
    printf("Requests: 98 183 37 122 14 124 65 67\nHead = %d, Disk = 0-%d\n", head, MAXC);
    printf("\n--- FCFS ---\n%d", head);
    cur = head; total = 0;
    for (i = 0; i < N; i++) { total += abs(req[i] - cur); cur = req[i]; printf(" -> %d", cur); }
    printf("\nTotal head movement = %d\n", total);
    int s[N];
    for (i = 0; i < N; i++) s[i] = req[i];
    qsort(s, N, sizeof(int), cmp);
    int pos = 0;
    while (pos < N && s[pos] < head) pos++;
    printf("\n--- SCAN (moving right) ---\n%d", head);
    cur = head; total = 0;
    for (i = pos; i < N; i++) { total += abs(s[i] - cur); cur = s[i]; printf(" -> %d", cur); }
    total += abs(MAXC - cur); cur = MAXC; printf(" -> %d", cur);
    for (i = pos - 1; i >= 0; i--) { total += abs(s[i] - cur); cur = s[i]; printf(" -> %d", cur); }
    printf("\nTotal head movement = %d\n", total);
    printf("\n--- C-SCAN (moving right) ---\n%d", head);
    cur = head; total = 0;
    for (i = pos; i < N; i++) { total += abs(s[i] - cur); cur = s[i]; printf(" -> %d", cur); }
    total += abs(MAXC - cur); cur = MAXC; printf(" -> %d", cur);
    total += MAXC; cur = 0; printf(" -> 0");
    for (i = 0; i < pos; i++) { total += abs(s[i] - cur); cur = s[i]; printf(" -> %d", cur); }
    printf("\nTotal head movement = %d\n", total);
    return 0;
}