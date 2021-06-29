#include <iostream>
#include <cstdio>
using namespace std;

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionsort(int array[],int number){
    int cnt = 0;
    int min;
    for(int i = 0;i < number;i++){
        min = i;
        for(int j = i+1;j < number;j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(i != min){
            swap(array[i],array[min]);
            cnt++;
        }
    }
    for(int i = 0;i < number;i++){
        if(i != 0) printf(" ");
        printf("%d",array[i]);
    }
    printf("\n%d\n",cnt);
}

int main(){
    int num;
    int origin[100];
    cin >> num;
    for(int i = 0;i < num;i++) cin >> origin[i];
    selectionsort(origin,num);
    return 0;
}
