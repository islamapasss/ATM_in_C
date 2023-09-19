#include "Server.h"
#include <conio.h>
#include <stdio.h>

DataBase_t Server_DataBase[DATABASE_SIZE] = {

    [0].id = 1, [0].password = 111, [0].balance = 1000,
    [1].id = 2, [1].password = 222, [1].balance = 2000,
    [2].id = 3, [2].password = 333, [2].balance = 3000.5};

u8 login() {
  int ID;
  printf("\nEnter ID(1,2,3): ");
  scanf_s("%d", &ID);

  int password;
  printf("Enter Password(111,222,333): ");
  scanf_s("%d", &password);

  if (check_ID(ID) == ID && check_password(password) == password) {
    printf("\nLogged in Successfully\n");
    printf("Press any key to continue\n\n");
    _getch();
    return 1;
  }
  return 0;
}

u8 cmp(u16 arg1, u16 arg2) { return arg1 == arg2; }

char check_ID(int account_id) {
  if (is_valid_id(account_id)) {
    return account_id;
  }
  printf("\nERROR! Invalid ID\n");
  return -1;
}
char check_password(int account_password) {
  if (is_valid_password(account_password)) {
    return account_password;
  }
  printf("\nERROR! Invalid password\n");
  return -1;
}

u8 is_valid_id(int account_id) {
  for (int i = 0; i < DATABASE_SIZE; ++i) {
    if (cmp(account_id, Server_DataBase[i].id)) {
      return 1;
    }
  }
  return 0;
}

u8 is_valid_password(int account_password) {
  for (int i = 0; i < DATABASE_SIZE; ++i) {
    if (cmp(account_password, Server_DataBase[i].password)) {
      return 1;
    }
  }
  return 0;
}