#include <iostream>
#include <numeric>
#include <string>
#include <utility>

template<typename T>
T VectorSum(const std::vector<T>& vector, T initialValue) {
    return std::accumulate(vector.begin(), vector.end(), initialValue);
}

int main() {
    std::cout << VectorSum({1, 2, 3, 4, 5}, 3) << std::endl;
    std::pair<std::string, double> pair {"Hello, World", 42};
    const auto& [str, num] = pair;
    std::cout << str << ": " << num << std::endl;
}
