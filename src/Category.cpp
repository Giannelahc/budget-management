#include <iostream>
#include <Category.h>
#include <iomanip>

Category::Category()
{
}

Category::Category(const string &name, TransactionType transactionType): name(name), type(transactionType)
{
}

Category::Category(int id, const string &name, TransactionType transactionType)
    : id(id), name(name), type(transactionType), registeredDate() {}

Category::Category(int id, const string &name, TransactionType transactionType, Date date): 
    id(id), name(name), type(transactionType), registeredDate(date)
{
}

string Category::getName() const
{
    return name;
}

TransactionType Category::getType() const { 
    return type; 
}

void Category::setType(TransactionType t) { 
    type = t; 
}

int Category::getId()
{
    return id;
}

void Category::setId(int id)
{
    this->id = id;
}

void Category::setRegisteredDate(Date date){
    this->registeredDate = date;
}

string Category::getDate() const{
  return registeredDate.showDate();
}

void Category::showCategory() {
    std::string typeName = (type == TransactionType::INCOME) ? "INCOME" : "OUTCOME";

        std::cout << std::setw(3) << id 
                  << std::setw(15) << name 
                  << std::setw(10) << typeName
                  << std::setw(20) << registeredDate.showDate()
                  << std::endl;
}

void Category::serialize(std::ostream& out) const {
    char type = 'C'; 
    out.write(&type, sizeof(type));
    size_t length = name.size();
    out.write(reinterpret_cast<const char*>(&id), sizeof(id));
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(name.c_str(), length);
    registeredDate.serialize(out);
}

void Category::deserialize(std::istream& in) {
    size_t length;
    in.read(reinterpret_cast<char*>(&id), sizeof(id));
    in.read(reinterpret_cast<char*>(&length), sizeof(length));
    name.resize(length);
    in.read(&name[0], length);
    registeredDate.deserialize(in);
}