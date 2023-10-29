
#include <algorithm>
#include<iostream>
#include<string>
#include<vector>


struct contacts{
    std::string name;
    std::string phone;
    std::string Email;
};



void list_contacts(std::vector<contacts>&add_book){

    if(add_book.empty()){
        std::cout << "There are no contacts ." << std::endl<<std::endl;
    }
    else{
        for(contacts con : add_book){
            std::cout<<"name : "<<con.name<<std::endl;
            std::cout<<"phone : "<<con.phone<<std::endl;
            std::cout<<"Email : "<<con.Email<<std::endl;
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
}

void add_contact(std::vector<contacts>&add_book){
    contacts con;
    std::cout << "Enter the name: ";
    std::cin >> con.name;
     for (contacts c: add_book) {
        if (con.name == c.name) {
            std::cout<<"name exists , try with different name !"<<std::endl<<std::endl;
            return;
        }
     }

    std::cout << "Enter the phone number: ";
    std::cin >> con.phone;
    std::cout << "Enter the email address: ";
    std::cin >> con.Email;
    add_book.push_back(con);
    std::cout << "Contact added successfully." << std::endl<<std::endl;
    std::cout<<std::endl;
}

void update_contact(std::vector<contacts>&add_book){
    std::string nameToUpdate;
    std::cout << "Enter the name of the contact to update: ";
    std::cin >> nameToUpdate;

    for(contacts &con : add_book){
        if(nameToUpdate==con.name){
            std::cout << "Enter the new phone number: ";
            std::cin >> con.phone;
            std::cout << "Enter the new email address: ";
            std::cin >> con.Email;
            std::cout << "Contact updated successfully." << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}


void search_Contact(const std::vector<contacts>&add_book) {
    std::string nameToSearch;
    std::cout << "Enter the name to search for: ";
    std::cin >> nameToSearch;

    for (contacts con: add_book) {
        if (con.name == nameToSearch) {
            std::cout << "Name: " << con.name << std::endl;
            std::cout << "Phone: " << con.phone << std::endl;
            std::cout << "Email: " << con.Email << std::endl;
            return;
        }
    }
    std::cout << "Contact not found." << std::endl;
}

void delete_contact(std::vector<contacts> &add_book) {
    std::string nameToDelete;
    std::cout << "Enter the name you want to delete : ";
    std::cin >> nameToDelete;

    auto del_item= std::find_if(add_book.begin(),add_book.end(),[nameToDelete](contacts con){
        return con.name==nameToDelete;
    }
    );
       if (del_item != add_book.end()) {
        // Element found, erase it
        add_book.erase(del_item);
        std::cout << "Contact with name " << nameToDelete << " found and deleted." << std::endl;
    } else {
        // Element not found
        std::cout << "Contact with name " << nameToDelete << " not found in the vector." << std::endl;
    }
    
}




int main(){
    std::vector<contacts>address_book;

    while(true){
        std::cout<<"Welcome to address book !"<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;
        std::cout<<"what do you want to do ?"<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;
        std::cout << "1. list all contacts" << std::endl;
        std::cout << "2. Add Contact" << std::endl;
        std::cout << "3. Update Contact" << std::endl;
        std::cout << "4. Search Contact" << std::endl;
        std::cout << "5. delete Contact" << std::endl; 
        std::cout << "6. Quit" << std::endl<<std::endl;

        std::cout << "Enter your choice :  ";
        int choice=0;
        std::cin>>choice;
        std::cout << std::endl;

      switch (choice) {
            case 1:
                list_contacts(address_book);
                break;
            case 2:
                add_contact(address_book);
                break;
            case 3:
                update_contact(address_book);
                break;
            case 4:
                search_Contact(address_book);
                break;
                case 5:
                delete_contact(address_book);
                break;
            case 6:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
        }


    }

    return 0;
}