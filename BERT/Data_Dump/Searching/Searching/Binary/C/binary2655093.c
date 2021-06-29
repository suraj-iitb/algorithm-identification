#include<stdio.h>

int S[100000], T[50000], C = 0;

void binarysearch(int,int,int);

int main(){
    //??\???
    int n, q;
    scanf("%d",&n);
    //printf("%d\n",n);
    for(int i = 0; i < n; i++){
        scanf("%d",&S[i]);
        //printf("%d ",S[i]);
    }//S??????????????????????????????
    //printf("\n");
    scanf("%d",&q);
    //printf("%d\n",q);
    for(int j = 0; j < q; j++){
        scanf("%d",&T[j]);
        //printf("%d ",T[j]);
        
    }
    //printf("\n");//T??????????????????????????????
    
   
    for(int k = 0; k < q; k++){
        binarysearch(0,n,T[k]);
    }
    printf("%d\n",C);
    return 0;
}


void binarysearch(left,right,key){
    int mid = (left + right)/2;
    if(left < right){
        if (S[mid] == key){
            //printf("%d ",mid);
            C++;
        }
        else{
            if(S[mid] < key){
                binarysearch(mid+1,right,key);
            }
            else{
                binarysearch(left, mid,key);
            }
        }
    }
}
