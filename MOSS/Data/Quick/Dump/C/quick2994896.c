
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char cha;
    int val;
} Card;

#define SENTINEL 1000000001

void swap(Card Array[], int i, int j) {
    Card temp;
    temp = Array[i];
    Array[i] = Array[j];
    Array[j] = temp;
}

int partition(Card Array[], int pIndex, int rIndex) {
    Card x = Array[rIndex];
    int i = pIndex;
    
    for (int j = pIndex; j < rIndex; j++)
        if (Array[j].val <= x.val)
            swap(Array, i++, j);

    swap(Array, i, rIndex);
    return i;
}

void quickSort(Card Array[], int pIndex, int rIndex) {
    if (pIndex < rIndex) {
        int qIndex = partition(Array, pIndex, rIndex);
        quickSort(Array, pIndex, qIndex - 1);
        quickSort(Array, qIndex + 1, rIndex);
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", array[i]);
    };
}

void printCardArray(Card array[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%c%d", array[i].cha, array[i].val);
    };
}

void printCardSiteFormat(Card array[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) printf("\n");
        printf("%c %d", array[i].cha, array[i].val);
    };
}

// 1-origin to 0-origin
int o1(int i) {
    return i-1;
}

void bubbleSort(Card array[], int length) {
    int swapCount = 0;
    int temp;
    
    for (int i = 0; i < length; i++)
        for (int j = length - 1; j > i; j--)
            if (array[j].val < array[j-1].val) {
                swap(array, j, j-1);
            }
    
}

void countingSort(Card Array[], Card Brrby[], int length, int upperBound) {
    int i, j;
//    printf("length: %d", length);printf("\n");
//    printf("upperBound: %d", upperBound);printf("\n");
//    printCardArray(Array, length);printf("\n");
    
    int Crrcy[upperBound+1];
//    printf("Array:   ");printArray(Array, length);printf(", upperBound: %d\n", upperBound);
    
    for (i = 0; i <= upperBound; i++)
        Crrcy[i] = 0;
    
    for (j = 1; j <= length; j++)
        Crrcy[Array[o1(j)].val]++;
    
//    printf("Counted: ");printArray(Crrcy, upperBound+1);printf("\n");
    
    for (i = 1; i <= upperBound; i++)
        Crrcy[i] = Crrcy[i] + Crrcy[i-1];
    
//    printf("Indexed: ");printArray(Crrcy, upperBound+1);printf("\n");
    
    for (j = length; j >= 1; j--) {
        Brrby[o1(Crrcy[Array[o1(j)].val])] = Array[o1(j)];
        Crrcy[Array[o1(j)].val]--;
    }
    
//    printf("Sorted:  ");printArray(Brrby, length);printf("\n");
}





void merge_REVERSED(Card array[], int left, int mid, int right) {
    int nL = mid - left;
    int nR = right - mid;
    
    Card Left[nL + 1], Right[nR + 1];
    int i, j, k;
    
    for (i = 0; i < nL; i++)  Left[i] = array[left + i];
    for (j = 0; j < nR; j++) Right[j] = array[mid  + j];
    
    Left[nL].cha = Right[nR].cha = '#';
    Left[nL].val = Right[nR].val = SENTINEL;
    
    for (i = 0, j = 0, k = left; k < right; k++)
        if (Left[i].val < Right[j].val) {
            array[k] = Left[i];
            i++;
        }
        else {
            array[k] = Right[j];
            j++;
        }

//    
//    for (i = nL-1, j = nR-1, k = right-1; k >=left; k--)
//        if (Left[i].val > Right[j].val)
//            array[k] = Left[i--];
//        else 
//            array[k] = Right[j--];
    
    // <why?!!>
}

void mergeSort(Card array[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right)/2;
        mergeSort(array, left, mid);
        mergeSort(array, mid, right);
        merge_REVERSED(array, left, mid, right);
    }
}






int main(int argc, char** argv) {
    int nArray;//, max_num = 0;
    scanf("%d", &nArray);
    
    Card arrayQS[nArray], arrayCS[nArray];//, brrbyCS[nArray];
    
    // ------------------------------------------------
    // scan array and duplicate array
    
    for (int iArray = 0; iArray < nArray; iArray++) {
        scanf(" %c", &(arrayQS[iArray].cha));
        scanf(" %d", &(arrayQS[iArray].val));
        
//        arrayCS[iArray].cha = arrayQS[iArray].cha;
//        arrayCS[iArray].val = arrayQS[iArray].val;
        arrayCS[nArray-iArray-1].cha = arrayQS[iArray].cha;
        arrayCS[nArray-iArray-1].val = arrayQS[iArray].val;
        
//        if (arrayQS[iArray].val > max_num)
//            max_num = arrayQS[iArray].val;
    }
//    printCardArray(arrayQS, nArray);printf("\n");
    
    // ------------------------------------------------
    // quick sort
    
    quickSort(arrayQS, 0, nArray - 1);
//    printf("quickSort: ");printCardArray(arrayQS, nArray);printf("\n");
    
    // ------------------------------------------------
    // Use other sorts to check for stability
    
//    countingSort(arrayCS, brrbyCS, nArray, max_num);
//    bubbleSort(arrayCS, nArray);
    mergeSort(arrayCS, 0, nArray);
//    printf("mergeSort: ");printCardArray(arrayCS, nArray);printf("\n");
    
    int isStable = 1;
    for (int iArray = 0; iArray < nArray; iArray++)
        isStable = (isStable && (arrayCS[iArray].cha == arrayQS[iArray].cha));
    
    // ------------------------------------------------
    // output
    
    if (!isStable)
        printf("Not stable\n");
    else
        printf("Stable\n");
    
    printCardSiteFormat(arrayQS, nArray);
    printf("\n");

    return (EXIT_SUCCESS);
}


