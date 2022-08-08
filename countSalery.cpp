#include <iostream>
using std::cout;
using std::endl;
using std::cerr;
#include <fstream>
using  std::fstream;
using std::ifstream;
using std::ofstream;
#include <string>
using std::string;


// Computes total salary;
double processEmp(ifstream&, ofstream&); 

int main(){

   ifstream in_put{"Emp.txt"}; // input:  employee data stream
   ofstream out_put{"payroll.txt"}; // output: employee payroll data stream
 
    if(!in_put){
      cerr << "!!! ERROR!!! Could not input the data." << endl;
      return -1;
    }
    if(!out_put){
      cerr << "!!! ERROR!!! Could output the data." << endl;
      return -1;
    }


    double totalPayroll = processEmp(in_put, out_put);
    // display 
    cout << "Total payroll is " << totalPayroll << "kr." << endl;


    // Close the files 
    in_put.close();
    out_put.close();
    // new line 
    cout << endl;
    cout << "Done!" << endl;
    return 0;
}

// implement function here
double processEmp(ifstream &in_put, ofstream &out_put){
    cout << "*********************************************************" << endl;
    string first_name{}; // Emp name
    string last_name{}; //  Emp last_name
    double hours{0.0}; // Hours worked
    double rate{0.0}; // hourly rate
    double salary{0.0}; // gross salary
    double payroll{0.0}; // return value, total company payroll
    // Reading first emp data record
    in_put >> first_name >> last_name >> hours >> rate;
    while (!in_put.eof()){
     /* code */
    salary = rate * hours;
    out_put << first_name << " " << last_name << " " <<  salary << endl;
    payroll += salary;
    // Read next employee data
    in_put >> first_name >> last_name >> hours >> rate;
    }
  // return total payroll
  return payroll;

} 