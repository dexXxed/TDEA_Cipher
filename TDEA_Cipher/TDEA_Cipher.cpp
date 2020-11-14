#include <iostream>
#include <string.h>
#include "3des.h"

int main()
{
    char key[] = "12345678901234567890";
    char text[] = "1a2b3c4d5e6f7g2387937894724897892704878945689479082094748957204894853097304983049";

    DES3_Cipher d3(key); 
    std::cout << "Key used in TDEA: " << key << std::endl;
    std::cout << "Text to be encrypted/decrypted: " << text << std::endl << std::endl;
   
    std::string ff = d3.encrypt(text);
    std::cout << "Encrypted text: " << ff << std::endl << std::endl;
    // в CBC-MAC
    // В качестве MAC берётся последний блок сообщения зашифрованного блочным алгоритмом в режимах CBC или СFB.
    std::cout << "MAC in next line: " << std::endl;

    for (int i = (ff.size() / 32) * 32; i < ff.size(); i++)
        std::cout << ff[i];

    auto ok_ff = d3.decrypt(ff);
    std::cout << std::endl << "Decrypted text: " << ok_ff << std::endl;

    return 0;
}