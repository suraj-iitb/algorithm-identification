#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int bubbleSort(int,int []);
void trace(int,int []);

int main(){
    int N,i,l;
    cin >> N;
    int a[N];

    for(i=0;i<N;i++){
        cin >> a[i];
    }

    l = bubbleSort(N,a);
    cout << l << "\n";




    return 0;
}

int bubbleSort(int N, int a[]){
    int i,tmp,count=0,flag=1;
    while(flag){
        flag = 0;
        for(i=N-1;i>=1;i--){
            if(a[i]<a[i-1]){
                tmp = a[i];
                a[i] = a[i-1];
                a[i-1] = tmp;
                flag = 1;
                count++;
            }
        }
    }
    trace(N,a);
    return count;
}

void trace(int N,int a[]){
    for(int i=0; i<N; i++){
        if(i<N-1){
            cout << a[i] << " ";
        } else{
            cout << a[i] << "\n";
        }
    }
    return;
}
