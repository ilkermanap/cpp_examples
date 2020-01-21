// This is a comment
/*
 * Multi-line comment
 */

// Tells the compiler iostream library which contains the function cout
#include <iostream>

#include <cstring>

#include <ctime>
 // Allows us to use vectors
#include <vector>

// Allows us to use strings
#include <string>

// Allow us to work with files
#include <fstream>

#include <string>
 // Allows functions in the std namespace to be used without their prefix
// std::cout becomes cout
using namespace std;


#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'


struct Books {
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
};

void printBook(struct Books book) {
  cout << "Book title : " << book.title << endl;
  cout << "Book author : " << book.author << endl;
  cout << "Book subject : " << book.subject << endl;
  cout << "Book id : " << book.book_id << endl;
}
int main() {

  cout << "tesast" << endl;
  const double PI = 3.1415;
  char letter = 'J';
  bool isThattrue = true;
  int ageas = 12;
  float money = 123.123;
  double newmoney = 12.12321323;
  cout << "mymoney" << money << endl;

  cout << "1+2 -3*2=" << 1 + 2 - 3 * 2 << endl;
  cout << "4/4=" << 4 / 4 << endl;

  // ==, !=,<,>,>=,<=

  //giris programı
  int age = 19;
  bool kimlik = true;
  bool unicard = true;

  if (age <= 18 && kimlik == false) {
    cout << "giremessin" << endl;
  } else if (age > 18 && unicard == true) {
    cout << "girebilirsin" << endl;
  } else {
    cout << "giremezsin" << endl;
  }

  int trlanguage = 1;

  switch (trlanguage) {
  case 1:
    cout << "türkçe dil dosyası eklendi" << endl;
    break;

  default:
    break;
  }

  // variable =(condition)?true :false
  int largest = (5 > 2) ? 5 : 2;
  cout << "türkçe dil dosyası eklendi  " << largest << endl;

  // ---------- ARRAYS ----------

  int myFavNums[5];

  int lotonumaralari[5] = {
    4,
    13,
    14,
    24,
    34
  };

  // The first item in the array has the label (index) of 0
  cout << "1.loto numarası: " << lotonumaralari[0] << endl;

  lotonumaralari[0] = 1;

  cout << " yeni 1.loto numarası: " << lotonumaralari[0] << endl;

  //Loop döngüsü 
  for (int i = 1; i <= 10; i++) {

    cout << i << endl;

  }

  // You can also cycle through an array by nesting for loops
  for (int j = 0; j < 5; j++) {
    cout << lotonumaralari[j] << endl;
    cout << endl;
  }

  //While döngüsü 
  int index = 1;
  while (index <= 10) {
    cout << "," << index;
    // Increment inside the loop
    index++;
  }
  //Do while
  int a = 10;

  do {
    cout << "value of a: " << a << endl;
    a = a + 1;
  } while (a < 20);

  //Strings
  char happyArray[6] = {
    'H',
    'a',
    'p',
    'p',
    'y',
    '\0'
  };

  // The C++ way
  string birthdayString = " Birthday";
  cout << happyArray + birthdayString << endl;
  //Pointers
  int
  var = 20; // actual variable declaration.
  int * ip; // pointer variable 

  ip = &
    var; // store address of var in pointer variable

  cout << "Value of var variable: ";
  cout <<
    var << endl;

  // print the address stored in ip pointer variable
  cout << "Address stored in ip variable: ";
  cout << ip << endl;

  // access the value at the address available in pointer
  cout << "Value of *ip variable: ";
  cout << * ip << endl;

  //Referanslar
  // declare simple variables
  int i;
  double d;

  // declare reference variables
  int & r = i;
  double & s = d;
  i = 5;
  cout << "Value of i : " << i << endl;
  cout << "Value of i reference : " << r << endl;

  d = 11.7;
  cout << "Value of d : " << d << endl;
  cout << "Value of d reference : " << s << endl;

  // input output
  char name[50];
  cout << "Please enter your name: ";
  cin >> name;
  cout << "Your name is: " << name << endl;

  struct Books Book1;

  // book 1 sveri yapısı
  strcpy(Book1.title, "Learn C++ Programming");
  strcpy(Book1.author, "Chand Miyan");
  strcpy(Book1.subject, "C++ Programming");
  Book1.book_id = 6495407;

  //yazdırmak
  cout << "Book 1 title : " << Book1.title << endl;
  cout << "Book 1 author : " << Book1.author << endl;
  cout << "Book 1 subject : " << Book1.subject << endl;
  cout << "Book 1 id : " << Book1.book_id << endl;

  //veri yapısını fonksiyon içinde kullanmak
  printBook(Book1);

  //ZAMAN VE DATE KULLANIMI
  time_t now = time(0);
  tm * gmtm = gmtime( & now);
  // convert now to string form
  char * dt = ctime( & now);

  dt = asctime(gmtm);
  cout << "The UTC date and time is:" << dt << endl;

  return 0;
}
