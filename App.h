#pragma once
#include "List.h"

class App
{
public:
    App();
    ~App();


private:
    void ShowMainMenuHelp();
    void ShowListMenuHelp();

    bool VerifyInputInMainMenu(std::string choice);
    bool VerifyInputInListMenu(std::string choice);
    void ShowAllLists();
    void CreateNewList(std::string choice);
    bool EnterList(std::string choice);
    void DeleteList(std::string choice);

private:
    std::vector<List> m_lists;
    List* m_current_list;
};