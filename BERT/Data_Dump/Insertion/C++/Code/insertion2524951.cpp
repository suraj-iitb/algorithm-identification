#include<cstdio>

int insertionSort(int* , int length);
int output_array(int*, int length);

int main()
{
    int length;
    scanf("%d", &length);
    int seq[length];
    for (int i=0;i<length;i++)
    {
        scanf("%d", &seq[i]);
    }
    output_array(seq, length);
    insertionSort(seq, length);
}

int insertionSort(int *array , int length)
{
    for (int i=1; i<length; i++)
    {
        //printf("%d\n", i);
        int v = array[i];
        int j =i - 1;
        //printf("j=%d\n", j);
        while((j>=0)&&(array[j]>v))
        {
            array[j+1]=array[j];
            j--;
            //output_array(array, length);
        }
        array[j+1] = v;
        output_array(array, length);
    }
}

int output_array(int *array, int length)
{
    for (int i=0;i<length;i++)
    {
        if(i<length-1)
        {
            printf("%d ", array[i]);
        }
        else{
            printf("%d", array[i]);
        }
    }
    printf("\n");
}
