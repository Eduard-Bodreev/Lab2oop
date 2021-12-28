// sarkoxed //

#include "pascal.hpp"
#include <iostream>

void help(){
    std::cout << "0 to create empty curve" << std::endl;
    std::cout << "1 to create curve with your parameters" << std::endl;
    std::cout << "2 to get a" << std::endl;
    std::cout << "3 to get l" << std::endl;
    std::cout << "4 to set a" << std::endl;
    std::cout << "5 to set l" << std::endl;
    std::cout << "6 to get dist" << std::endl;
    std::cout << "7 to get curvative radius" << std::endl;
    std::cout << "8 to get type" << std::endl;
    std::cout << "9 to get polar area" << std::endl;
    std::cout << "10 to get char form" << std::endl;
    std::cout << "11 to exit" << std::endl;
    std::cout << "12 to get help" << std::endl;
}


int main(){
    Limacon li;
    double a, l;
    int choice;
    help();
    while(true){
        std::cout << "What shall i do?: ";
        std::cin >> choice;
        switch(choice){
            case 0:
                {
                    Limacon k;
                    std::cout << "Here\'s your curve: " << k << std::endl;
                    break;
                }
            case 1:
                {
                    std::cout << "a: ";
                    std::cin >> a;
                    std::cout << "l: ";
                    std::cin >> l;
                    try{
                        Limacon tmp(a, l);
                        std::cout << "Here\'s your curve: " << tmp << std::endl;
                    }
                    catch(const std::exception& e){
                        std::cerr << e.what() << std::endl;
                    }
                    break;
                }
            case 2:
                std::cout << "a: " << li.getA() << std::endl;
                break;
            case 3:
                std::cout << "l: " << li.getL() << std::endl;
                break;
            case 4:
                {
                    std::cout << "a: ";
                    std::cin >> a;
                    std::cout << "Here\'s your curve before: " << li << std::endl;
                    try{
                        li.setA(a);
                        std::cout << "Here\'s your curve: " << li << std::endl;
                    }
                    catch(const std::exception& e){
                        std::cerr << e.what() << std::endl;
                    }

                    break;
                }
            case 5:
                {
                    std::cout << "l: ";
                    std::cin >> l;
                    std::cout << "Here\'s your curve before: " << li << std::endl;
                    try{
                        li.setL(l);
                        std::cout << "Here\'s your curve: " << li << std::endl;
                    }
                    catch(const std::exception& e){
                        std::cerr << e.what() << std::endl;
                    }


                    break;
                } 
            case 6:
                {
                    double phi;
                    std::cout << "phi: ";
                    std::cin >> phi;
                    std::cout << "Dist: " << li.getCentDist(phi) << std::endl;
                }
                break;
            case 7:
                {
                    std::vector<double> ans = li.getCurvativeRadius();  
                    for(auto i: ans){
                        std::cout << i << std::endl;
                    }
                    break;
                }
            case 8:
                std::cout << toString(li.getType()) << std::endl;
                break;
            case 9:
                std::cout << "Area: " << li.getArea() << std::endl;
                break;
            case 10:
                std::cout << "Here\'s your Limacon: " << li << std::endl;
                break;
            case 11:
                exit(0);
            case 12:
                help();
                break;
            default:
                break;
        }
    }
}
