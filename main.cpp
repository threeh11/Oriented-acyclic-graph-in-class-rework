#include <iostream>
#include <string>
#include "logic.hpp"

using namespace std;

int main()
{
    setRussian();
    string answer;

    cout << "�� ������� ������� ��������� ������ ����('y' - ��, 'n' - ���):" << endl;
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
                    class ElementGraph* startTmp = graphs->getStart();
                    int count = graphs->amountGraphs();
                    
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "|       ���������� ������ � ��������� ������ = "<< count <<"              |" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                    graphs->refresStart(startTmp);
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
                    graphs->removeGraph(graphs->getNow());
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "|        ��������� �������� � ����� {{"<< graphs->getNow() <<"}}             |" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                    graphs->clearPointers(deletedRoot);
                    graphs->updateNow();
                    break;
                }
                case 5:
                {
                    graphs->removeGraph(graphs->getStart());
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "|            ��������� �������� ��������� ������              |" << endl;
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
        cout << "�� ��������� ������� ������!" << endl;
        exit(0);   
    }
}