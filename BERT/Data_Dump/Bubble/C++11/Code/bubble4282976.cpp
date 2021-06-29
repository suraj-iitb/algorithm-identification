/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <iostream>
#include <cstdint>

class BubbleSort {
 public:
  BubbleSort() noexcept;
  ~BubbleSort() noexcept;
  void Main(std::istream &input_stream) noexcept;

 private:
  void Sort() noexcept;
  bool ShouldSwap(const int index_target) noexcept;
  void SwapWithLeftNext(const int32_t index_target) noexcept;
  void Load(std::istream &input_stream) noexcept;
  void Print() noexcept;

 private:
  BubbleSort(const BubbleSort &obj) noexcept = delete;
  BubbleSort &operator=(const BubbleSort &obj) noexcept = delete;
  BubbleSort(BubbleSort &&obj) = delete;
  BubbleSort &operator=(BubbleSort &&obj) = delete;

 private:
  int32_t count_;
  int32_t values_[100];
  int32_t swapped_count_;
};

BubbleSort::BubbleSort() noexcept : count_(0), values_{-1}, swapped_count_{0} {}

BubbleSort::~BubbleSort() noexcept {}

void BubbleSort::Main(std::istream &input_stream) noexcept {
  Load(input_stream);
  Sort();
  Print();
}

void BubbleSort::Sort() noexcept {
  bool should_scan = true;
  int32_t index_unsorted_head = 0;
  while (should_scan) {
    should_scan = false;
    for (int index_target = count_ - 1; index_target >= index_unsorted_head + 1; --index_target) {
      if (ShouldSwap(index_target)) {
        SwapWithLeftNext(index_target);
        should_scan = true;
      }
    }
    ++index_unsorted_head;
  }
}

bool BubbleSort::ShouldSwap(const int index_target) noexcept {
  return (values_[index_target - 1] > values_[index_target]);
}

void BubbleSort::SwapWithLeftNext(const int index_target) noexcept {
  const int32_t cvalue = values_[index_target];
  values_[index_target] = values_[index_target - 1];
  values_[index_target - 1] = cvalue;
  ++swapped_count_;
}

void BubbleSort::Load(std::istream &input_stream) noexcept {
  input_stream >> count_;
  for (int32_t index = 0; index < count_; ++index) {
    input_stream >> values_[index];
  }
}

void BubbleSort::Print() noexcept {
  for (int32_t index = 0; index < count_; ++index) {
    if (index != 0) {
      std::cout << " ";
    }
    std::cout << values_[index];
  }
  std::cout << std::endl;
  std::cout << swapped_count_ << std::endl;
}

int main(int32_t argc, char *argv[]) {
  BubbleSort *bubble_sort = new BubbleSort();
  bubble_sort->Main(std::cin);
  delete bubble_sort;
  return 0;
}

