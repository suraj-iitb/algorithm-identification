#include <stdio.h>

int maxArray;

/* 配列の要素を順番に出力 */
void printOut(int *numericArray)
{
    int count;
    for (count = 0; count < maxArray; count++) {
        if (count > 0) {
            printf(" ");
        }
        printf("%d",numericArray[count]);
    }
    printf("\n");
}

/* 挿入ソート */
void insertionSort(int *numericArray)
{
    int count, currentReference, insertedValue;

    for (count = 1; count < maxArray; count++) {
        insertedValue = numericArray[count];
        currentReference = count - 1;
        while (currentReference >= 0 && numericArray[currentReference] > insertedValue) {
            numericArray[currentReference + 1] = numericArray[currentReference];
            currentReference--;
        }
        numericArray[currentReference + 1] = insertedValue;
        printOut(numericArray);
    }
}

int main(void)
{
    int count;

    scanf("%d",&maxArray);
    int numericArray[maxArray];

    for (count = 0; count < maxArray; count++) {
        scanf("%d", &numericArray[count]);
    }

    printOut(numericArray);
    insertionSort(numericArray);

    return 0;
}

