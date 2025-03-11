#include "Product.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Product class implementations
// Constructors
Product::Product() : name(""), description(""), rating(0), soldCount(0) {}

Product::Product(const std::string& name, const std::string& description, int rating, int soldCount)
    : name(name), description(description), rating(rating), soldCount(soldCount) {}

// Destructor
Product::~Product() {}

// Getters
std::string Product::getName() const {
    return name;
}

std::string Product::getDescription() const {
    return description;
}

int Product::getRating() const {
    return rating;
}

int Product::getSoldCount() const {
    return soldCount;
}

// Setters
void Product::setName(const std::string& name) {
    this->name = name;
}

void Product::setDescription(const std::string& description) {
    this->description = description;
}

void Product::setRating(int rating) {
    this->rating = rating;
}

void Product::setSoldCount(int soldCount) {
    this->soldCount = soldCount;
}

// Display product information
void Product::display() const {
    std::cout << "Product Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Rating: " << rating << std::endl;
    std::cout << "Sold Count: " << soldCount << std::endl;
}

// Modify product details
bool Product::modify() {
    std::string newName, newDescription;
    
    std::cout << "Current Name: " << name << std::endl;
    std::cout << "Enter new name (or press Enter to keep current): ";
    std::getline(std::cin, newName);
    if (!newName.empty()) {
        name = newName;
    }
    
    std::cout << "Current Description: " << description << std::endl;
    std::cout << "Enter new description (or press Enter to keep current): ";
    std::getline(std::cin, newDescription);
    if (!newDescription.empty()) {
        description = newDescription;
    }
    
    std::cout << "Current Rating: " << rating << std::endl;
    std::cout << "Enter new rating (0-5) (or press Enter to keep current): ";
    std::string ratingStr;
    std::getline(std::cin, ratingStr);
    if (!ratingStr.empty()) {
        try {
            int newRating = std::stoi(ratingStr);
            if (newRating >= 0 && newRating <= 5) {
                rating = newRating;
            } else {
                std::cout << "Invalid rating. Using current value." << std::endl;
            }
        } catch (...) {
            std::cout << "Invalid input. Using current value." << std::endl;
        }
    }
    
    std::cout << "Product modified successfully!" << std::endl;
    return true;
}

// Operator overloading implementation
bool Product::operator==(const Product& otherProduct) const {
    return name == otherProduct.name;
}

// Media class implementations
// Constructors
Media::Media() : Product(), type(""), targetAudience("") {}

Media::Media(const std::string& name, const std::string& description, 
             const std::string& type, const std::string& targetAudience,
             int rating, int soldCount)
    : Product(name, description, rating, soldCount), type(type), targetAudience(targetAudience) {}

// Getters
std::string Media::getType() const {
    return type;
}

std::string Media::getTargetAudience() const {
    return targetAudience;
}

// Setters
void Media::setType(const std::string& type) {
    this->type = type;
}

void Media::setTargetAudience(const std::string& targetAudience) {
    this->targetAudience = targetAudience;
}

// Override display method
void Media::display() const {
    Product::display();
    std::cout << "Type: " << type << std::endl;
    std::cout << "Target Audience: " << targetAudience << std::endl;
}

// Override modify method
bool Media::modify() {
    // First modify base class attributes
    Product::modify();
    
    // Then modify media-specific attributes
    std::string newType, newTargetAudience;
    
    std::cout << "Enter new type (or press Enter to keep current): ";
    std::getline(std::cin, newType);
    if (!newType.empty()) {
        type = newType;
    }
    
    std::cout << "Enter new target audience (or press Enter to keep current): ";
    std::getline(std::cin, newTargetAudience);
    if (!newTargetAudience.empty()) {
        targetAudience = newTargetAudience;
    }
    
    return true;
}

// Override sell method
bool Media::sell(int quantity) {
    // Generate a random access code (simple implementation)
    srand(static_cast<unsigned int>(time(nullptr)));
    int accessCode = rand() % 900000 + 100000; // 6-digit code
    
    // Increment sold count by quantity
    soldCount += quantity;
    
    // Display access code
    std::cout << "Product sold! Your one-time access code is: " << accessCode << std::endl;
    std::cout << "Quantity sold: " << quantity << std::endl;
    
    return true;
}

// Good class implementations
// Constructors
Good::Good() : Product(), expirationDate(""), quantity(0) {}

Good::Good(const std::string& name, const std::string& description, 
         const std::string& expirationDate, int quantity,
         int rating, int soldCount)
    : Product(name, description, rating, soldCount), expirationDate(expirationDate), quantity(quantity) {}

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
    if (quantity >= sellQuantity) {
        // Decrement quantity
        quantity -= sellQuantity;
        // Increment sold count
        soldCount += sellQuantity;
        
        std::cout << "Product sold! Quantity sold: " << sellQuantity << std::endl;
        std::cout << "Remaining quantity: " << quantity << std::endl;
        return true;
    } else {
        std::cout << "Sorry, not enough inventory. Available quantity: " << quantity << std::endl;
        return false;
    }
}

