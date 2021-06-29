#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int x, y[1000] = {};
    int v, j;
    cin >> x;
    for (int i = 0;i < x;i++){
        cin >> y[i];
    }
    for(int i = 0;i < x;i++){
        if(i != x-1){
            printf("%d ", y[i]);
        }
        else{
            printf("%d\n", y[i]);
        }
    }
    for (int i = 1;i < x;i++){
        v = y[i];
        j = i - 1;
        while(j >= 0 && y[j] > v){
            y[j+1] = y[j];
            j--;
        }
        y[j+1] = v;
        for(int i = 0;i < x;i++){
            if(i != x-1){
                printf("%d ", y[i]);
            }
            else{
                printf("%d\n", y[i]);
            }
        }
    }
    return 0;
}
