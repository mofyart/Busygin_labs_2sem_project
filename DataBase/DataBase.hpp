#include "../StringClass/String.cpp"
#include "DataBase.cpp"

int DataBase::HashKey(String key);

int DataBase::HashKey(char* key);

void ReinitializeDataBase();

void AddNewObject(ClassMode values);

void DeleteObject(char* nameObject);

void SortDataBase();

void EditDataBase(ClassMode values);

ClassMode* GetDataBase();

int getCout();

int getCapacity();

void CleanDB();
