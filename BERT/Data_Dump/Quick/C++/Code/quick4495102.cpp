#include <bits/stdc++.h>
using namespace std;

struct Card{
    char a;
    int b;
};

bool compare_as_ints(Card i,Card j){
    return (i.b<j.b);
}

int partition(Card a[],int p,int r){
    Card x = a[r];
    int i = p-1;

    for(int j=p;j<=r-1;j++){
        if(a[j].b<=x.b){
            i++;

            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[r]);

    return i+1;
}


void quickSort(Card a[],int p,int r){
    if(p<r){
        int q = partition(a,p,r);
        quickSort(a,p,q-1);
        quickSort(a,q+1,r);
    }
}


int main(){
    int n;
    cin >> n;

    Card a[100000],b[100000];

    for(int i=0;i<n;i++){
        cin >> a[i].a >> a[i].b;
        b[i] = a[i];
    }

    quickSort(a,0,n-1);
    stable_sort(b,b+n,compare_as_ints);


    bool flg = true;

    for(int i=0;i<n;i++){
        if(!(a[i].a==b[i].a&&a[i].b==b[i].b)){
            flg = false;
            break;
        }
    }


    if(flg){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }

    for(int i=0;i<n;i++){
        cout << a[i].a << ' ' << a[i].b << endl;
    }

    return 0;
}
