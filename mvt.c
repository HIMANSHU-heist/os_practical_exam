#include <stdio.h>
int main()
{
    int mem = 1000, n = 4, i;
    int proc[4] = {300, 250, 400, 200};
    for (i = 0; i < n; i++)
    {
        if (proc[i] <= mem)
        {
            mem -= proc[i];
            printf("P%d (%d) allocated, memory left = %d\n", i+1, proc[i], mem);
        }
        else printf("P%d (%d) NOT allocated, only %d left\n", i+1, proc[i], mem);
    }
    printf("Free memory left = %d\n", mem);
    return 0;
}
