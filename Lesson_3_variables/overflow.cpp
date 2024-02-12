#include <iostream>

int main(){
    unsigned short unsignedShort = 65535;
    std::cout << "Incrementing unsigned short " << unsignedShort << " gives: ";
    std::cout << ++unsignedShort << std::endl;

    short signedShort = 32767;
    std::cout << "Incrementing signed short " << signedShort << " gives: ";
    std::cout << ++signedShort << std::endl;

    return 0;
}

// Incrementing unsigned short 65535 gives: 0
// Incrementing signed short 32767 gives: -32768