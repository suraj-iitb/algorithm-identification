#include<iostream>

using namespace std;

void swap(int *v, int *u){
    int temp = *v;
    *v = *u;
    *u = temp;
}

void BubbleSort(int a[], int n, int *count){
    int flag = 1;
    while(flag){
        flag = 0;
        for(int j=n-1;j>=1;j--){
            if(a[j]<a[j-1]){
                swap(&a[j], &a[j-1]);
                flag = 1;
                *count = *count + 1;
            }
        }
    }
}

int main(void){
    int n, count = 0;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    BubbleSort(a, n, &count);
    for(int i=0;i<n;i++){
        if(i>0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}
