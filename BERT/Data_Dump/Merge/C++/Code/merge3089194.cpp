#include <iostream>
#include <fstream>

#define INF 1000000001
using namespace std;

int counter =0;

void merge(int *a, int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int *l = new int[n1+1];
    int *r = new int[n2+1];
    for(int i=0;i<n1;i++) l[i] = a[left+i];
    for(int i=0;i<n2;i++) r[i] = a[mid+i];
    l[n1] = r[n2] = INF;
    int i=0,j=0;
    for(int k= left;k<right;k++){
        if(l[i] <= r[j]){
            a[k] = l[i];
            i++;
        }else{
            a[k] = r[j];
            j++;
        }
        counter++;
    }

    delete [] l;
    delete [] r;
}

void mergeSort(int *a, int left, int right){
    if(left+1 < right){
        int mid = (left + right) /2;
        mergeSort(a,left,mid);
        mergeSort(a,mid,right);
        merge(a,left,mid,right);
    }
}

int main(){

    int n;
    cin >> n;
    int *s = new int[n];
    for(int i=0;i<n;i++) cin >> s[i];
    mergeSort(s,0,n);
    for(int i=0;i<n;i++){
        cout << s[i];
        if(i!=n-1){
            cout << " ";
        }
    }
    cout << endl;
    cout << counter << endl;

    delete [] s;
    return 0;
}

