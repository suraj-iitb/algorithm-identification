// 2020 1.22 選択ソート

#include <stdio.h>
#define N 100

int main()
{
    int a,min=0,temp,cnt=0;
    int i,j;
    int array[N];

    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%d",&array[i]);
    }
    for(j=0;j<a;j++)
    {
    min = array[j];
    temp = j;
    //printf("%d\n",min);
    for(i=j;i<a;i++)   //最小値求める
    {
        if(min <= array[i])
        {
          continue;
        }
        else
        {
           min = array[i];
           temp = i; //場所変えるための一時変数
        } 
    }
    //printf("k%d\n",min);
    if(j != temp) cnt++;
    int temp2 = array[j];
    array[j] = min;
    array[temp] = temp2;

    /* for(i=0;i<a;i++)
    {
        printf("%d",array[i]);
        if(i != a-1) printf(" ");
    }
    printf("\n"); */
    }

    for(i=0;i<a;i++)
    {
        printf("%d",array[i]);
        if(i != a-1) printf(" ");
    }
    printf("\n");
    printf("%d\n",cnt);  
    return 0;
}
