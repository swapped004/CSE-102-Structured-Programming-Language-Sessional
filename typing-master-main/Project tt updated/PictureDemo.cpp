# include "iGraphics.h"
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<windowsx.h>
#include<mmsystem.h>
#pragma comment(lib,"Winmm.lib")

char str[100], str2[100],sac1[10],sbc1[10],scc1[10],s_time_h[10],s_time_n[10],s_time_e[10], s_time[10];
///str is the string the user write, sca1,sbc1,scc1 are used to convert int value to string.
char stringm[500],stringn[500],stringo[500], stringp[500], str3[100], str4[100],str5[100],str6[100],str7[100];
///stringm is the string for the easy string, stingn for the normal, stringo for the hard
int flag=0,flag1=0, nflag = 0;
///flag is used to determine what kind of string the user chose
int dex=800,dem=800,deh=800,corner_flag=1,z=0;
/// dex, dem, deh are the co-ordinates of x for there kind of string
int dc=0, t_st_hard = 30, t_st_normal = 45, t_st_easy = 60;
/// that is used for color change
int randa=0,random = 0, uflag = 0;
/// for changing the string randomly.
int colmode=0;

int len,i,j,comp_flag = 0,comp_flag1=0;

int mode=0, tme = 0;
/// for creating several windows
int length=0,length1=0,length2=0,lengthp = 0,lengthp1 = 0,lengthp2 = 0 ;
double ac,bc,cc,st_au;
/// for the accuracy
int ac1,bc1,cc1;

int len1=0,start=0,len2,len3,len4,len5;
///for determining typing speed for every level
int tme_h, tme_n, tme_e, tme_temp;

int t_st_hard1, t_st_normal1, t_st_easy1;

int s_hard, s_nor, s_easy;

char s_hard_s[10], s_nor_s[10], s_easy_s[10], TIME[10], *cuteasy;

char st_hard[100], st_normal[100], st_easy[100];

char t_st_hard2[10], t_st_normal2[10], t_st_easy2[10];

double s_nor1, s_easy1;

char stringp1[400],stringp2[400];

int st_au1_hard, st_au1_normal, st_au1_easy;

double st_au_hard, st_au_normal, st_au_easy;

char st_au2_hard[10],st_au2_normal[10],st_au2_easy[10];

char tok[100][100], tok1[100][100];

int cm_i,cm_j=0,cm_k=0,cm_l,cm_m=0,cm_n=0,cm_ara[100];

struct performace{
    int score;
    char name[10];
};
struct performace high[10];

struct performace low[10];

struct performace lower[10];

char user_hard[10];

char user_low[10];

char user_lower[10];

void drawTextBox()
{
	iRectangle(30, 50, 740, 300);
}

char *strcut_easy(char *strconst)
{
    char *strncons, i;
    strncons = (strconst+1);
    return strncons;
}

int word_easy(char strfff[])
{
    int k, wordeasy = 0;
    for(k = 0; k < strlen(strfff); k++){
        if(strfff[k] == ' '){
            wordeasy++;
        }
    }
    return (wordeasy+1);
}

///for determining score for level hard
void score_hard()
{
    s_hard =(80*cc1)+(20*tme_h);
    itoa(s_hard,s_hard_s,10);
}

///for determining score for normal level
void score_normal()
{
    s_nor1 = ((80*bc1)+(20*tme_n))*0.75;
    s_nor=(int)s_nor1;
    itoa(s_nor,s_nor_s,10);
}

///for determining score for easy level
void score_easy()
{
    s_easy1 = ((80*ac1)+(20*tme_e))*.5;
    s_easy = (int)s_easy1;
    itoa(s_easy,s_easy_s,10);
}
///in case accuracy is less than 20%
void score_hard_sp()
{
    s_hard = (100*cc1);
    itoa(s_hard,s_hard_s,10);
}
///in case accuracy is less than 20%
void score_easy_sp()
{
    s_easy1 = (100*ac1)*.5;
    s_easy = (int)s_easy1;
    itoa(s_easy,s_easy_s,10);
}
///in case accuracy is less than 20%
void score_normal_sp()
{
    s_nor1 = (100*bc1)*0.75;
    s_nor=(int)s_nor1;
    itoa(s_nor,s_nor_s,10);
}
///to determining accuracy for easy level
int accu_easy(char str2[], char stringm[])
{
    int j,c = 0;
    for(j = 0; j <= strlen(stringm); j++){
        if(stringm[j] == str2[j]){
            c++;
        }
        else continue;
    }
    ac = (c*1.0/strlen(stringm))*100;
    ac1=(int)ac;
    return ac1;
}



///to determine accuracy for level normal
int accu_nor(char str2[], char stringn[])
{
    int j,c = 0;
    for(j = 0; j <= strlen(stringn); j++){
        if(stringn[j] == str2[j]){
            c++;
        }
        else continue;
    }
    bc = (c*1.0/strlen(stringn))*100;
    bc1=(int)bc;
    return bc1;
}


/// to determine accuracy for hard level
int accu_hard(char str2[], char stringo[])
{
    int j,c = 0;
    for(j = 0; j <= strlen(stringo); j++){
        if(stringo[j] == str2[j]){
            c++;
        }
        else continue;
    }
    cc = (c*1.0/strlen(stringo))*100;
    cc1=(int)cc;
    return cc1;
}

int accuracy_st_hard(char str7[], char stringp[])
{
    int j,c = 0;
    for(j = 0; j <= strlen(stringp); j++){
        if(stringp[j] == str7[j]){
            c++;
        }
        else continue;
    }
    st_au_hard = (c*1.0/strlen(stringp))*100;
    st_au1_hard=(int)st_au_hard;
    return st_au1_hard;
}

int accuracy_st_normal(char str7[], char stringp1[])
{
    int j,c = 0;
    for(j = 0; j <= strlen(stringp1); j++){
        if(stringp1[j] == str7[j]){
            c++;
        }
        else continue;
    }
    st_au_normal = (c*1.0/strlen(stringp1))*100;
    st_au1_normal=(int)st_au_normal;
    return st_au1_normal;
}

