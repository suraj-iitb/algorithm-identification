/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <cstdint>
#include <iostream>

constexpr int32_t kMaxArraySize = 100;

class SelectionSort {
 public:
  SelectionSort() noexcept;
  ~SelectionSort() noexcept;
  void Main(std::istream &input_stream) noexcept;

 private:
  void Sort() noexcept;
  int32_t FindMinimumIndex(int32_t index_unsorted_top) const noexcept;
  void Swap(const int32_t index_unsorted_top, const int32_t index_minimum) noexcept;
  void Load(std::istream &input_stream) noexcept;
  void Print() noexcept;

 private:
  SelectionSort(const SelectionSort &obj) noexcept = delete;
  SelectionSort &operator=(const SelectionSort &obj) noexcept = delete;
  SelectionSort(SelectionSort &&obj) = delete;
  SelectionSort &operator=(SelectionSort &&obj) = delete;

 private:
  int32_t count_;
  int32_t values_[kMaxArraySize];
  int32_t swapped_count_;

};

SelectionSort::SelectionSort() noexcept : count_(0), values_{-1}, swapped_count_{0} {}

SelectionSort::~SelectionSort() noexcept {}

void SelectionSort::Main(std::istream &input_stream) noexcept {
  Load(input_stream);
  Sort();
  Print();
}

void SelectionSort::Sort() noexcept {
  for (int32_t index_unsorted_top = 0; index_unsorted_top < count_; ++index_unsorted_top) {
    const int32_t index_minimum = FindMinimumIndex(index_unsorted_top);
    if (index_unsorted_top != index_minimum) {
      Swap(index_unsorted_top, index_minimum);
    }
  }
}

int32_t SelectionSort::FindMinimumIndex(int32_t index_unsorted_top) const noexcept {
  int32_t index_minimum = index_unsorted_top;
  for (int32_t index_scan = index_unsorted_top; index_scan < count_; ++index_scan) {
    if (values_[index_scan] < values_[index_minimum]) {
      index_minimum = index_scan;
    }
  }
  return index_minimum;
}

void SelectionSort::Swap(const int32_t index_unsorted_top, const int32_t index_minimum) noexcept {
  const int32_t value_top = values_[index_unsorted_top];
  values_[index_unsorted_top] = values_[index_minimum];
  values_[index_minimum] = value_top;
  ++swapped_count_;
}

void SelectionSort::Load(std::istream &input_stream) noexcept {
  input_stream >> count_;
  for (int32_t index = 0; index < count_; ++index) {
    input_stream >> values_[index];
  }
}

void SelectionSort::Print() noexcept {
  for (int32_t index = 0; index < count_; ++index) {
    if (index != 0) {
      std::cout << " ";
    }
    std::cout << values_[index];
  }
  std::cout << std::endl;
  std::cout << swapped_count_ << std::endl;
}

int main(int argc, char *argv[]) {
  SelectionSort *selection_sort = new SelectionSort();
  selection_sort->Main(std::cin);
  delete selection_sort;
  return 0;
}

