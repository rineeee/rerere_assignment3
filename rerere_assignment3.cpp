﻿#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<bangtal.h>
#include<windows.h>
#include <stdbool.h>
#pragma comment(lib, "Bangtal.lib")

SceneID scene1, scene2, scene3;
ObjectID start3, start4, a, b, c, d, e, f, g, h, i, point, r, end, a_, b_, c_, d_, e_, f_, g_, h_, i_, j_, k_, l_, m_, n_, o_, p_, hint3, hintp3, hint4, hintp4, restart, key, chest3, stopwatch, chest4, restart3, restart4;
SoundID ost1;
TimerID timer1;
time_t timerstart, timerend;
double timerresult;


bool closed1 = true, closed2 = true;

void time() {
    timer1 = createTimer(270.0f);
    showTimer(timer1);

}
void timerCallback(TimerID timer) {
    if (timer == timer1) {
        showMessage("다시 도전 해보세요!");
        enterScene(scene1);
        showObject(restart);
        showObject(restart3);
        showObject(restart4);
        showObject(end);

    }
}


int blankX = 738, blankY = 59, m, m__, blankX_ = 787, blankY_ = 60;
int s[3][3], s_[4][4];

void sceneCallback(SceneID scene, EventID event)
{
    if (scene == scene2) {
        if (event == EVENT_ENTER_SCENE)
            playSound(ost1);
        else if (event == EVENT_LEAVE_SCENE)
            stopSound(ost1);
    }
    if (scene == scene3) {
        if (event == EVENT_ENTER_SCENE)
            playSound(ost1);
        else if (event == EVENT_LEAVE_SCENE)
            stopSound(ost1);
    }
}

void endG3() {
    if (s[0][0] == a && s[0][1] == b && s[0][2] == c && s[1][0] == d && s[1][1] == e && s[1][2] == f && s[2][0] == g && s[2][1] == h && s[2][2] == i) {
        stopTimer(timer1);
        timerend = time(NULL);
        timerresult = (double)(timerend - timerstart);
        setTimer(timer1, timerresult);
        showTimer(timer1);
        timerend = 0;
        timerstart = 0;
        showMessage("성공!");
        setObjectImage(chest3, "chest.png");
        enterScene(scene1);
        showObject(restart);
        showObject(restart3);
        showObject(restart4);

        hideObject(hintp3);
        showObject(end);



    }
}
void endG4() {
    if (s_[0][0] == a_ && s_[0][1] == b_ && s_[0][2] == c_ && s_[0][3] == d_ && s_[1][0] == e_ && s_[1][1] == f_ && s_[1][2] == g_ && s_[1][3] == h_ && s_[2][0] == i_ && s_[2][1] == j_ && s_[2][2] == k_ && s_[2][3] == l_ && s_[3][0] == m_ && s_[3][1] == n_ && s_[3][2] == o_ && s_[3][3] == p_) {
        stopTimer(timer1);
        timerend = time(NULL);
        timerresult = (double)(timerend - timerstart);
        setTimer(timer1, timerresult);
        showTimer(timer1);
        timerend = 0;
        timerstart = 0;
        showMessage("성공!");
        setObjectImage(chest4, "chest.png");
        enterScene(scene1);
        showObject(restart3);
        showObject(restart);
        showObject(restart4);
        showObject(end);


        hideObject(hintp4);


    }
}



ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown) {
    ObjectID object = createObject(name, image);
    locateObject(object, scene, x, y);
    if (shown) {
        showObject(object);
    }
    return object;
}


int T, t;

