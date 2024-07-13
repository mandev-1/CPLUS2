#include <iostream>
#include <limits>

#include "phonebook.hpp"

void add_contact(PhoneBook& phonebook) {
    std::string input;
    Contact contact;

    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    contact.set_first_name(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    contact.set_last_name(input);

    std::cout << "Enter nickname: ";
    std::getline(std::cin, input);
    contact.set_nickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    contact.set_phone_number(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    contact.set_darkest_secret(input);

    if (contact.get_first_name().empty() || contact.get_last_name().empty() ||
        contact.get_nickname().empty() || contact.get_phone_number().empty() ||
        contact.get_darkest_secret().empty()) {
        std::cout << "All fields are required. Contact not added." << std::endl;
    } else {
        phonebook.add_contact(contact);
        std::cout << "Contact added successfully!" << std::endl;
    }
}

void search_contacts(const PhoneBook& phonebook) {
    phonebook.display_contacts();
    std::cout << "Enter the index of the contact to view details: ";
    int index;
    std::cin >> index;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // clear the input buffer
    phonebook.display_contact_details(index);
}

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            add_contact(phonebook);
        } else if (command == "SEARCH") {
            search_contacts(phonebook);
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Unknown command. Please try again." << std::endl;
        }
    }

    return 0;
}
