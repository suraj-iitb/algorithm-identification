#include<stdio.h>
//#include<stdlib.h>



int linearSearch(int,int);

int S[1000000000];



int main(){


    int n,i,q,j = 0,key,num = 0;

    scanf("%d",&n);

    //if(n > 10000)exit(0);

    for(i = 0;i < n;i++){

        scanf("%d",&S[i]);
    }

    scanf("%d",&q);
    
    for(i = 0;i < q;i++){

        scanf("%d",&key);

        if(linearSearch(n,key) == 1){

            num++;
        }
    }
    printf("%d\n",num);

    return 0;
}

int linearSearch(int n,int key){

    int i = 0,j = 0;

    S[n] = key;
    while(S[i] != key){
        i++;
        if(i == n){

            return 0;
        }
    }

    
    return 1;
}

