#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

#define MAX_CONTACTS 8

class Contact
{
public:
    Contact() {}
    void setFirstName(const std::string &firstName) { this->firstName = firstName; }
    void setLastName(const std::string &lastName) { this->lastName = lastName; }
    void setNickname(const std::string &nickname) { this->nickname = nickname; }
    void setPhoneNumber(const std::string &phoneNumber) { this->phoneNumber = phoneNumber; }
    void setDarkestSecret(const std::string &darkestSecret) { this->darkestSecret = darkestSecret; }
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }

private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
};

class PhoneBook
{
public:
    PhoneBook() : currentContactIndex(0) {}
    void addContact(const Contact &contact)
    {
        contacts[currentContactIndex % MAX_CONTACTS] = contact;
        currentContactIndex++;
    }
    Contact getContact(int index) const
    {
        if (index < 0 || index >= currentContactIndex)
        {
            std::cerr << "Invalid contact index" << std::endl;
            return Contact();
        }
        return contacts[index % MAX_CONTACTS];
    }
    int getContactCount() const
    {
        return currentContactIndex < MAX_CONTACTS ? currentContactIndex : MAX_CONTACTS;
    }

private:
    Contact contacts[MAX_CONTACTS];
    int currentContactIndex;
};

std::string truncateField(std::string field)
{
    if (field.length() > 10)
    {
        field = field.substr(0, 9) + ".";
    }
    return field;
}

bool isNotValid(const std::string &str)
{
    return str.find_first_not_of(" \t\n\v\f\r") == std::string::npos;
}

int main()
{
    PhoneBook phoneBook;
    std::string command;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        if (std::cin.eof())
        {
            std::cout << "CTRL D detected! Exiting phonebook cleanly" << std::endl;
            break;
        }
        if (isNotValid(command))
        {
            std::cout << "Command cannot be empty. Use: ADD, SEARCH or EXIT" << std::endl;
            continue;
        }

        if (command == "ADD")
        {
            Contact newContact;
            std::string input;

            while (true)
            {
                std::cout << "Enter first name: ";
                std::getline(std::cin, input);
                bool allAlpha = true;
                for (std::string::iterator it = input.begin(); it != input.end(); ++it)
                {
                    if (!isalpha(*it))
                    {
                        allAlpha = false;
                        break;
                    }
                }
                if (allAlpha)
                {
                    newContact.setFirstName(input);
                    break;
                }
                else
                {
                    std::cout << "First name can only contain letters. Please try again.\n";
                }
            }

            while (true)
            {
                std::cout << "Enter last name: ";
                std::getline(std::cin, input);
                bool allAlpha = true;
                for (std::string::iterator it = input.begin(); it != input.end(); ++it)
                {
                    if (!isalpha(*it))
                    {
                        allAlpha = false;
                        break;
                    }
                }
                if (allAlpha)
                {
                    newContact.setLastName(input);
                    break;
                }
                else
                {
                    std::cout << "Last name can only contain letters. Please try again.\n";
                }
            }

            while (true)
            {
                std::cout << "Enter nickname: ";
                std::getline(std::cin, input);
                bool allAlpha = true;
                for (std::string::iterator it = input.begin(); it != input.end(); ++it)
                {
                    if (!isalpha(*it))
                    {
                        allAlpha = false;
                        break;
                    }
                }
                if (allAlpha)
                {
                    newContact.setNickname(input);
                    break;
                }
                else
                {
                    std::cout << "Nickname can only contain letters. Please try again.\n";
                }
            }

            while (true)
            {
                std::cout << "Enter phone number: ";
                std::getline(std::cin, input);
                bool allDigit = true;
                for (std::string::iterator it = input.begin(); it != input.end(); ++it)
                {
                    if (!isdigit(*it))
                    {
                        allDigit = false;
                        break;
                    }
                }
                if (allDigit)
                {
                    newContact.setPhoneNumber(input);
                    break;
                }
                else
                {
                    std::cout << "Phone number can only contain digits. Please try again.\n";
                }
            }

            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, input);
            newContact.setDarkestSecret(input);

            // Check for empty fields
            if (newContact.getFirstName().empty() || newContact.getLastName().empty() ||
                newContact.getNickname().empty() || newContact.getPhoneNumber().empty() ||
                newContact.getDarkestSecret().empty())
            {
                std::cout << "All fields must be filled." << std::endl;
                continue;
            }

            phoneBook.addContact(newContact);
        }
        else if (command == "SEARCH")
        {
            for (int i = 0; i < phoneBook.getContactCount(); i++)
            {
                Contact contact = phoneBook.getContact(i);
                std::cout << std::setw(10) << i << "|";
                std::cout << std::setw(10) << truncateField(contact.getFirstName()) << "|";
                std::cout << std::setw(10) << truncateField(contact.getLastName()) << "|";
                std::cout << std::setw(10) << truncateField(contact.getNickname()) << std::endl;
            }

            std::string input;
            std::cout << "Enter the index of the contact to display: ";
            std::cin >> input;

            std::cin.ignore(1000, '\n');
            std::istringstream iss(input);
            int index;
            if (!(iss >> index) || index < 0 || index >= phoneBook.getContactCount())
            {
                std::cout << "Invalid input. Please enter a valid index." << std::endl;
            }
            else
            {
                Contact contact = phoneBook.getContact(index);
                std::cout << "First name: " << contact.getFirstName() << std::endl;
                std::cout << "Last name: " << contact.getLastName() << std::endl;
                std::cout << "Nickname: " << contact.getNickname() << std::endl;
                std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
                std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
            }
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command" << std::endl;
        }
    }

    return 0;
}