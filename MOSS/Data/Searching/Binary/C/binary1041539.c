#include <stdio.h>
#include <stdlib.h>


void InputFrom(int from[], int num);
void InputTarget(int target[], int num);

int main(void)
{
    int i;

    int num_from;
    scanf("%d", &num_from);
    int *from;
    from = (int *)malloc(sizeof(int) * num_from);
    if (from == NULL) {
        printf("ERROR\n");
        return 1;
    }
    InputFrom(from, num_from);

    int num_target;
    scanf("%d", &num_target);
    int *target;
    target = (int *)malloc(sizeof(int) * num_target);
    if (target == NULL) {
        printf("ERROR\n");
        return 1;
    }
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

void InputFrom(int from[], int num)
{
    int i;

    for (i = 0; i < num; i++) {
        scanf("%d", from + i);
    }
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
