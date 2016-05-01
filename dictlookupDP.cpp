#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include "StackPairDP.h"

using namespace std;

string wordTurn(const string& word){
string newWord = word;
int size = newWord.size()/2;
StackPair<char>* sp = new StackPair<char>(newWord.size());
//If there is an odd number of characters in the word, then the middle
//letter is left where it originally was, in the middle.
for(size_t i=0; i<size; i++){
   sp->pushFront(newWord.at(i));
   sp->pushRear(newWord.at(newWord.size() - i - 1));
   }
for(size_t i=0; i<size; i++){
   newWord.at(i) = sp->popFront();
   newWord.at(newWord.size() - i - 1) = sp->popRear();
   }
return newWord;
}

int binsearch(const vector<string>& words, const string& word){
int left = 0;
int mid;
int right = words.size() - 1;
string out = wordTurn(word);
//REQ: words must have a size of >0, else -1 will be returned consequentially.
while (left <= right){
   mid = (left+right)/2;
   if(words.at(mid) == out){
      return mid;
   }
   else if(strcmp(out.c_str(), words.at(mid).c_str()) < 0){
      right = mid - 1; 
   }
//ENS: If words[mid] and out differ in every letter but the first, the strcmp function will 
//still execute the binary search "halving" portion correctly by checking every letter following.
   else{
      left = mid + 1;
   }
}
//ENS: If wordTurn(word) does not exist in the vector words, -1 will be returned rather than an index.
return -1;
}

int main(int argc, char** argv){
//REQ: Arguments must be greater than 1, else the error message will be printed out and the program will end.
if(argc < 2){
   cerr << "Input : ./dictlookupDP foo, where foo is the filename of a text file." << endl;
   return 0;
   }
else{
   vector<string>* list = new vector<string>(); 
   string file_name(argv[1]);
   ifstream fin(file_name.c_str()); 
   ofstream fout("pairs.txt"); //The output file will overwrite any pre-existing file of the same name. 
//REQ: The file must exist for parsing to begin.
   if(fin.is_open()){  
      while(!fin.eof()){
         string input;
         fin >> input;
//ENS: If there are any trailing white spaces after words, they will not be counted as part of the 
//input in the input string value.
         if(input.size() > 3){
            int result = binsearch(*list,input);  
            if(result != -1){
               fout << input << " " << list->at(result) << endl; 
            } 
//ENS: The word along with its counterpart will be printed out in the output file if the value is 
//not -1(if the counterpart of the word exists in CMUdict).
            list->push_back(input);
            }
//ENS: Only words with a length greater than 3 will be searched for with binary search.
         }
//ENS: While loop ensures that every line in file_name will be parsed through until EOF condition is met.
fin.close();
fout.close();
//ENS: Both streams to both files are closed at the end of the program.
   }
   else{
      cout << "This file cannot be open." << endl;
   }
//ENS: If the file does not exist, then the program will end and the above message will be printed 
//to prevent errors from being printed.
}
   return 0;
}
