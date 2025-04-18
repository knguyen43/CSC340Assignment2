#include "Vendor.h"
#include <iostream>
#include <vector>

// Constructors
Vendor::Vendor() : username(""), email(""), password(""), bio(""), profilePicture("") {}

Vendor::Vendor(const std::string& username, const std::string& email, 
               const std::string& password, const std::string& bio, 
               const std::string& profilePicture)
    : username(username), email(email), password(password), bio(bio), profilePicture(profilePicture) {}

// Copy constructor
Vendor::Vendor(const Vendor& other)
    : username(other.username), email(other.email), password(other.password),
      bio(other.bio), profilePicture(other.profilePicture) {
    // Copy products using LinkedBag assignment operator
    products = other.products;
}

// Destructor - Smart pointers handle cleanup automatically
Vendor::~Vendor() {
    // No manual cleanup needed with smart pointers
}

// Assignment operator
Vendor& Vendor::operator=(const Vendor& other) {
    if (this != &other) {
        username = other.username;
        email = other.email;
        password = other.password;
        bio = other.bio;
        profilePicture = other.profilePicture;
        products = other.products;
    }
    return *this;
}

// Getters
std::string Vendor::getUsername() const {
    return username;
}

std::string Vendor::getEmail() const {
    return email;
}

std::string Vendor::getBio() const {
    return bio;
}

std::string Vendor::getProfilePicture() const {
    return profilePicture;
}

// Setters
void Vendor::setUsername(const std::string& username) {
    this->username = username;
}

void Vendor::setEmail(const std::string& email) {
    this->email = email;
}

void Vendor::setPassword(const std::string& password) {
    this->password = password;
}

void Vendor::setBio(const std::string& bio) {
    this->bio = bio;
}

void Vendor::setProfilePicture(const std::string& profilePicture) {
    this->profilePicture = profilePicture;
}

// Profile management
void Vendor::displayProfile() const {
    std::cout << *this;
}

bool Vendor::modifyPassword(const std::string& newPassword) {
    password = newPassword;
    std::cout << "Password updated successfully to: " << newPassword << std::endl;
    return true;
}

// Product management
bool Vendor::createProduct(ProductPtr product) {
    if (product) {
        return products.add(product);
    }
    return false;
}

void Vendor::displayProduct(int k) const {
    if (k <= 0 || k > products.getCurrentSize()) {
        std::cout << "Error: Invalid product index. You have " << products.getCurrentSize() << " products." << std::endl;
        return;
    }
    
    Node<ProductPtr>* productNode = products.reversedFindKthItem(k);
    if (productNode != nullptr) {
        ProductPtr product = productNode->getItem();
        std::cout << "Product #" << k << ":" << std::endl;
        std::cout << *product << std::endl;
    }
}

void Vendor::displayAllProducts() const {
    std::vector<ProductPtr> productsList = products.toVector();
    
    if (productsList.empty()) {
        std::cout << "You don't have any products yet." << std::endl;
        return;
    }
    
    std::cout << "==== Your Products ====" << std::endl;
    for (int i = 0; i < productsList.size(); i++) {
        std::cout << "Product #" << (i + 1) << ":" << std::endl;
        std::cout << *productsList[i] << std::endl;
        std::cout << "----------------------" << std::endl;
    }
}

ProductPtr Vendor::getKthProduct(int k) const {
    if (k <= 0 || k > products.getCurrentSize()) {
        std::cout << "Error: Invalid product index. You have " << products.getCurrentSize() << " products." << std::endl;
        return nullptr;
    }
    
    Node<ProductPtr>* productNode = products.reversedFindKthItem(k);
    if (productNode != nullptr) {
        return productNode->getItem();
    }
    
    return nullptr;
}

bool Vendor::modifyProduct(int k) {
    ProductPtr product = getKthProduct(k);
    if (product) {
        return product->modify();
    }
    return false;
}

bool Vendor::sellProduct(int k, int quantity) {
    ProductPtr product = getKthProduct(k);
    if (product) {
        return product->sell(quantity);
    }
    return false;
}

bool Vendor::deleteProduct(int k) {
    if (k <= 0 || k > products.getCurrentSize()) {
        std::cout << "Error: Invalid product index. You have " << products.getCurrentSize() << " products." << std::endl;
        return false;
    }
    
    // Get the product to delete
    Node<ProductPtr>* productNode = products.reversedFindKthItem(k);
    if (productNode != nullptr) {
        ProductPtr product = productNode->getItem();
        
        // Remove from bag
        bool removed = products.remove(product);
        
        // If successfully removed, smart pointer will handle cleanup
        if (removed) {
            std::cout << "Product deleted successfully!" << std::endl;
            return true;
        }
    }
    
    std::cout << "Failed to delete the product." << std::endl;
    return false;
}

int Vendor::getProductCount() const {
    return products.getCurrentSize();
}

LinkedBag<ProductPtr>& Vendor::getProductsBag() {
    return products;
}

// Operator overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
    return (username == otherVendor.username) && (email == otherVendor.email);
}

// Input operator implementation
std::istream& operator>>(std::istream& is, Vendor& vendor) {
    std::cout << "Enter username: ";
    std::getline(is, vendor.username);
    
    std::cout << "Enter email: ";
    std::getline(is, vendor.email);
    
    std::cout << "Enter password: ";
    std::getline(is, vendor.password);
    
    std::cout << "Enter bio: ";
    std::getline(is, vendor.bio);
    
    std::cout << "Enter profile picture URL: ";
    std::getline(is, vendor.profilePicture);
    
    return is;
}

// Output operator implementation
std::ostream& operator<<(std::ostream& os, const Vendor& vendor) {
    os << "==== Vendor Profile ====" << std::endl;
    os << "Username: " << vendor.username << std::endl;
    os << "Email: " << vendor.email << std::endl;
    os << "Bio: " << vendor.bio << std::endl;
    os << "Profile Picture: " << vendor.profilePicture << std::endl;
    os << "Number of Products: " << vendor.products.getCurrentSize() << std::endl;
    return os;
}
