#include <stdio.h>
int main(){
    int i,j,n,a[100],help,state,p;
    scanf("%d", &n); 
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    state=0;
    for(i=0;i<n-1;i++){
        for(j=n-1;j>i;j--){
            if(a[j] < a[j-1]){
                help=a[j];
                a[j]=a[j-1];
                a[j-1]=help;
                state++;
            }
        }
    }
        

    for(p=0; p<n; p++){
      printf("%d",a[p]);
      if(p<n-1){
        printf(" ");
      }
    }
    
    printf("\n");
    printf("%d\n",state);

    
    return (0);
}