void random3() {
    int r[3][3] = { {0,0,0},{0,0,0},{0,0,1} };
    s[0][0] = a, s[0][1] = b, s[0][2] = c;
    s[1][0] = d, s[1][1] = e, s[1][2] = f;
    s[2][0] = g, s[2][1] = h, s[2][2] = i;

    int blankX[3] = { 338,538,738 };
    int blankY[3] = { 459,259,59 };
    int i, j;

    int k = 0;
    ObjectID temp;
    srand(time(NULL));
    while (k < 70) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (r[i][j] == 1) {
                    T = i;
                    t = j;
                }
            }
        }
        switch (rand() % 4) {
        case 0: {//위쪽
            if (T == 0) {
                k = k + 1;
                break;
            }

            r[T][t] = 0;
            r[T - 1][t] = 1;
            hideObject(s[T - 1][t]);
            locateObject(s[T - 1][t], scene2, blankX[t], blankY[T]);
            showObject(s[T - 1][t]);
            hideObject(s[T][t]);
            locateObject(s[T][t], scene2, blankX[t], blankY[T - 1]);
            showObject(s[T][t]);

            temp = s[T][t];
            s[T][t] = s[T - 1][t];
            s[T - 1][t] = temp;
            k = k + 1;


            break;
        }
        case 1: {//아래쪽     
            if (T == 2) {
                k = k + 1;
                break;
            }

            r[T][t] = 0;
            r[T + 1][t] = 1;
            hideObject(s[T + 1][t]);
            locateObject(s[T + 1][t], scene2, blankX[t], blankY[T]);
            showObject(s[T + 1][t]);
            hideObject(s[T][t]);
            locateObject(s[T][t], scene2, blankX[t], blankY[T + 1]);
            showObject(s[T][t]);

            temp = s[T][t];
            s[T][t] = s[T + 1][t];
            s[T + 1][t] = temp;
            k = k + 1;

            break;
        }
        case 2: {//오른쪽
            if (t == 2) {
                k = k + 1;
                break;
            }

            r[T][t] = 0;
            r[T][t + 1] = 1;
            hideObject(s[T][t + 1]);
            locateObject(s[T][t + 1], scene2, blankX[t], blankY[T]);
            showObject(s[T][t + 1]);
            hideObject(s[T][t]);
            locateObject(s[T][t], scene2, blankX[t - 1], blankY[T]);
            showObject(s[T][t]);

            temp = s[T][t];
            s[T][t] = s[T][t + 1];
            s[T][t + 1] = temp;
            k = k + 1;

            break;
        }
        case 3: { //왼쪽
            if (t == 0) {
                k = k + 1;
                break;
            }

            r[T][t] = 0;
            r[T][t - 1] = 1;
            hideObject(s[T][t - 1]);
            locateObject(s[T][t - 1], scene2, blankX[t], blankY[T]);
            showObject(s[T][t - 1]);
            hideObject(s[T][t]);
            locateObject(s[T][t], scene2, blankX[t - 1], blankY[T]);
            showObject(s[T][t]);

            temp = s[T][t];
            s[T][t] = s[T][t - 1];
            s[T][t - 1] = temp;
            k = k + 1;

            break;

        }

        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (r[i][j] == 1) {
                T = i;
                t = j;
            }
        }
    }
}

