#include <iostream>
#include <string>
#define INF 1<<30
using namespace std;

int cnt = 0, n;
class Node{
    private:
    char sign;
    unsigned int num;
    public:
    Node(): sign('O'), num(0){};
    Node(char sign, int num){
        this->sign = sign;
        this->num = num;
    };
    int getnum(){
        return this->num;
    };
    char getsign(){
        return this->sign;
    };
    void setnum(int n){
        this->num = n;
    }
    void setsign(char sign){
        this->sign = sign;
    }
};
void merge(Node *A, int left, int mid, int right){
    int n1 = mid - left, n2 = right - mid;
    Node L[n1+1], R[n2+1];
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1].setnum(INF), R[n2].setnum(INF);

    int curL = 0, curR = 0;
    for (int k = left; k < right; k++){
        if (L[curL].getnum() <= R[curR].getnum()){
            A[k].setnum(L[curL].getnum());
            A[k].setsign(L[curL].getsign());
            curL++;
        }else{
            A[k] = R[curR];
            A[k].setnum(R[curR].getnum());
            A[k].setsign(R[curR].getsign());
            curR++;
        }
        cnt++;
    }
    return;
}

void mergeSort(Node *A, int left, int right){
    if (left+1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(Node *array, int l, int r){
    int pivot = array[r].getnum();
    int i = l - 1;

    for (int j = l; j < r; j++){
        if (array[j].getnum() <= pivot){
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1], array[r]);
    return (i + 1);
}

void quicksort(Node *array, int l, int r){
    if (l < r){
        int pivot = partition(array, l, r);
        quicksort(array, l, pivot-1);
        quicksort(array, pivot+1, r);
    }
}

void display(Node * a){
    for (int i = 0; i < n; i++){
        printf("%c %d\n", a[i].getsign(), a[i].getnum());
    }
}

bool comapre(Node *s, Node *t){
    int i = n;
    bool flag = true;
    while(--i){
        //printf("s[%d] = %d%c, t[%d] = %d%c\n", i, s[i].getnum(), s[i].getsign(), i, t[i].getnum(), t[i].getsign());
        if ((s[i].getnum() == t[i].getnum()) &&
                (s[i].getsign() == t[i].getsign()))
                continue;
        else{
            flag = false;
            break;
        }
    }
    return flag;
}
int main(int argc, char* argv[]) {
    Node p;
    char c;
    int num;
    cin >> n;
    Node s[n], t[n];
    for (int i = 0; i < n; i++){
        cin >> c >> num;
        s[i].setsign(c);
        s[i].setnum(num);
        t[i].setsign(c);
        t[i].setnum(num);
    }
    quicksort(s, 0, n-1);
    mergeSort(t, 0, n);

    cout << (comapre(s, t)? "Stable": "Not stable") << endl;
    display(s);
    return 0;
}

