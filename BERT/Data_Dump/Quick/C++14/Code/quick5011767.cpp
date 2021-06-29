#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 500000
#define INFTY 2000000000

struct card{ // define card structure.
    char pict;
    int num;
};

card l[MAX/2 + 2],r[MAX/2 + 2];

void marge(card a[],int n, int left, int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++){
        l[i] = a[left + i];
    }
    for(int i = 0; i < n2; i++){
        r[i] = a[mid + i];
    }
    l[n1].num = r[n2].num = INFTY;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++){
        if(l[i].num <= r[j].num){
            a[k] = l[i++];
        }else{
            a[k] = r[j++];
        }
    }
}

void margesort(card a[],int n,int left,int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        margesort(a,n,left,mid);
        margesort(a,n,mid,right);
        marge(a,n,left,mid,right);
    }
}

int partition(card a[], int n, int p, int r){
    card x = a[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(a[j].num <= x.num){
            i++;
            swap(a[i],a[j]);
        }    
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void quicksort(card a[],int n,int p,int r){
    if(p < r){
        int q = partition(a,n,p,r);
        quicksort(a,n,p,q-1);
        quicksort(a,n,q+1,r);
    }
}

int main(){
    int n,v;
    card a[MAX],b[MAX];
    char s;
    bool stable = true;

    cin >> n;
    for(int i = 0;  i < n; i++){
        cin >> s >> v;
        a[i].pict = b[i].pict = s;
        a[i].num = b[i].num = v;
    }

    margesort(a,n,0,n);
    quicksort(b,n,0,n-1);

    for(int i = 0; i < n; i++){
        if(a[i].pict != b[i].pict){
            stable = false;
        }
    }
    if(stable){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }

    for(int i = 0; i < n; i++){
        cout << b[i].pict << " " << b[i].num << endl;
    }
    return 0;
}
