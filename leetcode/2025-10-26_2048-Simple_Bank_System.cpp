#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    vector<long long> bal;

    bool isValid(int acc) {
        return acc >= 1 && acc <= bal.size();
    }

public:
    Bank(vector<long long>& balance) {
        bal = balance;
    }

    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account1) || !isValid(account2)) return false;
        if (bal[account1 - 1] < money) return false;
        bal[account1 - 1] -= money;
        bal[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!isValid(account)) return false;
        bal[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValid(account)) return false;
        if (bal[account - 1] < money) return false;
        bal[account - 1] -= money;
        return true;
    }
};

int main() {
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank bank(balance);

    // Simulating input like the example
    cout << boolalpha; // prints true/false instead of 1/0

    cout << bank.withdraw(3, 10) << endl;    // true
    cout << bank.transfer(5, 1, 20) << endl; // true
    cout << bank.deposit(5, 20) << endl;     // true
    cout << bank.transfer(3, 4, 15) << endl; // false
    cout << bank.withdraw(10, 50) << endl;   // false
    
    return 0;
}
