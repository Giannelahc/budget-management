#include "User.h"

class UserDao {
    public:
        void saveUser(const User& user);
        void loadUser(User& user);
};