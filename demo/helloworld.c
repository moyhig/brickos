#include <conio.h>
#include <unistd.h>

int main(int argc, char **argv) {
  cputs("hello");
  sleep(1);
  cputs("world");
  sleep(1);
  cls("     ");
  
  return 0;
}
