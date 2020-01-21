/** 
   * \author SirmaXX
   * \version 1.0
   * \date 18.01.2020 
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>
#include <thread>         /// std::this_thread::sleep_for
#include <chrono>         /// std::chrono::seconds


using namespace std;


/// karakter sınıfı
class Characher
{   
/// karakterin statuleri
private:
    int health;///< karakter sağlık seviyesi
    int hungry ;///< karakterin açlık seviyesi
    int tired ; ///< karakterin yorgunluk seviyesi

 public:
    void setchar(int heal, int hun,int ti)
	{
		 health=heal; hungry =hun;tired =ti;
	}
/*! show character status  
    \param int health.` 
    \param int hungry.` 
    \param int tired.` 
    \return string.  
*/  
    void showcharstat(){
      cout <<  health << " " << hungry << " " << tired << "\n";
    }
/// yön tuşları
   void keysystem (){
     char key; ///< key
     cin>>key;
     while(cin>>key)
     {
        cout<<"tuşlara basınız : ";
       switch(key) {
        case 'w' :
            cout<<"w  bastın \n ";
                break;
        case 'a' :
          cout<<"a bastın \n";
                break;
        case 's' :
         cout<<"s bastın \n";
               break;
        case 'd' :
         cout<<"d bastın \n";
              break;
        default :
         cout << "Invalid grade" << endl;
         exit(0);
       }
    }
    
   }

/*! make healthstatus for character 
    \param int health.` 
    \param int hungry.` 
    \param int tired.` 
    \return string.  
*/  
 void healthstatus (int health ,int hungry ,int tired){
  for (int i=10; i>0; --i) {
   hungry=hungry-i;
   tired=tired-i;
   std::cout <<  hungry <<", "<<tired <<", "<< health << std::endl;
   std::cout << i << std::endl;
   std::this_thread::sleep_for (std::chrono::seconds(1));
  }
   if ((hungry = 0) && ( tired = 0))
    {
      std::cout << "die";
     }else {
    std::cout << "Lift off!\n";
   }
  }
};

/// uzay gemisi sınıfı
class Spaceship { 
   int shipnumber; ///< gemi numarası 
   int speed; ///< geminin hızı
protected :
   void run(){
   };
}; 
/// savaş gemisi sınıfı
class Warship{ 
   Spaceship number;
   int power; ///< geminin ateş gücü
   int firerate;  ///< geminin atış hızı
}; 
/// kargo gemisi sınıfı
class Cargoship { 
   Spaceship number;
   float weightlimit; ///< geminin yük kapasitesi
}; 

///oyun içeriği
int main() {
    Characher mesa;
    mesa.setchar(100,100,100);
    mesa.showcharstat();
    mesa.keysystem();
    mesa.healthstatus(100,100,100);

   }
