#ifndef OOP_ASSIGNMENT_RAWETHERNET_H
#define OOP_ASSIGNMENT_RAWETHERNET_H

#include "packets.h"

class rawEthernet : public packets {
public:
    rawEthernet(string x);

    void print(int packetNumber, ofstream &outputFile);
};


#endif //OOP_ASSIGNMENT_RAWETHERNET_H
