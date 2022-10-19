#include <iostream>
#include <string>

using namespace std;

class ElementGraph
{
protected:
    string typeAnimal;
    string race;
    string name;
    string mainColor;
    string gender;
    
public:
    class ElementGraph* pointers[10];

    ElementGraph(string typeAnimal,
                 string race,
                 string name,
                 string mainColor,
                 string gender);
    ~ElementGraph();

    string getTypeAnimal(){return this->typeAnimal;};
    string getRace(){return this->race;};
    string getName(){return this->name;};
    string getMainColor(){return this->mainColor;};
    string getGender(){return this->gender;};
    int getCountChildGraphs();
};

ElementGraph :: ElementGraph(string typeAnimal,
                             string race,
                             string name,
                             string mainColor,
                             string gender)
{

    this->typeAnimal = typeAnimal;
    this->race = race;
    this->name = name;
    this->mainColor = mainColor;
    this->gender = gender;

    for (int i = 0; i < 10; i++)
    {
        this->pointers[i] = NULL;
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "               ������ ���� � ������� {{"  << this << "}}       " << endl;
    cout << "---------------------------------------------------------------" << endl;
}

ElementGraph :: ~ElementGraph()
{
    delete this;
}

int ElementGraph :: getCountChildGraphs()
{
    int count = 0;

    for (int i = 0; i < 10; i++)
    {
        if (this->pointers[i] != NULL)
        {
            count++;
        }
    }

    return count;
}

class Graphs
{
protected:
    class ElementGraph* start;
    class ElementGraph* now;
    class ElementGraph* before;
    class ElementGraph* startForCount;

public:
    Graphs();
    ~Graphs();

    void create();
    int amountGraphs();
    void addGraphTo(int to);
    void removeGraph(class ElementGraph* now);
    void clearPointers(class ElementGraph* deletedNow);
    void updateNow(){this->now = this->before;};
    void updateBefore(){this->before = this->now;};
    void goToStart(){this->now = this->start;};
    void changePosition();
    void getValue();
    void refresStart(class ElementGraph* start){this->start = start;};

    class ElementGraph* getStart(){return this->start;}
    class ElementGraph* getNow(){return this->now;}
    class ElementGraph* getBefore(){return this->before;}
    class ElementGraph* getStartForCount(){return this->startForCount;};
};

Graphs :: ~Graphs()
{
    this->removeGraph(this->start);
}

Graphs :: Graphs()
{
    this->start = NULL;
    this->now = NULL;
    this->before = NULL;
    this->startForCount = NULL;
}

void Graphs :: create()
{
    string typeAnimal, race, name,
           mainColor, gender;

    cout << "---------------------------------------------------------------" << endl;
    cout << "|                     ��������� ����...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << "������� ��� ��������� ���������: ";
    cin >> typeAnimal;
    cout << "������� ������ ��������� ���������: ";
    cin >> race;
    cout << "������� ��� ��������� ���������: ";
    cin >> name;
    cout << "������� ������������� ���� ��������� ���������: ";
    cin >> mainColor;
    cout << "������� ��� ��������� ���������: ";
    cin >> gender;

    this->start = new ElementGraph(
        typeAnimal, race, name, 
        mainColor, gender
    );

    this->startForCount = this->start;
    this->now = this->start;
    this->before = this->start;
}

int Graphs :: amountGraphs()
{
    int count = 0;

    cout << this->start << endl;
    if (this->start == NULL)
    {
        cout << "� ���!" << endl;
        return 0;
    }
    else if (this->start != NULL)
    {
        count++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << this->start->pointers[i] << endl;
        this->start = this->start->pointers[i];
        cout << count << endl;
        count += amountGraphs();
        cout << count << endl;
    }
    return count;
}

void Graphs :: addGraphTo(int to)
{
    // to - 1 � ������, to - 2 � �������� �����
    string typeAnimal, race, name,
           mainColor, gender;

    cout << "---------------------------------------------------------------" << endl;
    cout << "|                     ��������� ����...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << "������� ��� ��������� ���������: ";
    cin >> typeAnimal;
    cout << "������� ������ ��������� ���������: ";
    cin >> race;
    cout << "������� ��� ��������� ���������: ";
    cin >> name;
    cout << "������� ������������� ���� ��������� ���������: ";
    cin >> mainColor;
    cout << "������� ��� ��������� ���������: ";
    cin >> gender;

    class ElementGraph* freshGraph = new ElementGraph(
        typeAnimal, race, name, 
        mainColor, gender
    );

    if (to == 1)
    {
        for (int i = 0; i < 10; i++)
        {
            if (this->start->pointers[i] == NULL)
            {
                this->start->pointers[i] = freshGraph;
                break;
            }
            if (i == 9)
            {
                cout << "���������� �� �������� ���������� ������������ ���������� �������� ������!" << endl;    
            }
        }
    }
    else if (to == 2)
    {
       for (int i = 0; i < 10; i++)
        {
            if (this->now->pointers[i] == NULL)
            {
                this->now->pointers[i] = freshGraph;
                break;
            }
            if (i == 9)
            {
                cout << "���������� �� �������� ���������� ������������ ���������� �������� ������!" << endl;    
            }
        } 
    }
    
}

void Graphs :: removeGraph(class ElementGraph* now)
{
    if (this->now != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            this->now = this->now->pointers[i];
            removeGraph(this->now);
        }
    }
    delete this->now;
}

