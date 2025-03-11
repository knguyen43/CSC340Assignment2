#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

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
     * @brief Virtual destructor to ensure proper cleanup of derived classes
     * @pre None
     * @post The Product object is properly destroyed
     */
    virtual ~Product();
    
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
};

/**
 * @brief Class representing media products such as books, music, or movies
 *
 * Media is a concrete implementation of Product that handles digital or
 * physical media items, including information about media type and target audience.
 */
class Media : public Product {
private:
    std::string type;          ///< Media type (e.g., book, music, movie)
    std::string targetAudience; ///< Target audience demographic

public:
    /**
     * @brief Default constructor
     * @pre None
     * @post A Media object is created with default values
     */
    Media();
    
    /**
     * @brief Parameterized constructor
     * @param name The media product name
     * @param description The media product description
     * @param type The type of media (e.g., book, music, movie)
     * @param targetAudience The intended audience for this media
     * @param rating The initial product rating (default 0)
     * @param soldCount The initial number of units sold (default 0)
     * @pre None
     * @post A Media object is created with the specified values
     */
    Media(const std::string& name, const std::string& description, 
          const std::string& type, const std::string& targetAudience,
          int rating = 0, int soldCount = 0);
    
    /**
     * @brief Gets the media type
     * @return The media type as a string
     */
    std::string getType() const;
    
    /**
     * @brief Gets the target audience
     * @return The target audience as a string
     */
    std::string getTargetAudience() const;
    
    /**
     * @brief Sets the media type
     * @param type The new media type
     * @pre None
     * @post The media type is updated
     */
    void setType(const std::string& type);
    
    /**
     * @brief Sets the target audience
     * @param targetAudience The new target audience
     * @pre None
     * @post The target audience is updated
     */
    void setTargetAudience(const std::string& targetAudience);
    
    /**
     * @brief Displays media product information including type and target audience
     * @pre None
     * @post Media product information is displayed
     */
    void display() const override;
    
    /**
     * @brief Modifies media product details based on user input
     * @pre None
     * @post Media product details are updated if the modification is successful
     * @return True if the modification was successful, false otherwise
     */
    bool modify() override;
    
    /**
     * @brief Sells a media product (typically generates access code)
     * @param quantity The quantity to sell
     * @pre None
     * @post If the sale is successful, the product's soldCount is incremented
     * @return True if the sale was successful, false otherwise
     */
    bool sell(int quantity) override;
};

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
};

#endif // PRODUCT_H

