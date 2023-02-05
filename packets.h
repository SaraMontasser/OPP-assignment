#ifndef OOP_ASSIGNMENT_PACKETS_H
#define OOP_ASSIGNMENT_PACKETS_H

#include <string>

using namespace std;

class packets {
private:
    string packetData;
public:
    packets(string packetData);

    virtual void print(int packetNumber, ofstream &outputFile);

    void printAsteriskLine(ofstream &outputFile);

    string getPacketData();

    string getPacketType();

    string getPacketCRC();

    string getPacketDestinationAddress();

    string getPacketSourceAddress();

    int getPacketDataSize();
};


#endif //OOP_ASSIGNMENT_PACKETS_H
