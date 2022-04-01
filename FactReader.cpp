#include<iostream>
#include<fstream>
#include<tuple>
#include<vector>
using namespace std;

vector <tuple <int, int, double>> TupleFromFile(string Filename) {
    ifstream FactIS;
    FactIS.open(Filename);
    vector <tuple <int, int, double>> facts;
    int r, l;
    double d;
    while (!FactIS.fail()) {
        FactIS >> r >> l >> d;
        facts.push_back(make_tuple(r, l, d));
        //cout << get<0>(fact) << " " << get<1>(fact) << " " << get<2>(fact) << endl;
    }
    return facts;
    
}

void WriteinProlog(vector <tuple <int, int, double>> facts, string Filename) {
    ofstream FactOS;
    FactOS.open(Filename, std::ios_base::app);

    ifstream initS;
    initS.open("init.txt");
    string line;
    while(getline(initS, line)) {
        FactOS << line << endl;
    }

    FactOS << endl << endl;
    for (int i = 0; i < facts.size() - 1; i++) {
        FactOS << "merge(" << get<0>(facts.at(i)) << ", " << get<1>(facts.at(i)) <<  ", " << get<2>(facts.at(i)) << ")." << endl;
    }
}

int main() {
    WriteinProlog(TupleFromFile("fact.txt"), "facts.pl");
}