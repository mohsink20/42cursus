#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

#define MAX_CONTACTS 8

class PhoneBook
{
public:
    PhoneBook();
    void addContact(const Contact &contact);
    Contact getContact(int index) const;
    int getContactCount() const;

private:
    Contact contacts[MAX_CONTACTS];
    int currentContactIndex;
};

#endif // PHONEBOOK_HPP