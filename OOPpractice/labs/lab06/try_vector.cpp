#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either statement. We wouldn't be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   v.push_back(45);
   v.push_back(18);
   stdv.push_back(20);
   stdv.push_back(12);
   stdv.push_back(14);

   cout << "Our vector size: " << v.size() << endl;
   cout << "STL vector size: " << stdv.size() << endl;

   v.print_array();
   cout << "v[0] test....: " << v[0] << endl;
   cout << "Testing at function" << v.at(0) << endl;


    


   return 0;
}