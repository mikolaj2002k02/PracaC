#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct osoba
{
        string imie, nazwisko;
        int wiek;
};

class populacja
{
                vector <struct osoba> spis;
       
        public:
                populacja();
                ~populacja();
                void wypiszJSON();
                void sortuj();
                void WypiszZPliku(const char *);
};

void populacja::wypiszJSON()
{
        for (vector<struct osoba>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                cout << it->wiek << " "
                         << it->imie << " "
                         << it->nazwisko << "\n";
        } 
}

void populacja::WypiszZPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct osoba>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik << it->wiek << " "
                         << it->imie << " "
                         << it->nazwisko << "\n";
        }
        plik.close();  
}

main()
{ 
  cout << "Content-Type:application/json;charset=UTF-8" << (char)13 << (char)10
      << "\n"
      << "[ \n "
          << "  { \"Imie\":\"Jan\", \"Wiek\":\"35\" }, \n"
          << "  { \"Nazwisko\":\"Kowalski\" } \n"
          << "]"; ; 
  populacja P1;
  P1.wypiszJSON();
    P1.sortuj();
    P1.WypiszZPliku("c:\\od.txt");
  return 0;
}
