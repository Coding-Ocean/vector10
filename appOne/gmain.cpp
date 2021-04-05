#include"libOne.h"
void gmain() {
    window(1000, 1000);
    angleMode(DEGREES);
    //ベクトルａ，ｂ
    float ax, ay;
    float bx, by;
    float a_angle = -15;
    float b_angle = 30;
    float inc_dec = 15;
    //内積、外積、なす角
    float dotProduct = 0;
    float crossProduct = 0;
    float angleBetween = 0;
    //表示切り替え用状態
    int state = 3;
    while (notQuit) {
        clear(0, 50, 0);
        mathAxis(1.5f, 255);
        //ベクトルａの回転
        if (isTrigger(KEY_A))a_angle += inc_dec;
        if (isTrigger(KEY_D))a_angle += -inc_dec;
        ax = cos(a_angle);
        ay = sin(a_angle);
        //ベクトルｂの回転
        if (isTrigger(KEY_LEFT))b_angle += inc_dec;
        if (isTrigger(KEY_RIGHT))b_angle += -inc_dec;
        bx = cos(b_angle);
        by = sin(b_angle);
        //ベクトルｂをマウス位置にする
        if (isPress(MOUSE_LBUTTON)) {
            bx = mathMouseX;
            by = mathMouseY;
        }
        //内積
        dotProduct = ax * bx + ay * by;
        //外積
        crossProduct = ax * by - ay * bx;
        //なす角
        angleBetween = atan2(crossProduct, dotProduct);
        //ベクトルａがｂを追いかける
        if (isPress(KEY_Z)) { a_angle += angleBetween * 0.1f; }
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
        if (state >= 1) {
            //底辺描画
            float cx = ax * dotProduct;
            float cy = ay * dotProduct;
            strokeWeight(10);
            stroke(150, 190, 255);
            mathLine(0, 0, cx, cy);
            //高さ描画（ベクトルａを９０°回転させ、外積を掛ける）
            float dx = -ay * crossProduct;
            float dy = ax * crossProduct;
            stroke(255, 190, 190);
            mathLine(cx, cy, cx + dx, cy + dy);
        }
        if (state >= 2) {
            //式と値描画
            textSize(50);
            fill(150, 190, 255);
            text((let)"dot:   ax * bx + ay * by = " + dotProduct, 0, 50);
            fill(255, 190, 190);
            text((let)"cross: ax * by - ay * bx = " + crossProduct, 0, 100);
        }
        if (state >= 3) {
            //なす角描画
            stroke(255, 255, 200);
            mathArc(a_angle, angleBetween, 0.1f);
            textSize(50);
            fill(255, 255, 200);
            text((let)"atan2(cross,dot) = " + round(angleBetween), 0, 150);
        }
    }
}
