#include <iostream>
#include "flyngBox.h"
#include "SDL.h"
#include "../utilitySDL/utilitySDLInline.h"

using namespace std;

void showFlyngBox() {
    point3d p(1.0, 2.0, 3.0);
    point3d q(1.0, 4.0, 5.0);
    point3d qi(1.0, 4.0, 5.0);
    point3d pi(1.0, 2.0, 3.0);
    vec3 v(2.0, 1.0, 4.0);
    v=p-q;
    q = p + v;
    cout << "Differenza tra punti" << endl << toString(pi) << " - " << toString(qi) << " = " << toString(v) << endl;
    cout << "Somma di punto  " << toString(p) << " + " << toString(v) << " = " << toString(q) <<  endl;

    point3d o(1.0, 0.0, 0.0);
    vec3 d(1.0, 1.0, 1.0);
    ray r(o, d);
    point3d pad = r.point_at_parameter(5.2);
    cout << "Point at parameter: " << toString(pad) << endl;
    cout << "Raggio: " << toString(r) << endl;
}