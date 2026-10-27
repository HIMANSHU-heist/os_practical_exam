#include <stdio.h>
int ref[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
int n = 20, F = 3;
void show(int fr[], int hit)
{
    for (int i = 0; i < F; i++) { if (fr[i] == -1) printf("- "); else printf("%d ", fr[i]); }
    printf("%s\n", hit ? "  (hit)" : "  (fault)");
}
int fifo()
{
    int fr[3] = {-1,-1,-1}, ptr = 0, faults = 0;
    printf("\n--- FIFO ---\n");
    for (int i = 0; i < n; i++)
    {
        int hit = 0;
        for (int j = 0; j < F; j++) if (fr[j] == ref[i]) hit = 1;
        if (!hit) { fr[ptr] = ref[i]; ptr = (ptr + 1) % F; faults++; }
        printf("%d -> ", ref[i]); show(fr, hit);
    }
    return faults;
}
int lru()
{
    int fr[3] = {-1,-1,-1}, last[3] = {0}, faults = 0;
    printf("\n--- LRU ---\n");
    for (int i = 0; i < n; i++)
    {
        int hit = 0, j;
        for (j = 0; j < F; j++) if (fr[j] == ref[i]) { hit = 1; last[j] = i; }
        if (!hit)
        {
            int v = 0;
            for (j = 0; j < F; j++)
            {
                if (fr[j] == -1) { v = j; break; }
                if (last[j] < last[v]) v = j;
            }
            fr[v] = ref[i]; last[v] = i; faults++;
        }
        printf("%d -> ", ref[i]); show(fr, hit);
    }
    return faults;
}
int lfu()
{
    int fr[3] = {-1,-1,-1}, freq[3] = {0}, age[3] = {0}, faults = 0;
    printf("\n--- LFU ---\n");
    for (int i = 0; i < n; i++)
    {
        int hit = 0, j;
        for (j = 0; j < F; j++) if (fr[j] == ref[i]) { hit = 1; freq[j]++; }
        if (!hit)
        {
            int v = 0;
            for (j = 0; j < F; j++)
            {
                if (fr[j] == -1) { v = j; break; }
                if (freq[j] < freq[v] || (freq[j] == freq[v] && age[j] < age[v])) v = j;
            }
            fr[v] = ref[i]; freq[v] = 1; age[v] = i; faults++;
        }
        printf("%d -> ", ref[i]); show(fr, hit);
    }
    return faults;
}
int main()
{
    printf("Reference string: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1\n");
    printf("Frames = %d\n", F);
    int a = fifo(), b = lru(), c = lfu();
    printf("\nPage faults: FIFO = %d, LRU = %d, LFU = %d\n", a, b, c);
    return 0;
}