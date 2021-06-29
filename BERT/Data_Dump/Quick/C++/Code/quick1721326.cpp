#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>

#define MAX 100002
#define INF 2000000000

using namespace std;

typedef struct {
    int num;
    string suit;
    int ID;
} Card;

Card LEFT[MAX/2 + 2],RIGHT[MAX/2 + 2];

void comb(Card A[],int left,int mid,int right){
    int n1,n2;
    n1 = mid - left;
    n2 = right - mid;
    for (int i = 0; i < n1; i++) LEFT[i] = A[left + i];
    for (int i = 0; i < n2; i++) RIGHT[i] = A[mid + i];
    
    LEFT[n1].num = INF;
    RIGHT[n2].num = INF;
    
    int N = n1 + n2;
    int count_l=0,count_r=0;
    
    for (int i = 0; i < N; i++) {
        if (LEFT[count_l].num <= RIGHT[count_r].num) {
            A[left + count_l + count_r] = LEFT[count_l];
            count_l++;
        }else{
            A[left + count_l + count_r] = RIGHT[count_r];
            count_r++;
        }
    }
}

void MegeSort(Card A[],int left,int right){
    //cout << "Merge" << endl;
    int mid = (left + right)/2;
    if (right - left > 1) {
        MegeSort(A,left,mid);
        MegeSort(A,mid,right);
        comb(A,left,mid,right);
    }
}

int partition(Card A[],int left,int right){
    int index=0;
    int a = left;
    for (int i = left; i < right; i++) {
        if (A[i].num <= A[right - 1].num) {
            Card c = A[i];
            A[i] = A[a];
            A[a] = c;
            a++;
            index = a;
        }
    }
    return index;
}

void quicksort(Card A[],int left,int right){
    //cout << "quick" << endl;
    int index = partition(A,left,right);
    if (index - 1 - left > 1) {
        quicksort(A,left,index - 1);
    }
    if (right - index > 1) {
        quicksort(A,index,right);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    Card A[MAX+1];
    Card B[MAX+1];
    for (int i=0; i < n; i++) {
        char k[2];
        scanf("%s %d",k,&A[i].num);
        A[i].suit = k;
        A[i].ID = i;
        B[i]=A[i];
    }

    quicksort(A,0,n);
    MegeSort(B,0,n);
    int flag=0;
    for (int i = 0; i < n; i++) {
        if (B[i].ID != A[i].ID) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        cout << "Not stable" << endl;
    }else{
        cout << "Stable" << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << A[i].suit << " " << A[i].num << endl;
    }
    
    return 0;
}
