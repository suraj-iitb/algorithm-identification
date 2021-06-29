#include<iostream>

using namespace std;
int selectionSort(int a[], int n){
    int count = 0;
	int i;
	int j;
    for (i = 0; i < n-1; i++){
        int pos = i;
        for (j = i; j < n; j++){
            if (a[j] < a[pos]){
                pos = j;
            }
        }
        swap(a[pos], a[i]);
        if (a[pos] != a[i]){
            count++;
        }
    }
    return count;
}

int main(){
    int n, a[100];
    cin>>n;
	int i;
    for (i = 0; i < n; i++){
        cin>>a[i];
    }
    int count = selectionSort(a, n);
    for ( i = 0; i < n; i++){
        if (i != n-1){
            cout<<a[i]<<" ";
        }else{
            cout<<a[i]<<endl;
        }
    }
    cout<<count<<endl;
}
