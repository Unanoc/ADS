/*
 Дан вектор длины n. Сместить элементы вектора на k. k < n. pf
*/
#include <iostream>
#include <vector>

void inverse(std::vector<int> &vec, size_t begin, size_t end) {
    while (begin < end) {
        std::swap(vec[begin], vec[end]);
        begin++;
        end--;
    }
}

void displace(std::vector<int> &vec, size_t k) {
    inverse(vec, vec.size() - k, vec.size() - 1);
    inverse(vec, 0, vec.size() - k - 1);
    inverse(vec, 0, vec.size() - 1);
}

int main() {
    size_t n, k;
    std::cin >> n >> k;

    if (n <= k || k == 0)
        return 0;
    std::vector<int> vector(n);
    for (size_t i = 0; i < n; i++)
        std::cin >> vector[i];

    displace(vector, k);

    for(size_t i = 0; i < n; i++)
        std::cout << vector[i] << " ";

    return 0;
}
