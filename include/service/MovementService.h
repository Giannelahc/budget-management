#include "model/User.h"
#include "util/StorageManagerDb.h"

class MovementService {
    public:
        static void calculateNewBalance(User& user, Movement &movement, StorageManagerDb &dbManager, int movementType);
    };