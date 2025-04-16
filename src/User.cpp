#include <User.h>

User::User(): name(""), balance(0.0) {}

User::User(string& name, double balance) : name(name), balance(balance){}

User::User(int id, string& name, string& password, double balance, Date registered) : id(id), name(name), password(password), 
    balance(balance), registeredDate(registered){}

int User::getId() const {
    return id;
}

string User::getName() const{
    return name;
}

void User::setName(string& name){
     this->name = name;
}

double User::getBalance() const{
    return balance;
}

void User::setBalance(double balance){
     this->balance = balance;
}

string User::getPassword() const
{
    return password;
}

void User::setPassword(string password)
{
    this->password = password;
}

void User::setRegisteredDate(Date date){
    this->registeredDate = date;
}

string User::getDate() const{
  return registeredDate.showDate();
}

void User::serialize(std::ostream& os) const {
    char type = 'U'; 
    os.write(&type, sizeof(type));
    size_t nameLen = name.size();
    os.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
    os.write(name.c_str(), nameLen);
    os.write(reinterpret_cast<const char*>(&balance), sizeof(balance));
    registeredDate.serialize(os);
}

void User::deserialize(std::istream& is) {
    size_t nameLen;
    is.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));

    name.resize(nameLen);
    is.read(&name[0], nameLen);

    is.read(reinterpret_cast<char*>(&balance), sizeof(balance));
    registeredDate.deserialize(is);
}
