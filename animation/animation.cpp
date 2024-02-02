#include <gl/glut.h>
#include <stdio.h>

//------------ 各種材質パラメータ--------------//
//光源(環境光､拡散光､鏡面光､位置)
GLfloat lightAmb[] = { 0.f, 0.f, 0.f, 1.f };
GLfloat lightDiff[] = { 1.f, 1.f, 1.f, 1.f };
GLfloat lightSpec[] = { 1.f, 1.f, 1.f, 1.f };
GLfloat lightPos[] = { 1.f, 2.f, 1.f, 0.f };//平行光源

//材質(環境光､拡散光､鏡面光､鏡面指数)
//set
///paper
GLfloat seatAmb[] = { 0.24725f, 0.1995f, 0.1745f, 1.f };
GLfloat seatDiff[] = { 0.75164f, 0.40648f , 0.22648f, 1.f };
GLfloat seatSpec[] = { 0.428281f, 0.555802f,0.366065f,1.f };
GLfloat seatShin = 51.2f;
///midpaper
GLfloat seat2Amb[] = { 0.24725f, 0.1995f, 0.1745f, 1.f };
GLfloat seat2Diff[] = { 0.3f, 0.3f , 0.3f, 1.f };
GLfloat seat2Spec[] = { 0.428281f, 0.555802f,0.366065f,1.f };
GLfloat seat2Shin = 11.2f;
//bigpaper
GLfloat goldAmb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat goldDiff[] = { 0.769f, 0.102f , 0.255f, 1.f };
GLfloat goldSpec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat goldShin = 41.2f;
//cup
GLfloat cupAmb[] = { 0.24725f, 0.1995f, 0.1745f, 1.f };
GLfloat cupDiff[] = { 0.65f, 0.65f , 0.65f, 1.f };
GLfloat cupSpec[] = { 0.428281f, 0.555802f,0.366065f,1.f };
GLfloat cupShin = 11.2f;
//cup2
GLfloat cup2Amb[] = { 0.24725f, 0.1995f, 0.1745f, 1.f };
GLfloat cup2Diff[] = { 0.65f, 0.4f , 0.4f, 1.f };
GLfloat cup2Spec[] = { 0.428281f, 0.555802f,0.366065f,1.f };
GLfloat cup2Shin = 11.2f;
//teapot
GLfloat teaAmb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat teaDiff[] = { 0.8f, 0.8f , 0.8f, 1.f };
GLfloat teaSpec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat teaShin = 31.2f;
//suger
GLfloat sAmb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat sDiff[] = { 0.9f, 0.9f , 0.9f, 1.f };
GLfloat sSpec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat sShin = 0.0f;
//kasi1
GLfloat kasiAmb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat kasiDiff[] = { 0.9f, 0.9f , 0.9f, 1.f };
GLfloat kasiSpec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat kasiShin = 10.0f;
//kasi2
GLfloat kasi2Amb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat kasi2Diff[] = { 0.6f, 0.6f , 0.0f, 1.f };
GLfloat kasi2Spec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat kasi2Shin = 10.0f;
//kasi3
GLfloat kasi3Amb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat kasi3Diff[] = { 0.925f, 0.647f , 0.698f, 1.f };
GLfloat kasi3Spec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat kasi3Shin = 10.0f;
//kasi4
GLfloat kasi4Amb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat kasi4Diff[] = { 0.9f, 0.0f , 0.0f, 1.f };
GLfloat kasi4Spec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat kasi4Shin = 10.0f;
//kasi5
GLfloat kasi5Amb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat kasi5Diff[] = { 0.211f, 0.145f , 0.098f, 1.f };
GLfloat kasi5Spec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat kasi5Shin = 10.0f;
//tumayouzi
GLfloat tAmb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat tDiff[] = { 0.341f, 0.467f , 0.184f, 1.f };
GLfloat tSpec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat tShin = 30.0f;
//water
GLfloat wAmb[] = { 0.24725f, 0.1995f, 0.0745f, 1.f };
GLfloat wDiff[] = { 0.415f, 0.5254f , 0.333f, 1.f };
GLfloat wSpec[] = { 0.628281f, 0.555802f,0.366065f,1.f };
GLfloat wShin = 20.0f;


