#include <stdio.h>

int BubbleSort(int *array, int len);

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
    cnt = BubbleSort(array, len);
    for (i=0;i<len;i++){
        if (i==(len-1)) printf("%d\n",*(array+i));
        else printf("%d ",*(array+i));
    }
    printf("%d\n",cnt);
    return 0;
}

int BubbleSort(int *array, int len)
{
    int i,j,tmp,cnt;
    cnt = 0;
    for (i=0;i<len;i++)
    {
        for (j=(len-1);j>i;j--)
        {
            if (array[j] < array[j-1])
                {
                    tmp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = tmp;
                    cnt += 1;
                }
        }
    }
    return cnt;
}
