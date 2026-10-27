#include <stdio.h>
int main()
{
    int in_mem[4] = {0, 1, 0, 1};
    int ref[] = {1, 2, 3, 0, 2};
    int n = 5, faults = 0;
    printf("Initially in memory: P1 P3\n\n");
    for (int i = 0; i < n; i++)
    {
        int p = ref[i];
        printf("CPU requests P%d : ", p);
        if (in_mem[p]) printf("page present (hit)\n");
        else
        {
            printf("PAGE FAULT -> OS loads P%d from secondary memory\n", p);
            in_mem[p] = 1;
            faults++;
        }
    }
    printf("\nTotal page faults = %d\n", faults);
    return 0;
}