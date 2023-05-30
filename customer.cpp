#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Gender {
    MALE,
    FEMALE,
    OTHER
};

class Person {
private:
    string personName;
    Gender gender;
    string mobileNumber;
    string address;

public:
    // Constructor
    Person(const string& name, Gender gen, const string& number, const string& addr) {
        personName = name;
        gender = gen;
        mobileNumber = number;
        address = addr;
    }

    // Getter methods
    string getPersonName() const {
        return personName;
    }

    Gender getGender() const {
        return gender;
    }

    string getMobileNumber() const {
        return mobileNumber;
    }

    string getAddress() const {
        return address;
    }

    // Setter methods
    void setPersonName(const string& name) {
        personName = name;
    }

    void setGender(Gender gen) {
        gender = gen;
    }

    void setMobileNumber(const string& number) {
        mobileNumber = number;
    }

    void setAddress(const string& addr) {
        address = addr;
    }
};

class Customer : public Person {
private:
    int customerId;
    double capital;
    vector<string> products;

public:
    // Constructor
    Customer(const string& name, Gender gen, const string& number, const string& addr, int id)
        : Person(name, gen, number, addr) {
        customerId = id;
        capital = 5000.0;
    }

    // Getter methods
    int getCustomerId() const {
        return customerId;
    }

    double getCapital() const {
        return capital;
    }

    const vector<string>& getProducts() const {
        return products;
    }

    // Setter methods
    void setCustomerId(int id) {
        customerId = id;
    }

    void setCapital(double amount) {
        capital = amount;
    }

    // Other methods
    void addProduct(const string& product) {
        products.push_back(product);
    }
};

int main() {
    // Create a Customer object
    Customer customer1("John Doe", MALE, "1234567890", "123 Main Street", 1);

    // Get and display customer information
    cout << "Customer Name: " << customer1.getPersonName() << endl;
    cout << "Gender: ";
    switch (customer1.getGender()) {
        case MALE:
            cout << "Male" << endl;
            break;
        case FEMALE:
            cout << "Female" << endl;
            break;
        case OTHER:
            cout << "Other" << endl;
            break;
    }
    cout << "Mobile Number: " << customer1.getMobileNumber() << endl;
    cout << "Address: " << customer1.getAddress() << endl;
    cout << "Customer ID: " << customer1.getCustomerId() << endl;
    cout << "Capital: " << customer1.getCapital() << " RMB" << endl;

    // Add a product
    customer1.addProduct("Product A");
    customer1.addProduct("Product B");

    // Get and display customer's products
    cout << "Products Purchasing: ";
    const vector<string>& products = customer1.getProducts();
    for (const string& product : products) {
        cout << product << ", ";
    }
    cout << endl;

    return 0;
}
