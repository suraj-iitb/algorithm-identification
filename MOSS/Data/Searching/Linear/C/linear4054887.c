#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void sort(int x[],int num){
    int ret[num];
    int count=0;
    bool flag=false;
    for(int i=0;i<num;i++){
        ret[i]=x[i];
        for(int j=0;j<=i;j++){
            if(ret[i]==ret[j])
                count++;
        }
        if(count>1)
            ret[i]=393939;
        count=0;
    }
    memcpy(x,ret,num*sizeof(int));
}

int main(){
    int* array1,*array2;
    int n,q,counter=0;

    scanf("%d",&n);
    array1=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&array1[i]);
    }
    sort(array1,n);

    scanf("%d",&q);
    array2=malloc(sizeof(int)*q);
    for(int j=0;j<q;j++){
        scanf("%d",&array2[j]);
    }
    for(int k=0;k<q;k++){
        for(int l=0;l<n;l++){
            if(array1[l]==393939)
                continue;
            if(array2[k]==array1[l]){
                counter++;
            }
        }
    }
    printf("%d\n",counter);

   /* for(int t=0;t<n;t++){
        printf("%d ",array1[t]);
    }*/

    return 0;
}

