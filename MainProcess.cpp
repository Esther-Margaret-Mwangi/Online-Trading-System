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

class Product {
private:
    int productId;
    string productName;
    int productAmount;
    double productPrice;

public:
    // Constructor
    Product(int id, const string& name, int amount, double price) {
        productId = id;
        productName = name;
        productAmount = amount;
        productPrice = price;
    }

    // Getter methods
    int getProductId() const {
        return productId;
    }

    string getProductName() const {
        return productName;
    }

    int getProductAmount() const {
        return productAmount;
    }

    double getProductPrice() const {
        return productPrice;
    }

    // Setter methods
    void setProductId(int id) {
        productId = id;
    }

    void setProductName(const string& name) {
        productName = name;
    }

    void setProductAmount(int amount) {
        productAmount = amount;
    }

    void setProductPrice(double price) {
        productPrice = price;
    }
};

class Customer : public Person {
private:
    int customerId;
    double capital;
    vector<Product> cart;

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

    const vector<Product>& getCart() const {
        return cart;
    }

    // Setter methods
    void setCustomerId(int id) {
        customerId = id;
    }

    void setCapital(double amount) {
        capital = amount;
    }

    // Other methods
    void addToCart(const Product& product) {
        cart.push_back(product);
    }
};

class Manager : public Person {
private:
    int age;
    string title;

public:
    // Constructor
    Manager(const string& name, Gender gen, const string& number, const string& addr, int ag, const string& t)
        : Person(name, gen, number, addr) {
        age = ag;
        title = t;
    }

    // Getter methods
    int getAge() const {
        return age;
    }

    string getTitle() const {
        return title;
    }

    // Setter methods
    void setAge(int ag) {
        age = ag;
    }

    void setTitle(const string& t) {
        title = t;
    }
};

class MainProcess {
private:
    vector<Product> products;
    vector<Customer> customers;
    Manager manager;
    Customer customer;

public:
    // Constructor
    MainProcess(const Manager& mgr, const Customer& cust)
        : manager(mgr), customer(cust) {}

    // Function to display the main operation menu
    void displayMainMenu() {
        cout << "---------- Main Operation Menu ----------" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Exit" << endl;
        cout << "----------------------------------------" << endl;
    }

    // Function to display manager's operation menu
    void displayManagerMenu() {
        cout << "---------- Manager Menu ----------" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Query Products" << endl;
        cout << "3. Add Customer" << endl;
        cout << "4. Query Customers" << endl;
        cout << "5. Back to Main Menu" << endl;
        cout << "----------------------------------" << endl;
    }

    // Function to display customer's operation menu
    void displayCustomerMenu() {
        cout << "---------- Customer Menu ----------" << endl;
        cout << "1. Add Products to Cart" << endl;
        cout << "2. Query Products in Cart" << endl;
        cout << "3. Check Up" << endl;
        cout << "4. Back to Main Menu" << endl;
        cout << "----------------------------------" << endl;
    }

    // Function to add a product
    void addProduct() {
        int productId;
        string productName;
        int productAmount;
        double productPrice;

        cout << "Enter product details:" << endl;
        cout << "Product ID: ";
        cin >> productId;

        // Check if the product ID already exists
        for (const Product& product : products) {
            if (product.getProductId() == productId) {
                cout << "Product ID already exists! Cannot add the product." << endl;
                return;
            }
        }

        cout << "Product Name: ";
        cin.ignore();
        getline(cin, productName);

        cout << "Product Amount: ";
        cin >> productAmount;

        cout << "Product Price: ";
        cin >> productPrice;

        // Create a new product and add it to the product vector
        Product newProduct(productId, productName, productAmount, productPrice);
        products.push_back(newProduct);

        cout << "Product added successfully!" << endl;
    }

