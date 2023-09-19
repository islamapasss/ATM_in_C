#include "Server.h"
#include "Transactions.h"


typedef struct System {
  // pointer to function run
  void (*Run)(void);

} System_t;

void run(void);
int menu(void);



