#include "Movement.h"
#include "MovementService.h"
#include "MovementDaoDb.h"
#include "UserDaoDb.h"

void MovementService::calculateNewBalance(User &user, Movement &movement, StorageManagerDb &dbManager, int movementType)
{
    if(movementType == 0) {
        user.setBalance(user.getBalance() + movement.getAmount());
    } else {
        user.setBalance(user.getBalance() - movement.getAmount());
    }

    MovementDaoDb movementDaoDb;
    movementDaoDb.saveMovement(movement, dbManager);

    UserDaoDb userDaoDb;
    userDaoDb.updateUser(user, dbManager);
}