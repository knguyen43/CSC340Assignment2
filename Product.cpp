#include "Product.h"
#include "Media.h"
#include "Good.h"
#include <iostream>
#include <string>

// Product class implementations
// Constructors
Product::Product() : name(""), description(""), rating(0), soldCount(0) {}

Product::Product(const std::string& name, const std::string& description, int rating, int soldCount)
    : name(name), description(description), rating(rating), soldCount(soldCount) {}

// Copy constructor
Product::Product(const Product& other)
    : name(other.name), description(other.description), rating(other.rating), soldCount(other.soldCount) {}

// Destructor
Product::~Product() {}

// Assignment operator
Product& Product::operator=(const Product& other) {
    if (this != &other) {
        name = other.name;
        description = other.description;
        rating = other.rating;
        soldCount = other.soldCount;
    }
    return *this;
}

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

// Input operator implementation
std::istream& operator>>(std::istream& is, Product& product) {
    std::cout << "Enter product name: ";
    std::getline(is, product.name);
    
    std::cout << "Enter product description: ";
    std::getline(is, product.description);
    
    std::cout << "Enter product rating (0-5): ";
    std::string ratingStr;
    std::getline(is, ratingStr);
    try {
        int newRating = std::stoi(ratingStr);
        if (newRating >= 0 && newRating <= 5) {
            product.rating = newRating;
        }
    } catch (...) {
        // Keep default rating if invalid input
    }
    
    return is;
}

// Output operator implementation
std::ostream& operator<<(std::ostream& os, const Product& product) {
    os << "Product Name: " << product.name << "\n"
       << "Description: " << product.description << "\n"
       << "Rating: " << product.rating << "\n"
       << "Sold Count: " << product.soldCount;
    return os;
}

