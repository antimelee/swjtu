// CG2016112422魏伟07View.cpp : implementation of the CCG201611242207View class
//

#include "stdafx.h"
#include "CG2016112422魏伟07.h"

#include "CG2016112422魏伟07Doc.h"
#include "CG2016112422魏伟07View.h"
#include "Light_dial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
bool x,y,z;//确定绕哪个轴旋转
int whichkind=0;//哪种动画
int sty=1;
int gsty=0;
int angle=0;//旋转角度
//光照属性
GLfloat	ambient[]={1,1,1,1};//环境光
GLfloat	diffuse[]={1.0,1.0,1.0,1.0};//漫反射光
GLfloat	specular[]={1.0,1.0,1.0,1.0};//镜面反射光
GLfloat position[] = {0.0f, 0.0f, 0.0f, 1.0f};
GLfloat direction[] = {-3.0f, -3.4f, -8.8f, 0.0f};
//材质属性
	GLfloat	mat_specular[]={1.0,1.0,0.0,1.0};
	GLfloat	mat_ambient[]={0.2,0.2,0.2,1.0};
	GLfloat	mat_diffuse[]={1.0,1.0,1.0,1.0};
	GLfloat mat_shininess[]={10.0};
//平移变量
float movex=0,movey=0,movez=0;
float Teapot_size=1,Sphere_size=1.5,Cone_size=1.5,Torus_size=0.4;
/////////////////////////////////////////////////////////////////////////////
// CCG201611242207View
void drawgraphic();
void drawground();
IMPLEMENT_DYNCREATE(CCG201611242207View, CScrollView)

BEGIN_MESSAGE_MAP(CCG201611242207View, CScrollView)
	//{{AFX_MSG_MAP(CCG201611242207View)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_COMMAND(ID_MENUITEM32771, OnMenuitemteapot)
	ON_COMMAND(ID_MENUITEM32773, OnMenuitemcone)
	ON_COMMAND(ID_MENUITEM32772, OnMenuitemball)
	ON_COMMAND(ID_MENUITEM32774, OnMenuitemtorus)
	ON_COMMAND(ID_MENUITEM32775, OnMenuitembrass)
	ON_COMMAND(ID_MENUITEM32776, OnMenuitembronze)
	ON_COMMAND(ID_MENUITEM32777, OnMenuitemgold)
	ON_COMMAND(ID_MENUITEM32778, OnMenuitemsilver)
	ON_COMMAND(ID_MENUITEM32779, OnMenuitemjade)
	ON_COMMAND(ID_MENUITEM32780, OnMenuitemplastic)
	ON_WM_TIMER()
	ON_COMMAND(ID_MENUITEM32782, OnMenuitemrotatex)
	ON_COMMAND(ID_MENUITEM32783, OnMenuitemrotatey)
	ON_COMMAND(ID_MENUITEM32784, OnMenuitemrotatez)
	ON_COMMAND(ID_MENUITEM32786, OnMenuitemmovex)
	ON_COMMAND(ID_MENUITEM32787, OnMenuitemmovey)
	ON_COMMAND(ID_MENUITEM32788, OnMenuitemmovez)
	ON_COMMAND(ID_MENUITEM32791, OnMenuitem32791)
	ON_COMMAND(ID_MENUITEM32792, OnMenuitem32792)
	ON_COMMAND(ID_MENUITEM32793, OnMenuitem32793)
	ON_COMMAND(ID_MENUITEM32794, OnMenuitem32794)
	ON_COMMAND(ID_MENUITEM32795, OnMenuitemstop)
	ON_WM_MOUSEWHEEL()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207View construction/destruction

CCG201611242207View::CCG201611242207View()
{
	// TODO: add construction code here

}

CCG201611242207View::~CCG201611242207View()
{
}

BOOL CCG201611242207View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= WS_CLIPCHILDREN | WS_CLIPSIBLINGS;
	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207View drawing

void CCG201611242207View::OnDraw(CDC* pDC)
{
	CCG201611242207Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	RenderScene();
	RenderScene();
	// TODO: add draw code for native data here
}

void CCG201611242207View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207View printing

BOOL CCG201611242207View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCG201611242207View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCG201611242207View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207View diagnostics

