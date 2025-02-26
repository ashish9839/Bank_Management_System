# Bank Management System

## Overview

This is a simple **Bank Management System** written in C++. It allows users to create accounts, deposit and withdraw money, and change their PIN. The system supports both **Savings** and **Current** accounts and provides secure PIN-based access to transactions.

## Features

- **Create an Account** (Savings or Current, with or without a joint holder)
- **Deposit Money**
- **Withdraw Money** (Ensuring balance sufficiency)
- **Change PIN** for security
- **Account Details Display** (After account creation and transactions)

## Account Types

- **Savings Account**: No minimum balance required.
- **Current Account**: Requires a minimum balance of **10,000**.

## How to Run

1. **Compile the program** using a C++ compiler (e.g., g++):
   ```sh
   g++ bank_management.cpp -o bank_management
   ```
2. **Run the executable**:
   ```sh
   ./bank_management
   ```
3. **Follow the on-screen menu** to perform transactions.

## Menu Structure

```
******************************
*        BANK MENU          *
******************************
* 1. Create Account         *
* 2. Deposit                *
* 3. Withdraw               *
* 4. Change PIN             *
* 5. Exit                   *
******************************
```

## Usage Instructions

### 1. Creating an Account

- Enter the **account holder's name**.
- Choose whether it's a **joint account** or not.
- Set a **4-digit PIN**.
- Select **account type** (1 for Savings, 2 for Current).
- Enter the **initial balance** (Minimum 10,000 for Current accounts).
- The system generates a **unique account number**.

### 2. Deposit Money

- Enter the **account number**.
- Enter the **PIN** for verification.
- Enter the **amount to deposit**.

### 3. Withdraw Money

- Enter the **account number**.
- Enter the **PIN** for verification.
- Enter the **amount to withdraw** (ensuring sufficient balance).

### 4. Change PIN

- Enter the **account number**.
- Enter the **old PIN**.
- Set a **new 4-digit PIN**.

## Notes

- Each account gets a **randomly generated 10-digit account number**.
- Incorrect PIN attempts will deny access.
- The program ensures **secure transactions** by validating balances before withdrawals.
- The program follows **a structured menu interface** for ease of use.