int T_, t_;
void random4() {
    int r_[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,1} };
    s_[0][0] = a_, s_[0][1] = b_, s_[0][2] = c_; s_[0][3] = d_;
    s_[1][0] = e_, s_[1][1] = f_, s_[1][2] = g_; s_[1][3] = h_;
    s_[2][0] = i_, s_[2][1] = j_, s_[2][2] = k_; s_[2][3] = l_;
    s_[3][0] = m_, s_[3][1] = n_, s_[3][2] = o_; s_[3][3] = p_;

    int blankX_[4] = { 337,487,637,787 };
    int blankY_[4] = { 510,360,210,60 };
    int i_, j_;

    int k_ = 0;
    ObjectID temp_;
    srand(time(NULL));
    while (k_ < 70) {
        for (i_ = 0; i_ < 4; i_++) {
            for (j_ = 0; j_ < 4; j_++) {
                if (r_[i_][j_] == 1) {
                    T_ = i_;
                    t_ = j_;
                }
            }
        }
        switch (rand() % 4) {
        case 0: {//위쪽
            if (T_ == 0) {
                k_ = k_ + 1;
                break;
            }

            r_[T_][t_] = 0;
            r_[T_ - 1][t_] = 1;
            hideObject(s_[T_ - 1][t_]);
            locateObject(s_[T_ - 1][t_], scene3, blankX_[t_], blankY_[T_]);
            showObject(s_[T_ - 1][t_]);
            hideObject(s_[T_][t_]);
            locateObject(s_[T_][t_], scene3, blankX_[t_], blankY_[T_ - 1]);
            showObject(s_[T_][t_]);

            temp_ = s_[T_][t_];
            s_[T_][t_] = s_[T_ - 1][t_];
            s_[T_ - 1][t_] = temp_;
            k_ = k_ + 1;


            break;
        }
        case 1: {//아래쪽     
            if (T_ == 3) {
                k_ = k_ + 1;
                break;
            }

            r_[T_][t_] = 0;
            r_[T_ + 1][t_] = 1;
            hideObject(s_[T_ + 1][t_]);
            locateObject(s_[T_ + 1][t_], scene3, blankX_[t_], blankY_[T_]);
            showObject(s_[T_ + 1][t_]);
            hideObject(s_[T_][t_]);
            locateObject(s_[T_][t_], scene3, blankX_[t_], blankY_[T_ + 1]);
            showObject(s_[T_][t_]);

            temp_ = s_[T_][t_];
            s_[T_][t_] = s_[T_ + 1][t_];
            s_[T_ + 1][t_] = temp_;
            k_ = k_ + 1;


            break;
        }
        case 2: {//오른쪽
            if (t_ == 3) {
                k_ = k_ + 1;
                break;
            }

            r_[T_][t_] = 0;
            r_[T_][t_ + 1] = 1;
            hideObject(s_[T_][t_ + 1]);
            locateObject(s_[T_][t_ + 1], scene3, blankX_[t_], blankY_[T_]);
            showObject(s_[T_][t_ + 1]);
            hideObject(s_[T_][t_]);
            locateObject(s_[T_][t_], scene3, blankX_[t_ + 1], blankY_[T_]);
            showObject(s_[T_][t_]);

            temp_ = s_[T_][t_];
            s_[T_][t_] = s_[T_][t_ + 1];
            s_[T_][t_ + 1] = temp_;
            k_ = k_ + 1;

            break;
        }
        case 3: { //왼쪽
            if (t_ == 0) {
                k_ = k_ + 1;
                break;
            }

            r_[T_][t_] = 0;
            r_[T_][t_ - 1] = 1;
            hideObject(s_[T_][t_ - 1]);
            locateObject(s_[T_][t_ - 1], scene3, blankX_[t_], blankY_[T_]);
            showObject(s_[T_][t_ - 1]);
            hideObject(s_[T_][t_]);
            locateObject(s_[T_][t_], scene3, blankX_[t_ - 1], blankY_[T_]);
            showObject(s_[T_][t_]);

            temp_ = s_[T_][t_];
            s_[T_][t_] = s_[T_][t_ - 1];
            s_[T_][t_ - 1] = temp_;
            k_ = k_ + 1;

            break;

        }

        }
    }

    for (i_ = 0; i_ < 4; i_++) {
        for (j_ = 0; j_ < 4; j_++) {
            if (r_[i_][j_] == 1) {
                T_ = i_;
                t_ = j_;
            }
        }
    }
}