#ifdef _DEBUG
void CCG201611242207View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CCG201611242207View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CCG201611242207Doc* CCG201611242207View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCG201611242207Doc)));
	return (CCG201611242207Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCG201611242207View message handlers

int CCG201611242207View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	SetTimer(1,1000,NULL);
	m_pDC = new CClientDC(this);
if(!SetupPixelFormat())
return -1;
m_hGLRC = wglCreateContext(m_pDC->GetSafeHdc());
wglMakeCurrent(m_pDC->GetSafeHdc(),m_hGLRC);
	return 0;
}

void CCG201611242207View::OnDestroy() 
{
	CScrollView::OnDestroy();
	::wglMakeCurrent(NULL,NULL);
::wglDeleteContext(m_hGLRC);
if(m_hPalette)
DeleteObject(m_hPalette);
if(m_pDC)
delete m_pDC;
	// TODO: Add your message handler code here
	
}

void CCG201611242207View::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);
	glViewport(0, 0, cx, cy);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//透视投影
	gluPerspective(90,(GLfloat)cx/(GLfloat)cy,1,60);
    //glOrtho(-15,15,-15,15,1,100);
	gluLookAt(0,0,2,0,0,0,0,1,0);
	glTranslatef(0,0,-5);
	// TODO: Add your message handler code here
	
}
//光源初始化设置函数
void lightinit()
{
// 点光源, GL_POSITION属性的最后一个参数为1
	if(sty==1)
	{
	position[3]=1;
	glLightfv(GL_LIGHT0, GL_POSITION, position);//设置光源位置
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);//设置环境光
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);//设置漫反射光强度
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);//设置镜面反射光强度
	}

// 平行光源, GL_POSITION属性的最后一个参数为0
	else if(sty==2)
	{position[3]=0;
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	//glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION,0.8);//设置线型衰减因子
	}

// 聚光灯光源, 需要指定位置、方向、光锥半角
	//GLfloat spot_direction[] = {3.0,0.0,0.0};//聚光灯指向位置
	else if(sty==3)
	{position[3]=1;
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);//设置光源指向方向
	glLightf(GL_LIGHT0,GL_SPOT_EXPONENT,0.0);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90);//设置漫反射截止角
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
	}

//定义材质属性

	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

	glClearColor(1.0,1.0,1.0,1.0);
	glShadeModel(GL_SMOOTH);