    // Function to query a product
    void queryProduct() {
        int choice;
        cout << "1. Query a particular product" << endl;
        cout << "2. List all products" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int productId;
            cout << "Enter the product ID: ";
            cin >> productId;

            bool found = false;
            for (const Product& product : products) {
                if (product.getProductId() == productId) {
                    cout << "Product ID: " << product.getProductId() << endl;
                    cout << "Product Name: " << product.getProductName() << endl;
                    cout << "Product Amount: " << product.getProductAmount() << endl;
                    cout << "Product Price: " << product.getProductPrice() << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No product found!" << endl;
            }
        } else if (choice == 2) {
            if (products.empty()) {
                cout << "No products available!" << endl;
            } else {
                cout << "List of all products:" << endl;
                for (const Product& product : products) {
                    cout << "Product ID: " << product.getProductId() << endl;
                    cout << "Product Name: " << product.getProductName() << endl;
                    cout << "Product Amount: " << product.getProductAmount() << endl;
                    cout << "Product Price: " << product.getProductPrice() << endl;
                    cout << "---------------------------" << endl;
                }
            }
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    // Function to add a customer
    void addCustomer() {
        int customerId;
        string customerName;
        Gender gender;
        string mobileNumber;
        string address;

        cout << "Enter customer details:" << endl;
        cout << "Customer ID: ";
        cin >> customerId;

        // Check if the customer ID already exists
        for (const Customer& cust : customers) {
            if (cust.getCustomerId() == customerId) {
                cout << "Customer ID already exists! Cannot add the customer." << endl;
                return;
            }
        }

        cout << "Customer Name: ";
        cin.ignore();
        getline(cin, customerName);

        int genderChoice;
        cout << "Gender (0 - Male, 1 - Female, 2 - Other): ";
        cin >> genderChoice;

        switch (genderChoice) {
            case 0:
                gender = MALE;
                break;
            case 1:
                gender = FEMALE;
                break;
            case 2:
                gender = OTHER;
                break;
            default:
                cout << "Invalid gender choice! Setting gender to Other." << endl;
                gender = OTHER;
                break;
        }

        cout << "Mobile Number: ";
        cin.ignore();
        getline(cin, mobileNumber);

        cout << "Address: ";
        getline(cin, address);

        // Create a new customer and add it to the customer vector
        Customer newCustomer(customerName, gender, mobileNumber, address, customerId);
        customers.push_back(newCustomer);

        cout << "Customer added successfully!" << endl;
    }

    // Function to query a customer
    void queryCustomer() {
        int choice;
        cout << "1. Query a particular customer" << endl;
        cout << "2. List all customers" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int customerId;
            cout << "Enter the customer ID: ";
            cin >> customerId;

            bool found = false;
            for (const Customer& cust : customers) {
                if (cust.getCustomerId() == customerId) {
                    cout << "Customer ID: " << cust.getCustomerId() << endl;
                    cout << "Customer Name: " << cust.getPersonName() << endl;
                    cout << "Gender: ";
                    switch (cust.getGender()) {
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
                    cout << "Mobile Number: " << cust.getMobileNumber() << endl;
                    cout << "Address: " << cust.getAddress() << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No customer found!" << endl;
            }
        } else if (choice == 2) {
            if (customers.empty()) {
                cout << "No customers available!" << endl;
            } else {
                cout << "List of all customers:" << endl;
                for (const Customer& cust : customers) {
                    cout << "Customer ID: " << cust.getCustomerId() << endl;
                    cout << "Customer Name: " << cust.getPersonName() << endl;
                    cout << "Gender: ";
                    switch (cust.getGender()) {
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
                    cout << "Mobile Number: " << cust.getMobileNumber() << endl;
                    cout << "Address: " << cust.getAddress() << endl;
                    cout << "---------------------------" << endl;
                }
            }
        } else {
            cout << "Invalid choice!" << endl;
        }
    }

    // Function to add products to the customer's cart
    void addProductsToCart() {
        int productId;
        int customerId;

        cout << "Enter customer ID: ";
        cin >> customerId;

        bool customerFound = false;
        for (Customer& cust : customers) {
            if (cust.getCustomerId() == customerId) {
                customerFound = true;
                cout << "Enter product ID (-1 to exit): ";
                cin >> productId;

                while (productId != -1) {
                    bool productFound = false;
                    for (const Product& product : products) {
                        if (product.getProductId() == productId) {
                            if (cust.getCapital() >= product.getProductPrice()) {
                                cust.addToCart(product);
                                cust.setCapital(cust.getCapital() - product.getProductPrice());
                                cout << "Product added to cart!" << endl;
                            } else {
                                cout << "Insufficient funds to purchase the product." << endl;
                            }
                            productFound = true;
                            break;
                        }
                    }

                    if (!productFound) {
                        cout << "Product not found!" << endl;
                    }

                    cout << "Enter product ID (-1 to exit): ";
                    cin >> productId;
                }
                break;
            }
        }

        if (!customerFound) {
            cout << "Customer not found!" << endl;
        }
    }

    // Function to query products in the customer's cart
    void queryProductsInCart() {
        int customerId;

        cout << "Enter customer ID: ";
        cin >> customerId;

        bool customerFound = false;
        for (const Customer& cust : customers) {
            if (cust.getCustomerId() == customerId) {
                customerFound = true;
                const vector<Product>& cart = cust.getCart();
                if (cart.empty()) {
                    cout << "No products in the cart!" << endl;
                } else {
                    cout << "Products in the cart:" << endl;
                    for (const Product& product : cart) {
                        cout << "Product ID: " << product.getProductId() << endl;
                        cout << "Product Name: " << product.getProductName() << endl;
                        cout << "Product Amount: " << product.getProductAmount() << endl;
                        cout << "Product Price: " << product.getProductPrice() << endl;
                        cout << "---------------------------" << endl;
                    }
                }
                break;
            }
        }

        if (!customerFound) {
            cout << "Customer not found!" << endl;
        }
    }

    // Function to start the main process
    void startProcess() {
        int choice;
        bool exitFlag = false;

        while (!exitFlag) {
            displayMainMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    managerOperation();
                    break;
                case 2:
                    customerOperation();
                    break;
                case 3:
                    exitFlag = true;
                    cout << "Exiting the program..." << endl;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
                    break;
            }
        }
    }

    // Function to perform manager operations
    void managerOperation() {
        int choice;
        bool backToMainMenu = false;

        while (!backToMainMenu) {
            displayManagerMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addProduct();
                    break;
                case 2:
                    queryProduct();
                    break;
                case 3:
                    addCustomer();
                    break;
                case 4:
                    queryCustomer();
                    break;
                case 5:
                    backToMainMenu = true;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
                    break;
            }
        }
    }

    // Function to perform customer operations
    void customerOperation() {
        int choice;
        bool backToMainMenu = false;

        while (!backToMainMenu) {
            displayCustomerMenu();
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addProductsToCart();
                    break;
                case 2:
                    queryProductsInCart();
                    break;
                case 3:
                    checkUp();
                    break;
                case 4:
                    backToMainMenu = true;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
                    break;
            }
        }
    }

    // Function to perform check-up
    void checkUp() {
        int customerId;
        cout << "Enter the customer ID: ";
        cin >> customerId;

        bool customerFound = false;
        for (Customer& cust : customers) {
            if (cust.getCustomerId() == customerId) {
                customerFound = true;
                cust.checkUp();
                break;
            }
        }

        if (!customerFound) {
            cout << "Customer not found!" << endl;
        }
    }
};

int main() {
    Manager manager("John Doe", "admin123");
    Customer customer("Alice", FEMALE, "1234567890", "123 ABC Street", 1);

    MainProcess mainProcess(manager, customer);
    mainProcess.startProcess();

    return 0;
}
