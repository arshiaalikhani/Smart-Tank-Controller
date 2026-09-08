#include <iostream>
#include <string>
#include <cstdlib>   // For EXIT_FAILURE
#include "utils.h"
#include "tank.h"
#include "pump.h"
/**
 * Removes leading and trailing whitespace characters from a string.
 * @param str The input string to trim.
 * @return A new string without leading/trailing spaces, tabs, or newlines.
 */
std::string trim(const std::string& str) {
    // Find the first character that is not whitespace
    size_t first = str.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos) {
        return "";  // The string consists only of whitespace characters
    }
    // Find the last character that is not whitespace
    size_t last = str.find_last_not_of(" \t\n\r\f\v");
    // Return the substring from the first to the last valid character
    return str.substr(first, last - first + 1);
}

int main() {
    tank tank;
    pump pump;
    std::string command;   // Stores the raw user input

    // Infinite loop to keep the menu running until the user chooses to exit
    while (true) {
        // Display the main menu
        std::cout << "========== TANK CONTROLLER ==========" << std::endl;
        std::cout << "Water Level:"
                  <<  tank.getLevel()
                  << "%" <<std::endl;
        std::cout << "Pump:";
                  if(pump.isrunning())
                    std::cout<<"ON";
                  else
                    std::cout<<"OFF";
                  std::cout<<std::endl;
        std::cout << "Alarm: OFF" << std::endl;
        std::cout << "1. Add Water" << std::endl;
        std::cout << "2. Remove Water" << std::endl;
        std::cout << "3. Start Pump" << std::endl;
        std::cout << "4. Stop Pump" << std::endl;
        std::cout << "5. Emergency Stop" << std::endl;
        std::cout << "6. Show Status" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Please enter the desired number: ";

        // Read the entire input line (prevents issues with spaces or invalid chars)
        std::getline(std::cin, command);

        // Sanitize the input by trimming unnecessary spaces
        std::string cleaned = trim(command);

        // ----- SECURITY VALIDATION (Critical for sensitive systems) -----
        // Step 1: Reject empty input (or input containing only spaces)
        if (cleaned.empty()) {
            std::cerr << "⛔ Security error: Input is empty. Access disabled." << std::endl;
            std::exit(EXIT_FAILURE); // Halt the program immediately
        }

        // Step 2: Strict matching against the exact allowed strings ("0" to "6")
        // This rejects malicious inputs like "01", "6abc", "3.5", or "a"
        bool isValid = false;
        for (const std::string& valid : {"0", "1", "2", "3", "4", "5", "6"}) {
            if (cleaned == valid) {
                isValid = true;
                break;
            }
        }

        // Step 3: If the input is not exactly one of the allowed values, terminate
        if (!isValid) {
            std::cerr << "Security error: Input '" << cleaned << "' is invalid. System access revoked." << std::endl;
            std::exit(EXIT_FAILURE);
        }

        // Safe conversion to integer (guaranteed valid because of the strict check above)
        int number = std::stoi(cleaned);

        // ----- COMMAND HANDLER (Using Switch-Case) -----
        switch (number) {
            case 0:
                clearScreen();
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                return 0;   // Terminate the program cleanly

            case 1:
                clearScreen();
                std::cout << "Adding water... (simulated)" << std::endl;
                // Insert actual logic for adding water here
                break;

            case 2:
                clearScreen();
                std::cout << "Removing water... (simulated)" << std::endl;
                // Insert actual logic for removing water here
                break;

            case 3:
                clearScreen();
                std::cout << "Starting the pump... (simulated)" << std::endl;
                // Insert actual pump start logic here
                break;

            case 4:
                clearScreen();
                std::cout << "Stopping the pump... (simulated)" << std::endl;
                // Insert actual pump stop logic here
                break;

            case 5:
                clearScreen();
                std::cout << "Emergency stop activated! All systems halted." << std::endl;
                // Insert actual emergency shutdown logic here
                break;

            case 6:
                clearScreen();
                std::cout << "Showing current status... (simulated)" << std::endl;
                // Insert actual status display logic here
                break;

            default:
                // This case should never occur due to the validation above.
                // It is kept as a safety net against unexpected states.
                std::cerr << "Unexpected critical error! Invalid case entered the switch." << std::endl;
                std::exit(EXIT_FAILURE);
        }

        // Print a separator for better readability before looping again

        std::cout << "\n------------------------------------\n" << std::endl;
    }

    return 0; // This line is never reached due to the 'return 0' inside case 0
}
