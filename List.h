#pragma once

#include <string>
#include <vector>
#include <iostream>

struct ListElement
{
    bool isDone = false;
    std::string description;
};


class List
{
public:
    List(std::string title);
    ~List();

    void ShowAllElementInList();
    void AppendToList();
    void MarkDone(std::string choice);
    void RemoveElement(std::string choice);
    std::string& GetTitle();

private:
    bool CheckIsValidNumber(const std::string& choice, unsigned int& num);
    std::string m_title;
    std::vector<ListElement> m_toDos;
};