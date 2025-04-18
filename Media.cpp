#include "Media.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <sstream>
#include <iomanip>

// Constructors
Media::Media() : Product(), type(""), targetAudience("") {}

Media::Media(const std::string& name, const std::string& description, 
             const std::string& type, const std::string& targetAudience,
             int rating, int soldCount)
    : Product(name, description, rating, soldCount), type(type), targetAudience(targetAudience) {}

// Copy constructor
Media::Media(const Media& other)
    : Product(other), type(other.type), targetAudience(other.targetAudience) {}

// Destructor
Media::~Media() {}

// Assignment operator
Media& Media::operator=(const Media& other) {
    if (this != &other) {
        Product::operator=(other);
        type = other.type;
        targetAudience = other.targetAudience;
    }
    return *this;
}

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
    
    std::cout << "Current Type: " << type << std::endl;
    std::cout << "Enter new type (or press Enter to keep current): ";
    std::getline(std::cin, newType);
    if (!newType.empty()) {
        type = newType;
    }
    
    std::cout << "Current Target Audience: " << targetAudience << std::endl;
    std::cout << "Enter new target audience (or press Enter to keep current): ";
    std::getline(std::cin, newTargetAudience);
    if (!newTargetAudience.empty()) {
        targetAudience = newTargetAudience;
    }
    
    std::cout << "Media product modified successfully!" << std::endl;
    return true;
}

// Override sell method - generates better random access codes
bool Media::sell(int quantity) {
    // Use a better random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100000, 999999); // 6-digit code
    
    // Generate an alphanumeric code
    std::stringstream accessCode;
    accessCode << std::setfill('0') << std::setw(6) << dis(gen);
    
    // Add 2 random uppercase letters
    accessCode << static_cast<char>('A' + (dis(gen) % 26))
               << static_cast<char>('A' + (dis(gen) % 26));
    
    // Increment sold count by quantity
    soldCount += quantity;
    
    // Display access code
    std::cout << "Media product sold successfully!" << std::endl;
    std::cout << "Your secure access code is: " << accessCode.str() << std::endl;
    std::cout << "Quantity sold: " << quantity << std::endl;
    std::cout << "Total items of this product sold: " << soldCount << std::endl;
    
    return true;
}

// Input operator implementation
std::istream& operator>>(std::istream& is, Media& media) {
    // First, get the base Product members
    operator>>(is, static_cast<Product&>(media));
    
    std::cout << "Enter media type (e.g., book, movie, music): ";
    std::getline(is, media.type);
    
    std::cout << "Enter target audience: ";
    std::getline(is, media.targetAudience);
    
    return is;
}

// Output operator implementation
std::ostream& operator<<(std::ostream& os, const Media& media) {
    os << static_cast<const Product&>(media) << std::endl;
    os << "Type: " << media.type << std::endl;
    os << "Target Audience: " << media.targetAudience;
    return os;
}