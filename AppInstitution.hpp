#include "InsitutionClass/Institution.hpp"
#include "VectorClass/Vector.hpp"
namespace AppInstitution {
enum class Tasks {
    readFile = 1,
    printDB = 2,
    deleteObject = 3,
    clenDB = 4,
    exitApp = 5,
};

void DeleteInstitution(MyVector<Institution*>& dataBase);

void RunProcessingInsitution();

void StartApp();
}  // namespace AppInstitution
