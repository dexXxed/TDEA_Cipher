#include <iostream>
#include "3des.h"

int main()
{
    char key[] = "12345678901234567890";
    char text[] = "1a2b3c4d5e6f7g";

    DES3_Cipher d3(key); 
    std::cout << "Key used in TDEA: " << key << std::endl;
    std::cout << "Text to be encrypted/decrypted: " << text << std::endl << std::endl;

    auto ff = d3.encrypt(text);
    std::cout << "Encrypted text: " << ff << std::endl;

    auto ok_ff = d3.decrypt(ff);
    std::cout << "Decrypted text: " << ok_ff << std::endl;

    return 0;
}