#include "Good.h"
#include <iostream>
#include <string>

// Constructors
Good::Good() : Product(), expirationDate(""), quantity(0) {}

Good::Good(const std::string& name, const std::string& description, 
         const std::string& expirationDate, int quantity,
         int rating, int soldCount)
    : Product(name, description, rating, soldCount), expirationDate(expirationDate), quantity(quantity) {}

// Copy constructor
Good::Good(const Good& other)
    : Product(other), expirationDate(other.expirationDate), quantity(other.quantity) {}

// Destructor
Good::~Good() {}

// Assignment operator
Good& Good::operator=(const Good& other) {
    if (this != &other) {
        Product::operator=(other);
        expirationDate = other.expirationDate;
        quantity = other.quantity;
    }
    return *this;
}

// Getters
std::string Good::getExpirationDate() const {
    return expirationDate;
}

int Good::getQuantity() const {
    return quantity;
}

// Setters
void Good::setExpirationDate(const std::string& expirationDate) {
    this->expirationDate = expirationDate;
}

void Good::setQuantity(int quantity) {
    this->quantity = quantity;
}

// Override display method
void Good::display() const {
    Product::display();
    std::cout << "Expiration Date: " << expirationDate << std::endl;
    std::cout << "Quantity Available: " << quantity << std::endl;
}

// Override modify method
bool Good::modify() {
    // First modify base class attributes
    Product::modify();
    
    // Then modify goods-specific attributes
    std::string newExpirationDate, quantityStr;
    
    std::cout << "Enter new expiration date (or press Enter to keep current): ";
    std::getline(std::cin, newExpirationDate);
    if (!newExpirationDate.empty()) {
        expirationDate = newExpirationDate;
    }
    
    std::cout << "Enter new quantity (or press Enter to keep current): ";
    std::getline(std::cin, quantityStr);
    if (!quantityStr.empty()) {
        try {
            int newQuantity = std::stoi(quantityStr);
            if (newQuantity >= 0) {
                quantity = newQuantity;
            } else {
                std::cout << "Invalid quantity. Using current value." << std::endl;
            }
        } catch (...) {
            std::cout << "Invalid input. Using current value." << std::endl;
        }
    }
    
    return true;
}

// Override sell method - checks quantity
bool Good::sell(int sellQuantity) {
    // Check if we have enough inventory
    if (quantity < sellQuantity) {
        std::cout << "Sorry, not enough inventory. Available quantity: " << quantity << std::endl;
        return false;
    }
    
    // Decrement quantity
    quantity -= sellQuantity;
    // Increment sold count
    soldCount += sellQuantity;
    
    std::cout << "Product sold! Quantity sold: " << sellQuantity << std::endl;
    std::cout << "Remaining quantity: " << quantity << std::endl;
    
    // Provide warning for low inventory
    if (quantity == 0) {
        std::cout << "WARNING: Item is now out of stock!" << std::endl;
    } else if (quantity < 5) {
        std::cout << "WARNING: Low inventory - only " << quantity << " items left!" << std::endl;
    }
    
    return true;
}

// Input operator implementation
std::istream& operator>>(std::istream& is, Good& good) {
    // First, get the base Product members
    operator>>(is, static_cast<Product&>(good));
    
    std::cout << "Enter expiration date: ";
    std::getline(is, good.expirationDate);
    
    std::cout << "Enter quantity: ";
    std::string quantityStr;
    std::getline(is, quantityStr);
    try {
        good.quantity = std::stoi(quantityStr);
        if (good.quantity < 0) {
            good.quantity = 0;
        }
    } catch (...) {
        good.quantity = 0;
    }
    
    return is;
}

// Output operator implementation
std::ostream& operator<<(std::ostream& os, const Good& good) {
    os << static_cast<const Product&>(good) << std::endl;
    os << "Expiration Date: " << good.expirationDate << std::endl;
    os << "Quantity Available: " << good.quantity;
    return os;
}