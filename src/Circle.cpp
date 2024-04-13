#include "Circle.h"



void Circle::draw(float x, float y, int n,float size,float r, float length) {
     angle += 0.0001;
   if (n == 0) return;

    int delta = r * 0.35;
    ofDrawCircle(x, y, r);

    float angle1 = angle;
    float angle2 = PI / 3 + angle;
    float angle3 = PI + angle;
    float angle4 = 2 * PI / 3 + angle;
    float angle5 = 4 * PI / 3 + angle;
    float angle6 = 5 * PI / 3 + angle;
    draw(x + r * cos(angle1), y + r * sin(angle1),n - 1,0, delta,0);
    draw(x + r * cos(angle2), y + r * sin(angle2),n - 1,0, delta,0);
    draw(x + r * cos(angle3), y + r * sin(angle3),n - 1,0, delta,0);
    draw(x + r * cos(angle4), y + r * sin(angle4),n - 1,0, delta,0);
    draw(x + r * cos(angle5), y + r * sin(angle5),n - 1,0, delta,0);
    draw(x + r * cos(angle6), y + r * sin(angle6),n - 1,0, delta,0);


}
