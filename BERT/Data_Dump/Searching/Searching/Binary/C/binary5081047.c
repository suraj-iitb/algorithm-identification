#include<stdio.h>
#include<stdlib.h>

int search(int,int);


int S[1000000000];

int main(){

  

    int q,i,key,cnt = 0,n;

    scanf("%d",&n);

    if(n > 100000)exit(0);

    for(i = 0;i < n;i++){

        scanf("%d",&S[i]);
    }

    scanf("%d",&q);

    if(q > 50000)exit(0);

    for(i = 0;i < q;i++){

        scanf("%d",&key);

        if(search(key,n) == 1){

            cnt = cnt + 1;
        }

            
    

    }

    printf("%d\n",cnt);

    return 0;
}

int search(int key,int n){

    int right,left = 0,mid;

    right = n;

    while(left < right){

        mid = (left + right)/2;

        if(key == S[mid]){
            //printf(" %d",key);
            return 1;
        }
        if(key > S[mid]){

            left = mid + 1;

        }

        else if(key < S[mid]){

            right = mid;
        }


    }

    
    return 0;
    

}



    



