#ifndef VENDOR_H
#define VENDOR_H

#include <string>
#include <iostream>
#include "Product.h"
#include "LinkedBagDS/LinkedBag.h"

class Vendor {
private:
    std::string username;
    std::string email;
    std::string password;
    std::string bio;
    std::string profilePicture;
    LinkedBag<Product*> products;  // Using LinkedBag for product storage

public:
    // Constructors
    Vendor();
    Vendor(const std::string& username, const std::string& email, 
           const std::string& password, const std::string& bio, 
           const std::string& profilePicture);
    
    // Destructor
    ~Vendor();
    
    // Getters
    std::string getUsername() const;
    std::string getEmail() const;
    std::string getBio() const;
    std::string getProfilePicture() const;
    
    // Setters
    void setUsername(const std::string& username);
    void setEmail(const std::string& email);
    void setPassword(const std::string& password);
    void setBio(const std::string& bio);
    void setProfilePicture(const std::string& profilePicture);
    
    // Profile management - aligned with UML
    void displayProfile() const;
    bool modifyPassword(const std::string& newPassword);
    
    // Product management - aligned with UML
    bool createProduct(Product* product);
    void displayProduct(int k) const;
    void displayAllProducts() const;
    bool modifyProduct(int k);
    bool sellProduct(int k, int quantity);
    bool deleteProduct(int k);
    
    // Additional helpers
    Product* getKthProduct(int k) const;
    int getProductCount() const;
    
    // Operator overloading as specified
    bool operator==(const Vendor& otherVendor) const;
};

#endif // VENDOR_H
