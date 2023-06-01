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

int main() {
    // Create a Manager object
    Manager manager1("Jane Smith", FEMALE, "9876543210", "456 Main Street", 35, "Senior Manager");

    // Get and display manager information
    cout << "Manager Name: " << manager1.getPersonName() << endl;
    cout << "Gender: ";
    switch (manager1.getGender()) {
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
    cout << "Mobile Number: " << manager1.getMobileNumber() << endl;
    cout << "Address: " << manager1.getAddress() << endl;
    cout << "Age: " << manager1.getAge() << endl;
    cout << "Title: " << manager1.getTitle() << endl;

    return 0;
}
