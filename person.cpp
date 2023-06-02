#include <iostream>
#include <string>

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

int main() {
    // Create a Person object
    Person person1("John Doe", MALE, "1234567890", "123 Main Street");

    // Get and display person information
    cout << "Person Name: " << person1.getPersonName() << endl;
    cout << "Gender: ";
    switch (person1.getGender()) {
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
    cout << "Mobile Number: " << person1.getMobileNumber() << endl;
    cout << "Address: " << person1.getAddress() << endl;

    return 0;
}
