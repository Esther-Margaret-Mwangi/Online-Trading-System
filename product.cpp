#include <iostream>
#include <string>

using namespace std;

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

int main() {
    // Create a product object
    Product product1(1, "Example Product", 10, 9.99);

    // Get and display product information
    cout << "Product ID: " << product1.getProductId() << endl;
    cout << "Product Name: " << product1.getProductName() << endl;
    cout << "Product Amount: " << product1.getProductAmount() << endl;
    cout << "Product Price: " << product1.getProductPrice() << endl;

    return 0;
}
