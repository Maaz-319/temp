#include <iostream>
#include <iomanip>

using namespace std;

void parsePacket(const unsigned char *buffer)
{
    cout << "Packet Type: 0x" << hex << setw(4) << setfill('0') << ((buffer[0] << 8) | buffer[1]);

    cout << "\nTimestamp: " << dec << ((buffer[2] << 24) | (buffer[3] << 16) | (buffer[4] << 8) | (buffer[5]));

    cout << "\nPayload: ";
    for (int i = 6; i < 14; i++)
    {
        cout << hex << setw(2) << setfill('0') << (int)buffer[i] << " ";
    }
    cout << endl;
}

int main()
{
    unsigned char buffer[14] = {0x01, 0x02, 0x00, 0x00, 0x00, 0x10, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22};
    parsePacket(buffer);
    return 0;
}