int accuracy_st_easy(char str7[], char stringp2[])
{
    int j,c = 0;
    for(j = 0; j <= strlen(stringp2); j++){
        if(stringp2[j] == str7[j]){
            c++;
        }
        else continue;
    }
    st_au_easy = (c*1.0/strlen(stringp2))*100;
    st_au1_easy=(int)st_au_easy;
    return st_au1_easy;
}
///function to determine speed
void hard_speed()
{
    tme_h = (word_easy(str2))*60/tme_temp;
}


///function to determine speed
void normal_speed()
{
    tme_n = (word_easy(str2))*60/tme_temp;
}


///function to determine speed
void easy_speed()
{
    tme_e = (word_easy(str2))*60/tme_temp;
}

void strrtok(char rts[])
{
    for(cm_i = 0; cm_i < strlen(rts); cm_i++){
        if(rts[cm_i] == ' '){
            tok[cm_j][cm_k] = '\0';
            cm_k = 0;
            cm_j++;
        }
        else{
            tok[cm_j][cm_k++] = rts[cm_i];
        }
    }
    tok[cm_j][cm_k] = '\0';
}

void strrtok1(char rts[])
{
    for(cm_l = 0; cm_l < strlen(rts); cm_l++){
        if(rts[cm_l] == ' '){
            tok1[cm_m][cm_n] = '\0';
            cm_n = 0;
            cm_m++;
        }
        else{
            tok1[cm_m][cm_n++] = rts[cm_l];
        }
    }
    tok1[cm_m][cm_n] = '\0';
}

void compare()
{
    int s,t;
    for(s = 0; s <= cm_j; s++){
        t = strcmp(tok[s],tok1[s]);
        if(t == 0){
            cm_ara[s] = 0;
        }
        else{
            cm_ara[s] = 1;
        }
    }
}

