#include <iostream>
#include <vector>
using namespace  std;

void fnOutput(const vector<int> &argviSort, int argiSortCnt)
{
  for (int i = 0; i < argviSort.size(); i++)
  {
    if (i) cout << " ";
    cout << argviSort[i];
  }
  cout << endl;
  cout << argiSortCnt << endl;
}

void fnBubbleSort(vector<int> &argviSort, int &argiSortCnt)
{
  int ixSorting = 0;
  bool bSorting = true;

  while (bSorting)
  {
    bSorting = false;
    for (int i = argviSort.size() - 1; i > ixSorting; i--)
    {
      if (argviSort[i] < argviSort[i - 1])
      {
        bSorting = true;
        swap(argviSort[i], argviSort[i - 1]);
        argiSortCnt++;
      }
    }
    ixSorting++;
  }
}
    
int main()
{
  int iSortCnt = 0;
  vector<int> viSort;
  int iMaxSize;
  
  cin >> iMaxSize;
  for (int i = 0; i < iMaxSize; i++)
  {
    int iNum;
    cin >> iNum;
    viSort.push_back(iNum);
  }

  fnBubbleSort(viSort, iSortCnt);
  fnOutput(viSort, iSortCnt);

  return 0;
}
