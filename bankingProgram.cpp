#include <iostream>
#include <iomanip>     // for setprecision and fixed used in showBalance function
using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main() {

    double balance = 0;
    int choice = 0;

do{
    cout << "***********************************" << endl;
    cout << "Enter your choice: " << endl;
    cout << "***********************************" << endl; 
    cout << "1. show Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;

    cin.clear(); // clear error flags
    fflush(stdin); // clear input buffer

    switch(choice) {
        case 1: showBalance(balance);
                break;
        case 2: balance += deposit();
                showBalance(balance);
                break;
        case 3: balance -= withdraw(balance);
                showBalance(balance);
                break;
        case 4: cout << "Thank you for visiting!" << endl;
                break;
        default: cout << "Invalid choice!" << endl;
                 break;
        }
}while(choice != 4);

    return 0;
}
void showBalance(double balance){
    cout << "Your current balance is: $" << setprecision(2) << fixed << balance << endl; // Set precision to 2 decimal places for currency display
}
double deposit(){
    double amount = 0;
    cout << "Enter amount to deposit: $";
    cin >> amount;

    if(amount > 0){
        return amount;
    }
    else{
        cout << "Invalid amount!" << endl;
        return 0;
    }
    return amount;
}
double withdraw(double balance){

    double amount = 0;
    cout << "Enter amount to withdraw: $";
    cin >> amount;

    if(amount > balance){
        cout << "Insufficient funds!" << endl;
        return 0;
    }
    else if(amount <= 0){
        cout << "Invalid amount!" << endl;
        return 0;
    }
    else{
        return amount;
    }
    return 0;
}