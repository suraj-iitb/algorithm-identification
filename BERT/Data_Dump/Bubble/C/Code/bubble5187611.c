# include <stdio.h>

void bubbleSort(int sequence[], int N, int swaps);
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

    bubbleSort(sequence, N, swaps);
}

void bubbleSort(int sequence[], int N, int swaps)
{
    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < N - i - 1; j++)
        {
            if (sequence[j] > sequence[j + 1])
            {
                int temp = sequence[j];
                sequence[j] = sequence[j+1];
                sequence[j+1] = temp;
                swaps++;
            }
        }
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
