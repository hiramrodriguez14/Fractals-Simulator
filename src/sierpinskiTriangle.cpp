#include "sierpinskiTriangle.h"


void SierpinskiTriangle::draw(float x, float y, int n,float size,float r, float length) {
    if (n == 0) {
        return;
    }

    ofPoint a(x, y);
    ofPoint b(x + size, y);
    ofPoint c(x + size / 2, y + ((sqrt(3) * size) / 2));

    ofDrawTriangle(a, b, c);

    draw(x, y,n - 1, size / 2,0,0);
    draw((a.x + b.x) / 2, (a.y + b.y) / 2, n - 1, size / 2,0,0);
    draw((a.x + c.x) / 2, (a.y + c.y) / 2, n - 1, size / 2,0,0);

}
