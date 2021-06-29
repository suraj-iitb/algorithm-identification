#include <iostream>
#include <fstream>

using namespace std;

typedef struct trump{
    char suit;
    int num,id;
} trump_t;

void pp_trump(trump_t *t){
    cout << t->suit << " " << t->num << endl;
}

void swap(trump_t *a, trump_t *b){
    trump_t temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(trump_t *t,int t_size, int p, int r){
    int x = t[r].num;
    int i = p-1;
    for(int j=p;j<r;j++){
        if(t[j].num <= x){
            i++;
            swap(t+i,t+j);
        }
    }
    swap(t+i+1,t+r);
    return i+1;
}

void quickSort(trump_t *t, int t_size, int p ,int r){
    if(p<r){
        int q = partition(t,t_size,p,r);
        quickSort(t,t_size,p,q-1);
        quickSort(t,t_size,q+1,r);
    }
}

int checkStable(trump_t *t, int t_size){
    for(int i=0;i<t_size;i++){
        if(t[i].num == t[i-1].num){
            if(t[i].id < t[i-1].id){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int n;
    cin >> n;
    trump_t *t = new trump_t[n];
    for(int i=0;i<n;i++){
        cin >> t[i].suit >> t[i].num;
        t[i].id = i;
    }
    quickSort(t,n,0,n-1);
    if(checkStable(t,n)){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }
    for(int i=0;i<n;i++){
        pp_trump(t+i);
    }
    return 0;
}

