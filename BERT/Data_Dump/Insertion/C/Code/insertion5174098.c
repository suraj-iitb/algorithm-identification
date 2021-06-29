# include <stdio.h>

void printArray(int sequence[], int N);
void insertionSort(int sequence[], int N);

int main(void)
{
    int N;
    scanf("%d", &N);

    int sequence[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &sequence[i]);
    }

    printArray(sequence, N);
    insertionSort(sequence, N);
}

void printArray(int sequence[], int N)
{
    for(int loop = 0; loop < N; loop++)
    {
        if (loop == N - 1)
        {
            printf("%d", sequence[loop]);
        }
        else
        {
            printf("%d ", sequence[loop]);
        }
    }
    printf("\n");
}

void insertionSort(int sequence[], int N)
{
    for(int i = 1; i < N; i++)
    {
        int compare = sequence[i];
        int j = i - 1;

        while(j >= 0 && sequence[j] > compare)
        {
            sequence[j + 1] = sequence[j];
            j = j - 1;
        }
        sequence[j + 1] = compare;

        printArray(sequence, N);
    }
}

