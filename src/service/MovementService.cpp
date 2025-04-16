#include "model/Movement.h"
#include "service/MovementService.h"
#include "dao/MovementDaoDb.h"
#include "dao/UserDaoDb.h"

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