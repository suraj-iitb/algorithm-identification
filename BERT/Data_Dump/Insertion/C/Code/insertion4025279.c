#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *data;
    int a,i,key,j;

scanf("%d\n",&a);

data = (int *)malloc(a * sizeof(int ));

for(i=0;i<a;i++) scanf("%d",&data[i]);


for(j=1;j<=a;j++)
{
     for(i=0;i<a;i++) 
    {
    printf("%d",data[i]);
    if(i != a-1) printf(" ");
    } 
    printf("\n");   
    
    if(j != a)
    {
       key = data[j];
       i = j - 1;
       while(i >= 0 && data[i] >key)
         {
          data[i+1] = data[i];
          i--;
          }
        data[i+1] = key;
    }
 
}

free(data);
return 0;
}
