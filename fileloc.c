#include <stdio.h>
int disk[50];
int main()
{
    int ch, i, start, len, n, ok;
    do
    {
        printf("\n1.Sequential 2.Indexed 3.Linked 4.Exit\nEnter choice: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter starting block and length: ");
            scanf("%d %d", &start, &len);
            ok = 1;
            for (i = start; i < start + len; i++) if (i >= 50 || disk[i]) ok = 0;
            if (ok)
            {
                for (i = start; i < start + len; i++) disk[i] = 1;
                printf("File allocated. Blocks: ");
                for (i = start; i < start + len; i++) printf("%d ", i);
                printf("\n");
            }
            else printf("Blocks not free or out of range.\n");
        }
        else if (ch == 2)
        {
            int idx, blocks[20];
            printf("Enter index block: ");
            scanf("%d", &idx);
            if (disk[idx]) { printf("Index block already used.\n"); continue; }
            printf("Enter number of blocks: ");
            scanf("%d", &n);
            printf("Enter block numbers: ");
            for (i = 0; i < n; i++) scanf("%d", &blocks[i]);
            ok = 1;
            for (i = 0; i < n; i++) if (disk[blocks[i]]) ok = 0;
            if (ok)
            {
                disk[idx] = 1;
                for (i = 0; i < n; i++) disk[blocks[i]] = 1;
                printf("Index block %d -> ", idx);
                for (i = 0; i < n; i++) printf("%d ", blocks[i]);
                printf("\n");
            }
            else printf("Some blocks already allocated.\n");
        }
        else if (ch == 3)
        {
            int blocks[20];
            printf("Enter number of blocks: ");
            scanf("%d", &n);
            printf("Enter block numbers: ");
            for (i = 0; i < n; i++) scanf("%d", &blocks[i]);
            ok = 1;
            for (i = 0; i < n; i++) if (disk[blocks[i]]) ok = 0;
            if (ok)
            {
                for (i = 0; i < n; i++) disk[blocks[i]] = 1;
                printf("Chain: ");
                for (i = 0; i < n; i++) printf("%d -> ", blocks[i]);
                printf("NULL\n");
            }
            else printf("Some blocks already allocated.\n");
        }
    } while (ch != 4);
    return 0;
}
