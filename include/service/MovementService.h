#include "model/User.h"
#include "util/StorageManagerDb.h"
#include <vector>

class MovementService {
    public:
        static void calculateNewBalance(User& user, Movement &movement, StorageManagerDb &dbManager, int movementType);
        static vector<MovementDto> getAllMovementsWithCategory(StorageManagerDb& db);
    };