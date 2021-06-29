#include<iostream>

using namespace std;

int input[100];
int output[100];
int number=0;

void insertion_sort(int a[]);
void print(int a[]);

int main(){
    cin>>number;
    for (int i=0; i<number; i++) {
        cin>>input[i];
    }
    insertion_sort(input);
}

void insertion_sort(int a[]){
    print(a);
    for (int j=1; j<number; j++) {
        int key = a[j];
        int i = j-1;
        while (i>=0 && a[i]>key) {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
        print(a);
    }
}

void print(int a[]){
    for (int i=0; i<number-1; i++) {
        cout<<a[i]<<" ";
    }
    cout<<a[number-1]<<endl;
}
