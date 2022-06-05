#include <string>
using namespace std;

class Constants
{
private:
    /* data */
    Constants(/* args */);
    ~Constants();
public:
    static string getSSID(){return "";}
    static string getPassword() { return ""; }
    static string getServerName() { return ""; }
};

Constants::Constants(/* args */)
{
}

Constants::~Constants()
{
}
