#include <stdio.h>
int main(){
    int n,i,j,k;
    int str[100];
    int max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&str[i]);
    for(k=0;k<n-1;k++)
        printf("%d ",str[k]);
    printf("%d\n",str[k]);
    for(i=1;i<n;i++){
        max=str[i];
        
        for(j=i-1;j>=0 && str[j]>max;j--)
            str[j+1]=str[j];
        str[j+1]=max;
        for(k=0;k<n-1;k++) printf("%d ",str[k]);
        printf("%d\n",str[k]);
    }
    //system("pause");
    return 0;
}
