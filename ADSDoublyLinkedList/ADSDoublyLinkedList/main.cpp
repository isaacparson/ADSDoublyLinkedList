#include <iostream>
#include "List.h"
#include "Listitem.h"
#include <locale.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Russian");

    int command = 1;
    int amountOfValues = 10;

    cout << "Структура данных \"Двусвязный список\" \n";

    while (command != 0)
    {
        Menu();
        cin >> command;

        switch (command)
        {

        case 1:
        {
            Init(amountOfValues);
            Tabulation();
            break;
        }
        case 2:
        {
            Show();
            Tabulation();
            break;
        }
        case 3:
        {
            int valueToAdd;
            cout << "Введите элемент, который хотите добавить: \n";
            cin >> valueToAdd;
            Add(valueToAdd);
            Tabulation();
            break;
        }
        case 4:
        {
            int valueToDelete;
            cout << "Введите элемент, который хотите удалить: \n";
            cin >> valueToDelete;
            Delete(valueToDelete);
            Tabulation();
            break;
        }
        case 5:
        {
            int valueToInsert;
            cout << "Введите элемент, который хотите вставить в начало: \n";
            cin >> valueToInsert;
            InsertInTheStart(valueToInsert);
            Tabulation();
            break;
        }
        case 6:
        {
            int valueToAdd;
            cout << "Введите элемент, который хотите вставить в конец: \n";
            cin >> valueToAdd;
            Add(valueToAdd);
            Tabulation();
            break;
        }
        case 7:
        {
            int valueToInsert;
            int afterElement;
            cout << "Введите элемент, после которого хотите вставить: \n";
            cin >> afterElement;
            cout << "Введите элемент, который хотите вставить \n";
            cin >> valueToInsert;

            InsertAfter(afterElement, valueToInsert);
            Tabulation();
            break;
        }
        case 8:
        {
            int valueToInsert;
            int beforeElement;
            cout << "Введите элемент, перед которого хотите вставить: \n";
            cin >> beforeElement;
            cout << "Введите элемент, который хотите вставить \n";
            cin >> valueToInsert;

            InsertBefore(beforeElement, valueToInsert);
            Tabulation();
            break;
        }
        case 9:
        {
            int bigOrLittle;
            cout << "1 - по возрастанию\n";
            cout << "2 - по убыванию\n";

            cin >> bigOrLittle;
            switch (bigOrLittle)
            {
            case 1:
            {
                BigSort();
                Tabulation();
                break;
            }
            case 2:
            {
                LittleSort();
                Tabulation();
                break;
            }
            }
            break;
        }
        case 10:
        {
            int findElement;
            cout << "Введите элемент который хотите найти: ";
            cin >> findElement;
            Find(findElement);
            Tabulation();
        }
        }
    }
}