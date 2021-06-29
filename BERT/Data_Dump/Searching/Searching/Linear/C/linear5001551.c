#include <stdio.h>

int main() {
    int arrsize, query, matchtime = 0;
    scanf("%d", &arrsize);
    int arr[arrsize];
    for (int i = 0; i < arrsize; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &query);
    for (int h = 0; h < query; h++){
        int temp;
        scanf("%d", &temp);
        for (int i = 0; i < arrsize; i++){
            if (arr[i] == temp){
                matchtime++;
                break;
            }
        }
    }
    printf("%d\n", matchtime);
}
