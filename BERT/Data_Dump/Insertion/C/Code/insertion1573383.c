#include<stdio.h>

int main(void){

    int a[100];

    int t,b,temp,s,l,q,r;

    scanf("%d",&b);

    for(t=0;t<b;t++){
       scanf("%d",&a[t]);
    }

    for(s=0;s<b-1;s++){
       printf("%d ",a[s]);
    }
    printf("%d\n",a[b-1]);

    for(t=1;t<b;t++){
       l = t-1;
       q=t;
       r=l;
       while(a[l]>a[t]){
            temp=a[l];
            a[l]=a[t];
            a[t]=temp;
            if(t!=1){
              l--;
              t--;
            }
       }
       t=q;
       l=r;
       for(s=0;s<b-1;s++){
          printf("%d ",a[s]);
       }
       printf("%d\n",a[b-1]);
    }

    return 0;
}
