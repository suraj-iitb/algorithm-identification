#include <stdio.h>

int ReadValue() {
    int value; 
    scanf("%d",&value);
    return value;
}
int linearSearch(int *Array,int index,int key) {
    int i;
    for (i=0; i<index; i++) {
        if (Array[i]==key) {
            return 1;
        }
    }
    return 0;
}
void ReadArray(int *Array,int index) {
    int i;
    for (i=0; i<index; i++) {
        scanf("%d",&Array[i]);
    }
}
int solve(int *Array,int index,int *Array1,int index1) {
    int ans=0;
    for (int i=0; i<index1; i++) {
        if (linearSearch(Array,index,Array1[i])) {
            ans++;
        }
    }
    return ans;
}
void display(int *Array,int index,int *Array1,int index1) {
    printf("%d\n",solve(Array,index,Array1,index1));
}
int main() {
    int n=ReadValue();
    int S[n]; ReadArray(S,n);
    int q=ReadValue();
    int T[q]; ReadArray(T,q);
    display(S,n,T,q);
    return 0;
}
