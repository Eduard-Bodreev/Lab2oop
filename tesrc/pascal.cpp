#include "pascal.hpp"

Types Limacon::getType() const{
    if(_a == 0 && _l == 0){
        return Types::point;
    }
    else if(_a == 0 || _l == 0){
        return Types::circle;
    }
    if(_a == _l){
        return Types::cardioid;
    }
    else if(_a > _l){
        return Types::looped;
    }
    else if(_l >= 2*_a){
        return Types::oval;
    }
    else{
        return Types::kinked;
    }
}

double Limacon::getArea() const{
    return pi * (0.5*_a*_a + _l*_l);
//    else if(getType() == Types::kinked || getType() == Types::oval){
//        return pi * (0.5*_a*_a + _l*_l);
//    }
//    else if(getType() == Types::cardioid){
//        return 1.5 * pi * _a * _a;
//    }
//    return (_a*_a / 2 + _l*_l) * (acos(-_l/_a) + acos(_l/_a)) + 3.0*_l*sqrt(_a*_a - _l*_l);
}

std::vector<double> Limacon::getCurvativeRadius() const{
    std::vector<double> ans;
    if(getType() == Types::looped){
        ans.push_back(0.5 * sqrt(_a*_a - _l*_l));
        ans.push_back(pow(_l-_a, 2) / fabs(_l - 2*_a));
        ans.push_back(pow(_l+_a, 2) / (_l + 2*_a));
    }
    else if(getType() == Types::cardioid){
        ans.push_back(pow(_l-_a, 2) / fabs(_l - 2*_a));
        ans.push_back(pow(_l+_a, 2) / (_l + 2*_a));
    }
    else if(getType() == Types::kinked){
        ans.push_back(pow(_l-_a, 2) / fabs(_l - 2*_a));
        ans.push_back(pow(_l+_a, 2) / (_l + 2*_a));
    }
    else if(getType() == Types::oval){
        if(_a == 2*_l){
        ans.push_back(pow(_l+_a, 2) / (_l + 2*_a));
        }
        ans.push_back(pow(_l-_a, 2) / fabs(_l - 2*_a));
    }
    else if(getType() == Types::circle){
        ans.push_back(_a + _l);
    }
    return ans;
}

char* Limacon::getText() const { 
    std::string x = "(x^2 + y^2 ";
    if(_a > 0){
        x += "- " + std::to_string(_a) + " * x)^2 = ";
    }
    else if(_a == 0.0){
        x += ")^2 = ";
    }
    else{
        x += "+ " + std::to_string(-_a) + " * x)^2 = ";
    }
    if(_l != 0.0){
        x+= std::to_string(_l*_l) + "*(x^2 + y^2)"; 
    }
    else{
        x+= "0";
    }
    int len = x.size();
    char* ans = new char [len+1];
    ans[len] = '\0';
    std::cout << x << std::endl;
    std::copy(x.begin(), x.end(), ans);
    return ans;

}

std::string toString(Types t){
    switch(t){
        case Types::point:
            return "point";
        case Types::looped:
            return  "looped";
        case Types::cardioid:
            return "cardioid";
        case Types::kinked:
            return "kinked";
        case Types::oval:
            return "oval";
        case Types::circle:
            return "circle";
    }
}

std::ostream& operator<<(std::ostream& out,const Limacon& l){
    char* ch = l.getText();
    for(char* c = ch; *c!='\0'; c++){
        out << *c;    
    }
    delete[] ch;
    return out;
}
