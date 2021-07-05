#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//--------WaterBody - водный объект-----------
class WaterBody
{
private:
    string name; //наименование
    string continent; //континетт
public:
    WaterBody(string sName, string sContinent = "")
        : name(sName), continent(sContinent) {}

    string getName() const { return name; }
    string getContinent() const { return continent; }

    void setName(string sName) { name = sName; }
    void setContinent(string sContinent) { continent = sContinent; }

}; 

//--------Like - озеро-----------
class Like: public WaterBody 
{
private:
    int area; //площадь
    int mediumdepth; //средняя глубина
public:
    Like(string sName, int iArea = 0, int iMediumDepth = 0, string sContinent = "")
        : area(iArea), mediumdepth(iMediumDepth), WaterBody(sName, sContinent) {}

    int getArea() const { return area; }
    int getMediumDepth() const { return mediumdepth; }

    void setArea(int iArea) { area = iArea; }
    void setMediumDepth(int iMediumDepth) { mediumdepth = iMediumDepth; }
    
    void print() 
    {
        cout << setw(20) << getName() << setw(20) << getContinent() << setw(10) << area << setw(10) << mediumdepth << endl;
    } 

}; 

//--------Waterfall - водопад-----------
class Waterfall: public WaterBody 
{
private:
    int height; //высота
    int width; //ширина
public:
    Waterfall(string sName, int iHeight = 0, int iWidth = 0, string sContinent = "")
        : height(iHeight), width(iWidth), WaterBody(sName, sContinent) {}

    int getHeight() const { return height; }
    int getWidth() const { return width; }

    void setHeight(int iHeight) { height = iHeight; }
    void setWidth(int iWidth) { width = iWidth; }
    
    void print() 
    {
        cout << setw(20) << getName() << setw(20) << getContinent() << setw(10) << height << setw(10)<< width << endl;
    } 

}; 

//--------River - река-----------
class River: public WaterBody 
{
private:
    int mediumdepth; //средняя глубина
    int length; //протяженность
public:
    River(string sName, int iMediumDepth = 0, int iLength = 0, string sContinent = "")
        : mediumdepth(iMediumDepth), length(iLength), WaterBody(sName, sContinent) {}

    int getMediumDepth() const { return mediumdepth; }
    int getLength() const { return length; }

    void setMediumDepth(int iMediumDepth) { mediumdepth = iMediumDepth; }
    void setLength(int iLength) { length = iLength; }
    
    void print() 
    {
        cout << setw(20) << getName() << setw(20) << getContinent() << setw(10) << mediumdepth << setw(10) << length << endl;
    } 

}; 

//--------NodeLike - для создания однонаправленного списка озер -----------
class NodeLike
{
  Like *pLike;
  class NodeLike *ptr;
  friend class CatalogWB;
};

//--------NodeWaterfall - для создания однонаправленного списка водопадов -----------
class NodeWaterfall
{
  Waterfall *pWaterfall;
  class NodeWaterfall *ptr;
  friend class CatalogWB;
};

//--------NodeRiver - для создания однонаправленного списка рек -----------
class NodeRiver
{
  River *pRiver;
  class NodeRiver *ptr;
  friend class CatalogWB;
};

//--------СatalogWB - справочник водных объектов (озер, водопадов, рек)-----------
class CatalogWB 
{
private:
    NodeLike *pLike; //указательна начало списка озер
    int countLike = 0; //длина списка озер

    NodeWaterfall *pWaterfall; //указательна начало списка водопадов
    int countWaterfall = 0; //длина списка водопадов
    
    NodeRiver *pRiver; //указательна начало списка рек
    int countRiver = 0; //длина списка рек
    
    //Печать строки заголовка
    void PrintHeadline(int i){
        
        cout << endl;
        cout.setf(ios::left);
        cout << setw(20) << "Name" << setw(20) << "Continent";
        
        switch (i) 
        {case 0: //i=0 - для массива озер 
            cout << setw(10) << "Area" << setw(10) << "M. depth" << endl;
            break;
        case 1: //i=1 - для массива водопадов
            cout << setw(10) << "Height" << setw(10) << "Width" << endl;
            break;
        case 2: //i=2 - для массива рек
            cout << setw(10) << "M. depth" << setw(10) << "Lenght" << endl;
            break;
        }
    }

    NodeLike* NextLike(NodeLike* node) // получение следующего элемента списка озер
    {
        if (countLike == 0) return NULL;
        return node->ptr;
    }

    NodeWaterfall* NextWaterfall(NodeWaterfall* node) // получение следующего элемента списка водопадов
    {
        if (countWaterfall == 0) return NULL;
        return node->ptr;
    }

    NodeRiver* NextRiver(NodeRiver* node) // получение следующего элемента списка рек
    {
        if (countRiver == 0) return NULL;
        return node->ptr;
    }

    void ClearLike() //очистка спика озер
    {
        if (countLike > 0)
        {
        class NodeLike *p = pLike;
        do 
        { 
            NodeLike *d = p;
            p = NextLike(p);
            delete d->pLike;
            delete d;
        } while (p != NULL);
        countLike = 0;
        pLike = NULL;    
        };
    }    
    
