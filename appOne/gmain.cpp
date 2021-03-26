#include"libOne.h"
void gmain() {
    //ベクトルａ，ｂ
    float ax, ay;
    float bx, by;
    float a_angle = -15;
    float b_angle = 15;
    //内積、外積、なす角
    float cosAngle = 0;
    float sinAngle = 0;
    float angleBetween = 0;
    //状態
    int state = 0;
    angleMode(DEGREES);
    window(1000, 1000);
    while (notQuit) {
        clear(0, 80, 0);
        mathAxis(1.5f, 255);
        //ベクトルａの回転
        if (isTrigger(KEY_A))a_angle += 15;
        if (isTrigger(KEY_D))a_angle += -15;
        ax = cos(a_angle);
        ay = sin(a_angle);
        //ベクトルｂの回転
        if (isTrigger(MOUSE_LBUTTON))b_angle += 15;
        if (isTrigger(MOUSE_RBUTTON))b_angle += -15;
        bx = cos(b_angle);
        by = sin(b_angle);
        //ベクトルｂをマウス位置にする
        if (isPress(MOUSE_MBUTTON)) {
            bx = mathMouseX;
            by = mathMouseY;
        }
        //内積
        cosAngle = ax * bx + ay * by;
        //外積
        sinAngle = ax * by - ay * bx;
        //なす角
        angleBetween = atan2(sinAngle, cosAngle);
        //ベクトルａがｂを追いかける
        if (isPress(KEY_Z)) {
            a_angle += angleBetween * 0.1f;
        }
        //ベクトルｂ描画
        strokeWeight(10);
        textSize(50);
        stroke(180);
        mathArrow(0, 0, bx, by);
        fill(180);
        mathText("b", bx, by);
        //ベクトルａ描画
        stroke(250);
        mathArrow(0, 0, ax, ay);
        fill(250);
        mathText("a", ax, ay);
        //情報描画
        if (isTrigger(KEY_SPACE)) {
            ++state %= 4;
        }
        if (state == 1 || state == 2) {
            //底辺と高さ描画
            float cx = ax * cosAngle;
            float cy = ay * cosAngle;
            strokeWeight(10);
            stroke(150, 190, 255);
            mathLine(0, 0, cx, cy);
            stroke(255, 190, 190);
            mathLine(cx, cy, bx, by);
        }
        if (state == 2) {
            textSize(50);
            fill(150, 190, 255);
            text((let)"cosθ = ax * bx + ay * by = " + cosAngle, 0, 50);
            fill(255, 190, 190);
            text((let)"sinθ = ax * by - ay * bx = " + sinAngle, 0, 100);
            fill(250);
            text((let)"θ = " + angleBetween, 0, 150);
        }
        if (state == 3) {
            textSize(50);
            fill(250);
            text((let)"θ = " + angleBetween, 0, 150);
        }
    }
}
