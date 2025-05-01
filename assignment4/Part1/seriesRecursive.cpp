#include <iostream>
#include <cstdlib> 

/**
 * Calculates the value of the series J(n) using recursion
 * J(0) = 0
 * J(1) = 1
 * J(2) = 1
 * J(n) = J(n-1) + 2 * J(n-2) + 4 * J(n-3) for n > 2
 * 
 * @param n The term in the series to calculate
 * @return The value of J(n) as a long long integer
 */
long long seriesRecursive(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1 || n == 2) return 1;
    
    // Recursive case: J(n) = J(n-1) + 2 * J(n-2) + 4 * J(n-3)
    return seriesRecursive(n-1) + 2 * seriesRecursive(n-2) + 4 * seriesRecursive(n-3);
}

int main(int argc, char* argv[]) {
    // Read n from command line argument
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1; 
    }

    // Convert n to an integer
    int n = std::atoi(argv[1]); 

    // Compute series value of n
    long long result = seriesRecursive(n); 
    std::cout << "seriesRecursive(" << n << ") = " << result << std::endl;

    return 0; 
}
