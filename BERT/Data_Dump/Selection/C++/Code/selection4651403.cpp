#include<iostream>
#include<algorithm>

using namespace std;

void selection_sort(int a[]);
void print(int a[]);

int number=0;
int a[100];
int numberOfSwap=0;

int main(){
    cin>>number;
    for (int i=0; i<number; i++) {
        cin>>a[i];
    }
    selection_sort(a);
    print(a);
    cout<<numberOfSwap<<endl;
}

void selection_sort(int a[]){
    for (int i=0; i<number; i++) {
        int mini = i;
        for (int j=i; j<number; j++) {
            if (a[j]<a[mini]) {
                mini = j;
            }
        }
        if (i!=mini) {
            swap(a[i],a[mini]);
            numberOfSwap++;
        }
    }
}

void print(int a[]){
    for (int i=0; i<number-1; i++) {
        cout<<a[i]<<" ";
    }
    cout<<a[number-1]<<endl;
}

