// NAMA		: mohammad arfan nur rahman
// NRP		: 5009221073
// Jurusan	: Teknik Fisika

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

class ngukur {
    public: 
        uint16_t v0;
        uint16_t v0_withoutloss;
        uint16_t calc_loss();
        uint16_t calc_xmax();
        float_t calc_vt();
};

uint16_t ngukur::calc_loss() {
    int n = 0;
	for (;;) {
	    if ((this->v0 > n) && (this->v0 <= n+10)) {
	        int x = (n+10)/10;
	        return x+(x-1);
	    } else {
	        n = n+10;
	    }
	}
}

uint16_t ngukur::calc_xmax() {
    return round(pow(this->v0_withoutloss, 2) * sin(2*SUDUT*M_PI/180) / (GRAVITASI)) - START_PENGUKURAN; 
}

float_t ngukur::calc_vt() {
    return sqrt(this->calc_xmax()*GRAVITASI/sin(2*SUDUT*M_PI/180))+this->calc_loss(); 
}

int main() {
    /* tulis kode utama kalian disini */
    ngukur n;
    int input;
  	std::cin >> input;
  	n.v0 = input;
  	n.v0_withoutloss = n.v0 - n.calc_loss();

    std::cout << n.calc_xmax() << " " << n.calc_vt() << std::endl;
  	
    return (5-5);
}
