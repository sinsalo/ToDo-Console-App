#include "App.h"

App::App()
{
    std::cout << "This is a simple ToDo-List App!" << std::endl;
    ShowMainMenuHelp();
}



App::~App()
{
}



bool App::VerifyInputInMainMenu(std::string choice)
{
    if (choice.compare("S") == 0)
    {
        ShowAllLists();
        return false;
    }
    else if (choice[0] == 'C')
    {
        CreateNewList(choice);
        return false;
    }
    else if (choice[0] == 'D')
    {
        DeleteList(choice);
        return false;
    }
    else if (choice[0] == 'E')
    {
        if (EnterList(choice))
            return true;
        else
            return false;
    }
    else
    {
        std::cout << "Could not read your input\n" << std::endl;
        return false;
    }
}



void App::CreateNewList(std::string choice)
{
    std::string list_name = choice.erase(0,1);
    
    if (list_name.empty())
        return;

    for (auto& list : m_lists)
    { 
        if (list.GetTitle().compare(list_name) == 0)
        {
            std::cout << "ERROR: This list-name is already taken!" << std::endl;
            return;
        }
    }
    m_lists.push_back(List{list_name});
    std::cout << "List succesfully created!" << std::endl;
}



bool App::EnterList(std::string choice)
{
    std::string list_name = choice.erase(0,1);

    if (m_lists.empty())
    {
        std::cout << "There are no Lists! Create one..." << std::endl;
        return false;
    }

    for (auto& list : m_lists)
    {
        if (list.GetTitle().compare(list_name) == 0)
        {
            m_current_list = &list;
            std::cout << "You are in list: " + list.GetTitle() << std::endl;
            return true;
        }
    }
    return false;
}



void App::DeleteList(std::string choice)
{
    std::string list_name = choice.erase(0,1);

    if (list_name.empty())
        return;

    if (m_lists.empty())
    {
        std::cout << "There are no Lists! Create one..." << std::endl;
        return;
    }
    auto to_erase = std::remove_if(m_lists.begin(), m_lists.end(), 
                                   [&list_name](List& list)
                                   { return (list.GetTitle().compare(list_name) == 0); });
    m_lists.erase(to_erase, m_lists.end());
}



bool App::VerifyInputInListMenu(std::string choice)
{
    if (choice.compare("B") == 0)
    {
        return false;
    }
    else if (choice[0] == 'A')
    {
        m_current_list->AppendToList();
        return true;
    }
    else if (choice[0] == 'R')
    {
        m_current_list->RemoveElement(choice);
        return true;
    }
    else if (choice[0] == 'M')
    {
        m_current_list->MarkDone(choice);
        return true;
    }
    else if (choice[0] == 'S')
    {
        m_current_list->ShowAllElementInList();
        return true;
    }
    else
    {
        std::cout << "Could not read your input\n" << std::endl;
        return true;
    }
}



void App::ShowMainMenuHelp()
{
    std::string choice;

    std::cout << "\nYou have following options:" << std::endl;
    std::cout << "[S]how all lists" << std::endl;
    std::cout << "[C]reate a new list: e.g. CMyToDoList" << std::endl;
    std::cout << "[E]nter a list: e.g. EMyToDoList" << std::endl;
    std::cout << "[D]elete a list: e.g. DMyToDoList" << std::endl;
    std::cout << "E[X]it App" << std::endl;
    std::cin >> choice;

    if (choice[0] == 'X')
        return;

    if (!VerifyInputInMainMenu(choice))
    {
        ShowMainMenuHelp();
    }
    else
    {
        ShowListMenuHelp();
    }
}



void App::ShowListMenuHelp()
{
    std::string choice;

    std::cout << "\nYou have following options:" << std::endl;
    std::cout << "[A]ppend something to this list" << std::endl;
    std::cout << "[R]emove something in this list by its number: e.g. R1" << std::endl;
    std::cout << "[M]ark something in this list as done by its number: e.g. M1" << std::endl;
    std::cout << "[S]how all elements in this list" << std::endl;
    std::cout << "[B]ack to main menu" << std::endl;

    std::cin >> choice;

    if (!VerifyInputInListMenu(choice))
    {
        ShowMainMenuHelp();
    }
    else
    {
        ShowListMenuHelp();
    }
}



void App::ShowAllLists()
{
    if (m_lists.empty())
    {
        std::cout << "There are no Lists! Create one..." << std::endl;
        return;
    }

    for (auto& list : m_lists)
    {
        std::cout << list.GetTitle() << std::endl;
    }
}