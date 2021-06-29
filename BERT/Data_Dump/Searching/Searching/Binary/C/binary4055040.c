#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


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
    int* array1,*array2,*array3;
    int n,q,counter=0;
    int left=0;
    int right;
    int mid;
    int l=0;

    scanf("%d",&n);
    array1=malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        scanf("%d",&array1[i]);
    }
    //sort(array1,n);

    scanf("%d",&q);
    array2=malloc(sizeof(int)*q);
    for(int j=0;j<q;j++){
        scanf("%d",&array2[j]);
    }

    /*for(int k=0;k<n;k++){
        if(array1[k]!=393939){
            array3[l]=array1[k];
            //printf("%d ",array3[l]);
            l++;
        }
    }*/

    for(int m=0;m<q;m++){
        left=0;
        right=n;
        while(left<right){
            mid=(left+right)/2;
            if(array1[mid]==array2[m]){
                counter++;
                break;
            }
            else if(array2[m]<array1[mid])
                right=mid;
            else
                left=mid+1;
        }
    }
    printf("%d\n",counter);
    return 0;
}

