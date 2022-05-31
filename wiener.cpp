#define _USE_MATH_DEFINES
#include <vector>
#include <iostream>
#include <iomanip>
#include <random>
#include <fstream>
#include <cmath>

class nah_traj {
private:
    std::vector<double> x;
    std::vector<double> y;
public:
    nah_traj() {};
    nah_traj(std::vector<double> numX, std::vector<double> numY) { x = numX; y = numY; }
    std::vector<double> get_x() { return x; }
    std::vector<double> get_y() { return y; }
};

int main() {
    srand((unsigned)time(NULL));
    int poc_t = 10000;
    int N = 1000;
    double T = 1, pomoc;
    std::vector<double> time;
    std::vector<nah_traj> Tr;

    time.push_back(0);
    for (int i = 1; i < N; i++) {
        pomoc = time[i - 1] + (T / (N));
        time.push_back(pomoc);
    }
    for (int i = 0; i < poc_t; i++) {
        std::vector<double> vect;
        nah_traj TR1;
        double pomoc2 = 0;
        for (int i = 0; i < time.size(); i++) {
            double v1 = ((double)(rand()) + 1.) / ((double)(RAND_MAX)+1.);
            double v2 = ((double)(rand()) + 1.) / ((double)(RAND_MAX)+1.);
            vect.push_back(pomoc2);
            pomoc2 = pomoc2 + sqrt(T / (N)) * cos(2 * M_PI * v2) * sqrt(-2. * log(v1));
        }
        nah_traj Point(time, vect);
        TR1 = Point;
        Tr.push_back(TR1);
    }

    std::fstream vypis;
    vypis.open("celok.txt", std::ios::out);
    if (vypis.is_open()) {
        vypis << "x,y,typ,farba" << std::endl;
        for (int i = 0; i < poc_t; i++) {
            for (int j = 0; j < Tr.at(i).get_x().size(); j++) {
                vypis << Tr.at(i).get_x().at(j) << "," << Tr.at(i).get_y().at(j) << "," << i << ",";
                if (Tr.at(i).get_y().at(2) > 0.002 && Tr.at(i).get_y().at(3) < 0.002)
                    vypis << 0 << std::endl;
                else
                    vypis << 1 << std::endl;
            }
        }
        vypis.close();
    }
}
