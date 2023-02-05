#include "rawEthernet.h"
#include <iostream>
#include <fstream>

using namespace std;

void rawEthernet::print(int packetNumber, ofstream &outputFile) {
    outputFile << "Packet # " << packetNumber << ":" << '\n';
    outputFile << getPacketData() << '\n';
    outputFile << "CRC: " << getPacketCRC() << '\n';
    outputFile << "Destination Address: " << getPacketDestinationAddress() << '\n';
    outputFile << "Source Address: " << getPacketSourceAddress() << '\n';
    outputFile << "Type: " << getPacketType() << '\n';
    printAsteriskLine(outputFile);

}

rawEthernet::rawEthernet(string x) : packets(x) {

}
