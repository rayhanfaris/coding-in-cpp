#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//rumus haversine
// a = sin^2(perbedaan latitude/2) + cos(altitude1) + cos(altitude2) + sin^2(perbedaan longitude/2)
// c = 2*arctan2(sqrt(a), sqrt(1-a))
// d = R * c * 1000 (meter)

const double pi = 3.14159;
const double R = 6371; //radius bumi

static double haversine(double lat1,double lon1, double lat2, double lon2){
        double a, c, d;
        //perbedaan lat & lon
        double difLat = abs(lat1-lat2) * (pi/180);
        double difLon = abs(lon1-lon2) * (pi/180);
        
        //rubah lat1 & lat2 ke radian
        lat1 = lat1*(pi/180);
        lat2 = lat2*(pi/180);
        
        //rumus
        a = pow(sin(difLat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(difLon/2), 2);
        c = 2*atan2(sqrt(a), sqrt(1-a));
        d = R * c;
        return static_cast<int>(d*1000);
    }
    
static double hypothenuse(double a, double alt1, double alt2){
    double difHeight = abs(alt1-alt2);
    double result = sqrt(pow(a, 2)+pow(difHeight, 2));
    return static_cast<int>(result);
}

int main(){
    double lat1 = 51.5007, lon1 = 0.1246, alt1 = 3;
    double lat2 = 40.6892, lon2 = 74.0445, alt2 = 40000;
    
    cout << static_cast<int>(hypothenuse(haversine(lat1, lon1, lat2, lon2), alt1, alt2)) << " Meter";
    
    return 0;
}
