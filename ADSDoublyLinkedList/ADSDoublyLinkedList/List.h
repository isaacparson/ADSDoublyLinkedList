#pragma once

struct Node
{
    int value;
    Node* Next = nullptr;
    Node* Prev = nullptr;
};

struct List
{
    Node* Head = nullptr;
    Node* Tail = nullptr;
};