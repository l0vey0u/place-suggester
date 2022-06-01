#include <fstream>
#include <iostream>

struct Spot {
    string name;
    string path;
    string image_url;
    string[] tags;
};

using namespace std;
class DataParser {
    private:
        ifstream spotDataStream;
        Spot* parseFormattedSpot(string condition);
    public:
        Spot*[] getSpotListFromFile();
}