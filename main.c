#include <windows.h>
#include <gl/gl.h>
#include <stdlib.h>


LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

float x = 0;
float y = 0;
int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;

    /* create main window */
    hwnd = CreateWindowEx(0,
                          "GLSample",
                          "CS352 17235002 Ebrahim Ahmed 15 Aug 20",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          1200,
                          800,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit) {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT) {
                bQuit = TRUE;
            } else {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        } else {
            /* OpenGL animation code goes here */

            glClearColor(0.39608, 0.61961,0.79608, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            glPushMatrix();

            glBegin(GL_POLYGON);
            glColor3f(86.0/255.0,133.0/255.0,3.0/255.0);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(.24555*cos(angle)+0.85319,  -0.90241+sin(angle)*.24555);
            }
            glEnd();

            glPopMatrix();

            glPushMatrix();

            glBegin(GL_POLYGON);
            glColor3f(86.0/255.0,133.0/255.0,3.0/255.0);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(0.27225*cos(angle)+0.6,  -.8+sin(angle)*0.27225);
            }
            glEnd();

            glPopMatrix();



            glPushMatrix();

            glBegin(GL_POLYGON);
            glColor3f(86.0/255.0,133.0/255.0,3.0/255.0);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(0.27225*cos(angle)+0.33304,  -0.95469+sin(angle)*0.27225);
            }
            glEnd();

            glPopMatrix();

            glPushMatrix();

            glBegin(GL_POLYGON);
            glColor3f(86.0/255.0,133.0/255.0,3.0/255.0);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(0.28525*cos(angle)+0.09516,  -1.09722+sin(angle)*0.28525);
            }
            glEnd();

            glPopMatrix();



            glPushMatrix();

            glBegin(GL_POLYGON);
            glColor3f(86.0/255.0,133.0/255.0,3.0/255.0);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(0.41293*cos(angle)-0.29081,  -0.9957+sin(angle)*0.41293);
            }
            glEnd();

            glPopMatrix();

            glPushMatrix();

            glBegin(GL_POLYGON);
            glColor3f(217.0/255.0,231.0/255.0,244.0/255.0);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(0.7*cos(angle)-1,  sin(angle)*.7);
            }
            glEnd();

            glPopMatrix();



            glPushMatrix();

            glBegin(GL_POLYGON);
            glColor3f(188.0/255.0,238.0/255.0,252.0/255.0);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(.5*cos(angle)-.5, .58+sin(angle)*.1);
            }
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1, 1, 1);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(.5*cos(angle)-.5, .60+sin(angle)*.1);
            }

            glEnd();
            glPopMatrix();



            glPushMatrix();
            glBegin(GL_POLYGON);
            glColor3f(188.0/255.0,238.0/255.0,252.0/255.0);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(.5*cos(angle)+.5, .48+sin(angle)*.1);
            }
            glEnd();

            glBegin(GL_POLYGON);
            glColor3f(1, 1, 1);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(.5*cos(angle)+.5, .5+sin(angle)*.1);
            }
            glEnd();
            glPopMatrix();
//ground
            glPushMatrix();
            glBegin(GL_QUADS);
            glColor3f(74510, 0.55686, 0.28627);
            glVertex2f(-1.,-1.);
            glVertex2f(1.,-1.);
            glColor3f(0.26667, 0.52941, 0.19216);
            glVertex2f(1.,-.8);
            glVertex2f(-1.,-.8);
            glEnd();
            glPopMatrix();


            //Stairs
            glPushMatrix();
            glBegin(GL_QUADS);



            glColor3f(74510, 0.55686, 0.28627);
            glVertex2f(.7,-.8);
            glVertex2f(0.,-.8);
            glColor3f(0.26667, 0.52941, 0.19216);
            glVertex2f(0,-.6);
            glVertex2f(0.7,-.6);

            glColor3f(74510, 0.55686, 0.28627);
            glVertex2f(0.6,-.6);
            glVertex2f(.2,-.6);
            glColor3f(0.26667, 0.52941, 0.19216);
            glVertex2f(.2,-.4);
            glVertex2f(.6,-.4);


            glEnd();
            glPopMatrix();


