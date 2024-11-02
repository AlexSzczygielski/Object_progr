#include <iostream>

#define OCT_1 (0x000000FF)
#define OCT_2 (0x0000FF00)
#define OCT_3 (0x00FF0000)
#define OCT_4 (0xFF000000)

class IP{
    unsigned int m_ip_addr;

    public:
        unsigned int getIp_addr() const {return m_ip_addr;}
        void setIp_addr(unsigned int ip) {m_ip_addr = ip;}
};

std::ostream& operator<<(std::ostream& out, IP& address){
    out << ((address.getIp_addr() & OCT_4) >> 24) << ".";
    out << ((address.getIp_addr() & OCT_3) >> 16) << ".";
    out << ((address.getIp_addr() & OCT_2) >> 8) << ".";
    out << (address.getIp_addr() & OCT_1);
    return out;
}

int main(){
    IP ip_1;
    ip_1.setIp_addr(0xFFFFFFFF);
    std::cout << ip_1 << "\n";

    ip_1.setIp_addr(0xC0A80001);
    std::cout << ip_1;
}