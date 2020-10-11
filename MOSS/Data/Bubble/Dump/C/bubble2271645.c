#include <stdio.h>
 
int main(){
int a,i,c=0,j,temp,data[100];
scanf("%d",&a);
for(i=0;i<a;i++)
{
    scanf("%d",&data[i]);
}
for(i=0;i<a-1;i++)
{
    for(j=a-1;j>i;j--){
        if(data[j-1]>data[j]){
            temp=data[j-1];
            data[j-1]=data[j];
            data[j]=temp;
            c++;
        }
    }
}
for(i=0;i<a;i++)
{
    printf("%d",data[i]);
    if(i!=a-1) printf(" ");
}
printf("\n");
printf("%d\n",c);
return 0;
}
