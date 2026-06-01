#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class ContactType {
    FRIEND,
    ACQUAINTANCE,
    COLLEAGUE
};

class Contact {
protected:
    string name;

public:
    Contact(const string& name) : name(name) {}

    virtual ~Contact() = default;

    string GetName() const {
        return name;
    }

    virtual ContactType GetType() const = 0;
    virtual void PrintDetails() const = 0;
};

class Friend : public Contact {
private:
    string dateOfBirth;
    string phoneNumber;
    string address;

public:
    Friend(const string& name, const string& dob, const string& phone, const string& addr)
        : Contact(name), dateOfBirth(dob), phoneNumber(phone), address(addr) {
    }

    ContactType GetType() const override {
        return ContactType::FRIEND;
    }

    void PrintDetails() const override {
        cout << "(prieten) nume: " << name << " tel: " << phoneNumber
            << "data nasterii: " << dateOfBirth << " adresa: " << address << endl;
    }
};

class Acquaintance : public Contact {
private:
    string phoneNumber;

public:
    Acquaintance(const string& name, const string& phone)
        : Contact(name), phoneNumber(phone) {
    }

    ContactType GetType() const override {
        return ContactType::ACQUAINTANCE;
    }

    void PrintDetails() const override {
        cout << "(cunostinta) Nume: " << name << " tel: " << phoneNumber << endl;
    }
};

class Colleague : public Contact {
private:
    string phoneNumber;
    string company;
    string address;

public:
    Colleague(const string& name, const string& phone, const string& company, const string& addr)
        : Contact(name), phoneNumber(phone), company(company), address(addr) {
    }

    ContactType GetType() const override {
        return ContactType::COLLEAGUE;
    }

    void PrintDetails() const override {
        cout << "(coleg) nume: " << name << " tel: " << phoneNumber
            << " companie: " << company << " adresa: " << address << endl;
    }
};

class AddressBook {
private:
    vector<Contact*> contacts; 

public:
    ~AddressBook() {
        for (Contact* c : contacts) {
            delete c;
        }
    }

    void AddContact(Contact* contact) {
        contacts.push_back(contact);
    }

    Contact* SearchByName(const string& name) const {
        for (Contact* c : contacts) {
            if (c->GetName() == name) {
                return c;
            }
        }
        return nullptr; 
    }

    vector<Contact*> GetFriends() const {
        vector<Contact*> friendsList;
        for (Contact* c : contacts) {
            if (c->GetType() == ContactType::FRIEND) {
                friendsList.push_back(c);
            }
        }
        return friendsList;
    }

    bool DeleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if ((*it)->GetName() == name) {
                delete* it;          
                contacts.erase(it);  
                return true;
            }
        }
        return false;
    }

    void PrintAll() const {
        cout << "\nagenda telefonica (" << contacts.size() << " contacte)" << endl;
        for (Contact* c : contacts) {
            c->PrintDetails();
        }
        cout << endl;
    }
};

int main() {
    AddressBook agenda;

    agenda.AddContact(new Friend("Andrei Popescu", "15.08.1995", "0722111222", "Str. Primaverii 10"));
    agenda.AddContact(new Colleague("Mihai Ionescu", "0744333444", "TechCorp SRL", "Bd. Unirii 20"));
    agenda.AddContact(new Acquaintance("Maria Radu", "0755666777"));
    agenda.AddContact(new Friend("Elena Marin", "22.11.1998", "0766123456", "Aleea Rozelor 5"));

    agenda.PrintAll();

    cout << "cautam contactul 'Maria Radu':" << endl;
    Contact* found = agenda.SearchByName("Maria Radu");
    if (found != nullptr) {
        found->PrintDetails();
    }
    else {
        cout << "contactul nu a fost gasit" << endl;
    }

    cout << "\nlista doar cu prieteni:" << endl;
    vector<Contact*> friends = agenda.GetFriends();
    for (Contact* f : friends) {
        f->PrintDetails();
    }

    cout << "\nstergem contactul 'Mihai Ionescu'" << endl;
    bool deleted = agenda.DeleteContact("Mihai Ionescu");
    if (deleted) cout << "stergere reusita" << endl;

    agenda.PrintAll();

    return 0;
}