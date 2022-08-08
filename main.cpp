#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::cerr;
#include <string>
using std::string;
#include <vector>
using std::vector;



unsigned int copyLine(ifstream &in_file, ofstream &outfile){
     const char newLine{'\n'};
     char next_char;
     unsigned int count_chars{0};
     in_file.get(next_char); // get first char
     while((next_char != newLine) && !in_file.eof()){
        outfile.put(next_char); // write to the new file
        in_file.get(next_char); // read next char
        ++count_chars;  // increment the count
     }

     if(!in_file.eof()){
       outfile.put(newLine);
       ++count_chars;
     }

     return count_chars;
}
int main(){

    ifstream in_file{"InData.txt"}; // input stream 
    ofstream out_file{"outData.txt"}; // output stream
    if(!in_file){
      cerr << "!!! ERROR!!! Could not input the data." << endl;
      return -1;
    }
    if(!out_file){
      cerr << "!!! ERROR!!! Could output the data." << endl;
      return -1;
    }
    unsigned int lineCount{1};
    unsigned int charachters{0};
    /*
    while(!in_file.eof()){
     if((charachters+=copyLine(in_file, out_file)) != 0){
        ++lineCount;
      }
    }


    */
     vector<char> vecCha;
     string getlines;
     getline(in_file, getlines);
     while(!in_file.eof()){
        lineCount++;
        charachters+= getlines.length();
        out_file << getlines << endl;
        getline(in_file, getlines);
     }
      getline(in_file, getlines);
             charachters+= getlines.length();
      out_file << getlines << endl;
    cout << "Input file has been copied to output file." << endl;
    cout << lineCount << " line copied." << endl;
    std::cout << "There are " <<charachters << " charachters."<< endl;

    cout << "Done!";
    // close the files
    in_file.close();
    out_file.close();

    return 0;
}