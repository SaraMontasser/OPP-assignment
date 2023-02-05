#include "ecpriFrame.h"
#include <iostream>
#include <fstream>

#define protocolVersionStartPosition 44
#define protocolVersionSize 1
#define concatenationIndicatorStartPosition 45
#define concatenationIndicatorSize 1
#define messageTypeStartPosition 46
#define messageTypeSize 2
#define payloadSizeStartPosition 48
#define payloadSizeBitsNumber 4
#define RTCIDStartPosition 52
#define RTCIDSize 4
#define sequenceIDStartPosition 56
#define sequenceIDSize 4
using namespace std;

void ecpriFrame::print(int packetNumber, ofstream &outputFile) {
    outputFile << "Packet # " << packetNumber << ":" << '\n';
    outputFile << getPacketData() << '\n';
    outputFile << "CRC: " << getPacketCRC() << '\n';
    outputFile << "Concatenation Indicator: " << getPacketConcatenationIndicator() << '\n';
    outputFile << "Destination Address: " << getPacketDestinationAddress() << '\n';
    outputFile << "Message Type: " << getPacketMessageType() << '\n';
    outputFile << "Payload Size: " << getPacketPayloadSize() << '\n';
    outputFile << "Protocol Version: " << getPacketProtocolVersion() << '\n';
    outputFile << "RTC ID: " << getPacketRTCID() << '\n';
    outputFile << "Sequence ID: " << getPacketSequenceID() << '\n';
    outputFile << "Source Address: " << getPacketSourceAddress() << '\n';
    outputFile << "Type: " << getPacketType() << '\n';
    printAsteriskLine(outputFile);
}

string ecpriFrame::getPacketConcatenationIndicator() {
    string packetData = getPacketData();
    return packetData.substr(concatenationIndicatorStartPosition, concatenationIndicatorSize);
}

string ecpriFrame::getPacketMessageType() {
    string packetData = getPacketData();
    return packetData.substr(messageTypeStartPosition, messageTypeSize);
}

string ecpriFrame::getPacketPayloadSize() {
    string packetData = getPacketData();
    return packetData.substr(payloadSizeStartPosition, payloadSizeBitsNumber);
}

string ecpriFrame::getPacketProtocolVersion() {
    string packetData = getPacketData();
    return packetData.substr(protocolVersionStartPosition, protocolVersionSize);
}

string ecpriFrame::getPacketRTCID() {
    string packetData = getPacketData();
    return packetData.substr(RTCIDStartPosition, RTCIDSize);
}

string ecpriFrame::getPacketSequenceID() {
    string packetData = getPacketData();
    return packetData.substr(sequenceIDStartPosition, sequenceIDSize);
}

ecpriFrame::ecpriFrame(string x) : packets(x) {

}
