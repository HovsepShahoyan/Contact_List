#include <iostream>
#include <fstream>
#include <vector>

struct Person {
    std::string name;
    std::string surname;
    std::string DateOfBirth;
    std::string PasportID;
    std::string PhoneNumber;
    std::string Email;
};

void InterfaceWindow();
void fillTheVector();
void addContact();
void SearchForContact();
void listALlContacts();
void EditContact();
void DeleteContact();
void Exit();
std::vector<Person> persons;

int main() {
    InterfaceWindow();
}

void fillTheVector() {
    std::fstream fin;
    fin.open("contact.txt");
    std::string str;
    getline(fin, str);
    int count = stoi(str);
        for(int i = 0; i < count; i++) {  
            Person pers;
            getline(fin, str);
            pers.name = str;
            getline(fin, str);
            pers.surname = str;
            getline(fin, str);
            pers.DateOfBirth = str;
            getline(fin, str);
            pers.PasportID = str;
            getline(fin, str);
            pers.PhoneNumber = str;
            getline(fin, str);
            pers.Email = str;
            persons.push_back(pers);
    }
    fin.close();
}

void listAllContacts() {
    std::cout << "Here are all your contacts" << std::endl;
     for(int i = 0; i < persons.size(); i++) {
         std::cout << persons[i].name << std::endl;
         std::cout << persons[i].surname << std::endl;
         std::cout << persons[i].DateOfBirth << std::endl;
         std::cout << persons[i].PasportID << std::endl;
         std::cout << persons[i].PhoneNumber << std::endl;
         std::cout << persons[i].Email << std::endl;
     }
}

void DeleteContact() {
    std::cout << std::endl;
    std::cout << "Enter the email address of Contact you want to find: ";
    std::string address;
    bool check = false;
    std::cin >> address;
    for(int i = 0; i < persons.size(); i++) {
        if(persons[i].Email == address) {
            check = true;
            std::cout << persons[i].name << " Is deleted from your Contact List" << std::endl;
            persons.erase(persons.begin() + i);
        }
    }
    if(check == false) { std::cout << "Sorry, there is no matches"; }        
}

void Exit() {
    std::ofstream fin;
    fin.open("contact.txt");
    fin.clear();
    fin << persons.size() << std::endl;
    for(int i = 0; i < persons.size(); i++) {
        fin << persons[i].name << std::endl;
        fin << persons[i].surname << std::endl;
        fin << persons[i].DateOfBirth << std::endl;
        fin << persons[i].PasportID << std::endl;
        fin << persons[i].PhoneNumber << std::endl;
        fin << persons[i].Email << std::endl;
    }
    fin.close();
}

void addContact() {
    std::cout << std::endl;
    Person pers;
    std::cout << "Enter the name of Contact: ";
    std::cin >> pers.name;
    std::cout << "Enter the surname of Contact: ";
    std::cin >> pers.surname;
    std::cout << "Enter the dateOfBirth of Contact: ";
    std::cin >> pers.DateOfBirth;
    std::cout << "Enter the PassportID of Contact: ";
    std::cin >> pers.PasportID;
    std::cout << "Enter the PhoneNumber of Contact: ";
    std::cin >> pers.PhoneNumber;
    std::cout << "Enter the Email of Contact: ";
    std::cin >> pers.Email;
    persons.push_back(pers);
}

void SearchForContact() {
    std::cout << std::endl;
    std::cout << "Enter the email address of Contact you want to find: ";
    std::string address;
    bool check = false;
    std::cin >> address;
    for(int i = 0; i < persons.size(); i++) {
        if(persons[i].Email == address) {
            check = true;
            std::cout << "Here is Contact you searched for" << std::endl;
            std::cout << persons[i].name << "\n" << persons[i].surname;
            std::cout << std::endl;
        }
    }
    if(check == false) { std::cout << "Sorry, there is no matches"; }
}

void EditContact() {
std::cout << std::endl;
    std::cout << "Enter the email address of Contact you want to edit: ";
    std::string address;
    bool check = false;
    std::cin >> address;
    for(int i = 0; i < persons.size(); i++) {
        if(persons[i].Email == address) {
            Person pers;
            check = true;
            std::cout << "Enter the new name of Contact: ";
            std::cin >> pers.name;
            std::cout << "Enter the new surname of Contact: ";
            std::cin >> pers.surname;
            std::cout << "Enter the new dateOfBirth of Contact: ";
            std::cin >> pers.DateOfBirth;
            std::cout << "Enter the new PassportID of Contact: ";
            std::cin >> pers.PasportID;
            std::cout << "Enter the new PhoneNumber of Contact: ";
            std::cin >> pers.PhoneNumber;
            std::cout << "Enter the new Email of Contact: ";
            std::cin >> pers.Email;
            persons[i] = pers;
        }
    }
    if(check == false) { std::cout << "Sorry, there is no matches"; }
}   

void InterfaceWindow() {
    int i = 10;
    fillTheVector();
    std::cout << "          Main Menu      " << std::endl;
    std::cout << "=========================" << std::endl;        
    std::cout << "  [1] Add a new Contact  " << std::endl;
    std::cout << "  [2] List all Contacts  " << std::endl;
    std::cout << "  [3] Search for contact " << std::endl;
    std::cout << "  [4] Edit a Contact     " << std::endl;
    std::cout << "  [5] Delete a Contact   " << std::endl;
    std::cout << "  [0] Exit               " << std::endl;
    std::cout << "==============           " << std::endl;
    while(i != 0) {
        std::cout << "Enter the choice" << "[_]\b\b" << std::endl;
        std::cin >> i;
        switch(i) {
            case 1: addContact();
            break;
            //case 2: listALlContacts();
            //break;
            case 3: SearchForContact();
            break;
            case 4: EditContact();
            break;
            case 5: DeleteContact();
            break;
            case 0: Exit();
            break;
        }
    }
}
