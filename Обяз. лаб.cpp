#include <iostream>
using namespace std;

//--------Harbinger-----------
class Harbinger
{
private:
    string h_name;
    int h_age;
    string CatchPhrase;
public:
    Harbinger(string name = "", int age = 0, string sCatchPhrase = "" )
        : h_name(name), h_age(age), CatchPhrase(sCatchPhrase)
    {
    }

    string getName() const { return h_name; }
    int getAge() const { return h_age; }
    string getCatchPhrase() const { return CatchPhrase; }
    
    void setName(string name) { h_name = name; }
    void setAge(int age) { h_age = age; }
    void setCatchPhrase(string sCatchPhrase) { CatchPhrase = sCatchPhrase; }

}; 

//--------Prophet-----------
class Prophet: public Harbinger
{
private:
    string ph_name;
    int ph_age; 
    string ph_call;
    string MagnumOpus[3];
    void updateCall() 
    {   string temp = "";
        for (int i = 0; i < 3; i++)
             if (MagnumOpus[i].length() > temp.length()) temp = MagnumOpus[i]; 
        ph_call = temp;
    }    
public:    
    Prophet(string phname = "", int phage = 0, string MagnumOpus0 = "", 
        string MagnumOpus1 = "", string MagnumOpus2 = "",
        string hname = "", int hage = 0, string sCatchPhrase = "") 
        : ph_name(phname), ph_age(phage), Harbinger(hname, hage, sCatchPhrase)
    {   setMagnumOpus(0, MagnumOpus0); 
        setMagnumOpus(1, MagnumOpus1); 
        setMagnumOpus(2, MagnumOpus2); 
    }    
    string getMagnumOpus(int i) const { return MagnumOpus[i]; }
    void setMagnumOpus(int i, string element)
    {   if ((i >= 0) && (i < 3)) 
        { if (element.length() > 25) 
            {  cout << element << endl;
                cout << "Строка усечена до 25 символов.\n"; 
             element = element.substr(0, 25); 
             cout << element << endl;
            }
         MagnumOpus[i] = element; 
         updateCall(); 
        }
    }
    string getName() const { return ph_name; }
    void setName(string name) { ph_name = name; }

    int getAge() const { return ph_age; }
    void setAge(int age) { ph_age = age; }

    string getCall() const { return ph_call; }
    void setCall(string Call) { ph_call = Call; }
  
};

//--------DeusEx-----------
class DeusEx: public Prophet
{
private:
    string gd_name;
    int gd_year; 
public:    
    DeusEx(string gdname = "", int gdyear = 0,
        string phname = "", int phage = 0, string MagnumOpus0 = "", 
        string MagnumOpus1 = "", string MagnumOpus2 = "",
        string hname = "", int hage = 0, string sCatchPhrase = "") 
        : gd_name(gdname), gd_year(gdyear), 
        Prophet(phname, phage, MagnumOpus0, 
            MagnumOpus1, MagnumOpus2, hname, hage, sCatchPhrase) 
    {   if (gd_year < 0 || gd_year > 9999) 
        { cout << "Значение Year установлено равным 0.\n"; 
            gd_year = 0; 
        }    
    }
    
    string getName() const { return gd_name; }
    int getYear() const { return gd_year; }

    void PrintDeusEx() { 
        cout << Harbinger::getName() << " в возрасте " << Harbinger::getAge();
        cout << " говорил, что " << getCatchPhrase() << ".\n";
        cout << "Первое пророчество: " << getMagnumOpus(0) << ".\n";
        cout << "Второе пророчество: " << getMagnumOpus(1) << ".\n";
        cout << "Главное пророчество: " << getCall() << ".\n";
        cout << "Так говорил " << Prophet::getName() << " в возрасте ";
        cout << Prophet::getAge() << ".\n";
        cout << "В год " << getYear() <<  " пришёл " << getName();
        cout << ", которого предрекали " << Harbinger::getName() << " и ";
        cout << Prophet::getName() << ".\n";
    }    
};

//--------Believer-----------
class Believer: public DeusEx
{
private:
    string bv_name;
    int bv_age; 
public:    
    Believer(string name, int age, string gdname = "", int gdyear = 0,
        string phname = "", int phage = 0, string MagnumOpus0 = "", 
        string MagnumOpus1 = "", string MagnumOpus2 = "",
        string hname = "", int hage = 0, string sCatchPhrase = "") 
        : bv_name(name), bv_age(age),
        DeusEx(gdname, gdyear, phname, phage, MagnumOpus0, 
            MagnumOpus1, MagnumOpus2, hname, hage, sCatchPhrase)
    { }

    string getName() const { return bv_name; }
    void setName(string name) { bv_name = name; }

    int getAge() const { return bv_age; }
    void setAge(int age) { bv_age = age; }
        
    void PrintBeliever() { 
        cout << "Верующий " << getName() << " молится " << DeusEx::getName();
        cout << " именем " << Prophet::getName() << ". C ";
        cout << getYear() << " и по сей день.\n"; 
    }    
};

///////
int main()
{

    Believer b("Иван", 35, //Believer
        "Соломон", 300, //DeusEx
        "Петр", 40, "Миру - мир", "И это пройдет", "Весна пришла", //Prophet
        "Платон", 25, "Мир, дружба, май"); //Harbinger

    b.PrintBeliever(); //Believer
    b.PrintDeusEx(); //DeusEx
    
    return 0;

}    

