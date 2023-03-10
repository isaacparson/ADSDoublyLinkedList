#include "List.h"
#include "Listitem.h"
#include <iostream>
#include <locale.h>
using namespace std;

List* list = new List;

void Init(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        Node* temp = new Node;
        temp->Next = nullptr;
        temp->value = rand() % 100 + 1;

        if (list->Head != nullptr)
        {
            temp->Prev = list->Tail;
            list->Tail->Next = temp;
            list->Tail = temp;
        }
        else
        {
            temp->Prev = nullptr;
            list->Head = list->Tail = temp;
        }
    }
}

void Add(int valueToAdd)
{
    Node* temp = new Node;
    temp->Next = nullptr;
    temp->value = valueToAdd;

    if (list->Head != nullptr)
    {
        temp->Prev = list->Tail;
        list->Tail->Next = temp;
        list->Tail = temp;
    }
    else
    {
        temp->Prev = nullptr;
        list->Head = list->Tail = temp;
    }
}

void Delete(int valueToDelete)
{
    Node* temp = list->Head;
    while (temp != nullptr)
    {
        if (temp->value == valueToDelete)
        {
            if (temp->Prev == nullptr)
            {
                temp->Next->Prev = nullptr;
                list->Head = temp->Next;
            }
            else if (temp->Next == nullptr)
            {
                temp->Prev->Next = nullptr;
                list->Tail = temp->Prev;
            }
            else
            {
                temp->Prev->Next = temp->Next;
                temp->Next->Prev = temp->Prev;
            }
            break;
        }
        else
        {
            temp = temp->Next;
        }
    }
}

void InsertInTheStart(int valueToInsert)
{
    Node* temp = new Node;
    temp->value = valueToInsert;
    temp->Next = list->Head;
    list->Head->Prev = temp;
    list->Head = temp;
    temp->Prev = nullptr;
}

void InsertAfter(int afterElement, int valueToInsert)
{
    Node* temp = list->Head;
    Node* insertNode = new Node;
    insertNode->value = valueToInsert;

    while (temp != nullptr)
    {
        if (temp->value == afterElement)
        {
            if (temp->Next == nullptr)
            {
                Add(valueToInsert);
                break;
            }
            else
            {
                insertNode->Next = temp->Next;
                temp->Next->Prev = insertNode;
                insertNode->Prev = temp;
                temp->Next = insertNode;
                break;
            }
        }
        else
        {
            temp = temp->Next;
        }
    }
}

void InsertBefore(int beforeElement, int valueToInsert)
{
    Node* temp = list->Head;
    Node* insertNode = new Node;
    insertNode->value = valueToInsert;

    while (temp != nullptr)
    {
        if (temp->value == beforeElement)
        {
            if (temp->Prev == nullptr)
            {
                list->Head->Prev = insertNode;
                insertNode->Next = list->Head;
                insertNode->Prev = nullptr;
                list->Head = insertNode;
                break;
            }
            else
            {
                insertNode->Prev = temp->Prev;
                temp->Prev->Next = insertNode;
                insertNode->Next = temp;
                temp->Prev = insertNode;
                break;
            }
        }
        else
        {
            temp = temp->Next;
        }
    }
}

void BigSort()
{
    Node* temp = list->Head;
    bool isSwap = false;

    while (true)
    {
        if (temp->Next == nullptr)
        {
            if (isSwap == false)
            {
                break;
            }
            temp = list->Head;
            isSwap = false;
        }

        if (temp->value > temp->Next->value)
        {
            int bufValue = temp->value;
            temp->value = temp->Next->value;
            temp->Next->value = bufValue;
            isSwap = true;
        }

        temp = temp->Next;
    }
}

void LittleSort()
{
    Node* temp = list->Head;
    bool isSwap = false;

    while (true)
    {
        if (temp->Next == nullptr)
        {
            if (isSwap == false)
            {
                break;
            }
            temp = list->Head;
            isSwap = false;
        }

        if (temp->value < temp->Next->value)
        {
            int bufValue = temp->value;
            temp->value = temp->Next->value;
            temp->Next->value = bufValue;
            isSwap = true;
        }

        temp = temp->Next;
    }
}


void Find(int findElement)
{
    bool isAlreadyFind = false;
    Node* temp = list->Head;

    while (temp != nullptr)
    {
        if (temp->Prev == nullptr && temp->value == findElement)
        {
            cout << "????? ??????? ????????? ? ?????? ??????";
            isAlreadyFind = true;
        }
        else if (temp->Next == nullptr && temp->value == findElement)
        {
            if (isAlreadyFind == true)
            {
                cout << "\n ????? ????? ??????? ????????? ? ????? ??????";
            }
            else
            {
                cout << "??????? " << findElement << " ????????? ? ????? ??????";
            }

        }
        else if (temp->value == findElement)
        {
            if (isAlreadyFind == true)
            {
                cout << "\n????? ????? ??????? ????????? ????? " << temp->Prev->value << " ? " << temp->Next->value;
            }
            else
            {
                cout << "??????? " << findElement << " ????????? ????? " << temp->Prev->value << " ? " << temp->Next->value;
                isAlreadyFind = true;
            }

        }
        temp = temp->Next;
    }
}


void Show()
{
    Node* temp = list->Head;
    while (temp != nullptr)
    {
        cout << temp->value << " ";
        temp = temp->Next;
    }
    cout << "\n";
}

void Tabulation()
{
    cout << "\n" << "\n" << "\n";
}

void Menu()
{
    cout << "????????? ???????: \n";
    cout << "1 - ????????????? ?????? \n";
    cout << "2 - ????? ?????? \n";
    cout << "3 - ?????????? ???????? \n";
    cout << "4 - ???????? ???????? \n";
    cout << "5 - ??????? ???????? ? ?????? \n";
    cout << "6 - ??????? ???????? ? ????? \n";
    cout << "7 - ??????? ????? ????????????? ???????? \n";
    cout << "8 - ??????? ????? ???????????? ????????? \n";
    cout << "9 - ??????????\n";
    cout << "10 - ????? ????????\n";
    cout << "0 - ????? ?? ?????????\n";

    cout << "\n???????? ???????: \n";
}