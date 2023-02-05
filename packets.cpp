#include "packets.h"
#include <iostream>
#include <string>
#include <fstream>

#define typeStartPosition 40
#define typeSize 4
#define CRCSize 8
#define DestinationAddressStartPosition 16
#define DestinationAddressSize 12
#define SourceAddressStartPosition 28
#define SourceAddressSize 12
#define lineSize 230
using namespace std;

packets::packets(string packetData) {
    this->packetData = packetData;
}

string packets::getPacketData() {
    return packetData;
}

string packets::getPacketType() {
    return packetData.substr(typeStartPosition, typeSize);
}

string packets::getPacketCRC() {
    int packetDataSize = getPacketDataSize();
    return packetData.substr(packetDataSize - CRCSize, CRCSize);
}

string packets::getPacketDestinationAddress() {
    return packetData.substr(DestinationAddressStartPosition, DestinationAddressSize);
}

string packets::getPacketSourceAddress() {
    return packetData.substr(SourceAddressStartPosition, SourceAddressSize);
}

int packets::getPacketDataSize() {
    return packetData.size();
}

void packets::printAsteriskLine(ofstream &outputFile) {
    for (int i = 0; i < lineSize; ++i) {
        outputFile << '*';
    }
    outputFile << '\n';
}

void packets::print(int packetNumber, ofstream &outputFile) {

}
