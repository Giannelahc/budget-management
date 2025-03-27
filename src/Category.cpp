#include <iostream>
#include <Category.h>

Category::Category(string& name) 
    : name(name), registeredDate() {}

string Category::getName() {
    return name;
}

void Category::serialize(std::ostream& out) const {
    size_t length = name.size();
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(name.c_str(), length);
    registeredDate.serialize(out);
}

void Category::deserialize(std::istream& in) {
    size_t length;
    in.read(reinterpret_cast<char*>(&length), sizeof(length));
    name.resize(length);
    in.read(&name[0], length);
    registeredDate.deserialize(in);
}