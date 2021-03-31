#include"libOne.h"
void gmain() {
    window(1040, 1040);
    angleMode(DEGREES);
    //�x�N�g�����C��
    float ax, ay;
    float bx, by;
    float a_angle = -15;
    float b_angle = 30;
    float inc_dec = 15;
    //���ρA�O�ρA�Ȃ��p
    float dotProduct = 0;
    float crossProduct = 0;
    float angleBetween = 0;
    //�\���؂�ւ��p���
    int state = 0;
    while (notQuit) {
        clear(0, 50, 0);
        mathAxis(1.5f, 255);
        //�x�N�g�����̉�]
        if (isTrigger(KEY_A))a_angle += inc_dec;
        if (isTrigger(KEY_D))a_angle += -inc_dec;
        ax = cos(a_angle);
        ay = sin(a_angle);
        //�x�N�g�����̉�]
        if (isTrigger(KEY_LEFT))b_angle += inc_dec;
        if (isTrigger(KEY_RIGHT))b_angle += -inc_dec;
        bx = cos(b_angle);
        by = sin(b_angle);
        //�x�N�g�������}�E�X�ʒu�ɂ���
        if (isPress(MOUSE_LBUTTON)) {
            bx = mathMouseX;
            by = mathMouseY;
        }
        //����
        dotProduct = ax * bx + ay * by;
        //�O��
        crossProduct = ax * by - ay * bx;
        //�Ȃ��p
        angleBetween = atan2(crossProduct, dotProduct);
        //�x�N�g����������ǂ�������
        if (isPress(KEY_Z)) {
            a_angle += angleBetween * 0.1f;
        }
        //�x�N�g�����`��
        strokeWeight(10);
        textSize(50);
        stroke(180);
        mathArrow(0, 0, bx, by);
        fill(180);
        mathText("b", bx, by);
        //�x�N�g�����`��
        stroke(250);
        mathArrow(0, 0, ax, ay);
        fill(250);
        mathText("a", ax, ay);

        //���`��
        if (isTrigger(KEY_SPACE)) {
            ++state %= 4;
        }
        if (state >= 1) {
            //��ӂƍ����`��
            float cx = ax * dotProduct;
            float cy = ay * dotProduct;
            strokeWeight(10);
            stroke(150, 190, 255);
            mathLine(0, 0, cx, cy);
            stroke(255, 190, 190);
            mathLine(cx, cy, bx, by);
        }
        if (state >= 2) {
            textSize(50);
            fill(150, 190, 255);
            text((let)"����: ax * bx + ay * by = " + dotProduct, 0, 50);
            fill(255, 190, 190);
            text((let)"�O��: ax * by - ay * bx = " + crossProduct, 0, 100);
        }
        if (state >= 3) {
            //�Ȃ��p�`��
            stroke(255, 255, 200);
            mathArc(a_angle, angleBetween, 0.1f);
            textSize(50);
            fill(255,255,200);
            text((let)"�� = " + round(angleBetween), 0, 150);
        }
    }
}
