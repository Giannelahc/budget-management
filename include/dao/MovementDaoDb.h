#include <vector>
#include "model/Movement.h"
#include "dto/MovementDto.h"
#include "util/StorageManagerDb.h"

class MovementDaoDb {
    public:
        bool saveMovement(const Movement& movement, StorageManagerDb& dbManager);
        vector<MovementDto> getMovements(StorageManagerDb& dbManager);
};