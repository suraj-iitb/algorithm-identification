#include <stdio.h>
int main(){
    int i,j,n,a[100],help,state,p,mini,t;
    scanf("%d", &n); 
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    state=0;
    for(i=0;i<n-1;i++){
      mini=i;
        for(j=i;j<n;j++){
            if(a[j] < a[mini]){
                mini=j;
            }
        }
        t=a[i];
        a[i]=a[mini];
        a[mini]=t;

        if(i != mini){
           state++;
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
