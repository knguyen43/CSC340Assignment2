#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

// Base Product class
class Product {
protected:
    std::string name;
    std::string description;
    float rating;
    int soldCount;

public:
    // Constructors
    Product();
    Product(const std::string& name, const std::string& description, float rating = 0.0f, int soldCount = 0);
    
    // Destructor
    virtual ~Product();
    
    // Getters
    std::string getName() const;
    std::string getDescription() const;
    float getRating() const;
    int getSoldCount() const;
    
    // Setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setRating(float rating);
    void setSoldCount(int soldCount);
    
    // Display product information
    virtual void displayInfo() const;
    
    // Polymorphic sell method
    virtual bool sell() = 0;  // Pure virtual method
    
    // Operator overloading as specified
    bool operator==(const Product& otherProduct) const;
};

// Media class (inherits from Product)
class Media : public Product {
private:
    std::string type;  // e.g., book, music, movie
    std::string targetAudience;

public:
    // Constructors
    Media();
    Media(const std::string& name, const std::string& description, 
          const std::string& type, const std::string& targetAudience,
          float rating = 0.0f, int soldCount = 0);
    
    // Getters
    std::string getType() const;
    std::string getTargetAudience() const;
    
    // Setters
    void setType(const std::string& type);
    void setTargetAudience(const std::string& targetAudience);
    
    // Override display method
    void displayInfo() const override;
    
    // Override sell method
    bool sell() override;
};

// Goods class (inherits from Product)
class Goods : public Product {
private:
    std::string expirationDate;
    int quantity;

public:
    // Constructors
    Goods();
    Goods(const std::string& name, const std::string& description, 
          const std::string& expirationDate, int quantity,
          float rating = 0.0f, int soldCount = 0);
    
    // Getters
    std::string getExpirationDate() const;
    int getQuantity() const;
    
    // Setters
    void setExpirationDate(const std::string& expirationDate);
    void setQuantity(int quantity);
    
    // Override display method
    void displayInfo() const override;
    
    // Override sell method
    bool sell() override;
};

#endif // PRODUCT_H

