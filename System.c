#include "System.h"

void run(void) {
  u8 loginV = login();

  while (1) {

    if (!loginV) {
      printf("\nFailed to login. Try Again\n");
      loginV = login();
      continue;
    }

    int choice = menu();
    switch (choice) {
    case 1:
      printBalance();
      break;
    case 2:
      Deposit();
      break;
    case 3:
      withdraw();
      break;
    case 4:
      transfer();
      break;
    default:
      return;
    }
  }
}

int menu() {
  int choice = -1;

  while (choice == -1) {
    printf("\n\nEnter your choice:\n");
    printf("1)Print Balance\n");
    printf("2)Deposite\n");
    printf("3)Withdraw\n");
    printf("4)Transfer\n");
    printf("5)Exit\n");
    scanf_s("%d", &choice);

    if (!(choice >= 1 && choice <= 6)) {
      u8 trial = 3;
      if (trial-- != 0) {
        printf("Invalid choice. Try again\n");
        choice = -1;
      }
    }
  }
  return choice;
}
