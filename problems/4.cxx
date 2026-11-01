#include <iostream>
#include <string>

bool is_palindrome(size_t k) {
  std::string s = std::to_string(k);
  size_t n = s.size();
  size_t i = 0;
  while (i < n / 2) {
    if (s[i] != s[n-1-i]) {
        return false;
    }
    i++;
  }
  return true;
}

int main() {
  size_t p = 0;
  for (size_t i = 0; i < 999;i++) {
    for (size_t j = 0; j < 999; j++) {
      size_t k = (i+1)*(j+1);
      if (is_palindrome(k) && k > p) {
        p = k;
      }
    }
  }
  std::cout << p << std::endl;
}
