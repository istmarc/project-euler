#include <iostream>

int main(){
  size_t res = 0;
  for (size_t a = 1; a <= 1000; a++) {
    for (size_t b = a+1; b <= 1000; b++) {
      size_t c = 1000 - a - b;
      if (c>0 && a*a + b*b == c*c) {
        res = a * b * c;
        break;
      }
    }
  }
  std::cout << res << std::endl;
}
