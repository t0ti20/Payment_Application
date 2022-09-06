# Payment Application Simulation
This is a Payment Application Simulation project for the EgFWD Embedded Systems Professional NanoDegree Scholarship. This project was written in C. It includes a Luhn card PAN generation and validation and also simpla database management using C .

## Program Flow Chart
![payment-flowchart](https://i.postimg.cc/ZY7MG8rK/payment-flowchart.jpg)

## Functions

These are some of the functions I've Created:
- `appStart()` : this would be called in `Main.c` to start the application.
- `getTransactionDate()` : Gets `System Date` automatically.
- `getCardPAN()` : this functions asks the user to enter PAN Number.
- `PANCheck()` which essentially applie an algorithm to check the card PAN.
- `readAccountDB()` : this load the accounts database from the database file (*read [database](https://github.com/t0ti20/Payment_Application#databases) section*).
- `saveTransaction()` : saves APPROVED transactions with all details into the transactions database (*read [database](https://github.com/t0ti20/Payment_Application#databases) section*).

## Instructions
- You would find demonstrated test cases in the "Submission Files/Videos" Folder.
- This demonstrates showing files used and each function parameters.
- The test cases describe different scenarios that would happen:
  * `EXCEED_MAX_AMOUNT` : means that the user tried to make a transaction with more than specified max amount for card
  * `DECLINED_STOLEN_CARD` & `INVALID_ACCOUNT` : the card number is not present in the account database for the bank
  * `DECLINED_INSUFFECIENT_FUND` : transaction amount is greater than account balance
  *  `APPROVED` : the transaction was successful and saved to transactions database


## Databases
- `Bank_Data.txt` : has all accounts PAN (Primary Account Number) , Accounts balance and account State
![image](https://i.postimg.cc/L4x0ft5F/image.png)
- `Transactions.txt` : this stores different data about the transaction (shown in the picture below)
![image](https://i.postimg.cc/VL1nYpmY/image.png)
