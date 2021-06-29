#include <iostream>
#include <fstream>

using namespace std;

void pp_seg(int *a,int a_size){
    for(int i=0;i<a_size;i++){
        cout << a[i];
        if(i!=a_size-1){
            cout << " ";
        }
    }
    cout << endl;
}

int maxSegment(int *a, int a_size){
    int ans = a[0];
    for(int i=0;i<a_size;i++){
        if(ans < a[i]){
            ans = a[i];
        }
    }
    return ans;
}

void countingSort(int *a, int a_size, int *b){
    int max_a = maxSegment(a,a_size);
    int *c = new int[max_a+1];
    for(int i=0;i<max_a+1;i++) c[i] = 0;
    for(int i=0;i<a_size;i++) c[a[i]]++;
    for(int i=1;i<max_a+1;i++) c[i] = c[i] + c[i-1];
    for(int j=a_size-1;j>=0;j--){
        b[c[a[j]]-1] = a[j];
        c[a[j]]--;
    }
}

int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int *b = new int[n];
    countingSort(a,n,b);
    for(int i=0; i<n;i++){
        cout << b[i];
        if(i!=n-1){
            cout << " ";
        }
    }
    cout << endl;
    delete [] a;
    delete [] b;
    return 0;
}

