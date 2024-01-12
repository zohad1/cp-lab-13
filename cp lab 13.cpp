#include <iostream>
#include <string>

using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
     string input;
    int num;

    while (true) {
        cout << "Enter the number of products: ";
        cin >> input;

        if (isNumber(input)) {
            num = stoi(input);
            break;
        } else {
            cout << "Please enter a number." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    cin.ignore();

    Product products[num];

    for (int i = 0; i < num; ++i) {
    	cout<<" "<<endl;
        cout << i+1<< ") Product details:" << endl;
        cout << "Enter the product name: ";
        getline(cin, products[i].name);
        cout << "Enter price of product: ";
        cin >> products[i].price;
        cout << "Enter quantity of product: ";
        cin >> products[i].quantity;
        cout<<" "<<endl;
        cin.ignore();
    }

    string searchProductName;
    cout << "Enter the product name to display information: ";
    getline(cin, searchProductName);

    bool found = false;
    for (int i = 0; i < num; ++i) {
        if (searchProductName == products[i].name) {
            cout << "\nProduct Information:\n";
            cout << "Name: " << products[i].name << endl;
            cout << "Price: $" << products[i].price << endl;
            cout << "Quantity in stock: " << products[i].quantity << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nProduct not found!\n";
    }
    return 0;
}
