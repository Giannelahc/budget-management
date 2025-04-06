#include <iostream>
#include <Category.h>

Category::Category()
{
}

Category::Category(const string &name): name(name)
{
}

Category::Category(int id, const string &name)
    : id(id), name(name), registeredDate() {}

Category::Category(int id, const string &name, Date date): id(id), name(name), registeredDate(date)
{
}

string Category::getName() const{
    return name;
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