    void ClearWaterfall() //очистка спика водопадов
    {
        if (countWaterfall > 0)
        {
        class NodeWaterfall *p = pWaterfall;
        do 
        { 
            NodeWaterfall *d = p;
            p = NextWaterfall(p);
            delete d->pWaterfall;
            delete d;
        } while (p != NULL);
        countWaterfall = 0;
        pWaterfall = NULL;    
        };
    }    

    void ClearRiver() //очистка спика рек
    {
        if (countRiver > 0)
        {
        class NodeRiver *p = pRiver;
        do 
        { 
            NodeRiver *d = p;
            p = NextRiver(p);
            delete d->pRiver;
            delete d;
        } while (p != NULL);
        countRiver = 0;
        pRiver = NULL;    
        }
    }    

    void Init()
    {   //Инициализируем каталог
        // Добавим озера
        AddLike("Caspian", 371000, 4, "Eurasia");
        AddLike("Victoria", 69485, 40, "Africa");
        AddLike("Huron", 59600, 59, "North America");
        // Добавим водопады
        AddWaterfall("Salto Angel", 979, 107 , "South America");
        AddWaterfall("Niagara Falls", 53, 792 , "North America");
        AddWaterfall("Tugela", 393, 15 , "Africa");
        // Добавим реки
        AddRiver("Amazon", 9, 7100 , "South America");
        AddRiver("Nile", 8, 	6670 , "Africa");
        AddRiver("Missisipi", 7, 6420 , "North America");
    }
    
public:
    CatalogWB(){ pLike = NULL; pWaterfall = NULL; pRiver = NULL; Init(); }
    ~CatalogWB( ) {ClearLike(); ClearWaterfall(); ClearRiver();}

    //Добавление элемента в массив Like
    void AddLike(string sName, int iArea = 0, int iMediumDepth = 0, string sContinent = "")
    {
        Like *p = new Like(sName, iArea, iMediumDepth, sContinent);
        NodeLike *elem = new NodeLike();
        elem->pLike = p;
        elem->ptr = pLike;
        pLike = elem;
        countLike++;
    }

    //Добавление элемента в массив Waterfall
    void AddWaterfall(string sName, int iHeight = 0, int iWidth = 0, string sContinent = "")
    {
        Waterfall *p = new Waterfall(sName, iHeight, iWidth, sContinent);
        NodeWaterfall *elem = new NodeWaterfall();
        elem->pWaterfall = p;
        elem->ptr = pWaterfall;
        pWaterfall = elem;
        countWaterfall++;
    }

    //Добавление элемента в массив Like
    void AddRiver(string sName, int iMediumDepth = 0, int iLength = 0, string sContinent = "")
    {
        River *p = new River(sName, iMediumDepth, iLength, sContinent);
        NodeRiver *elem = new NodeRiver();
        elem->pRiver = p;
        elem->ptr = pRiver;
        pRiver = elem;
        countRiver++;
    }
    
    //Вывод всех элементов списка озер
    void PrintLike()
    {
        if (countLike == 0) 
            cout << "\nСписок озер пустой.\n";
        else
        {
            PrintHeadline(0);
            NodeLike *p = pLike;
            do 
            { 
                p->pLike->print();
                p = NextLike(p);
            } while (p != NULL);
        }    
    }
    
    //Вывод всех элементов списка водопадов
    void PrintWaterfall()
    {
        if (countWaterfall == 0) 
            cout << "\nСписок водопадов пустой.\n";
        else
        {
            PrintHeadline(1);
            NodeWaterfall *p = pWaterfall;
            do 
            { 
                p->pWaterfall->print();
                p = NextWaterfall(p);
            } while (p != NULL);
        }    
    }
    
    //Вывод всех элементов списка рек
    void PrintRiver()
    {
        if (countRiver == 0) 
            cout << "\nСписок водопадов рек пустой.\n";
        else
        {
            PrintHeadline(2);
            NodeRiver *p = pRiver;
            do 
            { 
                p->pRiver->print();
                p = NextRiver(p);
            } while (p != NULL);
        }    
    }
    
     //Вывод элементов массива озер, соответсвующих строке поиска
    void PrintLike(string sSearchLine)
    {
        if (countLike == 0) 
            cout << "\nСписок озер пустой.\n";
        else
        {
            PrintHeadline(0);
            NodeLike *p = pLike;
            do 
            { 
                if (p->pLike->getName().find(sSearchLine) != -1) p->pLike->print();
                p = NextLike(p);
            } while (p != NULL);
        }    
    }
    
     //Вывод элементов массива водопадов, соответсвующих строке поиска
    void PrintWaterfall(string sSearchLine)
    {
        if (countWaterfall == 0) 
            cout << "\nСписок водопадов пустой.\n";
        else
        {
            PrintHeadline(0);
            NodeWaterfall *p = pWaterfall;
            do 
            { 
                if (p->pWaterfall->getName().find(sSearchLine) != EOF) p->pWaterfall->print();
                p = NextWaterfall(p);
            } while (p != NULL);
        }    
    }
    
