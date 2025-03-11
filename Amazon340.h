#ifndef AMAZON340_H
#define AMAZON340_H

#include "LinkedBagDS/LinkedBag.h"
#include "Vendor.h"
#include <string>

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
		 * @brief Destructor
		 * @pre None
		 * @post The Amazon340 object is properly destroyed
		 */
		~Amazon340();

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
};

#endif // AMAZON340_H