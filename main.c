#include "System.h"
#include <stdio.h>

int main() {

  System_t ATM;
  ATM.Run = run;
  ATM.Run();

  return 0;
}