     //Вывод элементов массива рек, соответсвующих строке поиска
    void PrintRiver(string sSearchLine)
    {
        if (countRiver == 0) 
            cout << "\nСписок водопадов рек пустой.\n";
        else
        {
            PrintHeadline(0);
            NodeRiver *p = pRiver;
            do 
            { 
                if (p->pRiver->getName().find(sSearchLine) != EOF) p->pRiver->print();
                p = NextRiver(p);
            } while (p != NULL);
        }    
    }
    
    //-------- меню озер-----------
    void menuLike()
    {
        bool Cancel = false;
        int Choice;
        string s, name, continent;
        int area, mediumdepth;    
        while (!Cancel) 
        {
            cout<<"\nОзера:\n";
            cout<<"0 - показать все\n";
            cout<<"1 - найти\n";
            cout<<"2 - добавить\n";
            cout<<"3 - вернуться в главное меню\n";
            cout<<"Выберите действие: ";
            cin >> Choice;

            switch (Choice) 
            {case 0: //показать все
                PrintLike();
                break;
            case 1: //найти
                cout<<"\nВведите строку для поиска: ";
                cin >> s;
                PrintLike(s);
                break;
            case 2: //добавить
                cout<<"\nВведите данные для ввода нового озера:\n";
                cout<<"Наименование: ";
                cin >> name;
                cout<<"Площадь: ";
                cin >> area;
                cout<<"Средняя глубина: ";
                cin >> mediumdepth;
                cout<<"Континент: ";
                cin >> continent;
                AddLike(name, area, mediumdepth, continent);
                break;
            case 3:
                Cancel = true;
                break;
            }    
        }
    }    
 
    //-------- меню водопадов-----------
    void menuWaterfall()
    {
        bool Cancel = false;
        int Choice;
        string s, name, continent;
        int height, width;
        
        while (!Cancel) 
        {
            cout<<"\nВодопады: \n";
            cout<<"0 - показать все\n";
            cout<<"1 - найти\n";
            cout<<"2 - добавить\n";
            cout<<"3 - вернуться в главное меню\n";
            cout<<"Выберите действие: ";
            cin >> Choice;

            switch (Choice) 
            {case 0: //показать все
                PrintWaterfall();
                break;
            case 1: //найти
                cout<<"\nВведите строку для поиска: ";
                cin >> s;
                PrintWaterfall(s);
                break;
            case 2: //добавить
                cout<<"\nВведите данные для ввода нового водопада:\n";
                cout<<"Наименование: ";
                cin >> name;
                cout<<"Высота: ";
                cin >> height;
                cout<<"Ширина: ";
                cin >> width;
                cout<<"Континент: ";
                cin >> continent;
                AddWaterfall(name, height, width, continent);
                break;
            case 3:
                Cancel = true;
                break;
            }    
        }
    }    

    //-------- меню рек-----------
    void menuRiver()
    {
        bool Cancel = false;
        int Choice;
        string s, name, continent;
        int mediumdepth, length; 

        while (!Cancel) 
        {
            cout<<"\nРеки:\n";
            cout<<"0 - показать все\n";
            cout<<"1 - найти\n";
            cout<<"2 - добавить\n";
            cout<<"3 - вернуться в главное меню\n";
            cout<<"Выберите действие: ";
            cin >> Choice;

            switch (Choice) 
            {case 0: //показать все
                PrintRiver();
                break;
            case 1: //найти
                cout<<"\nВведите строку для поиска: ";
                cin >> s;
                PrintRiver(s);
                break;
            case 2: //добавить
                cout<<"\nВведите данные для ввода нового озера:\n";
                cout<<"Наименование: ";
                cin >> name;
                cout<<"Средняя глубина: ";
                cin >> mediumdepth;
                cout<<"Протяженность: ";
                cin >> length;
                cout<<"Континент: ";
                cin >> continent;
                AddRiver(name, mediumdepth, length, continent);
                break;
            case 3:
                Cancel = true;
                break;
            }    
        }
    }    

    //-------- главное меню-----------
    void MainMenu()
    {
        bool Cancel = false;
        int Choice;
    
        while (!Cancel) 
        {
            cout<<"\nСправочник рек, озер и водопадов\n";
            cout<<"0 - озера\n";
            cout<<"1 - водопады\n";
            cout<<"2 - реки\n";
            cout<<"3 - выход\n";
            cout<<"Выберите раздел:";
            cin >> Choice;

            switch (Choice) 
            {case 0: //озера
                menuLike();
                break;
            case 1: //i=1 - для массива водопадов
                menuWaterfall();
                break;
            case 2: //i=2 - для массива рек
                menuRiver();
                break;
            case 3:
                Cancel = true;
                break;
            }    
        }
    }
}; 

int main()
{

    CatalogWB catalog; 
    catalog.MainMenu();
    
    return 0;
}
