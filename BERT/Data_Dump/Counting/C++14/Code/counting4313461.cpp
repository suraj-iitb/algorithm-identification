/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <cstdint>
#include <iostream>
#include <string>

constexpr int32_t kMaxArraySize = 2000000;
constexpr int32_t kMaxIntegerValue = 10000;

void CallCountingSort(std::istream &input_stream);

class CountingSort {
 public:
  CountingSort() noexcept;
  ~CountingSort() noexcept;
  void AddData(const int32_t value);
  void ResetData() noexcept;
  void Sort();
  void Print() const noexcept;

 private:
  CountingSort(const CountingSort &obj) noexcept = delete;
  CountingSort &operator=(const CountingSort &obj) noexcept = delete;
  CountingSort(CountingSort &&obj) = delete;
  CountingSort &operator=(CountingSort &&obj) = delete;

  void ComputeCounts(void) noexcept;
  void ComputeCumulativeCounts(void) noexcept;
  void ComputeSortedOutput(void) noexcept;

 private:
  int32_t size_;
  int32_t input_values_[kMaxArraySize];
  int32_t counts_[kMaxIntegerValue + 1];
  int32_t output_values_[kMaxArraySize];
};

void CallCountingSort(std::istream &input_stream) {
  input_stream.tie(0);
  std::ios::sync_with_stdio(false);
  CountingSort *counting_sort = new CountingSort();
  try {
    int32_t count;
    input_stream >> count;
    for (int32_t index = 0; index < count; ++index) {
      int32_t cvalue;
      input_stream >> cvalue;
      counting_sort->AddData(cvalue);
    }
    counting_sort->Sort();
    counting_sort->Print();
  } catch (...) {
    std::cout << "ERROR: CallCountingSort()" << std::endl;
    throw;
  }
  delete counting_sort;
}

// ****************************************************

CountingSort::CountingSort() noexcept : size_(0), input_values_{}, output_values_{} {
  for (int32_t &ccount : counts_) {
    ccount = 0;
  }
}
CountingSort::~CountingSort() noexcept {}

void CountingSort::AddData(const int32_t value) {
  if (size_ >= kMaxArraySize) {
    std::cout << "ERROR: AddData(): Data size exceeded a limit = " << kMaxArraySize << std::endl;
    throw 1;
  }
  input_values_[size_] = value;
  size_++;
}

void CountingSort::Sort() {
  try {
    ComputeCounts();
    ComputeCumulativeCounts();
    ComputeSortedOutput();
  } catch (...) {
    std::cout << "ERROR: Sort()" << std::endl;
    throw;
  }
}

void CountingSort::Print() const noexcept {
  for (int32_t index = 0; index < size_; ++index) {
    if (index != 0) {
      std::cout << " ";
    }
    std::cout << output_values_[index];
  }
  std::cout << std::endl;
}

void CountingSort::ResetData() noexcept {
  size_ = 0;
}

void CountingSort::ComputeCounts(void) noexcept {
  for (int32_t index_input = 0; index_input < size_; ++index_input) {
    ++counts_[input_values_[index_input]];
  }
}

void CountingSort::ComputeCumulativeCounts(void) noexcept {
  for (int32_t index_count = 1; index_count <= kMaxIntegerValue; ++index_count) {
    counts_[index_count] += counts_[index_count - 1];
  }
}

void CountingSort::ComputeSortedOutput(void) noexcept {
  for (int32_t index_input = size_ - 1; index_input >= 0; --index_input) {
    const int32_t current_input_value = input_values_[index_input];
    output_values_[counts_[current_input_value] - 1] = current_input_value;
    --counts_[current_input_value];
  }
}

int main(int argc, char *argv[]) {
  try {
    CallCountingSort(std::cin);
  } catch (...) {
    std::cout << "ERROR: main()" << std::endl;
  }
  return 0;
}