void iDraw()
{
	iClear();

	iSetColor(255,255,255);
	iFilledRectangle(2,2,796,796);


	if(mode == 0){
	    for(i = 195, j = 195; i <= 599; i = i + 25){
            iSetColor(0,255,255);
            iFilledCircle(i,j,3);
        }
        for(i = 195, j = 220; j <= 599; j = j  + 25){
            iSetColor(0,255,255);
            iFilledCircle(i,j,3);
        }
        for(i = 195, j = 604; i <= 599; i = i + 25){
            iSetColor(0,255,255);
            iFilledCircle(i,j,3);
        }
        for(i = 604, j = 598; j >= 195; j = j - 25){
            iSetColor(0,255,255);
            iFilledCircle(i,j,3);
        }
        iSetColor(255,255,255);
        drawTexture(2,2,textures[10]);

        iSetColor(100, 30, 200);
        iText(250,750,"## T Y P I N G   T U T O R ##",  GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,255,255);
        iFilledRectangle(200,200,400,400);
        iRectangle(190,190,420,420);
        iSetColor(255,0,127);
        iText(190,150, ">> [OR] Press the number of keys to select your choice", GLUT_BITMAP_HELVETICA_12);

        iText(190,110, ">> Always Press left arrow to go back", GLUT_BITMAP_HELVETICA_12);

        iText(190,130, ">> Press <END> key to quit the game", GLUT_BITMAP_HELVETICA_12);

        iText(190,170, ">> Click over the options to make your choice", GLUT_BITMAP_HELVETICA_12);

        iSetColor(255,51,51);

        iText(285,550,"*** MAIN MENU ***",GLUT_BITMAP_TIMES_ROMAN_24);

        iText(220,450,"1.NEW GAME", GLUT_BITMAP_HELVETICA_18);

        iText(220,410,"2.HALL OF FAME", GLUT_BITMAP_HELVETICA_18);

        iText(218,213,"5.QUIT GAME", GLUT_BITMAP_HELVETICA_18);

        iText(220,370,"3.INSTRUCTIONS", GLUT_BITMAP_HELVETICA_18);

        iText(220,330,"4.CREDITS", GLUT_BITMAP_HELVETICA_18);


        iText(490,213," GO BACK",GLUT_BITMAP_HELVETICA_18);
    }

    else if(mode == 1){

	    for(i = 195, j = 195; i <= 599; i = i + 25){
            iSetColor(0,255,255);
            iFilledCircle(i,j,3);
        }
        for(i = 195, j = 220; j <= 599; j = j  + 25){
            iSetColor(0,255,255);
            iFilledCircle(i,j,3);
        }
        for(i = 195, j = 604; i <= 599; i = i + 25){
            iSetColor(0,255,255);
            iFilledCircle(i,j,3);
        }
        for(i = 604, j = 598; j >= 195; j = j - 25){
            iSetColor(0,255,255);
            iFilledCircle(i,j,3);
        }
        iSetColor(255,255,255);
        drawTexture(2,2,textures[13]);

        iSetColor(100,30,200);
        iText(250,650,"## T Y P I N G   T U T O R ##",  GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iFilledRectangle(200,200,400,400);
        iSetColor(0,255,255);
        iRectangle(190,190,420,420);
        iSetColor(0,0,0);

        iText(220,450,"<#> SELECT LEVEL", GLUT_BITMAP_HELVETICA_18);

        iText(218,213,"QUIT GAME", GLUT_BITMAP_HELVETICA_18);

        iText(350, 420,"1.Hard",  GLUT_BITMAP_HELVETICA_18);

        iText(350, 390,"2.Normal",  GLUT_BITMAP_HELVETICA_18);

        iText(350, 360,"3.Easy",  GLUT_BITMAP_HELVETICA_18);

        iSetColor(255,0,127);
        iText(190,130, ">> Click over the options to make your choice", GLUT_BITMAP_HELVETICA_12);

        iText(190,110, ">> [OR] Press the number of keys to select your choice", GLUT_BITMAP_HELVETICA_12);

        iText(490,213," GO BACK",GLUT_BITMAP_HELVETICA_18);
    }

    else if(mode == 15){
        drawTexture(2,2,textures[14]);
        iSetColor(100,30,200);
        iText(250,650,"## T Y P I N G   T U T O R ##",  GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,255);
        iText(250,525,"CHOOSE GAME MODE",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,229,204);
        iFilledRectangle(305,450,150,50);
        iFilledRectangle(305,390,150,50);
        ///iFilledRectangle(305,330,150,50);
        iSetColor(0,0,0);
        iText(330,465,"STATIC",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(325,405,"DYNAMIC",GLUT_BITMAP_TIMES_ROMAN_24);
        ///iText(327,348,"PASSAGE",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    else if(mode == 16){
        iSetColor(150, 80,200);

        iText(320, 700, "LET'S PLAY!!", GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,750,"## T Y P I N G   T U T O R ##", GLUT_BITMAP_TIMES_ROMAN_24);

        drawTextBox();
		iSetColor(255, 0, 0);
        iText(30, 370, "Click inside the box to start");
    }

    else if(mode == 17){
        iSetColor(255,255,255);

        iSetColor(150, 80,200);

        iText(320, 700, "LET'S PLAY!!", GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,750,"## T Y P I N G   T U T O R ##",  GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 0, 0);
        drawTextBox();
		iText(40,320,str6,GLUT_BITMAP_HELVETICA_18);
		iText(30,370,"Press ENTER key to finish");

		iText(35,700,"TIMES LEFT(sec):",GLUT_BITMAP_TIMES_ROMAN_24);

        if(flag == 1){
            iText(5,600,stringp,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(232,700,itoa(t_st_hard,t_st_hard2,10),GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(flag == 2){
            iText(5,600,stringp1,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(232,700,itoa(t_st_normal,t_st_normal2,10),GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(flag == 3){
            iText(5,600,stringp2,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(232,700,itoa(t_st_easy,t_st_easy2,10),GLUT_BITMAP_TIMES_ROMAN_24);

        }
    }
    else if(mode == -2){
        iSetColor(255,255,255);
        if(flag == 1){
            accuracy_st_hard(str7,stringp);
            if(st_au1_hard < 90){
                mode == 19;
                iFilledRectangle(2,2,796,796);
                accuracy_st_hard(str7,stringp);
                drawTexture(2,2,textures[16]);
                iSetColor(255,255,0);
                iFilledRectangle(35,90,190,50);
                iFilledRectangle(660,105,190,50);
                iFilledRectangle(270,735,190,50);
                iSetColor(255,0,255);
                iText(45,102,"MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(700,121,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(277,750,"ACCURACY:",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(440,750,"%",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(417,750,itoa(st_au1_hard,st_au2_hard,10),GLUT_BITMAP_TIMES_ROMAN_24);
            }
            else{
                mode == 18;
                drawTexture(2,2,textures[15]);
                iSetColor(255,255,255);
                iFilledRectangle(285,30,180,50);
                iFilledRectangle(260,735,200,50);
                iSetColor(0,0,0);
                iText(295,40,"MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
                iFilledRectangle(285,30,180,50);
                iText(445,750,"%",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(417,750,itoa(st_au1_hard,st_au2_hard,10),GLUT_BITMAP_TIMES_ROMAN_24);
            }
        }
        else if(flag == 2){
            accuracy_st_normal(str7,stringp1);
            if(st_au1_normal < 90){
                mode == 19;
                iFilledRectangle(2,2,796,796);
                accuracy_st_normal(str7,stringp1);
                drawTexture(2,2,textures[16]);
                iSetColor(255,255,0);
                iFilledRectangle(35,90,190,50);
                iFilledRectangle(660,105,190,50);
                iFilledRectangle(270,735,190,50);
                iSetColor(255,0,255);
                iText(45,102,"MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(700,121,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(277,750,"ACCURACY:",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(440,750,"%",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(417,750,itoa(st_au1_normal,st_au2_normal,10),GLUT_BITMAP_TIMES_ROMAN_24);
            }
            else{
                mode == 18;
                drawTexture(2,2,textures[15]);
                iSetColor(255,255,255);
                iFilledRectangle(285,30,180,50);
                iFilledRectangle(260,735,200,50);
                iSetColor(0,0,0);
                iText(295,40,"MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(277,750,"ACCURACY:",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(445,750,"%",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(417,750,itoa(st_au1_normal,st_au2_normal,10),GLUT_BITMAP_TIMES_ROMAN_24);
            }
        }
        else if(flag == 3){
            accuracy_st_easy(str7,stringp2);
            if(st_au1_easy < 90){
                mode == 19;
                iFilledRectangle(2,2,796,796);
                accuracy_st_easy(str7,stringp2);
                drawTexture(2,2,textures[16]);
                iSetColor(255,255,0);
                iFilledRectangle(35,90,190,50);
                iFilledRectangle(660,105,190,50);
                iFilledRectangle(270,735,190,50);
                iSetColor(255,0,255);
                iText(45,102,"MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(700,121,"EXIT",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(277,750,"ACCURACY:",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(440,750,"%",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(417,750,itoa(st_au1_easy,st_au2_easy,10),GLUT_BITMAP_TIMES_ROMAN_24);
            }
            else{
                mode == 18;
                drawTexture(2,2,textures[15]);
                iSetColor(255,255,255);
                iFilledRectangle(285,30,180,50);
                iFilledRectangle(260,735,200,50);
                iSetColor(0,0,0);
                iText(295,40,"MAIN MENU",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(277,750,"ACCURACY:",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(445,750,"%",GLUT_BITMAP_TIMES_ROMAN_24);
                iText(417,750,itoa(st_au1_easy,st_au2_easy,10),GLUT_BITMAP_TIMES_ROMAN_24);
            }
        }
    }
    else if(mode == -3){
        drawTexture(2,2,textures[17]);
        iSetColor(255,0,0);
        iText(14,746,"Press enter to continue",GLUT_BITMAP_TIMES_ROMAN_24);
    }

    else if(mode == 2){
        iSetColor(150, 80,200);

        iText(320, 700, "LET'S PLAY!!", GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,750,"## T Y P I N G   T U T O R ##",  GLUT_BITMAP_TIMES_ROMAN_24);

        drawTextBox();
		iSetColor(255, 0, 0);
        iText(30, 370, "Click inside the box to start");
        corner_flag=0;
    }

    else if(mode == 5){
        iSetColor(255,255,255);

        iSetColor(150, 80,200);

        iText(320, 700, "LET'S PLAY!!", GLUT_BITMAP_TIMES_ROMAN_24);

        iText(250,750,"## T Y P I N G   T U T O R ##",  GLUT_BITMAP_TIMES_ROMAN_24);

		iSetColor(255, 0, 0);
        drawTextBox();
		iText(40,320,str,GLUT_BITMAP_HELVETICA_18);
		iText(30,370,"Press ENTER key to finish");

		iText(40,715,"TIME:",GLUT_BITMAP_TIMES_ROMAN_24);

		iText(120,715,itoa(tme,TIME,10),GLUT_BITMAP_TIMES_ROMAN_24);

        if(mode==5&&flag==3)
        {
            if(dex>1){
                cuteasy=stringm;
                iSetColor(51+dc,51+dc,255-dc);
                iText(0+dex,600,stringm,GLUT_BITMAP_TIMES_ROMAN_24);
            }
            else{
                nflag = 1;
                cuteasy=strcut_easy(cuteasy);
                Sleep(300);
                iSetColor(51+dc,51+dc,255-dc);
                iText(0,600,cuteasy,GLUT_BITMAP_TIMES_ROMAN_24);
                if(strlen(cuteasy)==0)
                    nflag = 0;
            }
        }

        if(mode==5&&flag==2)
        {
            if(dem>1){
                cuteasy=stringn;
                iSetColor(51+dc,51+dc,255-dc);
                iText(0+dem,600,stringn,GLUT_BITMAP_TIMES_ROMAN_24);
            }
            else{
                nflag = 1;
                cuteasy=strcut_easy(cuteasy);
                Sleep(200);
                iSetColor(51+dc,51+dc,255-dc);
                iText(0,600,cuteasy,GLUT_BITMAP_TIMES_ROMAN_24);
                if(strlen(cuteasy)==0)
                    nflag = 0;
            }
        }

        if(mode==5&&flag==1)
        {
            if(deh>1){
                cuteasy=stringo;
                iSetColor(51+dc,51+dc,255-dc);
                iText(0+deh,600,stringo,GLUT_BITMAP_TIMES_ROMAN_24);
            }
            else{
                nflag = 1;
                cuteasy=strcut_easy(cuteasy);
                Sleep(100);
                iSetColor(51+dc,51+dc,255-dc);
                iText(0,600,cuteasy,GLUT_BITMAP_TIMES_ROMAN_24);
                if(strlen(cuteasy)==0)
                    nflag = 0;
            }
        }
    }

    else if(mode == -4){
        drawTexture(0,0,textures[18]);
        iSetColor(0,255,255);
        iText(300,710,"YOU WROTE:",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(295,705,"____________",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,0,0);
        iFilledRectangle(125,115,130,40);
        iSetColor(0,255,255);
        iText(135,125,"CONTINUE",GLUT_BITMAP_HELVETICA_18);
        if(comp_flag==0 && flag == 1)
        {
            strrtok(str2);
            strrtok1(stringo);
            compare();
            comp_flag=1;
        }
        else if(comp_flag==0 && flag == 2)
        {
            strrtok(str2);
            strrtok1(stringn);
            compare();
            comp_flag = 1;
        }
        else if(comp_flag==0 && flag == 3)
        {
            strrtok(str2);
            strrtok1(stringm);
            compare();
            comp_flag = 1;
        }

        for(int v = 0; v < cm_j; v++){
            if(cm_ara[v] == 0){
                iSetColor(128,255,0);
                iText(100,650-v*30,tok[v],GLUT_BITMAP_TIMES_ROMAN_24);
            }

            else if(cm_ara[v] == 1){
                iSetColor(255,0,0);
                iText(100,650-v*30,tok[v],GLUT_BITMAP_TIMES_ROMAN_24);
            }
            z=v*30;
        }
             for(j=0;tok[cm_j][j]!='\0';j++)
                {
                    if(tok[cm_j][j]!=tok1[cm_j][j])
                        break;
                }
                if(tok[cm_j][j]=='\0')
                {
                    iSetColor(128,255,0);
                    iText(100,650-z-30,tok[cm_j],GLUT_BITMAP_TIMES_ROMAN_24);
                }
                else
                {
                    iSetColor(255,0,0);
                    iText(100,650-z-30,tok[cm_j],GLUT_BITMAP_TIMES_ROMAN_24);
                }
    }

    else if(mode == 6){
        drawTexture(0,0,textures[18]);
        iSetColor(102,0,204);

        iText(250,750,"## T Y P I N G   T U T O R ##",  GLUT_BITMAP_TIMES_ROMAN_24);
        drawTexture(40, 300,textures[2]);
        iSetColor(102,0,204);

        itoa(tme_temp,s_time,10);

        iText(380,280,s_time,GLUT_BITMAP_HELVETICA_18);

        iText(150,280,"Required time(in second): ",GLUT_BITMAP_HELVETICA_18);

        iText(150,250,"Score:",GLUT_BITMAP_HELVETICA_18);

        iText(150,190,"Typing speed (WPM): ",GLUT_BITMAP_HELVETICA_18);


        if(flag == 3){
            accu_easy(str2,stringm);
            itoa(ac1,sac1,10);
            iText(230,220,sac1,GLUT_BITMAP_HELVETICA_18);
        }

        else if(flag == 2){
            accu_nor(str2,stringn);
            itoa(bc1,sbc1,10);
            iText(230,220,sbc1,GLUT_BITMAP_HELVETICA_18);

        }

        else if(flag == 1){
            accu_hard(str2,stringo);
            itoa(cc1,scc1,10);
            iText(230,220,scc1,GLUT_BITMAP_HELVETICA_18);
        }

        if(flag == 1){
            hard_speed();

            accu_hard(str2, stringo);

            if(cc1 <= 20)
            {
                score_hard_sp();
                iText(220,250,s_hard_s,GLUT_BITMAP_HELVETICA_18);
            }
            else
            {
                score_hard();

                iText(220,250,s_hard_s,GLUT_BITMAP_HELVETICA_18);
            }
            itoa(tme_h,s_time_h,10);

            iText(330,190, s_time_h,GLUT_BITMAP_HELVETICA_18);
        }


        else if(flag == 2){
            normal_speed();

            accu_nor(str2, stringn);

            if(bc1 <= 20)
            {
                score_normal_sp();

                iText(220,250,s_nor_s,GLUT_BITMAP_HELVETICA_18);
            }

            else
            {
                score_normal();

                iText(220,250,s_nor_s,GLUT_BITMAP_HELVETICA_18);
            }

            itoa(tme_n,s_time_n,10);

            iText(330,190, s_time_n,GLUT_BITMAP_HELVETICA_18);
        }


        else if(flag == 3){
            easy_speed();

            accu_easy(str2, stringm);

            if(ac1 <= 20)
            {
                score_easy_sp();

                iText(220,250,s_easy_s,GLUT_BITMAP_HELVETICA_18);
            }

            else
            {
                score_easy();

                iText(220,250,s_easy_s,GLUT_BITMAP_HELVETICA_18);
            }

            itoa(tme_e,s_time_e,10);

            iText(330,190, s_time_e,GLUT_BITMAP_HELVETICA_18);
        }

        iText(150,220,"Accuracy: ",GLUT_BITMAP_HELVETICA_18);

        iText(255,220,"%",GLUT_BITMAP_HELVETICA_18);

        iSetColor(0,255,255);

        iFilledRectangle(385,145,85,25);

        iSetColor(102,0,204);

        iText(390, 150, "Continue",GLUT_BITMAP_HELVETICA_18);

    }

    else if(mode == 7){
        iSetColor(255,255,255);
        drawTexture(2,2,textures[12]);
        char scor_lower[100];
        for(int c=0;c<3;c++)
        {
            iText(168,570-(c*78),lower[c].name,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(300,570-(c*78),itoa(lower[c].score,scor_lower,10) ,GLUT_BITMAP_TIMES_ROMAN_24);
        }

    }
    else if(mode == 13){
        iSetColor(255,255,255);
        drawTexture(2,2,textures[12]);
        char scor_low[100];
        for(int b=0;b<3;b++)
        {
            iText(168,570-(b*78),low[b].name,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(300,570-(b*78),itoa(low[b].score,scor_low,10) ,GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }

    else if(mode == 14){
        iSetColor(255,255,255);
        drawTexture(2,2,textures[12]);
        char scor_hard[100];
        for(int a=0;a<3;a++)
        {
            iText(168,570-(a*78),high[a].name,GLUT_BITMAP_TIMES_ROMAN_24);
            iText(300,570-a*(78),itoa(high[a].score,scor_hard,10) ,GLUT_BITMAP_TIMES_ROMAN_24);
        }
    }
    else if(mode == -1){
         iSetColor(255,255,255);
         drawTexture(2,2,textures[0]);
         iSetColor(255,0,127);
         iText(150,170,"Press ENTER to continue",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else if(mode == 8){
        //iSetColor(255,255,255);

        drawTexture(2,2,textures[3]);

        iSetColor(0,0,204);

        iText(250,750,"## T Y P I N G   T U T O R ##",  GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(64,64,64);

        iText(100,550,"We want a fair game here. So, there are certain rules. Here are those:-",GLUT_BITMAP_HELVETICA_18);

        iText(100,530,"You shouldn't use backspace. In fact, you cannot. :(. You can choose",GLUT_BITMAP_HELVETICA_18);

        iText(100,510,"any level you want to play. But each level brings you different rewards.",GLUT_BITMAP_HELVETICA_18);


        iText(100,490,"For example, you will be rewarded 100% of your real score as your score",GLUT_BITMAP_HELVETICA_18);

        iText(100,470,"if you choose level hard, 75% if you play level normal, 50% if you play",GLUT_BITMAP_HELVETICA_18);

        iText(100,450,"easy. Now, you should learn how we determine the score. We give more",GLUT_BITMAP_HELVETICA_18);

        iText(100,430,"importance on your accuracy than your typing speed. That's why, we take",GLUT_BITMAP_HELVETICA_18);

        iText(100,410,"80% of your accuracy and 20% of your typing speed. And a very important",GLUT_BITMAP_HELVETICA_18);

        iText(100,390,"point to note. While typing either if you miss a character or write an",GLUT_BITMAP_HELVETICA_18);

        iText(100,370,"extra character, all the characters next to the error character will be",GLUT_BITMAP_HELVETICA_18);

        iText(100,350,"harmful for accuracy. So, try to avoid that. In addition, if your accuracy is",GLUT_BITMAP_HELVETICA_18);
        iText(100,330,"less than 20% we will only count your accuracy not your speed. Any mode",GLUT_BITMAP_HELVETICA_18);

        iText(100,310,"you choose doesn't matter, you have to type something to see your accu-",GLUT_BITMAP_HELVETICA_18);

        iText(100,290,"racy properly. So, be careful. Best of luck!!!",GLUT_BITMAP_HELVETICA_18);

        iSetColor(0,0,255);

        iText(290,220,"HAPPY TYPING!!",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(255,255,0);

        drawTexture(350,160,textures[4]);

        iSetColor(255,0,0);

        iText(30,100,"<Press left arrow key to go back>",GLUT_BITMAP_HELVETICA_18);

	}

	else if(mode == 9){
        drawTexture(0,0,textures[9]);

        iSetColor(0,0,0);
        iText(150,580,"PROJECT TITLE:",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,0);
        iText(340,580,"TYPING TUTOR",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,0);
        iText(150,550,"DEVELOPED BY:",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,0);
        iText(260,520,"Md.Olid Hasan Bhuiyan",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(260,490,"Swapnil Dey",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,0);
        iText(150,440,"SUPERVISED BY--",GLUT_BITMAP_TIMES_ROMAN_24);

        iSetColor(0,0,0);
        iText(260,410,"Nafis Irtiza Tripto", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(260,380,"Lecturer, Department of Computer Science",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(260,350,"and Engineering, BUET.",GLUT_BITMAP_TIMES_ROMAN_24);


	}
	else if(mode == 10){
        drawTexture(0,0,textures[11]);
        iSetColor(255,0,0);
        iText(250,750,"##T Y P I N G   T U T O R##",GLUT_BITMAP_TIMES_ROMAN_24);
        iText(150,600,"ENTER YOUR NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,255);
        iRectangle(400,585,160,50);
	}
	else if(mode == 11){
         drawTexture(0,0,textures[11]);
        iSetColor(255,0,0);
        iText(250,750,"##T Y P I N G   T U T O R##",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,0);
        iText(150,600,"ENTER YOUR NAME:",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,0);
        iFilledRectangle(400,585,160,50);
        iSetColor(255,255,255);
        if(flag == 1)
        {
            iText(420,600,str3,GLUT_BITMAP_TIMES_ROMAN_24);
        }
        else if(flag == 2)
        {
            iText(420,600,str4,GLUT_BITMAP_TIMES_ROMAN_24);

        }
        else if(flag == 3)
        {
            iText(420,600,str5,GLUT_BITMAP_TIMES_ROMAN_24);
        }
	}
	else if(mode == 12){
        iSetColor(255,255,255);
        drawTexture(2,2,textures[8]);
        iSetColor(0,0,0);
        iText(250,750,"##T Y P I N G T U T O R##",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,0,255);
        iText(250,560,"SEE HIGH SCORES OF:",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,255);
        iFilledRectangle(340,450,120,40);
        iSetColor(0,0,0);
        iText(365,465,"EASY",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,255);
        iFilledRectangle(340,400,120,40);
        iSetColor(0,0,0);
        iText(350,410,"NORMAL",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(0,255,255);
        iFilledRectangle(340,340,120,40);
        iSetColor(0,0,0);
        iText(370,355,"HARD",GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	    printf("%d %d\n",mx,my);
		if(mx >= 220 && mx <= 355 && my >= 450 && my <= 465 && mode == 0)
		{
			mode = 1;
		}
		else if(mx >= 218 && mx <= 320 && my >= 213 && my <= 228)
        {
            exit(0);
        }
        else if(mx >= 350 && mx <= 415 && my >= 420 && my <= 435 && mode == 1)
        {
            mode = 15;
            flag = 1;
        }
        else if(mx >= 350 && mx <= 432 && my >= 390 && my <= 405 && mode == 1)
        {
            mode = 15;
            flag = 2;
        }
        else if(mx >= 350 && mx <= 415 && my >= 360 && my <= 375 && mode == 1)
        {
            mode = 15;
            flag = 3;
        }
        else if(mx >= 305 && mx <= 455  && my >= 390 && my <= 440 && mode == 15){
            mode = 2;
        }
        else if(mx >= 305 && mx <= 455  && my >= 450 && my <= 490 && mode == 15){
            mode = 16;
        }
        else if(mx >= 305 && mx <= 455  && my >= 330 && my <= 380 && mode == 15){
            mode = 20;
        }
        else if(mx >= 30 && mx <= 770  && my >= 50 && my <= 350 && mode == 16){
            mode = 17;
        }
        else if(mx >= 30 && mx <= 770  && my >= 50 && my <= 350 && mode == 2){
            mode = 5;
            flag1 = 1;
        }
        else if(mx >= 220 && mx <= 365 && my >= 410 && my <= 425 && mode == 0){
            mode = 12;
        }
        else if(mx >= 340 && mx <= 460 && my >= 450 && my <= 490 && mode == 12){
            mode = 7;
            FILE *fr;
            fr=fopen("lower.txt","r");
            int z=0;
            while(1)
            {
                if(fscanf(fr," %s\n",lower[z].name)==-1) break;
                if(fscanf(fr,"%d",&lower[z].score)==-1) break;
                z++;
            }
            fclose(fr);
            lower[z].score=s_easy;
            for(int c=0;c<strlen(user_lower);c++)
            {
                lower[z].name[c]=user_lower[c];
            }
            struct performace temp_2;
            int fl_2,sort_k;
            while(1)
            {
                fl_2=0;
                for(sort_k=0;sort_k<=z-1;sort_k++)
                {
                    if(lower[sort_k].score<lower[sort_k+1].score)
                    {
                        temp_2=lower[sort_k];
                        lower[sort_k]=lower[sort_k+1];
                        lower[sort_k+1]=temp_2;
                        fl_2=1;
                    }
                }
                if(fl_2==0) break;
            }
            fr=fopen("lower.txt","w");
            for(sort_k=0;sort_k<=z-1;sort_k++)
            {
                fprintf(fr,"%s %d\n",lower[sort_k].name,lower[sort_k].score);
            }
            fclose(fr);
        }
        else if(mx >= 340 && mx <= 460 && my >= 400 && my <= 440 && mode == 12){
            mode = 13;
            FILE *fq;
            fq=fopen("low.txt","r");
            int y=0;
            while(1)
            {
                if(fscanf(fq," %s\n",low[y].name)==-1) break;
                if(fscanf(fq,"%d",&low[y].score)==-1) break;
                y++;
            }
            fclose(fq);
            low[y].score=s_nor;
            for(int b=0;b<strlen(user_low);b++)
            {
                low[y].name[b]=user_low[b];
            }
            struct performace temp_1;
            int fl_1,sort_j;
            while(1)
            {
                fl_1=0;
                for(sort_j=0;sort_j<=y-1;sort_j++)
                {
                    if(low[sort_j].score<low[sort_j+1].score)
                    {
                        temp_1=low[sort_j];
                        low[sort_j]=low[sort_j+1];
                        low[sort_j+1]=temp_1;
                        fl_1=1;
                    }
                }
                if(fl_1==0) break;
            }
            fq=fopen("low.txt","w");
            for(sort_j=0;sort_j<=y-1;sort_j++)
            {
                fprintf(fq,"%s %d\n",low[sort_j].name,low[sort_j].score);
            }
            fclose(fq);
        }
        else if(mx >= 340 && mx <= 460 && my >= 340 && my <= 380 && mode == 12){
            mode = 14;
            FILE *fp;
            fp=fopen("hard.txt","r");
            int x=0;
            while(1)
            {
                if(fscanf(fp," %s\n",high[x].name)==-1) break;
                if(fscanf(fp,"%d",&high[x].score)==-1) break;
                x++;
            }
            fclose(fp);
            high[x].score=s_hard;
            for(int a=0;a<strlen(user_hard);a++)
            {
                high[x].name[a]=user_hard[a];
            }
            struct performace temp;
            int fl,sort_i;
            while(1)
            {
                fl=0;
                for(sort_i=0;sort_i<=x-1;sort_i++)
                {
                    if(high[sort_i].score<high[sort_i+1].score)
                    {
                        temp=high[sort_i];
                        high[sort_i]=high[sort_i+1];
                        high[sort_i+1]=temp;
                        fl=1;
                    }
                }
                if(fl==0) break;
            }
            fp=fopen("hard.txt","w");
            for(sort_i=0;sort_i<=x-1;sort_i++)
            {
                fprintf(fp,"%s %d\n",high[sort_i].name,high[sort_i].score);
            }
            fclose(fp);
        }
        else if(mx >= 490 && mx <= 575 && my >= 213 && my <= 228 && (mode == 0 || mode == 1)){
            mode = mode - 1;
        }
        else if(mx >= 218 && mx <= 378 && my >= 368 && my <= 385 && mode == 0){
            mode = 8;
        }
        else if(mx >= 218 && mx <= 315 && my >= 328 && my <= 345 && mode == 0){
            mode = 9;
        }
        else if(mx >= 385 && mx <= 470 && my >= 145 && my <= 170 && mode == 6){
            mode = 10;
        }
        else if(mx >= 400 && mx <= 560 && my >= 585 && my <= 635 && mode == 10){
            mode = 11;
        }
        else if(mx >= 150 && mx <= 330 && my >= 200 && my <= 250 && mode == 10){
            mode = 0;
        }
        else if(mx >= 35 && mx <= 225 && my >= 90 && my <= 140 && mode == -2){
            mode = 0;
        }
        else if(mx >= 285 && mx <= 465 && my >= 30 && my <= 80 && mode == -2){
            mode = 0;
        }
        else if(mx >= 660 && mx <= 800 && my >= 105 && my <= 155 && mode == -2){
            exit(0);
        }
        else if(mx >= 125 && mx <= 255 && my >= 115 && my <= 155 && mode == -4){
            mode = 6;
            for(int w = 0; w <= cm_j; w++){
                for(int h = 0; h < strlen(tok[w]); h++){
                    tok[w][h] = 0;
                }
            }
            for(int w = 0; w <= cm_j; w++){
                for(int h = 0; h < strlen(tok1[w]); h++){
                    tok1[w][h] = 0;
                }

            }
            comp_flag=0;
            cm_j=0;
            cm_m=0;
            cm_k=0;
            cm_n=0;
        }
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}
void iKeyboard(unsigned char key)
{
    if(mode == -1 && key == '\r'){
        mode = 0;
    }
	int i;
	if(mode == 5)
	{
        if(key == '\r')
		{
			mode = -4;
			tme_temp = tme;
			tme = 0;
			strcpy(str2, str);
			//printf("%c", str2[len-1]);
			for(i = 0; i < len; i++)
            str[i] = 0;
			len = 0;
			dex = 800;
			dem = 800;
			deh = 800;
			corner_flag=1;
		}
		else
		{
			str[len] = key;
			len++;
		}
	}
	else if(mode == 11 && flag == 1){
        if(key == '\r'){
            mode = 0;
            strcpy(user_hard, str3);
            for(i = 0; i < len2; i++)
            str3[i] = 0;
            len2 = 0;
        }
        else if(mode != 0 && key == 8){
            if(len2 > 0){
                len2--;
                str3[len2] = 0;
            }
        }
        else if(len2 < 10){
            str3[len2] = key;
            len2++;
        }
	}
	else if(mode == 11 && flag == 2){
        if(key == '\r'){
            mode = 0;
            strcpy(user_low, str4);
            for(i = 0; i < len3; i++)
            str4[i] = 0;
            len3 = 0;
        }
        else if(mode != 0 && key == 8){
            if(len3 > 0){
                len3--;
                str4[len3] = 0;
            }
        }
        else if(len3 < 10){
            str4[len3] = key;
            len3++;
        }
	}
	else if(mode == 11 && flag == 3){
        if(key == '\r'){
            mode = 0;
            strcpy(user_lower, str5);
            for(i = 0; i < len4; i++)
            str5[i] = 0;
            len4 = 0;
        }
        else if(mode != 0 && key == 8){
            if(len4 > 0){
                len4--;
                str5[len4] = 0;
            }
        }
        else if(len4 < 10){
            str5[len4] = key;
            len4++;
        }
	}

	else if(mode == 17 || mode == -3)
	{
        if(key == '\r')
		{
		    mode = -2;

			t_st_hard1 = t_st_hard;

			t_st_hard = 30;

			t_st_normal1 = t_st_normal;

            t_st_normal = 45;

            t_st_easy1 = t_st_easy;

            t_st_easy = 60;

			strcpy(str7, str6);

			for(i = 0; i < len5; i++)
            str6[i] = 0;
			len5 = 0;
		}
		else if(mode != 0 && key == 8){
            if(len5 > 0){
                len5--;
                str6[len5] = 0;
            }
        }
		else
		{
			str6[len5] = key;
			len5++;
		}
	}
	if(key == '1' && mode == 0){
        mode = 1;
	}

	else if(key == '2' && mode == 0){
        mode = 12;
	}

	else if(key == '5' && mode == 0){
        exit(0);
	}

	else if(key == '1' && mode == 1){
        mode = 15;
        flag = 1;
	}

	else if(key == '2' && mode == 1){
        mode = 15;
        flag = 2;
	}

	else if(key == '3' && mode == 1){
        mode = 15;
        flag = 3;
	}

	else if(key == '3' && mode == 0){
        mode = 8;
	}
	else if(key == '4' && mode == 0){
        mode = 9;
	}
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_END && mode == 0){
        exit(0);
    }

    else if(key == GLUT_KEY_LEFT && (mode == 0 || mode == 1)){
        mode = mode - 1;
    }

    else if(key == GLUT_KEY_LEFT && mode == 2){
        mode = 15;
    }

    else if(key == GLUT_KEY_LEFT && mode == 12){
        mode = 0;
    }

    else if(key == GLUT_KEY_LEFT && mode == 8){
        mode = 0;
    }
    else if(key == GLUT_KEY_LEFT && mode == 9){
        mode = 0;
    }
    else if(key == GLUT_KEY_LEFT && mode == 7){
        mode = 12;
    }
    else if(key == GLUT_KEY_LEFT && mode == 13){
        mode = 12;
    }
    else if(key == GLUT_KEY_LEFT && mode == 14){
        mode = 12;
    }
    else if(key == GLUT_KEY_LEFT && mode == 15){
        mode = 1;
    }
    else if(key == GLUT_KEY_LEFT && mode == 16){
        mode = 15;
    }
}

int printRandoms(int lower, int upper, int count)
{
    int i,num;
    for (i = 0; i < count; i++) {
        int num = (rand() %
           (upper - lower + 1)) + lower;
        return num;
    }
}

struct input
{
    char str[500];
};

struct input1
{
    char nstr[500];
};

struct input2
{
    char ostr[500];
};

struct St_input_hard
{
    char stat_hard[500];
};
struct St_input_normal
{
    char stat_normal[500];
};
struct St_input_easy
{
    char stat_easy[500];
};
void speedeasy()
{
    if(flag1==1&&nflag==0&&corner_flag==0)
    {
        dex=dex-1;
        if(dex<1)
            dex=800;
    }
}

void speedmedium()
{
    if(flag1==1&&nflag==0&&corner_flag==0)
    {
        dem-=1;
        if(dem<1)
            dem=800;
    }
}

void speedhard()
{
    if(flag1==1&&nflag==0&&corner_flag==0)
    {
        deh-=1;
        if(deh<1)
            deh=800;
    }
}

void colchange()
{
    if(colmode==0)
        dc+=2;
    else if(colmode==1)
        dc-=2;
    if(dc>=204)
        colmode=1;
    else if(dc<=-51)
        colmode=0;

}

void T_time()
{
    if(mode == 5 && (flag == 1 || flag == 2 || flag == 3)){
        tme++;
    }
}

void St_time_hard()
{
    if(mode == 17 && flag == 1){
        t_st_hard--;
    }
    if(t_st_hard == 0 && flag == 1){
        mode = -3;
        t_st_hard = 25;
        strcpy(str7,str6);
        //uflag=1;
    }
}

void St_time_normal()
{
    if(mode == 17 && flag == 2){
        t_st_normal--;
    }
    if(t_st_normal == 0 && flag == 2){
        mode = -3;
        t_st_normal = 27;
        strcpy(str7,str6);
    }
}

void St_time_easy()
{
    if(mode == 17 && flag == 3){
        t_st_easy--;
    }
    if(t_st_easy == 0 && flag == 3){
        mode = -3;
        t_st_easy = 30;
        strcpy(str7,str6);
    }
}

int main()
{
    len5 = 0;
	len = 0;
	len2 = 0;
	len3 = 0;
	len4 = 0;
	mode = -1;
	str[0]= 0;
	str3[0] = 0;
	str4[0] = 0;
	str5[0] = 0;
	str6[0] = 0;
	str7[0] = 0;
	iSetTimer(20,speedeasy);

	iSetTimer(10,speedmedium);

	iSetTimer(1,speedhard);

	iSetTimer(30,colchange);

	iSetTimer(1000, T_time);

    iSetTimer(1000,St_time_hard);

    iSetTimer(1000,St_time_normal);

    iSetTimer(1000,St_time_easy);

    struct input m[20];

    struct input1 n[20];

    struct input2 o[20];

    struct St_input_hard p[50];

    struct St_input_normal p1[50];


    struct St_input_easy p2[50];

    FILE *input;
    input=fopen("input.txt","r");
    srand(time(0));   /// should only be called once
    randa=printRandoms(0,19,1);
        /// returns a pseudo-random integer between 0 and RAND_MAX
    for(i=0;i<20;i++)
    {
        fgets(m[i].str,500,input);
    }

    strcpy(stringm,m[randa].str);
    length=strlen(stringm);

    fclose(input);

    FILE *input1;
    input1=fopen("input1.txt","r");
    srand(time(0));
    randa=printRandoms(0,19,1);
    for(i=0;i<20;i++)
    {
        fgets(n[i].nstr,500,input1);
    }

    strcpy(stringn,n[randa].nstr);
    length1=strlen(stringn);

    fclose(input1);

    FILE *input2;
    input2=fopen("input2.txt","r");
    srand(time(0));
    randa=printRandoms(0,19,1);
    for(i=0;i<20;i++)
    {
        fgets(o[i].ostr,500,input2);
    }

    strcpy(stringo,o[randa].ostr);
    length2=strlen(stringo);
    //strrtok1(stringo);

    fclose(input2);




    FILE *St_input_hard;
    St_input_hard=fopen("St_input_hard.txt","r");
    srand(time(0));
    random=printRandoms(0,19,1);
    for(i=0;i<20;i++)
    {
        fgets(p[i].stat_hard,500,St_input_hard);
    }

    strcpy(stringp,p[random].stat_hard);
    //lengthp=strlen(stringp);

    fclose(St_input_hard);

    FILE *St_input_normal;
    St_input_normal=fopen("St_input_normal.txt","r");
    srand(time(0));
    random=printRandoms(0,19,1);
    for(i=0;i<20;i++)
    {
        fgets(p1[i].stat_normal,500,St_input_normal);
    }

    strcpy(stringp1,p1[random].stat_normal);
    lengthp1=strlen(stringp1);


    fclose(St_input_normal);

    FILE *St_input_easy;
    St_input_easy=fopen("St_input_easy.txt","r");
    srand(time(0));
    random=printRandoms(0,19,1);
    for(i=0;i<20;i++)
    {
        fgets(p2[i].stat_easy,500,St_input_easy);
    }

    strcpy(stringp2,p2[random].stat_easy);
    lengthp2=strlen(stringp2);


    fclose(St_input_easy);
    PlaySound(TEXT("me3.wav"),NULL,SND_LOOP|SND_ASYNC);

    iInitialize(800, 800, "TYPE");


	return 0;
}
