#include "List.h"

List::List(std::string title)
    : m_title(title)
{
}


List::~List()
{
}


bool List::CheckIsValidNumber(const std::string& choice, unsigned int& num)
{
    auto valid_num = !choice.empty() && choice[0] != '0' && std::find_if(choice.begin(),
        choice.end(), [](unsigned char c) { return !isdigit(c); }) == choice.end();

    if (!valid_num)
    {
        std::cout << "Please enter a valid number!!!" << std::endl;
        return false;
    }

    unsigned int number = std::stoi(choice, nullptr, 10);

    if (number > List::m_toDos.size())
    {
        std::cout << "Out of bounds!!!" << std::endl;
        return false;
    }

    num = number;
    return true;
}



std::string& List::GetTitle()
{
    return m_title;
}



void List::ShowAllElementInList()
{
    if (m_toDos.empty())
    {
        std::cout << "List-Name: " + m_title + " is empty!" << std::endl;
        return;
    }

    std::cout << "List-Name: " + m_title << std::endl;
    for (auto& toDo : m_toDos)
    {
        std::cout << "IsDone:" << std::boolalpha << toDo.isDone << " - " << toDo.description << std::endl;
    }
}



void List::AppendToList()
{
    std::string task_to_append;

    std::cout << "Enter description:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, task_to_append);

    if (task_to_append.empty())
    {
        std::cout << "Cannot add empty task to list..." << std::endl;
        return;
    }
    ListElement new_element;
    new_element.isDone = false;
    new_element.description = task_to_append;

    m_toDos.push_back(new_element);
}



void List::MarkDone(std::string choice)
{
    std::string to_be_marked_as_done = choice.erase(0,1);
    unsigned int number = 0;

    if (!CheckIsValidNumber(to_be_marked_as_done, number))
        return;

    m_toDos.at(number - 1).isDone = true;
}



void List::RemoveElement(std::string choice)
{
    std::string to_be_deleted = choice.erase(0,1);
    unsigned int number = 0;

    if (!CheckIsValidNumber(to_be_deleted, number))
        return;

    m_toDos.erase(m_toDos.begin() + number - 1);
}