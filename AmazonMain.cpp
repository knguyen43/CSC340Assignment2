#include <iostream> 
#include <string>
#include <limits>  // For input handling
#include "Amazon340.h"
#include "Product.h"

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
                // Display vendor's profile information
                vendor.displayProfile();
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
                string name, description;
                
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
                cout << "Enter product name: ";
                getline(cin, name);
                
                cout << "Enter product description: ";
                getline(cin, description);
                
                if (productType == 1) {
                    // Media product
                    string type, targetAudience;
                    
                    cout << "Enter media type (e.g., book, movie, music): ";
                    getline(cin, type);
                    
                    cout << "Enter target audience: ";
                    getline(cin, targetAudience);
                    
                    Media* newMedia = new Media(name, description, type, targetAudience);
                    if (vendor.createProduct(newMedia)) {
                        cout << "Media product created successfully!" << endl;
                    } else {
                        cout << "Failed to create media product." << endl;
                        delete newMedia; // Clean up if failed
                    }
                    
                } else if (productType == 2) {
                    // Goods product
                    string expirationDate;
                    int quantity;
                    
                    cout << "Enter expiration date: ";
                    getline(cin, expirationDate);
                    
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    
                    // Handle invalid input
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid quantity. Using default of 0." << endl;
                        quantity = 0;
                    }
                    
                    Good* newGood = new Good(name, description, expirationDate, quantity);
                    if (vendor.createProduct(newGood)) {
                        cout << "Good product created successfully!" << endl;
                    } else {
                        cout << "Failed to create good product." << endl;
                        delete newGood; // Clean up if failed
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
                string newName, newDescription;
                
                cout << "Enter the product index to modify: ";
                cin >> index;
                
                // Handle invalid input
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a number." << endl;
                    break;
                }
                
                cin.ignore();
                cout << "Enter new product name: ";
                getline(cin, newName);
                
                cout << "Enter new product description: ";
                getline(cin, newDescription);
                
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

    cout << "\n Welcome to Amazon340:" << endl;
    
    // Ask the vendor to enter their information
    string username, email, password, bio, profilePicture;
    
    cout << "Let's create your vendor profile:" << endl;
    cout << "Enter username: ";
    cin >> username;
    
    cout << "Enter email: ";
    cin >> email;
    
    cout << "Enter password: ";
    cin >> password;
    
    cin.ignore(); // Clear input buffer
    
    cout << "Enter short bio: ";
    getline(cin, bio);
    
    cout << "Enter profile picture path: ";
    getline(cin, profilePicture);
    
    // Call amazon340 createVendor function
    amazon340.createVendor();
    
    // Since createVendor now prompts for input, we need to create the vendor manually here
    Vendor manualVendor(username, email, password, bio, profilePicture);
    // We'd need a setter in Amazon340 class to properly set this vendor, but for now we'll use what's returned

    // Retrieve the vendor 
    Vendor currentVendor = amazon340.getVendor();

    // Display the main menu
    displayVendorMenu(currentVendor);
                
    return 0;
}