void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
    if (object == start3) {
        hideObject(start3);
        hideObject(start4);
        hideObject(end);
        hideObject(restart);
        enterScene(scene2);
        setTimer(timer1, 270.0f);
        closed1 = true;
        random3();
        startTimer(timer1);
        timerstart = time(NULL);
        return;
    }
    if (object == start4) {
        hideObject(start3);
        hideObject(start4);
        hideObject(end);
        enterScene(scene3);
        hideObject(restart);
        setTimer(timer1, 270.f);
        closed2 = true;
        random4();

        startTimer(timer1);
        timerstart = time(NULL);
        return;
    }
    if (object == restart3) {
        hideObject(restart3);
        hideObject(restart4);
        hideObject(end);
        hideObject(restart);
        enterScene(scene2);
        setTimer(timer1, 270.0f);
        closed1 = true;
        random3();
        startTimer(timer1);
        timerstart = time(NULL);
        return;
    }
    if (object == restart4) {
        hideObject(restart3);
        hideObject(restart4);
        hideObject(end);
        enterScene(scene3);
        hideObject(restart);
        setTimer(timer1, 270.f);
        closed2 = true;
        random4();

        startTimer(timer1);
        timerstart = time(NULL);
        return;
    }

    if (object == key) {
        pickObject(key);
    }
    if (object == chest3) {
        if (closed1 == true) {
            if (getHandObject() == key) {
                setObjectImage(chest3, "stopwatch.png");
                increaseTimer(timer1, 30.f);
                closed1 = false;
            }
        }
    }
    if (object == chest4) {
        if (closed2 == true) {
            if (getHandObject() == key) {
                setObjectImage(chest4, "stopwatch.png");
                increaseTimer(timer1, 30.f);
                closed2 = false;
            }
        }
    }

    if (object == end) {
        endGame();
    }
    if (object == hint3) {
        showObject(hintp3);
    }
    if (object == hint4) {
        showObject(hintp4);
    }

    if (object == i)
        return;

    if (object == p_)
        return;

    int r[3][3] = { {0,0,0},{0,0,0},{0,0,0} };
    r[T][t] = 1;
    int blankX[3] = { 338,538,738 };
    int blankY[3] = { 459,259,59 };
    int i, j;

    int r_[4][4] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
    r_[T_][t_] = 1;
    int blankX_[4] = { 337,487,637,787 };
    int blankY_[4] = { 510,360,210,60 };
    int i_, j_;

    int k = 0;
    ObjectID temp;

    int k_ = 0;
    ObjectID temp_;

    int right = 0, left = 0, up = 0, down = 0;

    int right_ = 0, left_ = 0, up_ = 0, down_ = 0;

    if (T != 0)
        up = s[T - 1][t];

    if (T != 2)
        down = s[T + 1][t];

    if (t != 0)
        left = s[T][t - 1];

    if (t != 2)
        right = s[T][t + 1];

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (r[i][j] == 1) {
                T = i;
                t = j;
            }
        }
    }



    if (object == right) {
        m = 0;
    }
    else if (object == left) {
        m = 1;
    }
    else if (object == up) {
        m = 2;
    }
    else if (object == down) {
        m = 3;
    }
    else {
        m = -1;
    }

    switch (m) {
    case 0: {//오

        r[T][t] = 0;
        r[T][t + 1] = 1;
        hideObject(s[T][t + 1]);
        locateObject(s[T][t + 1], scene2, blankX[t], blankY[T]);
        showObject(s[T][t + 1]);
        hideObject(s[T][t]);
        locateObject(s[T][t], scene2, blankX[t - 1], blankY[T]);
        showObject(s[T][t]);

        temp = s[T][t];
        s[T][t] = s[T][t + 1];
        s[T][t + 1] = temp;

        k = k + 1;
        endG3();
        break;

    }
    case 1: {//왼
        r[T][t] = 0;
        r[T][t - 1] = 1;
        hideObject(s[T][t - 1]);
        locateObject(s[T][t - 1], scene2, blankX[t], blankY[T]);
        showObject(s[T][t - 1]);
        hideObject(s[T][t]);
        locateObject(s[T][t], scene2, blankX[t - 1], blankY[T]);
        showObject(s[T][t]);

        temp = s[T][t];
        s[T][t] = s[T][t - 1];
        s[T][t - 1] = temp;
        k = k + 1;
        endG3();
        break;

    }


    case 2: {//위
        r[T][t] = 0;
        r[T - 1][t] = 1;
        hideObject(s[T - 1][t]);
        locateObject(s[T - 1][t], scene2, blankX[t], blankY[T]);
        showObject(s[T - 1][t]);
        hideObject(s[T][t]);
        locateObject(s[T][t], scene2, blankX[t], blankY[T - 1]);
        showObject(s[T][t]);
        temp = s[T][t];
        s[T][t] = s[T - 1][t];
        s[T - 1][t] = temp;
        k = k + 1;
        endG3();
        break;

    }
    case 3: {//아래
        r[T][t] = 0;
        r[T + 1][t] = 1;
        hideObject(s[T + 1][t]);
        locateObject(s[T + 1][t], scene2, blankX[t], blankY[T]);
        showObject(s[T + 1][t]);
        hideObject(s[T][t]);
        locateObject(s[T][t], scene2, blankX[t], blankY[T + 1]);
        showObject(s[T][t]);

        temp = s[T][t];
        s[T][t] = s[T + 1][t];
        s[T + 1][t] = temp;
        k = k + 1;
        endG3();
        break;
    }


    default:
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (r[i][j] == 1) {
                    T = i;
                    t = j;
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (r[i][j] == 1) {
                T = i;
                t = j;
            }
        }
    }

    if (T_ != 0)
        up_ = s_[T_ - 1][t_];

    if (T_ != 3)
        down_ = s_[T_ + 1][t_];

    if (t_ != 0)
        left_ = s_[T_][t_ - 1];

    if (t_ != 3)
        right_ = s_[T_][t_ + 1];

    for (i_ = 0; i_ < 4; i_++) {
        for (j_ = 0; j_ < 4; j_++) {
            if (r_[i_][j_] == 1) {
                T_ = i_;
                t_ = j_;
            }
        }
    }
    if (object == right_) {
        m__ = 0;
    }
    else if (object == left_) {
        m__ = 1;
    }
    else if (object == up_) {
        m__ = 2;
    }
    else if (object == down_) {
        m__ = 3;
    }
    else {
        m__ = -1;
    }

    switch (m__) {
    case 0: {//오

        r_[T_][t_] = 0;
        r_[T_][t_ + 1] = 1;
        hideObject(s_[T_][t_ + 1]);
        locateObject(s_[T_][t_ + 1], scene3, blankX_[t_], blankY_[T_]);
        showObject(s_[T_][t_ + 1]);
        hideObject(s_[T_][t_]);
        locateObject(s_[T_][t_], scene3, blankX_[t_ + 1], blankY_[T_]);
        showObject(s_[T_][t_]);

        temp_ = s_[T_][t_];
        s_[T_][t_] = s_[T_][t_ + 1];
        s_[T_][t_ + 1] = temp_;
        k_ = k_ + 1;//오른쪽
        endG4();
        break;

    }
    case 1: {//왼
        r_[T_][t_] = 0;
        r_[T_][t_ - 1] = 1;
        hideObject(s_[T_][t_ - 1]);
        locateObject(s_[T_][t_ - 1], scene3, blankX_[t_], blankY_[T_]);
        showObject(s_[T_][t_ - 1]);
        hideObject(s_[T_][t_]);
        locateObject(s_[T_][t_], scene3, blankX_[t_ - 1], blankY_[T_]);
        showObject(s_[T_][t_]);

        temp_ = s_[T_][t_];
        s_[T_][t_] = s_[T_][t_ - 1];
        s_[T_][t_ - 1] = temp_;
        k_ = k_ + 1;//왼
        endG4();
        break;

    }


    case 2: {//위
        r_[T_][t_] = 0;
        r_[T_ - 1][t_] = 1;
        hideObject(s_[T_ - 1][t_]);
        locateObject(s_[T_ - 1][t_], scene3, blankX_[t_], blankY_[T_]);
        showObject(s_[T_ - 1][t_]);
        hideObject(s_[T_][t_]);
        locateObject(s_[T_][t_], scene3, blankX_[t_], blankY_[T_ - 1]);
        showObject(s_[T_][t_]);

        temp_ = s_[T_][t_];
        s_[T_][t_] = s_[T_ - 1][t_];
        s_[T_ - 1][t_] = temp_;
        k_ = k_ + 1; //위
        endG4();
        break;

    }
    case 3: {//아래
        r_[T_][t_] = 0;
        r_[T_ + 1][t_] = 1;
        hideObject(s_[T_ + 1][t_]);
        locateObject(s_[T_ + 1][t_], scene3, blankX_[t_], blankY_[T_]);
        showObject(s_[T_ + 1][t_]);
        hideObject(s_[T_][t_]);
        locateObject(s_[T_][t_], scene3, blankX_[t_], blankY_[T_ + 1]);
        showObject(s_[T_][t_]);

        temp_ = s_[T_][t_];
        s_[T_][t_] = s_[T_ + 1][t_];
        s_[T_ + 1][t_] = temp_;
        k_ = k_ + 1;//아래
        endG4();
        break;
    }


    default:
        for (i_ = 0; i_ < 4; i_++) {
            for (j_ = 0; j_ < 4; j_++) {
                if (r_[i_][j_] == 1) {
                    T_ = i_;
                    t_ = j_;
                }
            }
        }
    }
    for (i_ = 0; i_ < 4; i_++) {
        for (j_ = 0; j_ < 4; j_++) {
            if (r_[i_][j_] == 1) {
                T_ = i_;
                t_ = j_;
            }
        }
    }
}


