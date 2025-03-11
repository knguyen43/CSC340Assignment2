#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

// Base Product class (Abstract) - aligned with UML
class Product {
protected:
    std::string name;
    std::string description;
    int rating;
    int soldCount;

public:
    // Constructors
    Product();
    Product(const std::string& name, const std::string& description, int rating = 0, int soldCount = 0);
    
    // Destructor
    virtual ~Product();
    
    // Getters
    std::string getName() const;
    std::string getDescription() const;
    int getRating() const;
    int getSoldCount() const;
    
    // Setters
    void setName(const std::string& name);
    void setDescription(const std::string& description);
    void setRating(int rating);
    void setSoldCount(int soldCount);
    
    // Methods from UML
    virtual void display() const;  // Display product information
    virtual bool modify();         // Modify product details
    virtual bool sell(int quantity) = 0;  // Pure virtual method for selling
    
    // Operator overloading as specified
    bool operator==(const Product& otherProduct) const;
};

// Media class (inherits from Product) - aligned with UML
class Media : public Product {
private:
    std::string type;  // e.g., book, music, movie
    std::string targetAudience;

public:
    // Constructors
    Media();
    Media(const std::string& name, const std::string& description, 
          const std::string& type, const std::string& targetAudience,
          int rating = 0, int soldCount = 0);
    
    // Getters
    std::string getType() const;
    std::string getTargetAudience() const;
    
    // Setters
    void setType(const std::string& type);
    void setTargetAudience(const std::string& targetAudience);
    
    // Override methods from Product
    void display() const override;
    bool modify() override;
    bool sell(int quantity) override;
};

// Good class (inherits from Product) - aligned with UML (renamed from Goods to Good)
class Good : public Product {
private:
    std::string expirationDate;
    int quantity;

public:
    // Constructors
    Good();
    Good(const std::string& name, const std::string& description, 
         const std::string& expirationDate, int quantity,
         int rating = 0, int soldCount = 0);
    
    // Getters
    std::string getExpirationDate() const;
    int getQuantity() const;
    
    // Setters
    void setExpirationDate(const std::string& expirationDate);
    void setQuantity(int quantity);
    
    // Override methods from Product
    void display() const override;
    bool modify() override;
    bool sell(int quantity) override;
};

#endif // PRODUCT_H