//--------- 各種コールバック関数-------//

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, double(w) / h, 0.1, 200.0);

    glMatrixMode(GL_MODELVIEW);	// モデルビュー行列モード
    glLoadIdentity();
    gluLookAt(0.0, 2.0, 5, 0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display(void)
{
    static int angle = 0;
    static float y = 3;//bigpaper
    static float x = 4;//teapot
    static float s = 4;//smallpaper
    static float s2 = 4;//smallpaper2
    static float m = 4;//middlepaper
    static float t = -5;//cup
    static float t2 = -5;//cup2
    static float i = 4;
    static float i2 = 3;
    static float i3 = 4;
    static float i4 = 3;
    static float i5 = 4;//茶菓子
    static float f = 0;//茶菓子②
    static float f2 = 0;//茶菓子③
    static float f3 = 0;//茶菓子④
    static float f4 = 0;//tumayouzi

    static float potroute = 0;
    static float potroute2 = 0;
    static float count = 0;
    static float potup = 0;
    static float potmove = 0;
    static float potmove2 = 0;

    static float water = 0;
    static float water2 = 0;
    static int swi = 0;

    static int waterct = 0;//お茶を注ぐアニメーション利用

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    //光源の位置設定
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    //材質設定と描画
    //big paper
    glPushMatrix();
    glTranslatef(0, y, 0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, goldAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, goldDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, goldSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, goldShin);
    // 法線の設定
    glNormal3f(0.0, 2.0, 0.0);  // 単位ベクトルでなくても良い
    // 図形の描画
    glBegin(GL_QUADS);
    glVertex3f(2, 0.0, 2);
    glVertex3f(2, 0.0, -2);
    glVertex3f(-2, 0.0, -2);
    glVertex3f(-2, 0.0, 2);
    glEnd();
    glPopMatrix();


    //small paper
    glPushMatrix();
    glTranslatef(0, s, 0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, seatAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, seatDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, seatSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, seatShin);
    // 法線の設定
    glNormal3f(0.0, 2.0, 0.0);  // 単位ベクトルでなくても良い
    // 図形の描画
    glBegin(GL_QUADS);
    glVertex3f(0.3, 0.01, 0.3);
    glVertex3f(0.3, 0.01, -0.3);
    glVertex3f(-0.3, 0.01, -0.3);
    glVertex3f(-0.3, 0.01, 0.3);
    glEnd();
    glPopMatrix();

    //small paper2
    glPushMatrix();
    glTranslatef(-1.4, s2, -0.4);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, seatAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, seatDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, seatSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, seatShin);
    // 法線の設定
    glNormal3f(0.0, 2.0, 0.0);  // 単位ベクトルでなくても良い
    // 図形の描画
    glBegin(GL_QUADS);
    glVertex3f(0.3, 0.01, 0.3);
    glVertex3f(0.3, 0.01, -0.3);
    glVertex3f(-0.3, 0.01, -0.3);
    glVertex3f(-0.3, 0.01, 0.3);
    glEnd();
    glPopMatrix();

    //middle paper(茶菓子皿)
    glPushMatrix();
    glTranslatef(1.1, m, 1.1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, seat2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, seat2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, seat2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, seat2Shin);
    // 法線の設定
    glNormal3f(0.0, 2.0, 0.0);  // 単位ベクトルでなくても良い
    // 図形の描画
    glBegin(GL_QUADS);
    glVertex3f(0.7, 0.01, 0.7);
    glVertex3f(0.7, 0.01, -0.7);
    glVertex3f(-0.7, 0.01, -0.7);
    glVertex3f(-0.7, 0.01, 0.7);
    glEnd();
    glPopMatrix();

    //teapot
    glPushMatrix();
    glTranslatef(x, 0, -1);
    glTranslatef(-potmove, potup, potmove2);
    glRotatef(potroute, 0.f, 1.f, 0.f);
    glRotatef(potroute2, 0.f, 0.f, 1.f);
    glRotatef(180, 0.f, 1.f, 0.f);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, teaAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, teaDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, teaSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, teaShin);
    glutSolidTeapot(0.5);//描画
    glPopMatrix();

    //cup
    glPushMatrix();
    glTranslatef(t, 0, 0);

    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, -0.05);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cupAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cupDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cupSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cupShin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cupAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cupDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cupSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cupShin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.05);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cupAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cupDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cupSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cupShin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cupAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cupDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cupSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cupShin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.15);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cupAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cupDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cupSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cupShin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.20);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cupAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cupDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cupSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cupShin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.25);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cupAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cupDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cupSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cupShin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.30);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cupAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cupDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cupSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cupShin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.35);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cupAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cupDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cupSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cupShin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();

    glPopMatrix();

    //cup2
    glPushMatrix();
    glTranslatef(t2, 0, -0.4);

    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, -0.05);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cup2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cup2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cup2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cup2Shin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cup2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cup2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cup2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cup2Shin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.05);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cup2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cup2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cup2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cup2Shin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cup2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cup2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cup2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cup2Shin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.15);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cup2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cup2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cup2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cup2Shin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.20);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cup2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cup2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cup2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cup2Shin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.25);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cup2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cup2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cup2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cup2Shin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.30);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cup2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cup2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cup2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cup2Shin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1.f, 0.f, 0.f);
    glTranslatef(0, 0, 0.35);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, cup2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, cup2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, cup2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, cup2Shin);
    glutSolidTorus(0.03, 0.2, 40, 40);//描画
    glPopMatrix();

    glPopMatrix();

    //茶菓子
    glPushMatrix();

    glPushMatrix();//1段目
    glPushMatrix();
    glTranslatef(1.1, i, 1.1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPushMatrix();
    glTranslatef(1.25, i2, 1.1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPushMatrix();
    glTranslatef(1.4, i, 1.1);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPushMatrix();
    glTranslatef(1.175, i2, 0.95);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPushMatrix();
    glTranslatef(1.325, i, 0.95);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPushMatrix();
    glTranslatef(1.25, i2, 0.8);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPopMatrix();//1段目おわり

    glPushMatrix();//2段目
    glPushMatrix();
    glTranslatef(1.25, i3, 0.875);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPushMatrix();
    glTranslatef(1.175, i4, 1.025);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPushMatrix();
    glTranslatef(1.325, i4, 1.025);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPopMatrix();//2段目おわり

    glPushMatrix();//3段目
    glPushMatrix();
    glTranslatef(1.25, i5, 0.95);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, sAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, sDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, sSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, sShin);
    glutSolidCube(0.1);
    glPopMatrix();//
    glPopMatrix();//3段目おわり

    glPopMatrix();

    glPushMatrix();//茶菓子②
    glTranslatef(0, 3 - f, 0);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.7, 1.3, 0.34);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, kasiAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kasiDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, kasiSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, kasiShin);
    glutSolidTorus(0.1, 0.05, 40, 40);
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.7, 1.3, 0.24);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, kasi2Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kasi2Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, kasi2Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, kasi2Shin);
    glutSolidSphere(0.03, 40, 40);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();//茶菓子③
    glTranslatef(0.3, 3 - f2, 0.3);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.7, 1.3, 0.34);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, kasi3Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kasi3Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, kasi3Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, kasi3Shin);
    glutSolidTorus(0.1, 0.05, 40, 40);
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.7, 1.3, 0.24);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, kasi4Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kasi4Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, kasi4Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, kasi4Shin);
    glutSolidSphere(0.03, 40, 40);
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();//茶菓子④
    glTranslatef(-0.35, 3 - f3, -0.2);
    glRotatef(20, 0, 1, 0);
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.7, 1.3, 0.34);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, kasi5Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kasi5Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, kasi5Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, kasi5Shin);
    glutSolidCube(0.2);
    glPopMatrix();//
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0.95, 1.3, 0.34);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, kasi5Amb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kasi5Diff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, kasi5Spec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, kasi5Shin);
    glutSolidCube(0.2);
    glPopMatrix();//

    glPopMatrix();

    glPushMatrix();
    glRotatef(-45, 0, 1, 0);
    glTranslatef(1.35, 3 - f4, 0);
    glPushMatrix();//tumayouzi
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, tAmb);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, tDiff);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, tSpec);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, tShin);
    // 法線の設定
    glNormal3f(0.0, 1.0, 0.0);  // 単位ベクトルでなくても良い
    // 図形の描画
    glBegin(GL_POLYGON);
    glVertex3f(0.03, 0.2, 0.5);
    glVertex3f(0.03, 0.2, 0);
    glVertex3f(0, 0.2, -0.2);
    glVertex3f(-0.03, 0.2, 0);
    glVertex3f(-0.03, 0.2, 0.5);
    glEnd();
    glPopMatrix();
    glPopMatrix();

    if (swi == 18) {
        glPushMatrix();//water
        glTranslatef(0, 0.5 - water, 0);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wAmb);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, wDiff);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wSpec);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, wShin);
        glutSolidCube(0.05);
        glPopMatrix();//

        glPushMatrix();//water2
        glTranslatef(0, 0.5 - water2, 0);
        glPushMatrix();
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wAmb);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, wDiff);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wSpec);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, wShin);
        glutSolidCube(0.05);
        glPopMatrix();//
        glPopMatrix();
    }
    if (swi > 18) {
        glPushMatrix();
        glRotatef(90, 1.f, 0.f, 0.f);
        glTranslatef(0, 0, 0.25);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wAmb);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, wDiff);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wSpec);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, wShin);
        glutSolidTorus(0.18, 0.03, 40, 40);//描画
        glPopMatrix();//
    }
    if (swi == 22) {
        glPushMatrix();//water
        glTranslatef(-1.4, 0.5 - water, -0.4);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wAmb);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, wDiff);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wSpec);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, wShin);
        glutSolidCube(0.05);
        glPopMatrix();//

        glPushMatrix();//water2
        glTranslatef(-1.4, 0.5 - water2, -0.4);
        glPushMatrix();
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wAmb);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, wDiff);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wSpec);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, wShin);
        glutSolidCube(0.05);
        glPopMatrix();//
        glPopMatrix();
    }
    if (swi > 22) {
        glPushMatrix();
        glTranslatef(-1.4, -0.2, -0.4);
        glRotatef(90, 1.f, 0.f, 0.f);
        glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, wAmb);
        glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, wDiff);
        glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, wSpec);
        glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, wShin);
        glutSolidTorus(0.18, 0.03, 40, 40);//描画
        glPopMatrix();//
    }

    //描画ここまで
    glutSwapBuffers();


    //time変化
    if (swi == 0)
    {
        if (y > -0.4) {//bigpaper
            y = y - 0.01;

        }
        else
        {

            swi = 1;
        }
    }
    else if (swi == 1)
    {
        if (x > 1) {//teapot
            x = x - 0.01;

        }
        else
        {
            swi = 2;
        }
    }
    else if (swi == 2)
    {
        if (s > -0.39) {//smallpaper
            s = s - 0.01;
        }
        else
        {
            swi = 3;
        }
    }
    else if (swi == 3)
    {
        if (t < 0) {//cup
            t = t + 0.02;

        }
        else
        {
            swi = 4;
        }
    }
    else if (swi == 4)
    {
        if (s2 > -0.39) {//smallpaper2
            s2 = s2 - 0.01;
        }
        else
        {
            swi = 5;
        }
    }
    else if (swi == 5)
    {
        if (t2 < -1.4) {//cup2
            t2 = t2 + 0.02;

        }
        else
        {
            swi = 6;
        }
    }
    else if (swi == 6)
    {
        if (m > -0.4) {//middlepaper
            m = m - 0.01;
        }
        else
        {
            swi = 7;
        }
    }
    else if (swi == 7)
    {
        if (i > -0.34 && i2 > -0.34) {//茶菓子
            i = i - 0.02;
            i2 = i2 - 0.01;
        }
        else if (i <= 0.34 && i2 > -0.34)
        {
            i2 = i2 - 0.01;
        }
        else
        {
            swi = 8;
        }
    }
    else if (swi == 8)
    {
        if (i3 > -0.24 && i4 > -0.24) {//茶菓子
            i3 = i3 - 0.02;
            i4 = i4 - 0.01;
        }
        else if (i3 <= 0.24 && i4 > -0.24)
        {
            i4 = i4 - 0.01;
        }
        else
        {
            swi = 9;
        }
    }
    else if (swi == 9)
    {
        if (i5 > -0.14) {//茶菓子
            i5 = i5 - 0.02;
        }
        else
        {
            swi = 10;
        }
    }
    else if (swi == 10)
    {
        if (f < 2.9) {//茶菓子
            f = f + 0.02;
        }
        else
        {
            swi = 11;
        }
    }
    else if (swi == 11)
    {
        if (f2 < 2.9) {//茶菓子
            f2 = f2 + 0.02;
        }
        else
        {
            swi = 12;
        }
    }
    else if (swi == 12)
    {
        if (f3 < 2.9) {//茶菓子
            f3 = f3 + 0.02;
        }
        else
        {
            swi = 13;
        }
    }
    else if (swi == 13)
    {
        if (f4 < 3.2) {//
            f4 = f4 + 0.03;
        }
        else
        {
            swi = 14;
        }
    }
    else if (swi == 14)
    {
        if (potroute < 45) {
            ++potroute;
        }
        else
        {
            swi = 15;
        }
    }
    else if (swi == 15)
    {
        if (potup < 1.0) {//
            potup = potup + 0.05;
        }
        else
        {
            swi = 16;
        }
    }
    else if (swi == 16)
    {
        if (potmove < 0.4 && potmove2 < 0.3) {
            potmove = potmove + 0.05;
            potmove2 = potmove2 + 0.05;
        }
        else  if (potmove < 0.4 && potmove2 >= 0.3) {
            potmove = potmove + 0.05;
        }
        else
        {
            swi = 17;
        }
    }
    else if (swi == 17)
    {
        if (potroute2 < 45) {
            ++potroute2;
        }
        else
        {
            swi = 18;
        }
    }
    else if (swi == 18 && waterct <= 10)
    {
        if (water < 0.5 && water2 < 1) {
            water = water + 0.05;
        }
        else if (water >= 0.5 && water2 < 1) {
            water = water + 0.05;
            water2 = water2 + 0.06;
        }
        else if (water >= 1 && water2 < 1) {
            water2 = water2 + 0.06;

        }
        else
        {
            water = 0;
            water2 = 0;
            if (waterct < 10) {
                waterct++;
            }
            else {
                waterct = 0;
                swi = 19;
            }
        }
    }
    else if (swi == 19)
    {
        if (potroute2 > 0) {
            potroute2--;
        }
        else
        {
            swi = 20;
        }
    }
    else if (swi == 20)
    {
        if (potmove < 1.7 && potmove2 > 0.15) {
            potmove = potmove + 0.05;
            potmove2 = potmove2 - 0.05;
        }
        else  if (potmove < 1.7 && potmove2 <= 0.15) {
            potmove = potmove + 0.05;
        }
        else
        {
            swi = 21;
        }
    }
    else if (swi == 21)
    {
        if (potroute2 < 45) {
            ++potroute2;
        }
        else
        {
            swi = 22;
        }
    }
    else if (swi == 22 && waterct <= 10)
    {
        if (water < 0.5 && water2 < 1) {
            water = water + 0.05;
        }
        else if (water >= 0.5 && water2 < 1) {
            water = water + 0.05;
            water2 = water2 + 0.06;
        }
        else if (water >= 1 && water2 < 1) {
            water2 = water2 + 0.06;

        }
        else
        {
            water = 0;
            water2 = 0;
            if (waterct < 10) {
                waterct++;
            }
            else {
                waterct = 0;
                swi = 23;
            }
        }
    }
    else if (swi == 23)
    {
        if (potroute2 > 0) {
            potroute2--;
        }
        else
        {
            swi = 24;
        }
    }
    else if (swi == 24)
    {
        if (potmove > 0 && potmove2 > 0) {
            potmove = potmove - 0.05;
            potmove2 = potmove2 - 0.05;
        }
        else  if (potmove > 0 && potmove2 <= 0) {
            potmove = potmove - 0.05;
        }
        else
        {
            swi = 25;
        }
    }
    else if (swi == 25)
    {
        if (potup > 0) {//
            potup = potup - 0.05;
        }
        else
        {
            swi = 26;
        }
    }
    else if (swi == 26)
    {
        if (potroute > 0) {
            --potroute;
        }
        else
        {
            swi = 27;
        }
    }

    glFinish();
}


void idle(void)
{
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) {
        exit(0);
    }
}

//--------- その他各種設定-----------//
void otherInit(void)
{
    glClearColor(1.f, 1.f, 1.f, 1.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);

    //光源設定(環境､拡散､鏡面のみ)
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);

    //光源とライティング有効化
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    glEnable(GL_NORMALIZE);
}

//---------- メイン関数-------------//
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutCreateWindow("最終課題");

    //コールバック関数登録
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    otherInit();//その他設定

    glutMainLoop();

    return 0;
}