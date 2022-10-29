#include "matplotcpp.h"
#include <iostream>
#include <fstream>

namespace plt = matplotlibcpp;
using namespace std;

vector<double> get_wavelength_data(ifstream& inFS){
    //Takes an iftream by reference as input an returns a vector containing 
    //wavelength data. Specifically for "Vertical0275.ISD" from LAB07. 
    inFS.clear();
    inFS.seekg(ios::beg);


    string line;
    double w= 0.0;
    double p= 0.0;

    vector<double> w1;

    while(getline(inFS, line)){
        if(line.substr(0,6) == "Y-Unit"){
            break;
        }
    }

    getline(inFS, line);

    while(inFS.eof() == false){
        inFS >> w; 
        if (inFS.fail() == 1){
            break;
        }
        inFS >> p;

        w1.push_back(w);
    }
    
    return w1;
}
vector<double> get_power_data(ifstream& inFS){
    //Takes an iftream by reference as input an returns a vector containing 
    //power data. Specifically for "Vertical0275.ISD" from LAB07.
    inFS.clear();
    inFS.seekg(ios::beg);


    string line;
    double w= 0.0;
    double p= 0.0;

    vector<double> w2;

    while(getline(inFS, line)){
        if(line.substr(0,6) == "Y-Unit"){
            break;
        }
    }

    getline(inFS, line);

    while(inFS.eof() == false){
        inFS >> w; 
        if (inFS.fail() == 1){
            break;
        }
        inFS >> p;

        w2.push_back(p);
    }
    
    return w2;
}

int main(){
    vector<double> x; 
    vector<double> y;

    ifstream inF;
    inF.open("Vertical0275.ISD");

    x = get_wavelength_data(inF);
   
    y = get_power_data(inF);


    plt::figure();
    plt::plot(x,y, "bo-", {{"label", "data trend"}});
    plt::xlabel("wavelength");
    plt::ylabel("power");
    plt::title("wavelength vs. power graph");

    plt::legend();
    plt::show();

    return 0;

    
}