//启用光源
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);
	//glEnable(GL_LIGHT2);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    //glClearColor(0,0,0,0);
	//glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	drawgraphic();
}
//绘制图形
void drawgraphic()
{
    switch(gsty)//根据gsty判断是要绘制哪一种图形
	{
	case 1://茶壶
		glPushMatrix();
		glRotatef(angle,x,y,z);
		glTranslatef(movex,movey,movez);
		glutSolidTeapot(Teapot_size);
		glPopMatrix();
		break;
	case 2://圆锥
		glPushMatrix();
		glRotatef(angle,x,y,z);
		glTranslatef(movex,movey,movez);
		glutSolidCone(Cone_size,Cone_size+0.5,20,20);
		glPopMatrix();
		break;
	case 3://球体
		glPushMatrix();
		glRotatef(angle,x,y,z);
		glTranslatef(movex,movey,movez);
		glutSolidSphere(Sphere_size,30,20);
		glPopMatrix();
		break;
	case 4://甜甜圈
		glPushMatrix();
		glRotatef(angle,x,y,z);
		glTranslatef(movex,movey,movez);
		glutSolidTorus(Torus_size,Torus_size+0.4,40,50);
		glPopMatrix();
		break;
	}
}
//画地板函数
void drawground()
{   
	int line,column;
     glPushMatrix();
	 glRotatef(30,1,0,0);
     for(line=0;line<20;line++){
         glPushMatrix();
         for(column=0;column<20;column++){
             
             glColor3f(0.0,0.0,0.0);//黑地板 
         
             glBegin(GL_QUADS);//逆时针画出来的正方形才是正面朝着我们的
             glVertex3f(-4.8,0.0,-5.0);
             glVertex3f(-5.0,0.0,-5.0);
             glVertex3f(-5.0,0.0,-4.8);
             glVertex3f(-4.8,0.0,-4.8);
             glEnd();
             
             glTranslatef(0.2,0.0,0.0);
             
             glColor3f(1.0,1.0,1.0);//白地板
             
             glBegin(GL_QUADS); 
             glVertex3f(-4.8,0.0,-5.0);
             glVertex3f(-5.0,0.0,-5.0);
             glVertex3f(-5.0,0.0,-4.8);
             glVertex3f(-4.8,0.0,-4.8);
             glEnd();
             
             glTranslatef(0.2,0.0,0.0);
             }
         
         glPopMatrix();//让原点回到每行初始位置(行最左侧) 
         glTranslatef(0.0,0.0,0.4);
         }
     glPopMatrix();

     glPushMatrix();
	 glRotatef(30,1,0,0);
     for(line=0;line<20;line++){
         glPushMatrix();
         for(column=0;column<20;column++){
             
             glColor3f(1.0,0.3,1.0);//紫地板
         
             glBegin(GL_QUADS);//逆时针画出来的正方形才是正面朝着我们的
             glVertex3f(-4.8,0.0,-4.8);
             glVertex3f(-5.0,0.0,-4.8);
             glVertex3f(-5.0,0.0,-4.6);
             glVertex3f(-4.8,0.0,-4.6);
             glEnd();
             
             glTranslatef(0.2,0.0,0.0);
             
             glColor3f(0.0,0.0,0.0);//黑地板
             
             glBegin(GL_QUADS); 
             glVertex3f(-4.8,0.0,-4.8);
             glVertex3f(-5.0,0.0,-4.8);
             glVertex3f(-5.0,0.0,-4.6);
             glVertex3f(-4.8,0.0,-4.6);
             glEnd();
             
             glTranslatef(0.2,0.0,0.0);
             }
         
         glPopMatrix();//让原点回到每行初始位置(行最左侧) 
         glTranslatef(0.0,0.0,0.4);
         }
     glPopMatrix();
}
BOOL CCG201611242207View::RenderScene(void)
{
	//每次绘制前清空颜色和深度缓存
	glClearColor(0.2,0.6,0.5,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//画地板
	drawground();
	//存储地板，使其不受光照影响
	glPushMatrix();
	//将绘制图形也旋转，以使得与地板重合
	glRotatef(30,1,0,0);
	//光照设置初始化
	lightinit();
	//绘制图形
	display();
	//关闭光照
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glPopMatrix();
	glFlush();
	SwapBuffers(m_pDC->GetSafeHdc());
	return TRUE;
}

BOOL CCG201611242207View::SetupPixelFormat(void)
{
	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),	// pfd 结构的大小
		1,	// 版本号
		PFD_DRAW_TO_WINDOW |	// 支持在窗口中绘图
		PFD_SUPPORT_OPENGL |	// 支持 OpenGL
		PFD_DOUBLEBUFFER,	// 双缓存模式
		PFD_TYPE_RGBA,	// RGBA 颜色模式
		24,	// 24 位颜色深度
		0, 0, 0, 0, 0, 0,	// 忽略颜色位
		0,	// 没有非透明度缓存
		0,	//  忽略移位位
		0,	//  无累加缓存
		0, 0, 0, 0,	// 忽略累加位
		32,	// 32 位深度缓存
		0,	//  无模板缓存
		0,	//  无辅助缓存
		PFD_MAIN_PLANE,	// 主层
		0,	// 保留
		0, 0, 0	// 忽略层,可见性和损毁掩模
	};
	int iPixelFormat;
	// 为设备描述表得到最匹配的像素格式
	if ((iPixelFormat = ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0)
	{
		char s[] = "ChoosePixelFormat Failed";

		MessageBox(TEXT("ChoosePixelFormat Failed"), NULL, MB_OK); return FALSE;
	}

	// 设置最匹配的像素格式为当前的像素格式
	if (SetPixelFormat(m_pDC->GetSafeHdc(), iPixelFormat, &pfd) == FALSE)
	{
		MessageBox(TEXT("SetPixelFormat Failed"), NULL, MB_OK); return FALSE;
	}
	if (pfd.dwFlags & PFD_NEED_PALETTE)
		SetLogicalPalette();//设置逻辑调色板

	return TRUE;
}
void CCG201611242207View::SetLogicalPalette(void)
{
	struct
	{
		WORD Version;
		WORD NumberOfEntries; PALETTEENTRY aEntries[256];
	} logicalPalette = { 0x300, 256 };

	BYTE reds[] = { 0, 36, 72, 109, 145, 182, 218, 255 };
	BYTE greens[] = { 0, 36, 72, 109, 145, 182, 218, 255 };
	BYTE blues[] = { 0, 85, 170, 255 };

	for (int colorNum = 0; colorNum<256; ++colorNum)
	{
		logicalPalette.aEntries[colorNum].peRed = reds[colorNum & 0x07];
		logicalPalette.aEntries[colorNum].peGreen = greens[(colorNum >> 0x03) & 0x07];
		logicalPalette.aEntries[colorNum].peBlue = blues[(colorNum >> 0x06) & 0x03];
		logicalPalette.aEntries[colorNum].peFlags = 0;
	}

	m_hPalette = CreatePalette((LOGPALETTE*)&logicalPalette);
}
//菜单选择绘制茶壶
void CCG201611242207View::OnMenuitemteapot() 
{
	// TODO: Add your command handler code here
	Light_dial dial;
	gsty=1;
	if (dial.DoModal() == 1)
	{
		sty= dial.style;
		if(sty!=1)
		{
		ambient[0]=0;
		ambient[1]=0;
		ambient[2]=0;
		}
		else
		{
		ambient[0]=1;
		ambient[1]=1;
		ambient[2]=1;
		}
		position[0] = dial.pox;
		position[1] = dial.poy;
		position[2]= dial.poz;
		direction[0]= dial.dix;
		direction[1] = dial.diy;
		direction[2]= dial.diz;
	}
	RenderScene();
}
//菜单选择画椎体
void CCG201611242207View::OnMenuitemcone() 
{
	// TODO: Add your command handler code here
	Light_dial dial;
	gsty=2;
	float x1,x2,y1,y2,z1,z2;
	if (dial.DoModal() == 1)
	{
		sty= dial.style;
			if(sty!=1)
		{
		ambient[0]=0;
		ambient[1]=0;
		ambient[2]=0;
		}
			else
		{
		ambient[0]=1;
		ambient[1]=1;
		ambient[2]=1;
		}
		position[0] = dial.pox;
		position[1] = dial.poy;
		position[2]= dial.poz;
		direction[0]= dial.dix;
		direction[1] = dial.diy;
		direction[2]= dial.diz;
	}
	RenderScene();
}
//菜单选择画球体
void CCG201611242207View::OnMenuitemball() 
{
	// TODO: Add your command handler code here
	Light_dial dial;
	gsty=3;
	float x1,x2,y1,y2,z1,z2;
	if (dial.DoModal() == 1)
	{
		sty= dial.style;
			if(sty!=1)
		{
		ambient[0]=0;
		ambient[1]=0;
		ambient[2]=0;
		}
			else
		{
		ambient[0]=1;
		ambient[1]=1;
		ambient[2]=1;
		}
		position[0] = dial.pox;
		position[1] = dial.poy;
		position[2]= dial.poz;
		direction[0]= dial.dix;
		direction[1] = dial.diy;
		direction[2]= dial.diz;
	}
	RenderScene();
}
//菜单选择画甜甜圈
void CCG201611242207View::OnMenuitemtorus() 
{
	// TODO: Add your command handler code here
	Light_dial dial;
	gsty=4;
	float x1,x2,y1,y2,z1,z2;
	if (dial.DoModal() == 1)
	{
		sty= dial.style;
			if(sty!=1)
		{
		ambient[0]=0;
		ambient[1]=0;
		ambient[2]=0;
		}
			else
		{
		ambient[0]=1;
		ambient[1]=1;
		ambient[2]=1;
		}
		position[0] = dial.pox;
		position[1] = dial.poy;
		position[2]= dial.poz;
		direction[0]= dial.dix;
		direction[1] = dial.diy;
		direction[2]= dial.diz;
	}
	RenderScene();
}
//菜单选择材质：黄铜
void CCG201611242207View::OnMenuitembrass() 
{
	// TODO: Add your command handler code here
	if(sty==1)
	{mat_ambient[0]=0.329412;
		mat_ambient[1]=0.223529;
		mat_ambient[2]=0.027451;
		mat_ambient[3]=1;
	}
		mat_diffuse[0]=0.780392;
		mat_diffuse[1]=0.568627;
		mat_diffuse[2]=0.113725;
		mat_diffuse[3]=1.000000;
		mat_specular[0]=0.992157;
		mat_specular[1]=0.941176;
		mat_specular[2]=0.807843;
		mat_specular[3]=1.000000;
		mat_shininess[0]=27.897400;
	RenderScene();
}
//菜单选择材质：青铜
void CCG201611242207View::OnMenuitembronze() 
{
	// TODO: Add your command handler code here
	if(sty==1)
	{
		mat_ambient[0]=0.212500;
		mat_ambient[1]=0.127500;
		mat_ambient[2]=0.054000;
		mat_ambient[3]=1;
	}
		mat_diffuse[0]=0.714000;
		mat_diffuse[1]=0.428400;
		mat_diffuse[2]=0.181440;
		mat_diffuse[3]=1.000000;
		mat_specular[0]=0.393548;
		mat_specular[1]= 0.271906;
		mat_specular[2]=0.166721;
		mat_specular[3]=1.000000;
		mat_shininess[0]=25.600000;
	RenderScene();
}
//菜单选择材质：金
void CCG201611242207View::OnMenuitemgold() 
{
	// TODO: Add your command handler code here
	if(sty==1)
	{
		mat_ambient[0]=0.247250;
		mat_ambient[1]=0.199500;
		mat_ambient[2]=0.074500;
		mat_ambient[3]=1;
	}
		mat_diffuse[0]=0.751640;
		mat_diffuse[1]=0.606480;
		mat_diffuse[2]=0.226480;
		mat_diffuse[3]=1.000000;
		mat_specular[0]=0.628281;
		mat_specular[1]= 0.555802;
		mat_specular[2]= 0.366065;
		mat_specular[3]=1.000000;
		mat_shininess[0]=51.200001;
	RenderScene();	
}
//菜单选择材质：银
void CCG201611242207View::OnMenuitemsilver() 
{
	// TODO: Add your command handler code here
	if(sty==1)
	{
		mat_ambient[0]=0.192250;
		mat_ambient[1]=0.192250;
		mat_ambient[2]=0.192250;
		mat_ambient[3]=1;
	}
		mat_diffuse[0]=0.507540;
		mat_diffuse[1]=0.507540;
		mat_diffuse[2]= 0.507540;
		mat_diffuse[3]=1.000000;
		mat_specular[0]=0.508273;
		mat_specular[1]= 0.508273;
		mat_specular[2]= 0.508273;
		mat_specular[3]=1.000000;
		mat_shininess[0]=51.200001;
	RenderScene();	
}
//菜单选择材质：翡翠
void CCG201611242207View::OnMenuitemjade() 
{
	// TODO: Add your command handler code here
	if(sty==1)
	{
		mat_ambient[0]=0.021500;
		mat_ambient[1]=0.174500;
		mat_ambient[2]=0.021500;
		mat_ambient[3]=0.550000;
	}
		mat_diffuse[0]=0.075680;
		mat_diffuse[1]=0.614240;
		mat_diffuse[2]= 0.075680;
		mat_diffuse[3]=0.550000;
		mat_specular[0]=0.633000;
		mat_specular[1]=0.727811;
		mat_specular[2]= 0.633000;
		mat_specular[3]=0.550000;
		mat_shininess[0]=76.800003;
	RenderScene();
}
//菜单选择材质：黑塑料
void CCG201611242207View::OnMenuitemplastic() 
{
	// TODO: Add your command handler code here
		mat_ambient[0]=0;
		mat_ambient[1]=0;
		mat_ambient[2]=0;
		mat_ambient[3]=1;
		mat_diffuse[0]=0.01;
		mat_diffuse[1]=0.01;
		mat_diffuse[2]= 0.01;
		mat_diffuse[3]=0.5500;
		mat_specular[0]=1;
		mat_specular[1]=0.5;
		mat_specular[2]= 0.5;
		mat_specular[3]=0.5;
		mat_shininess[0]=32;
	RenderScene();	
}
//时钟响应函数，用来形成动画
void CCG201611242207View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(whichkind)
	{
	case 1:
	{
	angle+=15;
	RenderScene();
	break;
	}
	case 2:
	{
	angle+=15;
	RenderScene();
	break;
	}
	case 3:
	{
	angle+=15;
	RenderScene();
	break;
	}
	case 4:
	{
	movex+=0.2;
	if(movex>=8.0)
	movex=-8;
	RenderScene();
	break;
	}
	case 5:
	{
	movey+=0.2;
	if(movey>=8.0)
	movey=-8;
	RenderScene();
	break;
	}
	case 6:
	{
	movez+=0.2;
	if(movez>=8.0)
	movez=-8;
	RenderScene();
	break;
	}
	case 7:
	{
		srand((unsigned int)time(0));
		mat_ambient[0]=rand() % (1000) / (float)(1000);
		mat_ambient[1]=rand() % (1000) / (float)(1000);
		mat_ambient[2]=rand() % (1000) / (float)(1000);
		RenderScene();
		break;
	}
	case 8:
	{
		srand((unsigned int)time(0));
		mat_diffuse[0]=rand() % (1000) / (float)(1000);
		mat_diffuse[1]=rand() % (1000) / (float)(1000);
		mat_diffuse[2]=rand() % (1000) / (float)(1000);
		RenderScene();
		break;
	}
	case 9:
	{
		srand((unsigned int)time(0));
		mat_specular[0]=rand() % (1000) / (float)(1000);
		mat_specular[1]=rand() % (1000) / (float)(1000);
		mat_specular[2]=rand() % (1000) / (float)(1000);
		RenderScene();
		break;
	}
	case 10:
	{
		srand((unsigned int)time(0));
		mat_ambient[0]=rand() % (1000) / (float)(1000);
		mat_ambient[1]=rand() % (1000) / (float)(1000);
		mat_ambient[2]=rand() % (1000) / (float)(1000);
		mat_diffuse[0]=rand() % (1000) / (float)(1000);
		mat_diffuse[1]=rand() % (1000) / (float)(1000);
		mat_diffuse[2]=rand() % (1000) / (float)(1000);
		mat_specular[0]=rand() % (1000) / (float)(1000);
		mat_specular[1]=rand() % (1000) / (float)(1000);
		mat_specular[2]=rand() % (1000) / (float)(1000);
		RenderScene();
		break;
	}
	}
	CScrollView::OnTimer(nIDEvent);
}
//绕X轴旋转
void CCG201611242207View::OnMenuitemrotatex() 
{
	// TODO: Add your command handler code here
	whichkind=1;
	x=1;
	y=0;
	z=0;
}
//绕Y轴旋转
void CCG201611242207View::OnMenuitemrotatey() 
{
	// TODO: Add your command handler code here
		whichkind=2;
	x=0;
	y=1;
	z=0;
}
//绕Z轴旋转
void CCG201611242207View::OnMenuitemrotatez() 
{
	// TODO: Add your command handler code here
		whichkind=3;
	x=0;
	y=0;
	z=1;
}
//沿X轴平移
void CCG201611242207View::OnMenuitemmovex() 
{
	// TODO: Add your command handler code here
	whichkind=4;
}
//沿y轴平移
void CCG201611242207View::OnMenuitemmovey() 
{
	// TODO: Add your command handler code here
	whichkind=5;
}
//沿z轴平移
void CCG201611242207View::OnMenuitemmovez() 
{
	// TODO: Add your command handler code here
	whichkind=6;	
}

