#include <iostream>
#include <iomanip>
#include "phonebook.hpp"

PhoneBook::PhoneBook() : next_index(0), contact_count(0) {}

void PhoneBook::add_contact(const Contact& contact) {
    contacts[next_index] = contact;
    next_index = (next_index + 1) % 8;
    if (contact_count < 8) {
        contact_count++;
    }
}

void PhoneBook::display_contacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < contact_count; ++i) {
        std::cout << std::setw(10) << i << "|";
        print_column(contacts[i].get_first_name());
        print_column(contacts[i].get_last_name());
        print_column(contacts[i].get_nickname());
        std::cout << std::endl;
    }
}

void PhoneBook::display_contact_details(int index) const {
    if (index < 0 || index >= contact_count) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    std::cout << "First Name: " << contacts[index].get_first_name() << std::endl;
    std::cout << "Last Name: " << contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << std::endl;
}

void PhoneBook::print_column(const std::string& str) const {
    if (str.length() > 10) {
        std::cout << str.substr(0, 9) << ".";
    } else {
        std::cout << std::setw(10) << str;
    }
    std::cout << "|";
}
