#ifndef MEDIA_H
#define MEDIA_H

#include "Product.h"
#include <string>
#include <iostream>

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
     * @brief Copy constructor
     * @param other The Media object to copy from
     * @pre None
     * @post A new Media object is created as a copy of other
     */
    Media(const Media& other);
    
    /**
     * @brief Virtual destructor
     * @pre None
     * @post The Media object is properly destroyed
     */
    virtual ~Media();
    
    /**
     * @brief Assignment operator
     * @param other The Media object to assign from
     * @return Reference to this object after assignment
     */
    Media& operator=(const Media& other);
    
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
    
    /**
     * @brief Friend function for input operator overloading
     * @param is The input stream
     * @param media The Media object to input data into
     * @return Reference to the input stream
     */
    friend std::istream& operator>>(std::istream& is, Media& media);
    
    /**
     * @brief Friend function for output operator overloading
     * @param os The output stream
     * @param media The Media object to output
     * @return Reference to the output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Media& media);
};

/**
 * @brief Input operator for Media
 * @param is The input stream
 * @param media The Media object to input data into
 * @return Reference to the input stream
 */
std::istream& operator>>(std::istream& is, Media& media);

/**
 * @brief Output operator for Media
 * @param os The output stream
 * @param media The Media object to output
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Media& media);

#endif // MEDIA_H