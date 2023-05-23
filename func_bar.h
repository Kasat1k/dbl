#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>


using namespace std;

struct Bar {
	int id;
	string name;
};




void DataEntryBar(Bar* (&d), int& n);//enter data
void ReadingDataBar(Bar* (&d), int& n, string foleName);//read data
void PrintBar(Bar* d, int n);// output data
void DataChangeBar(Bar* (&d), int n);//Change data
void DeleteDataBar(Bar* (&d), int& n);//delete data
void CopyBar(Bar* (&d_n), Bar* (&d_o), int n);//copy data
void CopyBar(Bar&d_n, Bar &d_o);//copy data element
void AddDateBar(Bar* (&d), int& n);//add data
void DataSortingBar(Bar* d, int n);//sort data
void SavingDataBar(Bar* d, int n, string fileName);//save data
int GetCount(Bar* (&d), int& n);