//改变材质的环境光
void CCG201611242207View::OnMenuitem32791() 
{
	// TODO: Add your command handler code here
	whichkind=7;
}
//改变材质的漫反射
void CCG201611242207View::OnMenuitem32792() 
{
	// TODO: Add your command handler code here
	whichkind=8;
}
//改变材质的镜面反射
void CCG201611242207View::OnMenuitem32793() 
{
	// TODO: Add your command handler code here
	whichkind=9;
}
//改变材质
void CCG201611242207View::OnMenuitem32794() 
{
	// TODO: Add your command handler code here
	whichkind=10;	
}
//停止动画
void CCG201611242207View::OnMenuitemstop() 
{
	// TODO: Add your command handler code here
	whichkind=0;	
}
//鼠标滚轮响应函数
BOOL CCG201611242207View::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
	// TODO: Add your message handler code here and/or call default
		switch (gsty)
		{
		case 1:
			{
				Teapot_size+=(float)zDelta/1200;
				break;
			}
		case 3:
			{
				Sphere_size+=(float)zDelta/1200;
				break;
			}
		case 2:
			{
				Cone_size+=(float)zDelta/1200;
				break;
			}
		case 4:
			{
				Torus_size+=(float)zDelta/1200;
				break;
			}
		}
		RenderScene();
	return CScrollView::OnMouseWheel(nFlags, zDelta, pt);
}
