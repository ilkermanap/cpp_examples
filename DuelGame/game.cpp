#include <iostream>
#include <stdlib.h> 
#include <unistd.h>
using namespace std;
/* Sıradan bir karakterin tanımlanması-I*/
class Player
{
public:
     string charname;
     int strength = 100;
     int health = 100;
};
/* Savaşçı bir karakterin tanımlanmasıI*/
class Warior : public Player
{
     /*burada shield değerini public yapabilirdim fakat encapsulation çalışmak adına private olarak ekledim */
private:
     int shield;
     int luck;

public:
     string weaponname = "mızrak";
     int attack = 100;
     int SetShield(int shield)
     {
          health = health + shield;
          return health;
     }
     int SetLuck(int luck){
          luck = rand() % luck + 1;
          attack=attack+luck;
          return attack;
     }
};
/* oyunun olduğu sınıf */
class Game
{

public:
/*bekleme fonksiyonu */
     void delay(int n)
     {
          sleep(n);
     }
     /* oyuncuların envanterini sıralayan fonksiyon */
     void Inventory(Warior char1, Warior char2)
     {
          cout << "birinci karakterin özellikleri \n";
          cout << "karakter ismi "
               << ":" << char1.charname << "\n";
          cout << "karakter attack"
               << ":" << char1.attack << "\n";
          cout << "karakter saglık"
               << ":" << char1.health << "\n";
          cout << "karakter kuvvet"
               << ":" << char1.strength << "\n";
          cout << "kullandığı silah"
               << ":" << char1.weaponname << "\n";
          delay(3);
          cout << "ikinci karakterin özellikleri \n";
          cout << "karakter ismi"
               << ":" << char2.charname << "\n";
          cout << "karakter attack"
               << ":" << char2.attack << "\n";
          cout << "karakter saglık"
               << ":" << char2.health << "\n";
          cout << "karakter kuvvet"
               << ":" << char2.strength << "\n";
          cout << "kullandığı silah"
               << ":" << char2.weaponname << "\n";
          delay(3);
     }
     /*birinci karakter kazandığında çıkan output */
     void firstwon()
     {

          cout << " "
               << "o"
               << "\t"
               << " "
               << "o"
               << "\n";
          cout << "/|\\ "
               << "================>"
               << "\t"
               << " "
               << "/|\\ "
               << "\n";
          cout << " "
               << "/\\ "
               << "\t"
               << " "
               << "/\\ "
               << "\n";
     }
     /*birinci karakter vuruş outputu */
     void first()
     {
          cout << " "
               << "o"
               << "\n";
          cout << "/|\\ "
               << "========>"
               << "\n";
          cout << ""
               << "/\\ "
               << "\n";
     }
     /*ikinci karakter vuruş outputu */
     void sec()
     {
          cout << "\t"
               << " "
               << "o"
               << "\n";
          cout << "<======="
               << "/|\\ "
               << "\n";
          cout << "\t"
               << ""
               << " "
               << "/\\ "
               << "\n";
     }
     /*ikinci karakter kazanma outputu */
     void secwin()
     {
          cout << "o"
               << "\t"
               << "\t"
               << ""
               << " "
               << "o"
               << "\n";
          cout << " <=====/|\\======"
               << "/|\\ "
               << "\n";
          cout << "/\\ "
               << "\t"
               << "\t"
               << ""
               << ""
               << " "
               << "/\\ "
               << "\n";
     }

     /* dövüş fonksiyonu */
     void fight(Warior char1, Warior char2)
     {
          int fighttime = 1;
          Inventory(char1, char2);
          cout << "düello basladi \n";
          while (fighttime != 0)
          {

               char1.health -= char2.attack;
               char2.health -= char1.attack;
               first();
               cout << "birinci karakter"
                    << ":" << char1.charname << " "
                    << "can durumu "
                    << ":" << char1.health << "\n";
               delay(3);
               sec();
               cout << "ikinci karakter"
                    << ":" << char2.charname << " "
                    << "can durumu "
                    << ":" << char2.health << "\n";
               delay(3);

               fighttime = 1;
               if (char1.health <= 0 || char2.health <= 0)
               {
                    if (char1.health > char2.health)
                    {
                         firstwon();
                         cout << char1.charname << " kazandı \n";
                    }
                    else
                    {
                         secwin();
                         cout << char2.charname << " kazandı \n";
                    }
                    fighttime = 0;
               }
          }
     }
};

int main()
{
     /* karakter tanımlamaları -I*/
     Warior oguz;
     oguz.charname = "oguz";
     oguz.SetShield(120);
     oguz.SetLuck(20);
     oguz.attack = 100;
     oguz.strength = 100;
     oguz.weaponname = "mizrak";
     /* karakter tanımlamaları -2*/
     Warior deniz;
     deniz.charname = "deniz";
     deniz.SetShield(20);
     deniz.SetLuck(10);
     deniz.attack = 100;
     deniz.strength = 100;
     deniz.weaponname = "mizrak";

     Game firstFight;
     firstFight.fight(oguz, deniz);

     return 0;
}