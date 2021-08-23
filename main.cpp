#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cctype>


int main() {
   std::ifstream in_file;
   std::string line;
   std::string code;//The answer...
   std::string name;
   int count{0};
   int grade {0};
   int  runningsum{0};
   std::vector<std::string> students;
   std::vector<std::string> options;
   std::vector<int> scores;
   
   in_file.open("quiz.txt");
   
   if(!in_file){
       std::cerr<<"Error opening file"<<std::endl;
       return 1;
   }
   
 in_file>>code;
    std::cout<<"Correct Answer: "<<code<<std::endl;




while(in_file>>line){
    size_t i = line.length();
    
    for(size_t j {0}; j < i; j ++){
        if( islower(line[j])){
        students.push_back(line);
        count++;
          break;
        }
    } 
    
    if(count==0){
        options.push_back(line);
    }
    count = 0;
}
  
   

       for(auto response: options){
           size_t i = response.length();
           for(size_t j {0}; j<i; j++){
               if( code[j] == response[j]){
                   grade++;
               }
           }
           scores.push_back(grade);
           runningsum+=grade;
           grade = 0;
       }
   

   std::cout<<std::setw(10)<<std::left<<"Students"<<std::setw(10)<<std::left<<"Choices"<<"Grades\n---------------------------------\n";
   size_t toll = students.size();
   for(size_t i {0}; i<toll; i++){
   std::cout<<std::setw(10)<<std::left<<students.at(i)<<std::setw(10)<<std::left<<options.at(i)<<std::setw(10)<<std::left<<scores.at(i)<<std::endl;
   }
   
   double average =static_cast<double>( runningsum)/students.size();
   std::cout<<"---------------------------------\n";
   std::cout<<std::setw(20)<<std::left<<"Average"<<average<<std::endl;
   in_file.close();
    return 0;
}