#ifndef CLIENT_H
#define CLIENT_H
#include "users.h"

void clear();
int login(struct Usuario *usuarios, int contador);
void menuUsersOptions();
void menuUserOptions();
void menuAdminOptions();
void wait_action();
void logo();

#endif  
