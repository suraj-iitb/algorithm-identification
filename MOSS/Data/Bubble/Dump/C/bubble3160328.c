#include <stdio.h>

int maxArray;
int sortTimes = 0;

void bubbleSort(int *numericArray)
{
    int count, currentReference, temporaryValue;
    for (count = 0; count < maxArray; count++) {
        for(currentReference = maxArray - 1; currentReference > count; currentReference--) {
            if (numericArray[currentReference] < numericArray[currentReference - 1]) {
                temporaryValue = numericArray[currentReference];
                numericArray[currentReference] = numericArray[currentReference - 1];
                numericArray[currentReference - 1] = temporaryValue;
                sortTimes++;
            }
        }
    }
}

void printOut(int *numericArray)
{
    int count;

    printf("%d", numericArray[0]);
    for (count = 1; count < maxArray; count++) {
        printf(" %d", numericArray[count]);
    }
    printf("\n%d\n",sortTimes);
}

int main(void)
{
    int count;

    scanf("%d", &maxArray);
    int numericArray[maxArray];

    for (count = 0; count < maxArray; count++) {
        scanf("%d", &numericArray[count]);
    }

    bubbleSort(numericArray);
    printOut(numericArray);

    return 0;
}

