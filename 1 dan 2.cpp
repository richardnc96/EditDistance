#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <algorithm> 

using namespace std;

//frequensi blom

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
       transform(line.begin(),line.end(),line.begin(), ::tolower);//tolower
       line.erase(remove_if(line.begin(),line.end(), ::ispunct ), line.end());//punctuation 
	   array[a] = line;
       cout << array[a] << endl;
       a++;
    }
    
    data.close();
  }
  else cout << "Unable to open file"; 


  return 0;
}


