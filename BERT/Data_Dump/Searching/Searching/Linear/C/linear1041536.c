#include <stdio.h>
#include <stdlib.h>

void InputFrom(int *from, int num);
void InputTarget(int *target, int num);

int main(void)
{
    int i;

    int *from;
    int num_from;
    scanf("%d", &num_from);
    from = malloc(sizeof(int) * num_from);
    InputFrom(from, num_from);

    int *target;
    int num_target;
    scanf("%d", &num_target);
    target = malloc(sizeof(int) * num_target);
    InputTarget(target, num_target);

    int cnt = 0;
    for (i = 0; i < num_target; i++) {
        int first = 0, last = num_from;
        int mid;
        while (first <= last) {
            mid = (last + first) / 2;
            if (from[mid] < target[i]) {
                first = mid + 1;
            } else if (target[i] < from[mid]) {
                last = mid - 1;
            } else {
                cnt++;
                break;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}

int cmp(const void *a, const void *b);

void InputFrom(int from[], int num)
{
    int i;

    for (i = 0; i < num; i++) {
        scanf("%d", from + i);
    }

    qsort((void *)from, num, sizeof(int), cmp);
}

int cmp(const void *a, const void *b)
{
    int diff = *(int *)a - *(int *)b;
    return diff;
}

void InputTarget(int target[], int num)
{
    int i;

    for (i = 0; i < num; i++) {
        scanf("%d", target + i);
    }
}
