#include "Vendor.h"
#include <iostream>
#include <vector>

// Constructors
Vendor::Vendor() : username(""), email(""), password(""), bio(""), profilePicture("") {}

Vendor::Vendor(const std::string& username, const std::string& email, 
               const std::string& password, const std::string& bio, 
               const std::string& profilePicture)
    : username(username), email(email), password(password), bio(bio), profilePicture(profilePicture) {}

// Destructor - Clean up products
Vendor::~Vendor() {
    // Get all products and delete them
    std::vector<Product*> productsList = products.toVector();
    for (Product* product : productsList) {
        delete product;
    }
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
    std::cout << "==== Vendor Profile ====" << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Bio: " << bio << std::endl;
    std::cout << "Profile Picture: " << profilePicture << std::endl;
    std::cout << "Number of Products: " << products.getCurrentSize() << std::endl;
}

bool Vendor::updatePassword(const std::string& newPassword) {
    password = newPassword;
    std::cout << "Password updated successfully to: " << newPassword << std::endl;
    return true;
}

// Product management
bool Vendor::createMediaProduct(const std::string& name, const std::string& description,
                              const std::string& type, const std::string& targetAudience) {
    Media* newMedia = new Media(name, description, type, targetAudience);
    return products.add(newMedia);
}

bool Vendor::createGoodsProduct(const std::string& name, const std::string& description,
                              const std::string& expirationDate, int quantity) {
    Goods* newGoods = new Goods(name, description, expirationDate, quantity);
    return products.add(newGoods);
}

void Vendor::displayAllProducts() const {
    std::vector<Product*> productsList = products.toVector();
    
    if (productsList.empty()) {
        std::cout << "You don't have any products yet." << std::endl;
        return;
    }
    
    std::cout << "==== Your Products ====" << std::endl;
    for (int i = 0; i < productsList.size(); i++) {
        std::cout << "Product #" << (i + 1) << ":" << std::endl;
        productsList[i]->displayInfo();
        std::cout << "----------------------" << std::endl;
    }
}

Product* Vendor::getKthProduct(int k) const {
    if (k <= 0 || k > products.getCurrentSize()) {
        std::cout << "Error: Invalid product index. You have " << products.getCurrentSize() << " products." << std::endl;
        return nullptr;
    }
    
    Node<Product*>* productNode = products.findKthItem(k);
    if (productNode != nullptr) {
        Product* product = productNode->getItem();
        std::cout << "Product #" << k << ":" << std::endl;
        product->displayInfo();
        return product;
    }
    
    return nullptr;
}

bool Vendor::modifyProduct(int index, const std::string& newName, const std::string& newDescription) {
    Product* product = getKthProduct(index);
    if (product != nullptr) {
        product->setName(newName);
        product->setDescription(newDescription);
        std::cout << "Product modified successfully!" << std::endl;
        return true;
    }
    return false;
}

bool Vendor::sellProduct(int index) {
    Product* product = getKthProduct(index);
    if (product != nullptr) {
        return product->sell();
    }
    return false;
}

bool Vendor::deleteProduct(int index) {
    if (index <= 0 || index > products.getCurrentSize()) {
        std::cout << "Error: Invalid product index. You have " << products.getCurrentSize() << " products." << std::endl;
        return false;
    }
    
    // Get the product to delete
    Node<Product*>* productNode = products.findKthItem(index);
    if (productNode != nullptr) {
        Product* product = productNode->getItem();
        // Store a temporary copy of the product for comparison
        Product* productCopy = product;
        
        // Remove from bag
        bool removed = products.remove(product);
        
        // If successfully removed, delete the product
        if (removed) {
            delete productCopy;
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

// Operator overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
    return (username == otherVendor.username) && (email == otherVendor.email);
}
