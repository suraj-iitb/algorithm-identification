#include <stdio.h>

int main(){
    int i,j,quantity1,quantity2,time = 0;
    int isChecked[10005];
    int checker[5000];

    scanf("%d", &quantity1);
    for(i = 0; i < quantity1; i++){
        scanf("%d", &isChecked[i]);
    }
    scanf("%d", &quantity2);
    for(i = 0; i < quantity2; i++){
        scanf("%d", &checker[i]);
    }

    for(i = 0; i < quantity2; i++){
        for(j = 0; j < quantity1; j++){
            if(isChecked[j] == checker[i]){
                time++;
                break;
            }
        }
    }
    printf("%d\n", time);
    return 0;
}

