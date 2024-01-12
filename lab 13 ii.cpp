#include <iostream>
#include <string>

using namespace std;

struct Customer {
    string name;
    string address;
    double phoneNumber;
};

int main() {
    int num;
    cout << "Enter the number of customers: ";
    cin >> num;
    
    cin.ignore();

    Customer customers[num];

    for (int i = 0; i < num; ++i) {
        cout << " " << endl;
        cout << i + 1 << ") Customer details:" << endl;
        cout << "Enter name: ";
        getline(cin, customers[i].name);
        cout << "Enter address: ";
        getline(cin, customers[i].address);
        cout << "Enter phone number: ";
        cin >> customers[i].phoneNumber;
        cout << " " << endl;
        cin.ignore();
    }

    string searchCustomerName;
    cout << "Enter the customer name to display information: ";
    getline(cin, searchCustomerName);

    bool found = false;
    for (int i = 0; i < num; ++i) {
        if (searchCustomerName == customers[i].name) {
            cout << "\nCustomer Information:\n";
            cout << "Name: " << customers[i].name << endl;
            cout << "Address: " << customers[i].address << endl;
            cout << "Phone Number: " << customers[i].phoneNumber << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nCustomer not found!\n";
    }

    return 0;
}
