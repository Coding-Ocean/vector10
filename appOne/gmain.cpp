#include"libOne.h"
void gmain() {
    //�x�N�g�����C��
    float ax, ay;
    float bx, by;
    float a_angle = -15;
    float b_angle = 15;
    //���ρA�O�ρA�Ȃ��p
    float cosAngle = 0;
    float sinAngle = 0;
    float angleBetween = 0;
    //�\���؂�ւ��p���
    int state = 0;
    angleMode(DEGREES);
    window(1000, 1000);
    while (notQuit) {
        clear(0, 50, 0);
        mathAxis(1.5f, 255);
        //�x�N�g�����̉�]
        if (isTrigger(KEY_A))a_angle += 15;
        if (isTrigger(KEY_D))a_angle += -15;
        ax = cos(a_angle);
        ay = sin(a_angle);
        //�x�N�g�����̉�]
        if (isTrigger(KEY_J))b_angle += 15;
        if (isTrigger(KEY_L))b_angle += -15;
        bx = cos(b_angle);
        by = sin(b_angle);
        //�x�N�g�������}�E�X�ʒu�ɂ���
        if (isPress(MOUSE_LBUTTON)) {
            bx = mathMouseX;
            by = mathMouseY;
        }
        //����
        cosAngle = ax * bx + ay * by;
        //�O��
        sinAngle = ax * by - ay * bx;
        //�Ȃ��p
        angleBetween = atan2(sinAngle, cosAngle);
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
            float cx = ax * cosAngle;
            float cy = ay * cosAngle;
            strokeWeight(10);
            stroke(150, 190, 255);
            mathLine(0, 0, cx, cy);
            stroke(255, 190, 190);
            mathLine(cx, cy, bx, by);
        }
        if (state >= 2) {
            textSize(50);
            fill(150, 190, 255);
            text((let)"cos�� = ax * bx + ay * by = " + cosAngle, 0, 50);
            fill(255, 190, 190);
            text((let)"sin�� = ax * by - ay * bx = " + sinAngle, 0, 100);
        }
        if (state == 3) {
            //�Ȃ��p�`��
            stroke(255, 255, 200);
            mathArc(atan2(ay, ax), angleBetween, 0.1f);
            textSize(50);
            fill(255,255,200);
            text((let)"�� = " + round(angleBetween), 0, 150);
        }
    }
}
