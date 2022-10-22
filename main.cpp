#include <iostream>
#include <string>
#include "logic.hpp"

using namespace std;

int main()
{
    setRussian();
    string answer;

    cout << "---------------------------------------------------------------" << endl;
    cout << "Вы желаете создать структуру данных граф('y' - да, 'n' - нет):" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cin >> answer;

    if (answer == "y")
    {
        class Graphs* graphs = new Graphs;
        graphs->create();

        int tool = getTools();
        while (tool != 8)
        {
            switch (tool)
            {
            case 1:
            {
                int count = graphs->amountGraphs(graphs->getStart());
                cout << "---------------------------------------------------------------" << endl;
                cout << "|       Количество графов в структуре данных = " << count << "              |" << endl;
                cout << "---------------------------------------------------------------" << endl;
                break;
            }
            case 2:
            {
                graphs->addGraphTo(1);
                break;
            }
            case 3:
            {
                graphs->addGraphTo(2);
                break;
            }
            case 4:
            {
                class ElementGraph* deletedRoot = graphs->getNow();
                if (graphs->getNow() == graphs->getStart())
                {
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "Вы находитесь в стартовом графе, хотетите удалить всю структуру?('y' - да, 'n' - нет):" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                    string answer;
                    cin >> answer;
                    if (answer == "y")
                    {
                        graphs->removeGraph(graphs->getStart());
                        cout << "---------------------------------------------------------------" << endl;
                        cout << "|            Выполнено удаление структуры данных              |" << endl;
                        cout << "---------------------------------------------------------------" << endl;
                        exit(0);
                    }
                    else
                    {
                        break;
                    }
                }
                graphs->removeGraph(graphs->getNow());
                cout << "---------------------------------------------------------------" << endl;
                cout << "|        Выполнено удаление с графа {{" << graphs->getNow() << "}}             |" << endl;
                cout << "---------------------------------------------------------------" << endl;
                graphs->clearPointers(deletedRoot);
                graphs->updateNow();
                break;
            }
            case 5:
            {
                graphs->removeGraph(graphs->getStart());
                cout << "---------------------------------------------------------------" << endl;
                cout << "|            Выполнено удаление структуры данных              |" << endl;
                cout << "---------------------------------------------------------------" << endl;
                exit(0);
                break;
            }
            case 6:
            {
                graphs->updateBefore();
                graphs->changePosition();
                break;
            }
            case 7:
            {
                graphs->getValue();
                break;
            }
            }
            tool = getTools();
        }
    }
    else if (answer == "n")
    {
        exit(0);
    }
    else
    {
        cout << "Не правильно введены данные!" << endl;
        exit(0);
    }
}