void Graphs :: clearPointers(class ElementGraph* deletedNow)
{
    for (int i = 0; i < 10; i++)
    {
        if (this->before->pointers[i] == deletedNow)
        {
            this->before->pointers[i] = NULL;
        }
    }
}

void Graphs :: changePosition()
{
    cout << "---------------------------------------------------------------" << endl;
    cout << "          �� ���������� � {{" << this->now << "}} �����."       << endl;
    cout << "---------------------------------------------------------------" << endl;

    int countChildren = 0;

    while (this->now->pointers[countChildren] != NULL)
    {
        countChildren++;
    }

    if (countChildren == 0)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       � ����� ��� �������� ��������� ������� �� ��������!"      << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "�� ������ ��������� � ������ �����('y' - ��, 'n' - ���)?" << endl;
        string answer;
        cin >> answer;
        if (answer == "y")
        {
            this->goToStart();
            cout << "�� ������� ������������� � ������ �����!" << endl;
        }
        else if (answer == "n")
        {
            cout << "�� ���, ��� ���";
        }
        else
        {
            cout << "������� �� ���������� ��������!" << endl;
        }
    }
    else if (countChildren == 1)
    {
        cout << "� ����� 1 �������� �������, ������� � ����('y' - ��, 'n' - ���, '1' - ��������� � ������ �����):" << endl;
        string answer;
        cin >> answer;
        if (answer == "y") 
        {
            this->now = this->now->pointers[0];
            cout << "---------------------------------------------------------------" << endl;
            cout << "                    �� ������� �������� ����!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            countChildren = 0;
        }
        else if (answer == "n")
        {
            cout << "�� ���, ��� ���";
        }
        else if (answer == "1")
        {
            this->goToStart();
            cout << "�� ������� ������������� � ������ �����!" << endl;
        }
        else
        {
            cout << "������� �� ���������� ��������!" << endl;
        }
    }
    else
    {
        int answer = 0;
        int i1 = 0;
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ���� � �������� ������ �������, ����� �������� ������ = " << countChildren << endl;
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i+1 << ")" << this->now->pointers[i] << endl;
            if (i + 1 == countChildren)
            {
                i1 = i + 2;
            }
        }
        cout << i1 << ")" << "��������� � ������" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ����: ";
        cin >> answer;
        
        if (answer > 0 && answer <= countChildren)
        {
            if (answer == i1)
            {
                this->goToStart();
                cout << "�� ������� ������������� � ������ �����!" << endl;
            }
            else {
                cout << "---------------------------------------------------------------" << endl;
                cout << "               �� ������� �������� ����!" << endl;
                cout << "---------------------------------------------------------------" << endl;
                this->now = this->now->pointers[answer-1];
                countChildren = 0;
            }
        }
        else if (answer == i1)
        {
            this->goToStart();
            cout << "�� ������� ������������� � ������ �����!" << endl;
        }
        else
        {
            answer = 0;
            cout << "������� �� ���������� ��������" << endl;
            this->changePosition();
        }
    }
}

void Graphs :: getValue()
{
    cout << endl;
    cout << "---------------------------------------------------------------"       << endl;
    cout << "                      {{" << this->now << "}}                  "       << endl;
    cout << "��� ��������� ���������: " << this->now->getTypeAnimal()               << endl;
    cout << "������ ��������� ���������: " << this->now->getRace()                  << endl;
    cout << "��� ��������� ���������: "  << this->now->getName()                    << endl;
    cout << "������������� ���� ��������� ���������: " << this->now->getMainColor() << endl;
    cout << "��� ��������� ���������: " << this->now->getGender()                   << endl;
    cout << "---------------------------------------------------------------"       << endl;
    cout << endl;
}

void setRussian()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
}

void printTools()
{
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|                         ����                                |" << endl;
    cout << "| 1)��������� ���������� ��������� � ��������� ������         |" << endl;
    cout << "| 2)���������� �������� � ��������� ������                    |" << endl;
    cout << "| 3)������� ��������� �������� ��� �������� ��������          |" << endl;
    cout << "| 4)�������� �������� �������� ��������� ������               |" << endl;
    cout << "| 5)������� ��������� ������                                  |" << endl;
    cout << "| 6)����������� �� ��������� ��������� ������                 |" << endl;
    cout << "| 7)������ ���������� �� �������� �������� ��������� ������   |" << endl;
    cout << "| 8)�����                                                     |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
}

int getTools()
{
    printTools();
    int numberTool = 0;
    cout << "������� �����: ";
    cin >> numberTool;
    return numberTool;
}

