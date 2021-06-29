#include <iostream>
#include <cstdio>
using namespace std;

void swap(int *a,int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubblesort(int array[],int number){
    int cnt = 0;
    for(int i = 0;i < number;i++){
        for(int j = number-1;j > i;j--){
            if(array[j-1] > array[j]){
                swap(array[j-1],array[j]);
                cnt++;
            }
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
    bubblesort(origin,num);
    return 0;
}
