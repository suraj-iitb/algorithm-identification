#include<stdio.h>

int main(){
    int i,j,k,num1,first[10000],num2,second[10000],same=0;
    //一つ目の数列
    scanf("%d",&num1);
    for(int i=0;i<num1;i++){
        scanf("%d",&first[i]);
    }
/*
    //デバッグ
    for(int i=0;i<num1;i++){
        printf("%d ",first[i]);
    }
    */

    //二つ目の数列
    scanf("%d",&num2);
    for(i=0;i<num2;i++){
        scanf("%d",&second[i]);
    }
    /*
     //デバッグ
    for(i=0;i<num2;i++){
        printf("%d",second[i]);
    }
    printf("\n");
    */
     for(j=0;j<num2;j++){
         for(k=0;k<num1;k++){
           if(first[k]==second[j]){
            same++;
            break;
           }
         }
     }
    printf("%d\n",same);

    return 0;
}
/*
scanf()
for(i=0;i<n;i++){
    scanf k
    for(j=0;f[j] != k j++) sum++; 
}
*/
