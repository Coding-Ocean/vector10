#include"libOne.h"
void gmain() {
    window(1000, 1000);
    angleMode(DEGREES);
    //�x�N�g�����C��
    float ax, ay, aAngle = -15;
    float bx, by, bAngle = 30;
    //�p�x�����l
    float incDec = 15;
    //���ρA�O�ρA�Ȃ��p
    float dotProduct = 0;
    float crossProduct = 0;
    float angleBetween = 0;
    while (notQuit) {
        clear(0, 40, 0);
        mathAxis(1.5f, 200);
        //�x�N�g�����̉�]
        if (isTrigger(KEY_A))aAngle += incDec;
        if (isTrigger(KEY_D))aAngle += -incDec;
        ax = cos(aAngle);
        ay = sin(aAngle);
        //�x�N�g�����̉�]
        if (isTrigger(KEY_LEFT))bAngle += incDec;
        if (isTrigger(KEY_RIGHT))bAngle += -incDec;
        bx = cos(bAngle);
        by = sin(bAngle);
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
        if (isPress(KEY_Z)) { aAngle += angleBetween * 0.1f; }
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
        //��ӕ`��
        float cx = ax * dotProduct;
        float cy = ay * dotProduct;
        strokeWeight(10);
        stroke(150, 190, 255);
        mathLine(0, 0, cx, cy);
        //�����`��i�x�N�g�������X�O����]�����A�O�ς��|����j
        float dx = -ay * crossProduct;
        float dy = ax * crossProduct;
        stroke(255, 190, 190);
        mathLine(cx, cy, cx + dx, cy + dy);

        //���ƒl�e�L�X�g�`��
        textSize(50);
        fill(150, 190, 255);
        text((let)"dot:   ax * bx + ay * by = " + dotProduct, 0, 50);
        fill(255, 190, 190);
        text((let)"cross: ax * by - ay * bx = " + crossProduct, 0, 100);
        //�Ȃ��p�e�L�X�g�`��
        stroke(255, 255, 200);
        mathArc(aAngle, angleBetween, 0.1f);
        textSize(50);
        fill(255, 255, 200);
        text((let)"atan2(cross,dot) = " + round(angleBetween), 0, 150);
    }
}
