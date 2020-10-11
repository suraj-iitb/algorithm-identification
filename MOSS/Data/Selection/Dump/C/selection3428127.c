#include <stdio.h>

int SelectionSort(int *array, int len);

int main()
{
    int i,j,len;
    char buf[10];
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf,"%d",&len);
    int *array;
    array = malloc(len*sizeof(int));
    for (i=0;i<len;i++){
        scanf("%d",array+i);
    }
    int cnt;
    cnt = SelectionSort(array, len);
    for (i=0;i<len;i++){
        if (i==(len-1)) printf("%d\n",*(array+i));
        else printf("%d ",*(array+i));
    }
    printf("%d\n",cnt);
    return 0;
}

int SelectionSort(int *array, int len)
{
    int i,j,tmp,cnt,mini;
    cnt = 0;
    for (i=0;i<len;i++)
    {
        mini = i;
        for (j=i;j<len;j++)
        {
            if (array[j] < array[mini])
            {
                mini = j;
            }
        }
        tmp = array[i];
        array[i] = array[mini];
        array[mini] = tmp;
        if (i != mini) cnt += 1;
    }
    return cnt;
}

