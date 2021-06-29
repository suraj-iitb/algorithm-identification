#include<iostream>

using namespace std;

// static variable slows down the program!!
//static int swap_cnt=0;

/*
int swap(int *a, int *b){
    int buf=*a;
    *a=*b;
    *b=buf;
    return 1;
}
*/

int bubbleSort(int a[], int n){

    bool flag=true;
    int i=0;    // i is # of elems already in right position

    int sw=0;

    while(flag){
        flag=false;
        for(int j=n-1;j>=i+1;j--){    // start from last index, j is immigrant cadidate, from init(n-1) to limit(i+1) represents max # of swap needed.   
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
                sw++;
                flag=true;
            }
        }
    }

    i++;

    return sw;
}

// insertion sortと違い, 後ろから一個ずつ交換.

int main(){

    int n=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int sw=bubbleSort(a,n);

    //for(int x:a)cout<<x<<" "; // slows down the program!!
    for(int i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<a[i];
    }
    
    cout<<endl;
    cout<<sw<<endl;


    return 0;
}
