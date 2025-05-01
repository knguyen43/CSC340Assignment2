# CSC340 Assignment 4 Guidelines

## Build Commands
- Compile Part1: `g++ -std=c++11 Part1/seriesRecursive.cpp -o seriesRecursive`
- Run Part1: `./seriesRecursive <n>`
- Compile Part3: `g++ -std=c++11 Part3/linkedBagSortingMain.cpp -o bagSort`
- Run Part3: `./bagSort`

## Code Style Guidelines
- **Naming Conventions**: 
  - camelCase for variables and functions
  - PascalCase for classes
  - ALL_CAPS for constants
- **Comments**: Use Doxygen-style documentation comments
- **Error Handling**: Use status codes and std::cerr for error messages
- **Header Structure**: 
  - Use header guards (#ifndef NAME_)
  - Separate implementation (.cpp) from interface (.h)
- **Template Usage**: Include .cpp files at the end of header files
- **Code Organization**: Keep functions small and focused on a single task
- **File Structure**: Maintain assignment directory structure as specified

## Important Notes
- Do not modify main functions
- For Part3, modify LinkedBag.h and LinkedBag.cpp only
- Code must compile without errors and match assignment specifications
- Follow recursive function implementation as specified in instructions