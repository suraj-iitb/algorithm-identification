#include <stdio.h>
#include <stdlib.h>

int selectionSort(int array[],int arraySize);

int main() {
    int arraySize=0;
    scanf("%d",&arraySize);
    int*array = (int*)malloc(sizeof(int)*arraySize);

    for(int i=0;i<arraySize;i++)
    {
        scanf("%d",&array[i]);
    }
    //ソート
    int counter = selectionSort(array,arraySize);

    for(int i=0;i<arraySize;i++)
    {
        printf("%d",array[i]);
        if(i!=arraySize-1)printf(" ");
    }
    printf("\n%d\n",counter);
    return 0;
}

int selectionSort(int array[],int arraySize)
{
    int minPlace=0;
    int flag=0;
    int counter=0;
    //配列の初めから終わりまで精査する
    for(int i=0;i<arraySize;i++)
    {
        flag=0;
        minPlace=i;
        //i番目の精査では、後ろの(arraySize-i)個の配列の要素をチェックする
        for (int j=i+1;j<arraySize;j++)
        {
            //ifの方が高速(らしい)
            //min=array[j]<min?array[j]:min;
            if(array[minPlace]>array[j]) {
                flag++;
                minPlace = j;
            }
        }
        if(flag>0)
        {
            flag=array[i];
            array[i] = array[minPlace];
            array[minPlace]=flag;
            counter++;
        }
    }
    return counter;
}

