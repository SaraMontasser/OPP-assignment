#include <iostream>
#include <string>
#include <fstream>
#include "packets.h"
#include "ecpriFrame.h"
#include "rawEthernet.h"

#define inputFileName "input_packets"
#define outputFileName "output_packets"
using namespace std;

bool createOutputFile() {
    fstream outputFile;
    outputFile.open(outputFileName, ios::out);
    if (!outputFile) {
        outputFile.close();
        return 0;
    }
    outputFile.close();
    return 1;
}

int main() {
    fstream inputFile;
    inputFile.open(inputFileName, ios::in);
    if (!inputFile) {
        cout << "No such input file";
    } else {
        if (createOutputFile()) {
            ofstream outputFile(outputFileName);
            if (outputFile.is_open()) {
                string packet;
                int packetNumber = 0;
                packets *packetdata;
                while (!inputFile.eof()) {
                    inputFile >> packet;
                    packetdata = new packets(packet);
                    if (packetdata->getPacketType() == "AEFE") {
                        ecpriFrame ecpriPacket(packet);
                        packetdata = &ecpriPacket;
                        packetdata->print(packetNumber, outputFile);
                    } else {
                        rawEthernet rawEthernetPacket(packet);
                        packetdata = &rawEthernetPacket;
                        packetdata->print(packetNumber, outputFile);
                    }
                    ++packetNumber;
                }
            } else {
                cout << "No such output file";
            }
            outputFile.close();
        }
    }
    inputFile.close();


    return 0;
}
