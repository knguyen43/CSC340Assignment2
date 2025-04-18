#include <iostream> 
#include <string>
#include <limits>  // For input handling
#include <memory>  // For smart pointers
#include "Amazon340.h"
#include "Product.h"
#include "Media.h"
#include "Good.h"
#include "LinkedBagDS/LinkedBag.h"

using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Vendor
 * @param vendor object to interact with
 * 
 * */
void displayVendorMenu(Vendor& vendor) {
    int vendorChoice = 0;
    do {
        cout << "\n Hi, "<< vendor.getUsername() <<", what would you like to do:\n"
        << "1. Display Profile\n"
        << "2. Modify Password\n"
        << "3. Create Product\n"
        << "4. Display All Products\n"
        << "5. Display Kth Product\n"
        << "6. Modify Product\n"
        << "7. Sell Product\n"
        << "8. Delete Product\n"
        << "9. Add Product at Position K\n"
        << "0. Logout\n"
        << "Choice: ";
        cin >> vendorChoice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (vendorChoice) {
            case 1: {
                // Display vendor's profile information using operator<<
                cout << vendor << endl;
                break;
            }
            case 2: {
                // Modify vendor's password
                string newPassword;
                cout << "Enter new password: ";
                cin >> newPassword;
                
                if (vendor.modifyPassword(newPassword)) {
                    cout << "Password updated successfully!" << endl;
                }
                break;
            }
            case 3: {
                // Create a new product
                int productType;
                
                cout << "What type of product would you like to create?" << endl;
                cout << "1. Media" << endl;
                cout << "2. Goods" << endl;
                cout << "Enter choice: ";
                cin >> productType;
                
                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again." << endl;
                    break;
                }
                
                cin.ignore();
                
                if (productType == 1) {
                    // Media product using operator>>
                    Media media;
                    cin >> media;
                    
                    // Create a smart pointer
                    MediaPtr newMedia = make_shared<Media>(media);
                    if (vendor.createProduct(newMedia)) {
                        cout << "Media product created successfully!" << endl;
                    } else {
                        cout << "Failed to create media product." << endl;
                    }
                    
                } else if (productType == 2) {
                    // Goods product using operator>>
                    Good good;
                    cin >> good;
                    
                    // Create a smart pointer
                    GoodPtr newGood = make_shared<Good>(good);
                    if (vendor.createProduct(newGood)) {
                        cout << "Good product created successfully!" << endl;
                    } else {
                        cout << "Failed to create good product." << endl;
                    }
                    
                } else {
                    cout << "Invalid product type." << endl;
                }
                break;
            }
            case 4: {
                // Display all vendor's products
                vendor.displayAllProducts();
                break;
            }
            case 5: {
                // Display kth product
                int k;
                cout << "Enter the product index (k): ";
                cin >> k;
                
                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    break;
                }
                
                vendor.displayProduct(k);
                break;
            }
            case 6: {
                // Modify a product
                int index;
                
                cout << "Enter the product index to modify: ";
                cin >> index;
                
                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    break;
                }
                
                cin.ignore(); // Clear the input buffer for getline in modify method
                
                vendor.modifyProduct(index);
                break;
            }
            case 7: {
                // Sell a product
                int index;
                cout << "Enter the product index to sell: ";
                cin >> index;
                
                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    break;
                }
                
                int quantity;
                cout << "Enter quantity to sell: ";
                cin >> quantity;
                
                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid quantity. Using 1 as default." << endl;
                    quantity = 1;
                }
                
                vendor.sellProduct(index, quantity);
                break;
            }
            case 8: {
                // Delete a product
                int index;
                cout << "Enter the product index to delete: ";
                cin >> index;
                
                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    break;
                }
                
                vendor.deleteProduct(index);
                break;
            }
            case 9: {
                // Add product at position K
                int productType, k;
                
                cout << "Enter the position (K) to add the product at: ";
                cin >> k;
                
                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    break;
                }
                
                cout << "What type of product would you like to create?" << endl;
                cout << "1. Media" << endl;
                cout << "2. Goods" << endl;
                cout << "Enter choice: ";
                cin >> productType;
                
                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again." << endl;
                    break;
                }
                
                cin.ignore();
                
                ProductPtr newProduct = nullptr;
                
                if (productType == 1) {
                    // Media product
                    Media media;
                    cin >> media;
                    newProduct = make_shared<Media>(media);
                    
                } else if (productType == 2) {
                    // Goods product
                    Good good;
                    cin >> good;
                    newProduct = make_shared<Good>(good);
                    
                } else {
                    cout << "Invalid product type." << endl;
                    break;
                }
                
                // Add the product at position K
                LinkedBag<ProductPtr>& productsBag = vendor.getProductsBag();
                if (productsBag.appendK(newProduct, k)) {
                    cout << "Product successfully added at position " << k << "!" << endl;
                } else {
                    cout << "Failed to add product at position " << k << "." << endl;
                }
                break;
            }
            case 0: {
                cout << "Logging you out." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (vendorChoice != 0);
}


int main() {
    // Instantiating the program using the default constructor
    Amazon340 amazon340; 

    // Display welcome message using operator<<
    cout << amazon340 << endl;
    
    // We'll let createVendor() handle getting the vendor information
    cout << "Let's create your vendor profile:" << endl;
    
    // Call amazon340 createVendor function
    amazon340.createVendor();
    
    // Retrieve the vendor 
    Vendor currentVendor = amazon340.getVendor();

    // Display the main menu
    displayVendorMenu(currentVendor);
                
    return 0;
}