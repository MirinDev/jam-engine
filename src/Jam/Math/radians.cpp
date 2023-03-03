#include <Jam/Math/radians.h>
using namespace std;
using namespace Jam;

float Math::deg2rad(float value){return value * (float)M_PI / 180.0f;}
float Math::rad2deg(float value){return value * 180.0f / (float)M_PI;}