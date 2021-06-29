#include<iostream>
#include<algorithm>

using namespace std;

int number=0;
int a[100];
int numberOfSwap;

void bubble_sort(int a[]);
void print(int a[]);

int main(){
    numberOfSwap=0;
    cin>>number;
    for (int i=0; i<number; i++) {
        cin>>a[i];
    }
    bubble_sort(a);
    print(a);
    cout<<numberOfSwap<<endl;
}

void bubble_sort(int a[]){
    for (int i=0; i<number; i++) {
        for (int j=number-1; j>i; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j],a[j-1]);
                numberOfSwap++;
            }
        }
    }
}

void print(int a[]){
    for (int i=0; i<number-1; i++) {
        cout<<a[i]<<" ";
    }
    cout<<a[number-1]<<endl;
}
