#ifndef GOOD_H
#define GOOD_H

#include "Product.h"
#include <string>
#include <iostream>

/**
 * @brief Class representing physical goods with inventory and expiration dates
 *
 * Good is a concrete implementation of Product that handles physical goods
 * which have a limited quantity in stock and may have expiration dates.
 */
class Good : public Product {
private:
    std::string expirationDate; ///< Date when the product expires (if applicable)
    int quantity;               ///< Available inventory quantity

public:
    /**
     * @brief Default constructor
     * @pre None
     * @post A Good object is created with default values
     */
    Good();
    
    /**
     * @brief Parameterized constructor
     * @param name The good's name
     * @param description The good's description
     * @param expirationDate The expiration date of the good (if applicable)
     * @param quantity The initial inventory quantity
     * @param rating The initial product rating (default 0)
     * @param soldCount The initial number of units sold (default 0)
     * @pre None
     * @post A Good object is created with the specified values
     */
    Good(const std::string& name, const std::string& description, 
         const std::string& expirationDate, int quantity,
         int rating = 0, int soldCount = 0);
    
    /**
     * @brief Copy constructor
     * @param other The Good object to copy from
     * @pre None
     * @post A new Good object is created as a copy of other
     */
    Good(const Good& other);
    
    /**
     * @brief Virtual destructor
     * @pre None
     * @post The Good object is properly destroyed
     */
    virtual ~Good();
    
    /**
     * @brief Assignment operator
     * @param other The Good object to assign from
     * @return Reference to this object after assignment
     */
    Good& operator=(const Good& other);
    
    /**
     * @brief Gets the expiration date
     * @return The expiration date as a string
     */
    std::string getExpirationDate() const;
    
    /**
     * @brief Gets the current inventory quantity
     * @return The quantity as an integer
     */
    int getQuantity() const;
    
    /**
     * @brief Sets the expiration date
     * @param expirationDate The new expiration date
     * @pre None
     * @post The expiration date is updated
     */
    void setExpirationDate(const std::string& expirationDate);
    
    /**
     * @brief Sets the inventory quantity
     * @param quantity The new quantity
     * @pre quantity should be non-negative
     * @post The inventory quantity is updated
     */
    void setQuantity(int quantity);
    
    /**
     * @brief Displays good information including expiration date and quantity
     * @pre None
     * @post Good information is displayed
     */
    void display() const override;
    
    /**
     * @brief Modifies good details based on user input
     * @pre None
     * @post Good details are updated if the modification is successful
     * @return True if the modification was successful, false otherwise
     */
    bool modify() override;
    
    /**
     * @brief Sells a quantity of the good from inventory
     * @param quantity The quantity to sell
     * @pre None
     * @post If the sale is successful, the product's soldCount is incremented
     *       and the inventory quantity is reduced
     * @return True if the sale was successful, false otherwise
     */
    bool sell(int quantity) override;
    
    /**
     * @brief Friend function for input operator overloading
     * @param is The input stream
     * @param good The Good object to input data into
     * @return Reference to the input stream
     */
    friend std::istream& operator>>(std::istream& is, Good& good);
    
    /**
     * @brief Friend function for output operator overloading
     * @param os The output stream
     * @param good The Good object to output
     * @return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Good& good);
};

/**
 * @brief Input operator for Good
 * @param is The input stream
 * @param good The Good object to input data into
 * @return Reference to the input stream
 */
std::istream& operator>>(std::istream& is, Good& good);

/**
 * @brief Output operator for Good
 * @param os The output stream
 * @param good The Good object to output
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Good& good);

#endif // GOOD_H