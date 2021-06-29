#include <stdio.h>

void insertionSort(int targetArray[], int size)
{
        for (int i = 1; i < size; i++)
        {
                int currentNumber = targetArray[i];

                int j = i - 1;
                int foreNumber = targetArray[j];

                while (j >= 0 && targetArray[j] > currentNumber)
                {
                        targetArray[j + 1] = targetArray[j];
                        j--;
                        targetArray[j + 1] = currentNumber;
                }

                for (int j = 0; j < size; ++j)
                {
                        if (j == 0)
                                printf("%d", targetArray[j]);
                        else
                                printf(" %d", targetArray[j]);
                }
                putchar('\n');
        }
}

int main()
{
        int size;

        scanf("%d", &size);

        int targetArray[size];

        for (int i = 0; i < size; i++)
        {
                scanf("%d", &targetArray[i]);
        }

        for (int j = 0; j < size; ++j)
                {
                        if (j == 0)
                                printf("%d", targetArray[j]);
                        else
                                printf(" %d", targetArray[j]);
                }
                putchar('\n');

        insertionSort(targetArray, size);

        return 0;
}
