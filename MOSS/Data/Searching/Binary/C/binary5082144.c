#include <stdio.h>

int main(){
    int i,j,k,quantity1,quantity2,time = 0;
    int mid,right,left;
    int isChecked[100000];
    int checker[50000];

    scanf("%d", &quantity1);
    for(i = 0; i < quantity1; i++){
        scanf("%d", &isChecked[i]);
    }
    scanf("%d", &quantity2);
    for(i = 0; i < quantity2; i++){
        scanf("%d", &checker[i]);
    }

    for(i = 0; i < quantity2; i++){
        left = 0;
        right = quantity1;

        while(left < right){
           int mid = (right + left) / 2;
            if(isChecked[mid] == checker[i]){
                time++;
                //printf("OK!\n");
                break;
            }
            else if(isChecked[mid] > checker[i]){
                right = mid;
                //printf("%d %d %d\n", right, left, mid);
            }
            else if(isChecked[mid] < checker[i]){
                left = mid + 1;
                //printf("%d %d %d\n", right, left, mid);
            }
        }
    }
    printf("%d\n", time);
    return 0;
}
