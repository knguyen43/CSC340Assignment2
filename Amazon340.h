#ifndef AMAZON340_H
#define AMAZON340_H

#include "LinkedBagDS/LinkedBag.h"
#include "Vendor.h"
#include <string>

// This class represents the main application and contains a vendor
class Amazon340 {
	private:
		Vendor vendor;

	public:
		// Constructors and destructor
		Amazon340();
		~Amazon340();

		// Create a vendor
		void createVendor();

		// Get the current vendor
		Vendor getVendor() const;
};

#endif // AMAZON340_H