#include <stdio.h>

int bitAnd(int x, int y) { return ~((~x) | (~y)); }

int main() {
  printf("%d", bitAnd(2, 3));
  return 0;
}
