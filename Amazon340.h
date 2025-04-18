#ifndef AMAZON340_H
#define AMAZON340_H

#include "LinkedBagDS/LinkedBag.h"
#include "Vendor.h"
#include <string>
#include <iostream>

/**
 * @brief Main application class
 *
 * The Amazon340 class serves as the entry point,
 * managing the vendor and providing the interface to create and retrieve
 * vendor information.
 */
class Amazon340 {
	private:
		Vendor vendor; ///< The vendor associated with this application instance

	public:
		/**
		 * @brief Default constructor
		 * @pre None
		 * @post An Amazon340 object is created with a default vendor
		 */
		Amazon340();
		
		/**
		 * @brief Copy constructor
		 * @param other The Amazon340 object to copy from
		 * @pre None
		 * @post A new Amazon340 object is created with a copy of the other's vendor
		 */
		Amazon340(const Amazon340& other);
		
		/**
		 * @brief Destructor
		 * @pre None
		 * @post The Amazon340 object is properly destroyed
		 */
		~Amazon340();
		
		/**
		 * @brief Assignment operator
		 * @param other The Amazon340 object to assign from
		 * @return Reference to this object after assignment
		 */
		Amazon340& operator=(const Amazon340& other);

		/**
		 * @brief Creates a new vendor with user input
		 * @pre None
		 * @post A new vendor is created and stored in the application
		 */
		void createVendor();

		/**
		 * @brief Gets the current vendor
		 * @return The current vendor object
		 */
		Vendor getVendor() const;
		
		/**
		 * @brief Friend function for output operator overloading
		 * @param os The output stream
		 * @param amazon The Amazon340 object to output
		 * @return Reference to the output stream
		 */
		friend std::ostream& operator<<(std::ostream& os, const Amazon340& amazon);
};

/**
 * @brief Output operator for Amazon340
 * @param os The output stream
 * @param amazon The Amazon340 object to output
 * @return Reference to the output stream
 */
std::ostream& operator<<(std::ostream& os, const Amazon340& amazon);

#endif // AMAZON340_H