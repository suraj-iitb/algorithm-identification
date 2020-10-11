#include <stdio.h>
int main(void){
    int n,i,a[1000],temp,j,o;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    printf("%d",a[i]);
    if(i!=n-1)
      printf(" ");
    }
    printf("\n");
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    for(o=0;o<n;o++){
        printf("%d",a[o]);if(o!=n-1)printf(" ");}
    printf("\n");
    }
 
    return 0;
}
