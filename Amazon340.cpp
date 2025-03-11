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

// Create a vendor
void Amazon340::createVendor() {
    // Create a new vendor with default or prompted information
    std::string username, email, password, bio, profilePicture;
    
    std::cout << "Creating a new vendor..." << std::endl;
    std::cout << "Enter username: ";
    std::cin >> username;
    
    std::cout << "Enter email: ";
    std::cin >> email;
    
    std::cout << "Enter password: ";
    std::cin >> password;
    
    std::cin.ignore(); // Clear the newline from the input buffer
    
    std::cout << "Enter bio: ";
    std::getline(std::cin, bio);
    
    std::cout << "Enter profile picture URL: ";
    std::getline(std::cin, profilePicture);
    
    vendor = Vendor(username, email, password, bio, profilePicture);
    std::cout << "Vendor profile created successfully!" << std::endl;
}

// Get the current vendor
Vendor Amazon340::getVendor() const {
    return vendor;
}