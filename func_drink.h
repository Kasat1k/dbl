#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


using namespace std;


struct Drink {
	int id;
	int barId;
	string name;
};

void DataEntryDrink(Drink* (&d), int& n);//enter data
void ReadingDataDrink(Drink* (&d), int& n, string foleName);//read data
void PrintDrink(Drink* d, int n);// output data
void DataChangeDrink(Drink* (&d), int n);//Change data
void DeleteDataDrink(Drink* (&d), int& n);//delete data
void CopyDrink(Drink* (&d_n), Drink* (&d_o), int n);//copy data
void CopyDrink(Drink& d_n, Drink& d_o);//copy data element
void AddDateDrink(Drink* (&d), int& n);//add data
void DataSortingDrink(Drink* d, int n);//sort data
void SavingDataDrink(Drink* d, int n, string fileName);//save data
void ccount(Drink* d, int n);