//push boxes

            glPushMatrix();
            glBegin(GL_QUADS);



            glColor3f(0, 0, 0);
            glVertex2f(0.1, -0.5);
            glVertex2f(0.1, -0.4);
            glColor3f(0.84706, 0.80000, 0.33333);
            glVertex2f(0, -0.4);
            glVertex2f(0, -0.5);


            glColor3f(0, 0, 0);
            glVertex2f(0, -0.4);
            glVertex2f(0, -0.5);
            glColor3f(0.84706, 0.80000, 0.33333);
            glVertex2f(-0.1, -0.5);
            glVertex2f(-0.1, -0.4);

            glColor3f(0, 0, 0);
            glVertex2f(-0.1, -0.5);
            glVertex2f(-0.1, -0.4);
            glColor3f(0.84706, 0.80000, 0.33333);
            glVertex2f(-0.2, -0.4);
            glVertex2f(-0.2, -0.5);

            glColor3f(0, 0, 0);
            glVertex2f(-0.2, -0.4);
            glVertex2f(-0.2, -0.5);
            glColor3f(0.84706, 0.80000, 0.33333);
            glVertex2f(-0.3, -0.5);
            glVertex2f(-0.3, -0.4);

            glEnd();
            glPopMatrix();

            glPushMatrix();
            glBegin(GL_QUADS);
            glColor3f(0.61176,0.81569,0.31765);
            glVertex2f(-1, -0.8);
            glVertex2f(-.6, -0.8);
            glColor3f(1, 1, 1);
            glVertex2f(-0.6, 0.2);
            glVertex2f(-1,0.2);
            glEnd();
            glColor3f(238.0/255.0,248.0/255.0,188.0/255.0);
            glBegin(GL_POLYGON);

            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(.3*cos(angle)-.9, .2+sin(angle)*.3);
            }

            glEnd();
            glPopMatrix();


            glPushMatrix();
            glBegin(GL_QUADS);
            glColor3f(0.61176,0.81569,0.31765);
            glVertex2f(-.8,-.8);
            glVertex2f(-.4, -0.8);
            glColor3f(1, 1, 1);
            glVertex2f(-0.4, -0.2);
            glVertex2f(-0.8, -0.2);
            glEnd();
            glColor3f(238.0/255.0,248.0/255.0,188.0/255.0);
            glBegin(GL_POLYGON);

            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(.2*cos(angle)-.6, .2*sin(angle)-.2);
            }

            glEnd();
            glPopMatrix();


            glPushMatrix();
            glBegin(GL_QUADS);
            glColor3f(0, 0, 0);
            glVertex2f(0.3, -0.2);
            glVertex2f(0.3, -0.1);
            glColor3f(0.84706, 0.80000, 0.33333);
            glVertex2f(0.2, -0.1);
            glVertex2f(0.2, -0.2);
            glEnd();
            glPopMatrix();
            if(GetKeyState(VK_LEFT)&& x>-1){
                x-=.001;

            }
            if(GetKeyState(VK_RIGHT)&&x<1){
               x+=.001;
            }
            if(GetKeyState(VK_UP)&& y<1){
                y+=.001;
            }
            if(GetKeyState(VK_DOWN)&&y>-1){
                y-=.001;
            }

            glPushMatrix();
            glTranslatef(x,y,.0);
            glBegin(GL_POLYGON);
            glColor3f(248.0/255.0,3.0/255.0,2.0/255.0);
            for(int i=0; i<=360; i++) {
                float angle;
                angle = i * 3.14 /180;
                glVertex2f(0.1*cos(angle)+0,  0+sin(angle)*.1);
            }

            glEnd();

            glPopMatrix();

//side canon

            glPushMatrix();

            glBegin(GL_POLYGON);

            glColor3f(1,1,1);
            glVertex2f(1.,-.8);
            glVertex2f(1.,-0.48);

            glColor3f(0,0,0);
            glVertex2f(.9,-.4);
            glVertex2f(.73,-.6);


            glEnd();
            glPopMatrix();
            SwapBuffers(hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
    case WM_CLOSE:
        PostQuitMessage(0);
        break;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN: {
        switch (wParam) {
        case VK_ESCAPE:
            PostQuitMessage(0);
            break;
        }
    }
    break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}

