#include<iostream>
using namespace std;
#define MAX 500000
#define INFTY 2000000000

int l[MAX/2 + 2],r[MAX/2 + 2];
int cnt;

void marge(int a[],int n, int left, int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++){
        l[i] = a[left + i];
    }
    for(int i = 0; i < n2; i++){
        r[i] = a[mid + i];
    }
    l[n1] = r[n2] = INFTY;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
        cnt++;
        if(l[i] <= r[j]){
            a[k] = l[i++];
        }else{
            a[k] = r[j++];
        }
    }
}

void margesort(int a[],int n,int left,int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        margesort(a,n,left,mid);
        margesort(a,n,mid,right);
        marge(a,n,left,mid,right);
    }
}

int main(){
    int a[MAX],n;
    cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    margesort(a,n,0,n);

    for(int i = 0; i < n-1; i++){
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << cnt << endl;

    return 0;
}
