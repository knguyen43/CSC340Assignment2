#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <memory>

/**
 * @brief Abstract base class representing a generic product.
 *
 * The Product class serves as the foundation for all product types,
 * providing common attributes and behaviors. It cannot be instantiated
 * directly due to its pure virtual functions.
 */
class Product {
protected:
    std::string name;          ///< Product name
    std::string description;   ///< Product description
    int rating;                ///< Customer rating (typically 0-5)
    int soldCount;             ///< Number of units sold

public:
    /**
     * @brief Default constructor
     * @pre None
     * @post A Product object is created with default values
     */
    Product();
    
    /**
     * @brief Parameterized constructor
     * @param name The product name
     * @param description The product description
     * @param rating The initial product rating (default 0)
     * @param soldCount The initial number of units sold (default 0)
     * @pre None
     * @post A Product object is created with the specified values
     */
    Product(const std::string& name, const std::string& description, int rating = 0, int soldCount = 0);
    
    /**
     * @brief Copy constructor
     * @param other The Product object to copy from
     * @pre None
     * @post A new Product object is created as a copy of other
     */
    Product(const Product& other);
    
    /**
     * @brief Virtual destructor to ensure proper cleanup of derived classes
     * @pre None
     * @post The Product object is properly destroyed
     */
    virtual ~Product();
    
    /**
     * @brief Assignment operator
     * @param other The Product object to assign from
     * @return Reference to this object after assignment
     */
    Product& operator=(const Product& other);
    
    /**
     * @brief Gets the product name
     * @return The product name as a string
     */
    std::string getName() const;
    
    /**
     * @brief Gets the product description
     * @return The product description as a string
     */
    std::string getDescription() const;
    
    /**
     * @brief Gets the product rating
     * @return The product rating as an integer
     */
    int getRating() const;
    
    /**
     * @brief Gets the number of units sold
     * @return The sold count as an integer
     */
    int getSoldCount() const;
    
    /**
     * @brief Sets the product name
     * @param name The new product name
     * @pre None
     * @post The product name is updated
     */
    void setName(const std::string& name);
    
    /**
     * @brief Sets the product description
     * @param description The new product description
     * @pre None
     * @post The product description is updated
     */
    void setDescription(const std::string& description);
    
    /**
     * @brief Sets the product rating
     * @param rating The new product rating
     * @pre rating should be a valid rating value
     * @post The product rating is updated
     */
    void setRating(int rating);
    
    /**
     * @brief Sets the number of units sold
     * @param soldCount The new sold count
     * @pre soldCount should be non-negative
     * @post The product sold count is updated
     */
    void setSoldCount(int soldCount);
    
    /**
     * @brief Displays product information to the console
     * @pre None
     * @post Product information is displayed
     */
    virtual void display() const;
    
    /**
     * @brief Modifies product details based on user input
     * @pre None
     * @post Product details are updated if the modification is successful
     * @return True if the modification was successful, false otherwise
     */
    virtual bool modify();
    
    /**
     * @brief Pure virtual method for selling a product
     * @param quantity The quantity to sell
     * @pre None
     * @post If the sale is successful, the product's soldCount is incremented
     * @return True if the sale was successful, false otherwise
     */
    virtual bool sell(int quantity) = 0;
    
    /**
     * @brief Equality comparison operator
     * @param otherProduct The product to compare with
     * @return True if products have the same name, false otherwise
     */
    bool operator==(const Product& otherProduct) const;
    
    /**
     * @brief Friend function for input operator overloading
     * @param is The input stream
     * @param product The Product object to input data into
     * @return Reference to the input stream
     */
    friend std::istream& operator>>(std::istream& is, Product& product);
    
    /**
     * @brief Friend function for output operator overloading
     * @param os The output stream
     * @param product The Product object to output
     * @return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Product& product);
};

/**
 * @brief Input operator for Product
 * @param is The input stream
 * @param product The Product object to input data into
 * @return Reference to the input stream
 */
std::istream& operator>>(std::istream& is, Product& product);

/**
 * @brief Output operator for Product
 * @param os The output stream
 * @param product The Product object to output
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Product& product);

// Forward declarations for derived classes
class Media;
class Good;

// Define smart pointer types for Products
using ProductPtr = std::shared_ptr<Product>;
using MediaPtr = std::shared_ptr<Media>;
using GoodPtr = std::shared_ptr<Good>;

#endif // PRODUCT_H

