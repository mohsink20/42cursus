#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : currentContactIndex(0) {}

void PhoneBook::addContact(const Contact &contact)
{
    contacts[currentContactIndex % MAX_CONTACTS] = contact;
    currentContactIndex++;
}

Contact PhoneBook::getContact(int index) const
{
    if (index < 0 || index >= currentContactIndex)
    {
        std::cerr << "Invalid contact index" << std::endl;
        return Contact();
    }
    return contacts[index % MAX_CONTACTS];
}

int PhoneBook::getContactCount() const
{
    return currentContactIndex < MAX_CONTACTS ? currentContactIndex : MAX_CONTACTS;
}
