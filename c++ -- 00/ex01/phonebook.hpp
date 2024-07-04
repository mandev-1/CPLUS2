#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
public:
    PhoneBook();
    void add_contact(const Contact& contact);
    void display_contacts() const;
    void display_contact_details(int index) const;

private:
    Contact contacts[8];
    int next_index;
    int contact_count;
    void print_column(const std::string& str) const;
};

#endif
