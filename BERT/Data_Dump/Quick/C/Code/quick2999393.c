#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char suit;
    int val;
}Card;

int partition(int,Card[],int,int);
void quickSort(int,Card[],int,int);
void printArray(int,Card[]);
int checkStable(int,Card[],Card[]);

int main(int argc, char** argv) {
    int size;
    scanf("%d", &size);
    Card array[size],temp[size];
    for(int i = 0; i < size; i++)
        scanf("\n%c %d", &array[i].suit, &array[i].val);
    
    for(int i = 0; i < size; i++){
        temp[i].suit = array[i].suit;
        temp[i].val = array[i].val;
    }
    
    quickSort(size,temp,0,size-1);
    if(checkStable(size, array, temp))
        printf("Not stable\n");
    else
        printf("Stable\n");
    printArray(size,temp);
    return (EXIT_SUCCESS);
}

int partition(int size, Card array[size], int start, int end){
    Card compare = array[end];
    Card temp;
    int i = start - 1;
    for(int j = start; j < end; j++){
        if(array[j].val <= compare.val){
            i += 1;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i+1];
    array[i+1] = array[end];
    array[end] = temp;
    return i+1;
}

void quickSort(int size, Card array[size], int start, int end){
    if(start < end){
        int loc = partition(size,array,start,end);
        quickSort(size,array,start,loc-1);
        quickSort(size,array,loc+1,end);
    }
}

void printArray(int size, Card a[size]){
    for(int i = 0; i < size; i++){
        printf("%c %d\n", a[i].suit, a[i].val);
    }
}

int checkStable(int size, Card array[size], Card temp[size]){
    int returnVal = 0;
    int count = 0;
    int count2 = 0;
    for(int i = 0; i < size; i++){   
        for(int j = i + 1; j < size; j++)
            if(array[j].val == array[i].val)    //check how many cards have same val after the currently checking card in original array
                count++;
//            if(array[i].val == array[j].val){
//                temp1 = array[i];
//                temp2 = array[j];
//                for(int i2 = 0; i2 < size; i2++)
//                    if(temp[i2].val == temp1.val && temp[i2].suit == temp1.suit)
//                        for(int j2 = 0; j2 < size; j2++)
//                            if(temp[j2].val == temp2.val && i2 > j2)
//                                returnVal = 0;
//            }
        for(int k = 0; k < size; k++){
            if(array[i].val == temp[k].val && array[i].suit == temp[k].suit && count != 0)
                for(int j = k + 1; j < size; j++)
                    if(temp[k].val == temp[j].val)
                        count2++;               //check how many cards 
        }
        returnVal = count - count2;
        if(returnVal)
            break;
        count = 0;
        count2 = 0;
    }
    return returnVal;
}