int main() {
    setMouseCallback(mouseCallback);
    setSceneCallback(sceneCallback);
    setTimerCallback(timerCallback);
    ost1 = createSound("ost1.wav");
    scene1 = createScene("인어공주 퍼즐", "배경.jpg");
    scene2 = createScene("3X3퍼즐", "구멍.png");
    scene3 = createScene("4X4퍼즐", "구멍.png");



    chest3 = createObject("보물상자", "chest.png", scene2, 70, 600, true);
    chest4 = createObject("보물상자", "chest.png", scene3, 70, 600, true);

    key = createObject("열쇠", "열쇠.png", scene1, 150, 550, true);
    scaleObject(key, 0.3f);
    restart = createObject("restart", "restart.png", scene1, 700, 550, false);
    hint3 = createObject("hint", "hint.png", scene2, 1000, 450, true);
    hintp3 = createObject("hint", "hintp.png", scene2, 950, 200, false);
    hint4 = createObject("hint", "hint.png", scene3, 1000, 450, true);
    hintp4 = createObject("hint", "hintp.png", scene3, 950, 200, false);
    start3 = createObject("시작 버튼", "start3.png", scene1, 250, 70, true);
    start4 = createObject("시작 버튼", "start4.png", scene1, 550, 70, true);
    restart3 = createObject("시작 버튼", "restart3.png", scene1, 250, 70, false);
    restart4 = createObject("시작 버튼", "restart4.png", scene1, 550, 70, false);
    end = createObject("끝 버튼", "end.png", scene1, 850, 70, true);
    a = createObject("1", "1.png", scene2, 338, 459, true);
    b = createObject("2", "2.png", scene2, 538, 459, true);
    c = createObject("3", "3.png", scene2, 738, 459, true);
    d = createObject("4", "4.png", scene2, 338, 259, true);
    e = createObject("5", "5.png", scene2, 538, 259, true);
    f = createObject("6", "6.png", scene2, 738, 259, true);
    g = createObject("7", "7.png", scene2, 338, 59, true);
    h = createObject("8", "8.png", scene2, 538, 59, true);
    i = createObject("9_", "9_.png", scene2, 738, 59, true);
    a_ = createObject("1_", "1_.png", scene3, 337, 510, true);
    b_ = createObject("2_", "2_.png", scene3, 487, 510, true);
    c_ = createObject("3_", "3_.png", scene3, 637, 510, true);
    d_ = createObject("4_", "4_.png", scene3, 787, 510, true);
    e_ = createObject("5_", "5_.png", scene3, 337, 360, true);
    f_ = createObject("6_", "6_.png", scene3, 487, 360, true);
    g_ = createObject("7_", "7_.png", scene3, 637, 360, true);
    h_ = createObject("8_", "8_.png", scene3, 787, 360, true);
    i_ = createObject("9__", "9__.png", scene3, 337, 210, true);
    j_ = createObject("10_", "10_.png", scene3, 487, 210, true);
    k_ = createObject("11_", "11_.png", scene3, 637, 210, true);
    l_ = createObject("12_", "12_.png", scene3, 787, 210, true);
    m_ = createObject("13_", "13_.png", scene3, 337, 60, true);
    n_ = createObject("14_", "14_.png", scene3, 487, 60, true);
    o_ = createObject("15_", "15_.png", scene3, 637, 60, true);
    p_ = createObject("16_", "16_.png", scene3, 787, 60, true);

    point = createObject("point", "point.png", scene1, 738, 459, false);
    scaleObject(point, 0.5f);
    time();

    startGame(scene1);
    playSound(ost1);

}