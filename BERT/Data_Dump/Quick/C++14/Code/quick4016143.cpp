#include<bits/stdc++.h>
using namespace std;

struct Card{
    char c;
    int num;
    bool operator<(const Card& rhs) const{
        return num<rhs.num;
    }
    bool operator<=(const Card& rhs) const{
        return num<=rhs.num;
    }
    bool operator==(const Card& rhs) const{
        return c==rhs.c and num==rhs.num;
    }
};

int main()
{
    int N; cin>>N;
    vector<Card> card(N);
    for(int i=0;i<N;i++) cin>>card[i].c>>card[i].num;
    vector<Card> tmp=card;

    auto partition=[&](int l,int r)
    {
        int i=l;
        for(int j=l;j<r;j++){
            if(card[j]<=card[r]) swap(card[i++],card[j]);
        }
        swap(card[i],card[r]);
        return i;
    };
    function<void(int,int)> quicksort=[&](int l,int r)
    {
        if(r-l>1){
            int m=partition(l,r-1);
            quicksort(l,m);
            quicksort(m+1,r);
        }
    };
    quicksort(0,N);
    stable_sort(tmp.begin(),tmp.end());
    bool stable=true;
    for(int i=0;i<N;i++){
        stable&=(card[i]==tmp[i]);
    }
    cout<<(stable? "Stable":"Not stable")<<endl;
    for(int i=0;i<N;i++) cout<<card[i].c<<' '<<card[i].num<<endl;
    return 0;
}
