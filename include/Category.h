#include "Date.h"

class Category {

    private: 
        int id;
        string name;
        Date registeredDate;
    public:
        Category(string& name);
        string getName();
        void serialize(std::ostream& out) const;
        void deserialize(std::istream& in);
};