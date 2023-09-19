#ifndef __SERVER_H__
#define __SERVER_H__

#include "utils.h"

#define DATABASE_SIZE 3


typedef struct  {
  int id;
  int password;
  float balance;
}DataBase_t;

extern DataBase_t Server_DataBase[DATABASE_SIZE ]   ;


u8 cmp(u16 arg1, u16 arg2);
u8 is_valid_id(int account_id);
u8 is_valid_password(int account_password);
char check_ID(int account_id);
char check_password(int account_password) ;
u8 login(void);

#endif // __SERVER_H__