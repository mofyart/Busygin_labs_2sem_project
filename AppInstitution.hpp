#include "InsitutionClass/Institution.hpp"
#include "HashTableClass/HashTable.hpp"
namespace AppInstitution {
enum class Tasks {
    readFile = 1,
    printDB = 2,
    deleteObject = 3,
    clenDB = 4,
    exitApp = 5,
};

void DeleteInstitution(MyHashTable<Institution*>& dataBase);

void RunProcessingInsitution();

void StartApp();
}  // namespace AppInstitution
