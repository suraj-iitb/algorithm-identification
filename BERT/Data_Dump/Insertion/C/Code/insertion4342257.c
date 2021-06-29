#include<stdio.h>
int a[100] = {0};

int main(){

    

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

 for(int k=0;k<n;k++){
            if(k==n-1)
            printf("%d\n",a[k] );
            else
            printf("%d ",a[k]);
        }

    for(int i=1;i<n;i++){
       
       
        int key = a[i];

        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
             a[j+1] = key;
            
        } 
          
         for(int k=0;k<n;k++){
            if(k==n-1)
            printf("%d\n",a[k] );
            else
            printf("%d ",a[k]);
            
        }
         
        
    }


    

    return 0;
}
