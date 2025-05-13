#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
    struct Account* next;
};

struct Account* head = NULL;

// Function to create a new account node
struct Account* createAccount(int accNo, char name[], float balance) {
    struct Account* newAcc = (struct Account*)malloc(sizeof(struct Account));
    newAcc->accountNumber = accNo;
    strcpy(newAcc->name, name);
    newAcc->balance = balance;
    newAcc->next = NULL;
    return newAcc;
}

// Add account to list
void addAccount(int accNo, char name[], float balance) {
    struct Account* newAcc = createAccount(accNo, name, balance);
    newAcc->next = head;
    head = newAcc;
    printf("Account created: %s | A/C No: %d | Balance: %.2f\n", name, accNo, balance);
}

// Search account by account number
struct Account* searchAccount(int accNo) {
    struct Account* temp = head;
    while (temp != NULL) {
        if (temp->accountNumber == accNo)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

// Deposit money
void deposit(int accNo, float amount) {
    struct Account* acc = searchAccount(accNo);
    if (acc != NULL) {
        acc->balance += amount;
        printf("Deposit successful! New Balance: %.2f\n", acc->balance);
    } else {
        printf("Account not found!\n");
    }
}

// Withdraw money
void withdraw(int accNo, float amount) {
    struct Account* acc = searchAccount(accNo);
    if (acc != NULL) {
        if (acc->balance >= amount) {
            acc->balance -= amount;
            printf("Withdrawal successful! New Balance: %.2f\n", acc->balance);
        } else {
            printf("Insufficient balance!\n");
        }
    } else {
        printf("Account not found!\n");
    }
}

// Display all accounts
void displayAccounts() {
    struct Account* temp = head;
    if (temp == NULL) {
        printf("No accounts found!\n");
        return;
    }
    printf("Account List:\n");
    while (temp != NULL) {
        printf("Account No: %d | Name: %s | Balance: %.2f\n",
               temp->accountNumber, temp->name, temp->balance);
        temp = temp->next;
    }
}

// Add dummy accounts at start
void initializeDummyAccounts() {
    addAccount(1001, "Sachin Sharma", 1500.00);
    addAccount(1002, "Palak Aar", 2300.50);
    addAccount(1003, "Rohit Kumar", 320.75);
    addAccount(1004, "Vivek Kapoor", 5000.00);
}

// Main menu
int main() {
    int choice, accNo;
    char name[50];
    float amount;

    // Add predefined accounts
    initializeDummyAccounts();

    while (1) {
        printf("\n--- Banking System Menu ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Search Account\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Account Number: ");
            scanf("%d", &accNo);
            printf("Enter Name: ");
            scanf(" %[^\n]s", name);
            printf("Enter Initial Balance: ");
            scanf("%f", &amount);
            addAccount(accNo, name, amount);
            break;
        case 2:
            printf("Enter Account Number: ");
            scanf("%d", &accNo);
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);
            deposit(accNo, amount);
            break;
        case 3:
            printf("Enter Account Number: ");
            scanf("%d", &accNo);
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);
            withdraw(accNo, amount);
            break;
        case 4:
            printf("Enter Account Number: ");
            scanf("%d", &accNo);
            struct Account* found = searchAccount(accNo);
            if (found)
                printf("Account Found: %s | Balance: %.2f\n", found->name, found->balance);
            else
                printf("Account not found!\n");
            break;
        case 5:
            displayAccounts();
            break;
        case 6:
            printf("Exiting... Thank you!\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
