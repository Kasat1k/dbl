#include <iostream>
#include "func_bar.h"
#include "func_drink.h"
//#include "infodb.h"

using namespace std;

int _stateMenu;
void Menu()
{

    cout << "0 - exit" << endl
        << "1 - Get bar" << endl
        << "2 - Insert bar" << endl
        << "3 - Update bar" << endl
        << "4 - Delete bar" << endl
        << "5 - Get drink" << endl
        << "6 - Insert drink" << endl
        << "7 - Update drink" << endl
        << "8 - Delete drink" << endl
        << "9 - Info" << endl
        << "Enter number: ";

    cin >> _stateMenu;
}

int main()
{
    Menu();

    int amountOfData = 0;
    Bar* bar = new Bar[amountOfData];
    Drink* drink = new Drink[amountOfData];


    while (_stateMenu != 0) {
        switch (_stateMenu)
        {            
            
            case 1://GET
               // system("cls");
                ReadingDataBar(bar, amountOfData, "Input_bar.txt");
                if (amountOfData != 0) {
                    PrintBar(bar, amountOfData);
                }
                else
                    cout << "Data is empty" << endl;
                Menu();
                break;

            case 2://ADD
                //system("cls");

                ReadingDataBar(bar, amountOfData, "Input_bar.txt");
                if (amountOfData != 0) {
                    AddDateBar(bar, amountOfData);
                    amountOfData++;
                }
                else
                    cout << "Data empty" << endl;

                //system("cls");
                Menu();
                break;

            case 3://UPDATE
                //system("cls");
                ReadingDataBar(bar, amountOfData, "Input_bar.txt");
                if (amountOfData != 0) {
                    DataChangeBar(bar, amountOfData);
                }
                else
                    cout << "Data is empty" << endl;
               // system("cls");
                Menu();
                break;

            case 4://DELETE
                //system("cls");
                ReadingDataBar(bar, amountOfData, "Input_bar.txt");
                if (amountOfData != 0) {
                    DeleteDataBar(bar, amountOfData);
                }
                else {
                    cout << "Data empty";
                }
               // system("cls");
                Menu();
                break;
            case 5://GET Drink
                //system("cls");
                ReadingDataDrink(drink, amountOfData, "Input_drink.txt");
                if (amountOfData != 0) {
                    PrintDrink(drink, amountOfData);
                }
                else
                    cout << "Data is empty" << endl;
                Menu();
                break;

            case 6://ADD Drink
             
                ReadingDataDrink(drink, amountOfData, "Input_drink.txt");
                if (amountOfData != 0) {
                    AddDateDrink(drink, amountOfData);
                }
                else
                    cout << "Data empty" << endl;
               // system("cls");
                Menu();
                break;

            case 7://UPDATE Drink
                //system("cls");
                ReadingDataDrink(drink, amountOfData, "Input_drink.txt");
                if (amountOfData != 0) {
                    DataChangeDrink(drink, amountOfData);
                }
                else
                    cout << "Data empty" << endl;

               // system("cls");
                Menu();
                break;

            case 8: //DELETE Drink
               // system("cls");
                ReadingDataDrink(drink, amountOfData, "Input_drink.txt");
                if (amountOfData != 0) {
                    DeleteDataDrink(drink, amountOfData);
                }
                else {
                    cout << "Data empty";
                }
               //system("cls");
                Menu();
                break;
            
            case 9:
                //system("cls");
                ReadingDataDrink(drink, amountOfData, "Input_drink.txt");
                if (amountOfData != 0) {
                    ccount(drink, amountOfData);
                }
                else
                {
                    cout << "Error";
                }
               // system("cls");
                Menu();
                break;

            default: 
                cout << "Wrong number";
               // system("cls");
                Menu();
                break;
        }
    }
}
