#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include<algorithm>

int main(int argc, char* argv[]){
    
    //Need to specify input file as a command line argument.
    if(argc != 2){
        std::cout << "Need to specify input file as command line argument" << std::endl;
        std::cout << "Usage:./program [input file]" << std::endl;
    } else {
        //Ensuring that the command line input is a string should be checked here.
        std::ifstream ifs;
        ifs.open(argv[1], std::ifstream::in);

        if(ifs.good()){
            //Iterate through each line of the file.
            std::string line;
            for(int i = 0; std::getline(ifs,line); i++){
                if(i == 0) continue; // Skip the number of test cases as it's redundant.
                    //Get the string containing all the numbers for the first vector.
                    std::string vector1;
                    std::getline(ifs,vector1);
                    //Get the string containing all the numbers for the second vector.
                    std::string vector2;
                    std::getline(ifs,vector2);

                    //Constructing the first vector of numbers.
                    std::stringstream stream1(vector1);
                    long long getNum1 = 0;
                    std::vector<long long> firstVector;
                    while(stream1 >> getNum1){
                        firstVector.push_back(getNum1);
                    }

                    std::sort(firstVector.begin(), firstVector.end());

                    //Constructing the second vector of numbers.
                    std::stringstream stream2(vector2);
                    std::vector<long long> secondVector;
                    long long getNum2 = 0;
                    while(stream2 >> getNum2){
                        secondVector.push_back(getNum2);
                    }

                    //Reverse Sort.
                    std::sort(secondVector.begin(), secondVector.end(), std::greater<long long>());

                    long long minScalProd = 0;
                    std::vector<long long>::iterator firstIt = firstVector.begin();
                    std::vector<long long>::iterator secondIt = secondVector.begin();
                    while(firstIt != firstVector.end()){
                        minScalProd += (*firstIt)*(*secondIt);
                
                        firstIt++;  
                        secondIt++;
                    }
                    std::cout << "Case #" << i << ": ";
                    std::cout <<minScalProd << std::endl;
            }

        } else {
            std::cout << "Error file couldn't be opened" << std::endl;
        }
        ifs.close();
    }

    return 0;
}

