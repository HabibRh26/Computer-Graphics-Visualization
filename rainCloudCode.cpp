#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void drawMan();
void drawCloud(int,int);
void funDrawCloud();
void rainAndCloud();
int main()
{
                int gmode,gdriver=DETECT;
                int i,j,k;
                initgraph(&gdriver,&gmode,"");
                rainAndCloud();
                line(0,400,679,400);
                getch();
                return 0;
}
void rainAndCloud()
{
                int i,j,k;
                for(i=0;!kbhit();i+=10)
                {
                                if(i>680)
                                                i=0;
                                line(0,460,679,460);
                                drawMan(i);
                                funDrawCloud();
                                for(j=120;j<480;j+=5)
                                                for(k=0;k<640;k+=5)
                                                {
                                                                if(j%2==0)
                                                                {
                                                                                if(k>i-25&&j>340&&k<i+50&&j<460){}
                                                                                else
                                                                                                putpixel(k+5,j,WHITE);
                                                                }
                                                }

                                delay(300);
                                cleardevice();
                                drawMan(i);
                                line(0,460,679,460);
                                funDrawCloud();
                                for(j=120;j<480;j+=5)
                                                for(k=0;k<640;k+=5)
                                                {
                                                                if(j%2!=0)
                                                                {
                                                                                if(k>i-25&&j>340&&k<i+50&&j<460){}
                                                                                else
                                                                                                putpixel(k,j,WHITE);
                                                                }
                                                }
                                delay(250);
                                cleardevice();
                }
}

void drawMan(int x)
{
                //rectangle(x-25,340,x+50,460);
                circle(x,380,20);

                line(x,400,x,430);
                line(x,415,x+10,410);//hand
                line(x,430,x-10,460);
                line(x,430,x+10,460);
                line(x+10,410,x+10,340);
                line(x-25,340,x+50,340);//umbrella base

                arc(x+12,340,0,180,35);
}


void funDrawCloud()
{
                drawCloud(100,100);
                drawCloud(152,125);
                drawCloud(400,100);
                drawCloud(452,125);
}

void drawCloud(int x,int y)
{
                int r=50;

                arc(x,y,45,135,r);
                arc(x+50,y,45,135,r);
                arc(x+100,y,45,135,r);
                arc(x,y,135,225,r);
                arc(x+50,y,135+90,225+90,r);
                arc(x,y,135+90,225+90,r);
                arc(x+100,y,135+90,225+90,r);
                arc(x+100,y,315,45,r);
}
