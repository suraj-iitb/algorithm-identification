#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Card {
    public:
    char suit;
    int value;
    void printCard(){
        cout << suit << " " << value << endl; 
    }
    bool equal(Card a){
        if((suit == a.suit)&&(value == a.value)) {
            return true;
        }
        return false;
    }
};

void swap(Card &a, Card &b) {
    Card buf;
    buf = a;
    a = b;
    b = buf;
}

int partition(vector<Card> &A, int p, int r) {
    int x = A[r].value;
    int i = p-1;
    for(int j = p; j < r; j++) {
        if(A[j].value <= x) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(vector<Card> &A, int p, int r) {
    if(p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

void merge(vector<Card> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<Card> L(n1 + 1);
    vector<Card> R(n2 + 1);
    for(int i=0;i<n1;i++) {
        L[i] = A[left + i];
    }
    for(int i=0;i<n2;i++) {
        R[i] = A[mid + i]; 
    }
    L[n1].value = 1000000010;
    R[n2].value = 1000000010;
    int i=0, j=0;
    for(int k = left; k < right; k++) {
        if(L[i].value <= R[j].value) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(vector<Card> &A, int left, int right) {
    if(left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
//    ifstream in("ALDS1_6_C_Quick_Sort_input.txt");
//    cin.rdbuf(in.rdbuf());
    
    int n;
    cin >> n;
    vector<Card> A(n);
    for(int i=0;i<n;i++) {
        cin >> A[i].suit >> A[i].value;
    }
    
    vector<Card> B(n);
    B = A;
    
    quickSort(A, 0, n-1);
    merge_sort(B, 0, n);
    
    bool judge = true;
    for(int i=0;i<n;i++) {
        if(!A[i].equal(B[i])) {
            judge = false;
            break;
        }
    }
    if(judge) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }
    
    for(int i=0;i<n;i++) {
        A[i].printCard();
    }

    return 0;
}
