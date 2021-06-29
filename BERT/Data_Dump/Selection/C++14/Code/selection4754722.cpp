#include<iostream>

using namespace std;

static const int MAX = 100;

void printStringnum(int a[],int n){
    for(int i=0;i<n-1;i++){
        cout << a[i] << " ";
    }    
    cout << a[n-1] << "\n";
}


int selectionSort(int a[],int n){
    int count = 0;
    int i,j,num,flag;
    for(i = 0;i<n;i++){
        int lead = a[i];
        flag = 0;
        for(j = i+1;j<n;j++){
        if(lead > a[j]){
            lead= a[j];
            num = j;
            flag = 1;
        }
        }
        if(flag){
        a[num] = a[i];
        a[i] = lead;
        count++;
        //printStringnum(a,n);
        }
    }
    printStringnum(a,n);
    return count;
}

int main(){
    int n,count;
    int a[MAX];

    cin >> n;

    for(int i = 0;i<n;i++){
        cin >> a[i];
    }

    count = selectionSort(a,n);
    cout << count << "\n";

}
