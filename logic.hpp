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
    cout << "               Создан граф с адресом {{"  << this << "}}       " << endl;
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
    cout << "|                     Заполняем граф...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << "Введите тип домашнего животного: ";
    cin >> typeAnimal;
    cout << "Введите породу домашнего животного: ";
    cin >> race;
    cout << "Введите имя домашнего животного: ";
    cin >> name;
    cout << "Введите преоблодающий цвет домашнего животного: ";
    cin >> mainColor;
    cout << "Введите пол домашнего животного: ";
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
        cout << "Я ГЕЙ!" << endl;
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
    // to - 1 к старту, to - 2 к текущему графу
    string typeAnimal, race, name,
           mainColor, gender;

    cout << "---------------------------------------------------------------" << endl;
    cout << "|                     Заполняем граф...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << "Введите тип домашнего животного: ";
    cin >> typeAnimal;
    cout << "Введите породу домашнего животного: ";
    cin >> race;
    cout << "Введите имя домашнего животного: ";
    cin >> name;
    cout << "Введите преоблодающий цвет домашнего животного: ";
    cin >> mainColor;
    cout << "Введите пол домашнего животного: ";
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
                cout << "Добавление не возможно достигнуто максимальное количество дочерних графов!" << endl;    
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
                cout << "Добавление не возможно достигнуто максимальное количество дочерних графов!" << endl;    
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
    cout << "          Вы находитесь в {{" << this->now << "}} графе."       << endl;
    cout << "---------------------------------------------------------------" << endl;

    int countChildren = 0;

    while (this->now->pointers[countChildren] != NULL)
    {
        countChildren++;
    }

    if (countChildren == 0)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       У графа нет дочерних элементов переход не возможен!"      << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Вы хотите вернуться в начало графа('y' - да, 'n' - нет)?" << endl;
        string answer;
        cin >> answer;
        if (answer == "y")
        {
            this->goToStart();
            cout << "Вы успешно переместились в начало графа!" << endl;
        }
        else if (answer == "n")
        {
            cout << "Ну нет, так нет";
        }
        else
        {
            cout << "Введено не корректное значение!" << endl;
        }
    }
    else if (countChildren == 1)
    {
        cout << "У графа 1 дочерний элемент, перейти к нему('y' - да, 'n' - нет, '1' - Вернуться в начало гарфа):" << endl;
        string answer;
        cin >> answer;
        if (answer == "y") 
        {
            this->now = this->now->pointers[0];
            cout << "---------------------------------------------------------------" << endl;
            cout << "                    Вы успешно поменяли граф!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            countChildren = 0;
        }
        else if (answer == "n")
        {
            cout << "Ну нет, так нет";
        }
        else if (answer == "1")
        {
            this->goToStart();
            cout << "Вы успешно переместились в начало графа!" << endl;
        }
        else
        {
            cout << "Введено не корректное значение!" << endl;
        }
    }
    else
    {
        int answer = 0;
        int i1 = 0;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Выберите Граф к которому хотите перейти, всего дочерних графов = " << countChildren << endl;
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
        cout << i1 << ")" << "Вернуться в начало" << endl;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Выберите граф: ";
        cin >> answer;
        
        if (answer > 0 && answer <= countChildren)
        {
            if (answer == i1)
            {
                this->goToStart();
                cout << "Вы успешно переместились в начало графа!" << endl;
            }
            else {
                cout << "---------------------------------------------------------------" << endl;
                cout << "               Вы успешно поменяли граф!" << endl;
                cout << "---------------------------------------------------------------" << endl;
                this->now = this->now->pointers[answer-1];
                countChildren = 0;
            }
        }
        else if (answer == i1)
        {
            this->goToStart();
            cout << "Вы успешно переместились в начало графа!" << endl;
        }
        else
        {
            answer = 0;
            cout << "Введено не корректное значение" << endl;
            this->changePosition();
        }
    }
}

void Graphs :: getValue()
{
    cout << endl;
    cout << "---------------------------------------------------------------"       << endl;
    cout << "                      {{" << this->now << "}}                  "       << endl;
    cout << "Тип домашнего животного: " << this->now->getTypeAnimal()               << endl;
    cout << "Порода домашнего животного: " << this->now->getRace()                  << endl;
    cout << "Имя домашнего животного: "  << this->now->getName()                    << endl;
    cout << "Преоблодающий цвет домашнего животного: " << this->now->getMainColor() << endl;
    cout << "Пол домашнего животного: " << this->now->getGender()                   << endl;
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
    cout << "|                         МЕНЮ                                |" << endl;
    cout << "| 1)Получение количества элементов в структуре данных         |" << endl;
    cout << "| 2)Добавление элемента в структуру данных                    |" << endl;
    cout << "| 3)Вставка дочернего элемента для текущего элемента          |" << endl;
    cout << "| 4)Удаление текущего элемента структуры данных               |" << endl;
    cout << "| 5)Очистка структуры данных                                  |" << endl;
    cout << "| 6)Перемещение по элементам структуры данных                 |" << endl;
    cout << "| 7)Чтение информации из текущего элемента структуры данных   |" << endl;
    cout << "| 8)Выйти                                                     |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
}

int getTools()
{
    printTools();
    int numberTool = 0;
    cout << "Введите цифру: ";
    cin >> numberTool;
    return numberTool;
}

