#pragma once
#include <string>
#include <vector>

using namespace std;

class Spot {
    private:
        string name;
        string path;
        string image_url;
        vector<string> tags;
    public:
        Spot();
        Spot(string name, string path, vector<string> tags);
        Spot(string name, string path, string image_url, vector<string> tags);
        string getInfoTbl();
        string getName() { return name; }
        string getPath() { return path; }
        string getImageUrl() { return image_url; }
        vector<string> getTags() { return tags; }
};