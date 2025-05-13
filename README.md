# Simple Banking System in C

This is a simple console-based banking system written in C. It uses linked lists to manage multiple user accounts and supports basic operations like creating an account, depositing, withdrawing, searching, and displaying account information.

## Features

- Create new bank accounts
- Deposit and withdraw money
- Search for an account by account number
- Display all accounts
- Predefined dummy accounts on startup

## Code Overview

Each account is represented using a `struct` with the following fields:

```c
struct Account {
    int accountNumber;
    char name[50];
    float balance;
    struct Account* next;
};
