#ifndef VENDOR_H
#define VENDOR_H

#include <string>
#include <iostream>
#include <memory>
#include "Product.h"
#include "LinkedBagDS/LinkedBag.h"

/**
 * @brief Class representing a vendor selling products
 *
 * The Vendor class manages a seller's profile information and product catalog.
 * It provides functionality for managing products and vendor profile details.
 */
class Vendor {
private:
    std::string username;        ///< Vendor's username
    std::string email;           ///< Vendor's email address
    std::string password;        ///< Vendor's password
    std::string bio;             ///< Vendor's biographical information
    std::string profilePicture;  ///< Path/URL to vendor's profile picture
    LinkedBag<ProductPtr> products; ///< Collection of products the vendor sells using smart pointers

public:
    /**
     * @brief Default constructor
     * @pre None
     * @post A Vendor object is created with default values
     */
    Vendor();
    
    /**
     * @brief Parameterized constructor
     * @param username The vendor's username
     * @param email The vendor's email address
     * @param password The vendor's password
     * @param bio The vendor's biographical information
     * @param profilePicture Path/URL to the vendor's profile picture
     * @pre None
     * @post A Vendor object is created with the specified values
     */
    Vendor(const std::string& username, const std::string& email, 
           const std::string& password, const std::string& bio, 
           const std::string& profilePicture);
    
    /**
     * @brief Copy constructor
     * @param other The Vendor object to copy from
     * @pre None
     * @post A new Vendor object is created as a copy of other
     */
    Vendor(const Vendor& other);
    
    /**
     * @brief Destructor
     * @pre None
     * @post The Vendor object is destroyed (smart pointers handle memory cleanup)
     */
    ~Vendor();
    
    /**
     * @brief Assignment operator
     * @param other The Vendor object to assign from
     * @return Reference to this object after assignment
     */
    Vendor& operator=(const Vendor& other);
    
    /**
     * @brief Gets the vendor's username
     * @return The username as a string
     */
    std::string getUsername() const;
    
    /**
     * @brief Gets the vendor's email address
     * @return The email address as a string
     */
    std::string getEmail() const;
    
    /**
     * @brief Gets the vendor's biographical information
     * @return The bio as a string
     */
    std::string getBio() const;
    
    /**
     * @brief Gets the vendor's profile picture path/URL
     * @return The profile picture path/URL as a string
     */
    std::string getProfilePicture() const;
    
    /**
     * @brief Sets the vendor's username
     * @param username The new username
     * @pre None
     * @post The vendor's username is updated
     */
    void setUsername(const std::string& username);
    
    /**
     * @brief Sets the vendor's email address
     * @param email The new email address
     * @pre None
     * @post The vendor's email address is updated
     */
    void setEmail(const std::string& email);
    
    /**
     * @brief Sets the vendor's password
     * @param password The new password
     * @pre None
     * @post The vendor's password is updated
     */
    void setPassword(const std::string& password);
    
    /**
     * @brief Sets the vendor's biographical information
     * @param bio The new biographical information
     * @pre None
     * @post The vendor's bio is updated
     */
    void setBio(const std::string& bio);
    
    /**
     * @brief Sets the vendor's profile picture path/URL
     * @param profilePicture The new profile picture path/URL
     * @pre None
     * @post The vendor's profile picture is updated
     */
    void setProfilePicture(const std::string& profilePicture);
    
    /**
     * @brief Displays the vendor's profile information
     * @pre None
     * @post The vendor's profile information is displayed
     */
    void displayProfile() const;
    
    /**
     * @brief Modifies the vendor's password
     * @param newPassword The new password
     * @pre None
     * @post The vendor's password is updated if the modification is successful
     * @return True if the password was successfully changed, false otherwise
     */
    bool modifyPassword(const std::string& newPassword);
    
    /**
     * @brief Adds a new product to the vendor's catalog
     * @param product Smart pointer to the product to add
     * @pre product is a valid smart pointer to a Product object
     * @post The product is added to the vendor's catalog if creation is successful
     * @return True if the product was successfully added, false otherwise
     */
    bool createProduct(ProductPtr product);
    
    /**
     * @brief Displays information for a specific product
     * @param k The index of the product to display (1-based)
     * @pre None
     * @post The product information is displayed if the index is valid
     */
    void displayProduct(int k) const;
    
    /**
     * @brief Displays information for all products in the vendor's catalog
     * @pre None
     * @post All product information is displayed
     */
    void displayAllProducts() const;
    
    /**
     * @brief Modifies details of a specific product
     * @param k The index of the product to modify (1-based)
     * @pre None
     * @post The product is modified if the index is valid and modification is successful
     * @return True if the product was successfully modified, false otherwise
     */
    bool modifyProduct(int k);
    
    /**
     * @brief Sells a specified quantity of a product
     * @param k The index of the product to sell (1-based)
     * @param quantity The quantity to sell
     * @pre None
     * @post The product's sell method is called if the index is valid
     * @return True if the sale was successful, false otherwise
     */
    bool sellProduct(int k, int quantity);
    
    /**
     * @brief Removes a product from the vendor's catalog
     * @param k The index of the product to delete (1-based)
     * @pre None
     * @post The product is removed from the catalog if the index is valid
     * @return True if the product was successfully deleted, false otherwise
     */
    bool deleteProduct(int k);
    
    /**
     * @brief Gets a smart pointer to the kth product
     * @param k The index of the product to retrieve (1-based)
     * @pre None
     * @return Smart pointer to the product if found, nullptr otherwise
     */
    ProductPtr getKthProduct(int k) const;
    
    /**
     * @brief Gets the total number of products in the vendor's catalog
     * @pre None
     * @return The number of products as an integer
     */
    int getProductCount() const;
    
    /**
     * @brief Gets direct access to the products bag
     * @pre None
     * @return Reference to the LinkedBag containing the vendor's products
     */
    LinkedBag<ProductPtr>& getProductsBag();
    
    /**
     * @brief Equality comparison operator
     * @param otherVendor The vendor to compare with
     * @return True if vendors have the same username and email, false otherwise
     */
    bool operator==(const Vendor& otherVendor) const;
    
    /**
     * @brief Friend function for input operator overloading
     * @param is The input stream
     * @param vendor The Vendor object to input data into
     * @return Reference to the input stream
     */
    friend std::istream& operator>>(std::istream& is, Vendor& vendor);
    
    /**
     * @brief Friend function for output operator overloading
     * @param os The output stream
     * @param vendor The Vendor object to output
     * @return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Vendor& vendor);
};

/**
 * @brief Input operator for Vendor
 * @param is The input stream
 * @param vendor The Vendor object to input data into
 * @return Reference to the input stream
 */
std::istream& operator>>(std::istream& is, Vendor& vendor);

/**
 * @brief Output operator for Vendor
 * @param os The output stream
 * @param vendor The Vendor object to output
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Vendor& vendor);

#endif // VENDOR_H
