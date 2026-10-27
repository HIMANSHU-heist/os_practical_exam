#include <stdio.h>
#define B 5
#define P 4
void allocate(int type, int blk_orig[], int proc[])
{
    int blk[B], alloc[P], i, j;
    for (i = 0; i < B; i++) blk[i] = blk_orig[i];
    for (i = 0; i < P; i++) alloc[i] = -1;
    for (i = 0; i < P; i++)
    {
        int idx = -1;
        for (j = 0; j < B; j++)
        {
            if (blk[j] >= proc[i])
            {
                if (type == 1) { idx = j; break; }
                if (type == 2 && (idx == -1 || blk[j] < blk[idx])) idx = j;
                if (type == 3 && (idx == -1 || blk[j] > blk[idx])) idx = j;
            }
        }
        if (idx != -1) { alloc[i] = idx; blk[idx] -= proc[i]; }
    }
    printf("Process\tSize\tBlock\n");
    for (i = 0; i < P; i++)
    {
        printf("P%d\t%d\t", i + 1, proc[i]);
        if (alloc[i] != -1) printf("Block %d\n", alloc[i] + 1);
        else printf("Not Allocated\n");
    }
    printf("Remaining blocks: ");
    for (i = 0; i < B; i++) printf("%d ", blk[i]);
    printf("\n");
}
int main()
{
    int blocks[B] = {100, 500, 200, 300, 600};
    int proc[P] = {212, 417, 112, 426};
    printf("Memory blocks: 100 500 200 300 600\n");
    printf("Processes    : 212 417 112 426\n");
    printf("\n--- FIRST FIT ---\n");  allocate(1, blocks, proc);
    printf("\n--- BEST FIT ---\n");   allocate(2, blocks, proc);
    printf("\n--- WORST FIT ---\n");  allocate(3, blocks, proc);
    return 0;
}
