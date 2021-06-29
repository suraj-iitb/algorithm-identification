#include <iostream>
#include <string>
#include<vector>
using namespace std;

static const int MAX = 100;

void printStringnum(int a[],int n){
    for(int i=0;i<n-1;i++){
        cout << a[i] << " ";
    }    
    cout << a[n-1] << "\n";
}

void inserstionSort(int a[],int n){
    int v,j;
    for(int i=1;i<n;i++){
        printStringnum(a,n);
        v = a[i];
        j = i-1;
        while(j>=0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
    }
    printStringnum(a,n);
}

int bubbleSort(int a[],int n){
    int v,i,j;
    int count = 0;
    int flag = 1;
    for(i=0;flag;i++){
        flag = 0;
        for(j=n-1;j>=i+1;j--){
            v = a[j-1];
            if(v > a[j]){
                a[j-1] = a[j];
                a[j] = v;
                flag = 1;
                count++;
            }
        }
    }
    
    printStringnum(a,n);
    return count;

}


int main(){
    int n,count;

    cin >> n;
    
    int a[MAX];

    for(int i=0;i<n;i++){
    cin >> a[i];
    //cout << a[i];
    }

    //inserstionSort(a,n);
    count = bubbleSort(a,n);
    cout << count << "\n";
    }
