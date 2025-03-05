#include <iostream>
#include <string>
#include "Amazon340.h"

// Constructor
Amazon340::Amazon340() {
    // Initialize with default vendor
    std::cout << "Amazon340 application started." << std::endl;
}

// Destructor
Amazon340::~Amazon340() {
    std::cout << "Amazon340 application exiting." << std::endl;
}

// Create a vendor with provided information
void Amazon340::createVendor(const std::string& username, const std::string& email, 
                           const std::string& password, const std::string& bio, 
                           const std::string& profilePicture) {
    // Create a new vendor with the provided information
    vendor = Vendor(username, email, password, bio, profilePicture);
    std::cout << "Vendor profile created successfully!" << std::endl;
}

// Get the current vendor
Vendor Amazon340::getVendor() const {
    return vendor;
}