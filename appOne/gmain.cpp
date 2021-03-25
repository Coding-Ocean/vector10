#include"libOne.h"
struct VEC {
    float x = 0, y = 0;
    float m = 1;
};
void gmain() {
    float a_angle = -15;
    float b_angle = 15;
    VEC a, b, c;
    float angleBetween = 0;
    float sinAngle = 0;
    float cosAngle = 0;
    int state = 0;
    float bm = 1;
    angleMode(DEGREES);
    window(1000, 1000);
    while (notQuit) {
        clear(0, 80, 0);
        mathAxis(bm + 0.5f, 255);

        if (isTrigger(KEY_A))a_angle += 15;
        if (isTrigger(KEY_D))a_angle += -15;
        a.x = cos(a_angle);
        a.y = sin(a_angle);

        if (isTrigger(MOUSE_LBUTTON))b_angle += 15;
        if (isTrigger(MOUSE_RBUTTON))b_angle += -15;
        b.x = cos(b_angle) * bm;
        b.y = sin(b_angle) * bm;
        if (isPress(MOUSE_MBUTTON)) {
            b.x = mathMouseX;
            b.y = mathMouseY;
            float mag = sqrt(b.x * b.x + b.y * b.y);
            b.x /= mag;
            b.y /= mag;
            b.x *= bm;
            b.y *= bm;
        }
        //ì‡êœ
        cosAngle = a.x * b.x + a.y * b.y;
        c.x = a.x * cosAngle;
        c.y = a.y * cosAngle;
        angleBetween = acos(cosAngle / bm);
        //äOêœ
        sinAngle = a.x * b.y - a.y * b.x;
        if (sinAngle < 0) {
            angleBetween = -angleBetween;
        }

        //a_angle += angleBetween * 0.05f;



        strokeWeight(10);
        textSize(50);
        stroke(180);
        mathArrow(0, 0, b.x, b.y);
        fill(180);
        mathText("b", b.x, b.y);
        stroke(250);
        mathArrow(0, 0, a.x, a.y);
        fill(250);
        mathText("a", a.x, a.y);


        //strokeWeight(280);
        //stroke(0, 60, 00);
        //fill(0, 0, 0, 0);
        //rect(0, 0, width, height);
        if (isTrigger(KEY_SPACE)) {
            ++state %= 4;
        }
        if (state == 1 || state == 2) {
            strokeWeight(10);
            stroke(150, 190, 255);
            mathLine(0, 0, c.x, c.y);
            stroke(255, 190, 190);
            mathLine(c.x, c.y, b.x, b.y);
        }
        if (state == 2) {
            textSize(50);
            fill(150, 190, 255);
            text((let)"cosÉ∆*am*bm = ax * bx + ay * by = " + cosAngle, 0, 50);
            fill(255, 190, 190);
            text((let)"sinÉ∆ = ax * by - ay * bx = " + sinAngle, 0, 100);
            fill(250);
            text((let)"É∆ = " + angleBetween, 0, 150);
        }
        if (state == 3) {
            textSize(50);
            fill(250);
            text((let)"É∆ = " + angleBetween, 0, 150);
        }
    }
}
