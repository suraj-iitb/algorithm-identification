# include <stdio.h>
# include <stdbool.h>

void selectionSort(int sequence[], int N, int swaps);
void printArray(int sequence[], int N, int swaps);

int main(void)
{
    int N;
    scanf("%d", &N);

    int sequence[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &sequence[i]);
    }

    int swaps = 0;

    selectionSort(sequence, N, swaps);
}

void selectionSort(int sequence[], int N, int swaps)
{
    for(int i = 0; i < N - 1; i++)
    {
        _Bool swapped = false;
        int min_index = i;
        for(int j = i + 1; j < N; j++)
        {
            if (sequence[j] < sequence[min_index])
            {
                min_index = j;
                if (swapped == false)
                {
                    swaps++;
                }
                swapped = true;
            }
        }
        int temp = sequence[min_index];
        sequence[min_index] = sequence[i];
        sequence[i] = temp;
    }
    printArray(sequence, N, swaps);
}

void printArray(int sequence[], int N, int swaps)
{
    for(int loop = 0; loop < N; loop++)
    {
        if (loop == N - 1)
        {
            printf("%d\n%d\n", sequence[loop], swaps);
        }
        else
        {
            printf("%d ", sequence[loop]);
        }
    }
}
