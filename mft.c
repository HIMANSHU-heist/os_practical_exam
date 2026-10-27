#include <stdio.h>
int main()
{
    int total = 1000, psize = 250, n = 4, i, j;
    int parts = total / psize;
    int proc[4] = {200, 270, 150, 240};
    int used[4] = {0};
    int loss = 0;
    printf("Memory = %d, partition size = %d, partitions = %d\n", total, psize, parts);
    for (i = 0; i < n; i++)
    {
        int done = 0;
        if (proc[i] <= psize)
            for (j = 0; j < parts; j++)
                if (!used[j])
                {
                    used[j] = 1; done = 1;
                    printf("P%d (%d) -> Partition %d, internal frag = %d\n", i+1, proc[i], j+1, psize - proc[i]);
                    loss += psize - proc[i];
                    break;
                }
        if (!done) printf("P%d (%d) -> NOT allocated\n", i+1, proc[i]);
    }
    printf("Total internal fragmentation = %d\n", loss);
    return 0;
}
