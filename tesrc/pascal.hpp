#pragma once

#include <cmath>
#include <vector>
#include <iostream>
#include <string>

enum class Types: short{
    looped,
    cardioid,
    kinked,
    oval,
    point,
    circle
};

const double pi = 3.141592653589793;

class Limacon{
    private:
        double _a;
        double _l;
    public:
        explicit Limacon(double a = 0.0, double l = 0.0){
            if(a < 0.0 || l < 0.0){
                throw std::invalid_argument("no negative allowed");
            }
            _a =a;
            _l = l;
        }

        double getA() const {return _a;}
        double getL() const {return _l;}

        void setA(double a){ 
            if(a < 0.0){
                throw std::invalid_argument("no negative allowed");
            }
            _a = a; }
        void setL(double l){
            if(l < 0.0){
                throw std::invalid_argument("no negative allowed");
            }
            _l = l; }

        double getCentDist(double phi) const { return _l +  _a * cos(phi);}
        
        Types getType() const;

        std::vector<double> getCurvativeRadius() const;

        double getArea() const;
        
        char* getText() const;
        
        friend std::ostream& operator<<(std::ostream& out,const Limacon& l);

        ~Limacon() = default;
        
        
};

std::string toString(Types t);
