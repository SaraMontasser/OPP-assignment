#ifndef OOP_ASSIGNMENT_ECPRIFRAME_H
#define OOP_ASSIGNMENT_ECPRIFRAME_H

#include "packets.h"

class ecpriFrame : public packets {
public:
    ecpriFrame(string x);

    void print(int packetNumber, ofstream &outputFile);

    string getPacketConcatenationIndicator();

    string getPacketMessageType();

    string getPacketPayloadSize();

    string getPacketProtocolVersion();

    string getPacketRTCID();

    string getPacketSequenceID();
};


#endif //OOP_ASSIGNMENT_ECPRIFRAME_H
