#include "spot.h"

Spot::Spot()
{
    name = "";
    path = "";
    image_url = "";
    tags = {};
}
Spot::Spot(string name, string path, vector<string> tags)
{
    Spot(name, path, "", tags);
}
Spot::Spot(string name, string path, string image_url, vector<string> tags)
{
    this->name = name;
    this->path = path;
    this->image_url = image_url;
    this->tags = tags;
}
string Spot::getInfoTbl() {
    string infoTbl = "";
    infoTbl += name + ",";
    infoTbl += path + ",";
    infoTbl += image_url + ",";
    for (string tag : tags) {
        infoTbl += tag + " ";
    }
    return infoTbl;
}
