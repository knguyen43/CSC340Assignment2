#include "Product.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Product class implementations
// Constructors
Product::Product() : name(""), description(""), rating(0.0f), soldCount(0) {}

Product::Product(const std::string& name, const std::string& description, float rating, int soldCount)
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

float Product::getRating() const {
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

void Product::setRating(float rating) {
    this->rating = rating;
}

void Product::setSoldCount(int soldCount) {
    this->soldCount = soldCount;
}

// Display product information
void Product::displayInfo() const {
    std::cout << "Product Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Rating: " << rating << std::endl;
    std::cout << "Sold Count: " << soldCount << std::endl;
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
             float rating, int soldCount)
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
void Media::displayInfo() const {
    Product::displayInfo();
    std::cout << "Type: " << type << std::endl;
    std::cout << "Target Audience: " << targetAudience << std::endl;
}

// Override sell method - generates access code
bool Media::sell() {
    // Generate a random access code (simple implementation)
    srand(static_cast<unsigned int>(time(nullptr)));
    int accessCode = rand() % 900000 + 100000; // 6-digit code
    
    // Increment sold count
    soldCount++;
    
    // Display access code
    std::cout << "Product sold! Your one-time access code is: " << accessCode << std::endl;
    
    return true;
}

// Goods class implementations
// Constructors
Goods::Goods() : Product(), expirationDate(""), quantity(0) {}

Goods::Goods(const std::string& name, const std::string& description, 
             const std::string& expirationDate, int quantity,
             float rating, int soldCount)
    : Product(name, description, rating, soldCount), expirationDate(expirationDate), quantity(quantity) {}

// Getters
std::string Goods::getExpirationDate() const {
    return expirationDate;
}

int Goods::getQuantity() const {
    return quantity;
}

// Setters
void Goods::setExpirationDate(const std::string& expirationDate) {
    this->expirationDate = expirationDate;
}

void Goods::setQuantity(int quantity) {
    this->quantity = quantity;
}

// Override display method
void Goods::displayInfo() const {
    Product::displayInfo();
    std::cout << "Expiration Date: " << expirationDate << std::endl;
    std::cout << "Quantity Available: " << quantity << std::endl;
}

// Override sell method - checks quantity
bool Goods::sell() {
    if (quantity > 0) {
        // Decrement quantity
        quantity--;
        // Increment sold count
        soldCount++;
        
        std::cout << "Product sold! Remaining quantity: " << quantity << std::endl;
        return true;
    } else {
        std::cout << "Sorry, this product is sold out." << std::endl;
        return false;
    }
}

