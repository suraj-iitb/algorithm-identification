#include <vector>
#include <iostream>

template <typename T>
void dump_vector(const std::vector<T>& src)
{
  for (int i = 0; i < src.size()-1; ++i)
  {
    std::cout << src[i] << ' ';
  }
  std::cout << src.back() << std::endl;
}

template <typename T>
void insertion_sort(std::vector<T>* xs)
{
  for (int i = 1; i < xs->size(); ++i) // xs[i-1]?????§?????????????????? ?????§?????????xs[i]???????´??????????
  {
    dump_vector(*xs);
    T target = (*xs)[i];
    int j = i-1;
    while (j >= 0  && target < (*xs)[j]) {
      (*xs)[j+1] = (*xs)[j];
      --j;
    }
    (*xs)[j+1] = target;
  }
  dump_vector(*xs);
}

int main()
{
  int n;
  std::vector<int> xs{};

  std::cin >> n;
  xs.resize(n);

  for (int i = 0; i < n; ++i)
  {
    std::cin >> xs[i];
  }

  insertion_sort(&xs);

  return 0;
}
