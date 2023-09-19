#include "Transactions.h"
#include <stdio.h>

void printBalance() {
  int accountID;
  printf("Enter account ID:");
  scanf_s("%d", &accountID);

  if (check_ID(accountID) == accountID) {
    printf("Balance of user %d is %f", accountID,
           (float)Server_DataBase[accountID - 1].balance);
  }
}
void Deposit(void) {
  int accountID;
  float cash_amount;
  printf("Enter Account ID:");
  scanf_s("%d", &accountID);

  printf("Enter Cash Amount to Deposite:");
  scanf_s("%f", &cash_amount);

  if (check_ID(accountID) == accountID) {
    Server_DataBase[accountID - 1].balance += cash_amount;
  }
}
void withdraw(void) {
  int accountID;
  int cash_amount;
  printf("Enter Account ID:");
  scanf_s("%d", &accountID);

  printf("Enter Cash Amount to Withdraw:");
  scanf_s("%d", &cash_amount);

  if (check_ID(accountID) == accountID) {
    if (cash_amount <= Server_DataBase[accountID - 1].balance) {
      Server_DataBase[accountID - 1].balance -= cash_amount;
    }
  }
}
void transfer(void) {
  int senderID, recieverID;
  float transferred_amount;

  printf("Enter Sender ID:");
  scanf_s("%d", &senderID);

  printf("Enter Reciever ID:");
  scanf_s(" %d", &recieverID);

  printf("Enter Transfered Amount:");
  scanf_s(" %f", &transferred_amount);

  if (check_ID(senderID) == senderID) {

    Server_DataBase[senderID - 1].balance -= transferred_amount;
    Server_DataBase[recieverID - 1].balance += transferred_amount;
  }
}
