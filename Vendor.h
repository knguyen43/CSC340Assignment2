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
    
    // Profile management
    void displayProfile() const;
    bool updatePassword(const std::string& newPassword);
    
    // Product management
    bool createMediaProduct(const std::string& name, const std::string& description,
                          const std::string& type, const std::string& targetAudience);
    
    bool createGoodsProduct(const std::string& name, const std::string& description,
                          const std::string& expirationDate, int quantity);
    
    void displayAllProducts() const;
    
    Product* getKthProduct(int k) const;
    
    bool modifyProduct(int index, const std::string& newName, const std::string& newDescription);
    
    bool sellProduct(int index);
    
    bool deleteProduct(int index);
    
    int getProductCount() const;
    
    // Operator overloading as specified
    bool operator==(const Vendor& otherVendor) const;
};

#endif // VENDOR_H
