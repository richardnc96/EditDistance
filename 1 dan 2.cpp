#include <iostream>
#include <fstream>
#include <string>
#include <locale> // locale, tolower

using namespace std;

//tolower blom
//frequensi blom
//menghilngkan tanda baca blom

int main () {
  const int ukuran = 50;
  int a= 0;
  string array[ukuran];
  string line;
  ifstream data("dataku.txt");//baca file
  if (data.is_open())
  {
    while(!data.eof())
    {
       istream & getline(data >> line);
       array[a] = line;
       cout << array[a] << endl;
       a++;
    }
    
    data.close();
  }
  else cout << "Unable to open file"; 


  return 0;
}


