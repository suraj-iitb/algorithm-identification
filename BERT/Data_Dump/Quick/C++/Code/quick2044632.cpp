#include <iostream>
#include <vector>
#include <algorithm>

struct TCard
{
    char Suit;
    int  Num;
    bool operator==(const TCard& C)const
    {
        return Suit == C.Suit && Num == C.Num;
    }
    bool operator <(const TCard& C)const
    {
      return Num < C.Num;
    }
    bool operator <=(const TCard& C)const
    {
        return Num <= C.Num;
    }
};
typedef std::vector<TCard> TList;

int partition(TList& A, int p, int r)
{
  int i = p - 1;
  for(int j = p; j < r; ++j){
    if(A[j] <= A[r]){
      i = i + 1;
      std::swap(A[i],A[j]);
    }
  }
  std::swap(A[i+1],A[r]);
  return i+1;
}

void quickSort(TList& A, int p, int r)
{
  if(p < r){
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}
TList Input()
{
    int Count;
    std::cin >> Count;
    TList List(Count);
    for(int i = 0; i < Count; ++i){
        std::cin >> List[i].Suit;
        std::cin >> List[i].Num;
    }
    return List;
}
void Output(const TList& List)
{
    TList::const_iterator It = List.begin();
    std::cout << It->Suit << " " << It->Num;
    for(++It; It != List.end(); ++It){
        std::cout << "\n" << It->Suit << " " << It->Num;
    }
    std::cout << std::endl;
}
void Check(const TList& List, const TList& Stable)
{
    if(std::equal(List.begin(), List.end(), Stable.begin())){
        std::cout << "Stable" << std::endl;
    }else{
        std::cout << "Not stable" << std::endl;
    }
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    const TList List = Input();
    TList StableList = List;
    std::stable_sort(StableList.begin(), StableList.end());

    TList QuickList = List;
    quickSort(QuickList, 0, QuickList.size() - 1);
    Check(QuickList, StableList);
    Output(QuickList);
    return 0;
}
