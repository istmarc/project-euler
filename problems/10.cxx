#include <iostream>
#include <vector>

size_t crible_somme(size_t n) {
  std::vector<bool> isprime(n, true);
  isprime[0] = false;
  for (size_t i = 1; i < n; i++) {
    size_t j = 2;
    while ((i+1)*j <= n) {
      isprime[(i+1)*j - 1] = false;
      j++;
    }
  }
  size_t s = 0;
  for (size_t i = 0; i < n; i++) {
    if (isprime[i]) {
        s += i + 1;
    }
  }
  return s;
}

int main() {
  constexpr size_t n = 1999999;
  std::cout << crible_somme(n) << std::endl;
}
