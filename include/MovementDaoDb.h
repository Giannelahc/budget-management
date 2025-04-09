#include <vector>
#include "Movement.h"
#include "MovementDto.h"
#include "StorageManagerDb.h"

class MovementDaoDb {
    public:
        bool saveMovement(const Movement& movement, StorageManagerDb& dbManager);
        vector<MovementDto> getMovements(StorageManagerDb& dbManager);
};