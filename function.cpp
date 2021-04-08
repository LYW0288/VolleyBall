#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "function.h""

FILE *fPtr;
char s[11];
int all[2]={0, 0};
bool done;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_TIMER *timer;
ALLEGRO_DISPLAY *display;

/*AUDIO*/
    ALLEGRO_SAMPLE_ID *id = NULL;
    ALLEGRO_SAMPLE *title_song = NULL;
    ALLEGRO_SAMPLE *game_song = NULL;
    ALLEGRO_SAMPLE *record_song = NULL;
    ALLEGRO_SAMPLE *enter_song = NULL;
    ALLEGRO_SAMPLE *move_song = NULL;
    ALLEGRO_SAMPLE *ball_song = NULL;
    ALLEGRO_SAMPLE *cheer = NULL;
    ALLEGRO_SAMPLE *news_song = NULL;

/*TITLE*/
    /*TITLE BACK*/
        ALLEGRO_BITMAP *BLACK = NULL;
        ALLEGRO_BITMAP *TREE = NULL;
        ALLEGRO_BITMAP *littleball = NULL;
    /*TITLE MOOMIN*/
        ALLEGRO_BITMAP *T_M_1 = NULL;
        ALLEGRO_BITMAP *T_M_2 = NULL;
        ALLEGRO_BITMAP *T_M_3 = NULL;
        ALLEGRO_BITMAP *T_M_4 = NULL;
/*WIN*/
    ALLEGRO_BITMAP *MOOMIN_WIN = NULL;
    ALLEGRO_BITMAP *GF_WIN = NULL;
    ALLEGRO_BITMAP *MOOMIN_WIN2 = NULL;
    ALLEGRO_BITMAP *GF_WIN2 = NULL;
/*SHADOW*/
    ALLEGRO_BITMAP *SHADOW_M = NULL;
    ALLEGRO_BITMAP *SHADOW_B = NULL;
/*BALL*/
    ALLEGRO_BITMAP *BALL = NULL;
/*DECLARATION OF MOOMIN'S PICTURE*/
    ALLEGRO_BITMAP *RURU01 = NULL;
    ALLEGRO_BITMAP *RURU02 = NULL;
    ALLEGRO_BITMAP *RURU03 = NULL;
    ALLEGRO_BITMAP *RURU04 = NULL;
    /*DECLARATION OF MOOMIN'S RUNNING PICTURE*/
        ALLEGRO_BITMAP *MOO_run_1 = NULL;
        ALLEGRO_BITMAP *MOO_run_2 = NULL;
        ALLEGRO_BITMAP *MOO_run_3 = NULL;
        ALLEGRO_BITMAP *MOO_run_4 = NULL;
        ALLEGRO_BITMAP *MOO_run_5 = NULL;
        ALLEGRO_BITMAP *MOO_run_6 = NULL;
        ALLEGRO_BITMAP *MOO_run_7 = NULL;
        ALLEGRO_BITMAP *MOO_run_8 = NULL;
    /*DECLARATION OF MOOMIN'S BAT1 PICTURE*/
        ALLEGRO_BITMAP *MOO_bat1_1 = NULL;
        ALLEGRO_BITMAP *MOO_bat1_2 = NULL;
        ALLEGRO_BITMAP *MOO_bat1_3 = NULL;
        ALLEGRO_BITMAP *MOO_bat1_4 = NULL;
        ALLEGRO_BITMAP *MOO_bat1_5 = NULL;
        ALLEGRO_BITMAP *MOO_bat1_6 = NULL;
    /*DECLARATION OF MOOMIN'S BAT2 PICTURE*/
        ALLEGRO_BITMAP *MOO_bat2_1 = NULL;
        ALLEGRO_BITMAP *MOO_bat2_2 = NULL;
        ALLEGRO_BITMAP *MOO_bat2_3 = NULL;
        ALLEGRO_BITMAP *MOO_bat2_4 = NULL;
        ALLEGRO_BITMAP *MOO_bat2_5 = NULL;
        ALLEGRO_BITMAP *MOO_bat2_6 = NULL;
    /*DECLARATION OF MOOMIN'S BAT3 PICTURE*/
        ALLEGRO_BITMAP *MOO_bat3_1 = NULL;
        ALLEGRO_BITMAP *MOO_bat3_2 = NULL;
        ALLEGRO_BITMAP *MOO_bat3_3 = NULL;
        ALLEGRO_BITMAP *MOO_bat3_4 = NULL;
        ALLEGRO_BITMAP *MOO_bat3_5 = NULL;

/*DECLARATION OF MOOMIN'S GF'S PICTURE*/
    ALLEGRO_BITMAP *GF_01 = NULL;
    ALLEGRO_BITMAP *GF_02 = NULL;
    ALLEGRO_BITMAP *GF_03 = NULL;
    ALLEGRO_BITMAP *GF_04 = NULL;
    /*DECLARATION OF MOOMIN'S GF'S RUNNING PICTURE*/
        ALLEGRO_BITMAP *GF_run_1 = NULL;
        ALLEGRO_BITMAP *GF_run_2 = NULL;
        ALLEGRO_BITMAP *GF_run_3 = NULL;
        ALLEGRO_BITMAP *GF_run_4 = NULL;
        ALLEGRO_BITMAP *GF_run_5 = NULL;
        ALLEGRO_BITMAP *GF_run_6 = NULL;
        ALLEGRO_BITMAP *GF_run_7 = NULL;
        ALLEGRO_BITMAP *GF_run_8 = NULL;
    /*DECLARATION OF MOOMIN'S GF'S BAT1 PICTURE*/
        ALLEGRO_BITMAP *GF_bat1_1 = NULL;
        ALLEGRO_BITMAP *GF_bat1_2 = NULL;
        ALLEGRO_BITMAP *GF_bat1_3 = NULL;
        ALLEGRO_BITMAP *GF_bat1_4 = NULL;
        ALLEGRO_BITMAP *GF_bat1_5 = NULL;
        ALLEGRO_BITMAP *GF_bat1_6 = NULL;
    /*DECLARATION OF MOOMIN'S GF'S BAT2 PICTURE*/
        ALLEGRO_BITMAP *GF_bat2_1 = NULL;
        ALLEGRO_BITMAP *GF_bat2_2 = NULL;
        ALLEGRO_BITMAP *GF_bat2_3 = NULL;
        ALLEGRO_BITMAP *GF_bat2_4 = NULL;
        ALLEGRO_BITMAP *GF_bat2_5 = NULL;
        ALLEGRO_BITMAP *GF_bat2_6 = NULL;
    /*DECLARATION OF MOOMIN'S GF'S BAT3 PICTURE*/
        ALLEGRO_BITMAP *GF_bat3_1 = NULL;
        ALLEGRO_BITMAP *GF_bat3_2 = NULL;
        ALLEGRO_BITMAP *GF_bat3_3 = NULL;
        ALLEGRO_BITMAP *GF_bat3_4 = NULL;
        ALLEGRO_BITMAP *GF_bat3_5 = NULL;
/*DECLARATION OF BACKGROUND*/
    ALLEGRO_BITMAP *COLUMN = NULL;
    ALLEGRO_BITMAP *back_01  = NULL;
    ALLEGRO_BITMAP *back_02  = NULL;

/*DECLARATION OF TITLE*/
    ALLEGRO_FONT *title = NULL;
    ALLEGRO_FONT *title2 = NULL;
    ALLEGRO_FONT *title3 = NULL;
ALLEGRO_FONT *title4 = NULL;
int state = 0;
char warn[31];
//MOOMIN'S RUN
    bool keys[4]= {false};
    int Mdirect=0;
    int Gdirect=0;
//MOOMIN'S JUMP
    int MDY=0, MDA=1;
    bool Mjumpkeys=false;
//GF'S JUMP
    int GDY=0, GDA=1;
    bool Gjumpkeys=false;
//SCORE
    int SCORE[2]={0, 0};
    int SAVE_SCORE[2][2]={0, 0, 0, 0};
    bool SCORE_M=false, SCORE_G=false;
    bool M_WIN=false, G_WIN =false;
int rx = SCREEN_W/2, ry = SCREEN_H/2;
int x2 = SCREEN_W-169, x = 0;
int y=SCREEN_H-140-50,  y2=SCREEN_H-140-50;
int BALLtime=1;
int STAY=0;
int rest;
/*MOOMIN*/
    int TM=0, KM=0, BM=0;
    int TMbat1=0, BMbat1=0;
    bool key_bat1=false;
    bool key_bat2=false;
    bool key_bat3=false;
/*GF*/
    int TG=0, KG=0, BG=0;
    int TGbat1=0, BGbat1=0;
    bool key_G_bat1=false;
    bool key_G_bat2=false;
    bool key_G_bat3=false;
/*BALL*/
    bool who=true;
    bool INIT=true;
    bool keyball=false;
/*little ball*/
    bool play_ani = false;
bool yes = false, no = false;
bool about = false;
bool cursor = false;
bool REALM=true;
bool Serveball=true;
bool key_Q=false, key_E=false;
bool M_BAT1=false, M_BAT2=false, M_BAT3=false;
bool G_BAT1=false, G_BAT2=false, G_BAT3=false;
int XB, YB;
int XBsave, YBsave;
int DX=0, DY=0;
double scale = 1;



void WIN(ALLEGRO_BITMAP *who){
    static int ny, nx;
    static double  angle;
    if (scale == 1){
        al_stop_sample(id);
        al_play_sample(news_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        al_play_sample(record_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, id);
        scale++;
        rest=0;
        nx = SCREEN_W/2;
        ny = SCREEN_H/2;
        rx = SCREEN_W/2-105;
        ry = 100;
        angle = 2.5;
        al_draw_scaled_rotated_bitmap(who, 52.5, 71.5, nx-52.5, ny-71.5, scale, scale, angle, 0);
    }
    else if (scale<11.5){
        nx+=3;
        ny+=28;
        scale+=0.5;
        angle+=0.5;
        al_draw_scaled_rotated_bitmap(who, 52.5, 71.5, nx-52.5, ny-71.5, scale, scale, angle, 0);
    }
    else{
        if(rest==70){
            al_draw_scaled_rotated_bitmap(who, 52.5, 71.5, nx-52.5, ny-71.5, scale, scale, angle, 0);
            al_draw_filled_rectangle(SCREEN_W/2-250, 45-20, SCREEN_W/2+250, 45+150, al_map_rgb(0, 0, 0));
            al_draw_text(title4, al_map_rgb(255, 255, 255), SCREEN_W/2, 45, ALLEGRO_ALIGN_CENTRE, "Do you want to save score?");
            al_draw_text(title2, al_map_rgb(255, 255, 255), SCREEN_W/2, 100, ALLEGRO_ALIGN_CENTRE, "Yes  No ");
            al_draw_rectangle(rx, ry, rx+80, ry+40, al_map_rgb(255, 255, 255), 5);
            if(yes){
                fPtr = fopen("score.txt", "w");
                fprintf(fPtr, "%d%d%c%c%c%c %d %d", SAVE_SCORE[0][0], SAVE_SCORE[0][1], s[0], s[1], s[2], s[3], all[0]+1*G_WIN, all[1]+1*M_WIN);
                fclose(fPtr);
                init_title();
            }
            else if(no) init_title();
        }
        else rest++, al_draw_scaled_rotated_bitmap(who, 52.5, 71.5, nx-52.5, ny-71.5, scale, scale, angle, 0);
    }
    if (angle==6)
        angle = 0;
    return;
}

void event_title(ALLEGRO_EVENT event){
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES){
        if (event.mouse.x<rx+100 && event.mouse.x>rx-100){
            if(event.mouse.y > SCREEN_H/2 && event.mouse.y < SCREEN_H/2+20){
                if(ry != SCREEN_H/2 )
                    al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                ry = SCREEN_H/2;
            }
            else if(event.mouse.y > SCREEN_H/2+20 && event.mouse.y < SCREEN_H/2+40){
                if(ry != SCREEN_H/2+20 )
                    al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                ry = SCREEN_H/2+20;
            }
            else if(event.mouse.y > SCREEN_H/2+40 && event.mouse.y < SCREEN_H/2+60){
                if(ry != SCREEN_H/2+40 )
                    al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                ry = SCREEN_H/2+40;
            }
        }
        if(event.mouse.x>SCREEN_W-40 && event.mouse.x<SCREEN_W-20 && event.mouse.y>SCREEN_H-30 && event.mouse.y<SCREEN_H-10){
            if(!cursor)
                al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL), about=true;
            cursor = true;
        }
        else cursor = false, about = false;
    }
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.x > rx-100 && event.mouse.x<rx+100){
        if ( event.mouse.y > SCREEN_H/2+40 && event.mouse.y < SCREEN_H/2+60) done = true;
        else if(event.mouse.y > SCREEN_H/2+20 && event.mouse.y < SCREEN_H/2+40) init_record();
        else if(event.mouse.y > SCREEN_H/2 && event.mouse.y < SCREEN_H/2+20) play_ani=true;
    }
    if (event.type == ALLEGRO_EVENT_KEY_DOWN){ /*If you push up&down*/
        switch(event.keyboard.keycode){
            case ALLEGRO_KEY_UP:
                if ( ry != SCREEN_H/2) al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL), ry -= 20;
                else al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL), ry -= -40;
                break;
            case ALLEGRO_KEY_DOWN:
                if ( ry!= SCREEN_H/2+40) al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL), ry += 20;
                else al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL), ry += -40;
                break;
            case ALLEGRO_KEY_ENTER:/*If you push enter*/
                if ( ry == SCREEN_H/2+40) done = true;
                else if( ry == SCREEN_H/2+20 ) init_record();
                else if( ry == SCREEN_H/2 ) play_ani=true;
                break;
        }
    }
}

void init_record(){
    fPtr = fopen("score.txt", "r");
    fscanf(fPtr, "%s%d%d", s, &all[0], &all[1]);
    if(!fPtr) printf("No score file.\n");
    al_play_sample(enter_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    state=3;
    ry=100;
    fclose(fPtr);
}

void write(){
    fPtr = fopen("score.txt", "w");
    fprintf(fPtr, "000000 0 0");
    fclose(fPtr);
    fPtr = fopen("score.txt", "r");
    fscanf(fPtr, "%s%d%d", s, &all[0], &all[1]);
    fclose(fPtr);
}

void init_title(){
    al_play_sample(enter_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    scale = 1;
    M_WIN=false, G_WIN=false;
    no = false, yes = false;
    state = 0;
    TM = 0;
    KM = 0;
    rx = SCREEN_W/2;
    ry = SCREEN_H/2;
    if(id!=NULL) al_stop_sample(id);
    al_play_sample(title_song, 1.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, id);
}

void init_play(){
    static int lx, ly, lw=0, lh, vw, vh;
    if(lw == 0){
        al_play_sample(enter_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        al_stop_sample(id);
        lx = SCREEN_W/2;
        ly = SCREEN_H/2;
        lw = 7;
        lh = 7;
        vw = 7;
        vh = 7;
    }
    if(lw<SCREEN_W+500){
        al_draw_scaled_bitmap(littleball, 0, 0, 7, 7, lx-lw/2, ly-lh/2, lw, lh, 0);
        lw+=vw;
        lh+=vh;
        vw+=7;
        vh+=7;
    }
    else{
        al_draw_scaled_bitmap(littleball, 0, 0, 7, 7, lx-lw/2, ly-lh/2, lw, lh, 0);
    //MOOMIN'S RUN
        keys[0]= false;
        keys[1]= false;
        keys[2]= false;
        keys[3]= false;
        Mdirect=0;
    //MOOMIN'S JUMP
        MDY=0, MDA=1;
        Mjumpkeys=false;
    //GF'S JUMP
        GDY=0, GDA=1;
        Gjumpkeys=false;
    /*M_BAT*/
        TMbat1=0, BMbat1=0;
        key_bat1=false;
        key_bat2=false;
        key_bat3=false;
    /*G_BAT*/
        TGbat1=0, BGbat1=0;
        key_G_bat1=false;
        key_G_bat2=false;
        key_G_bat3=false;
    /*BALL*/
        INIT=true;
        keyball=false;
        memset(SAVE_SCORE, 0, sizeof(int)*2*2);
        x2 = SCREEN_W-169, x = 0;
        y=SCREEN_H-140-50,  y2=SCREEN_H-140-50;
        key_Q=true;
        key_E=false;
        REALM=true;
        Serveball=true;
        SCORE[0]=0, SCORE[1]=0;
        M_WIN = false, G_WIN = false;
        SCORE_M=false, SCORE_G=false, STAY=0, BALLtime=1;
        memset(warn, '\0', 31*sizeof(char));
        play_ani=false;
        lw = 0;

        al_play_sample(game_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, id);
        state = 1;
    }
}

void BALLcount(){
    if(BALLtime==2 && YB==SCREEN_H-65){
        if(Serveball){
            if(REALM){
                strcpy(warn, "Please serve ball.");
                SCORE[0]++;
                SCORE_G=true;
            }
            else if(!REALM){
                strcpy(warn, "Please serve ball.");
                SCORE[1]++;
                SCORE_M=true;
            }
        }
        else if(REALM){
            if (XB>SCREEN_W/2 || XB<SCREEN_W/2-480){
                SCORE[0]++;
                SCORE_G=true;
            }
        }
        else if(!REALM){
            if (XB<SCREEN_W/2 || XB>SCREEN_W/2+480){
                SCORE[1]++;
                SCORE_M=true;
            }
        }
    }
    else if(BALLtime==3 && YB==SCREEN_H-65){
        if(REALM){
            SCORE[1]++;
            SCORE_M=true;
        }
        else if(!REALM){
            SCORE[0]++;
            SCORE_G=true;
        }
    }
    if(!G_WIN && !M_WIN){
        if(XB>SCREEN_W){
            SCORE[0]++;
            SCORE_G=true;
        }
        else if(XB<0){
            SCORE[1]++;
            SCORE_M=true;
        }
    }
    return;
}

void BALLinit(){
    int STAY2=50;
    if((XB<0 || XB>SCREEN_W) && !G_WIN && !M_WIN){
        if(warn[0]=='\0') STAY2=10;
        else if(((STAY2-STAY)%10)/5) al_draw_textf(title4, al_map_rgb(0, 0, 0), SCREEN_W/2, 200, ALLEGRO_ALIGN_CENTER, "%s", warn);
        STAY++;
        if(STAY==STAY2){
            al_play_sample(cheer, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
            SCORE_M=false, SCORE_G=false, STAY=0, BALLtime=1;
            memset(warn, '\0', 31*sizeof(char));
            if(who) key_Q=true;
            else key_E=true;
        }
    }
    if(SCORE[1]==4&&SCORE[0]<3)//SCORE1
        SCORE[1]=0, SCORE[0]=0, SAVE_SCORE[1][1]++, who=!who;
    else if(SCORE[1]==4 && SCORE[0]==3)
        SCORE[1]=9;
    else if(SCORE[1]==9 && SCORE[0]==4)
        SCORE[1]=3, SCORE[0]=3;
    else if(SCORE[1]==10)
        SAVE_SCORE[1][1]++, SCORE[1]=0, SCORE[0]=0, who=!who;
    if(SCORE[0]==4&&SCORE[1]<3)//SCORE0
        SCORE[0]=0, SCORE[1]=0, SAVE_SCORE[1][0]++, who=!who;
    else if(SCORE[0]==4 && SCORE[1]==3)
        SCORE[0]=9;
    else if(SCORE[0]==9 && SCORE[1]==4)
        SCORE[0]=3, SCORE[1]=3;
    else if(SCORE[0]==10)
        SAVE_SCORE[1][0]++, SCORE[1]=0, SCORE[0]=0, who=!who;
    if(SAVE_SCORE[1][0]>=6 && SAVE_SCORE[1][1]+1!=SAVE_SCORE[1][0])/*SET SCORE*/
        SAVE_SCORE[1][1]=0, SAVE_SCORE[1][0]=0, SAVE_SCORE[0][0]++;
    if(SAVE_SCORE[1][1]>=6 && SAVE_SCORE[1][0]+1!=SAVE_SCORE[1][1])
        SAVE_SCORE[1][0]=0, SAVE_SCORE[1][1]=0, SAVE_SCORE[0][1]++;
    if(SAVE_SCORE[0][1]==2)/*M WIN*/
        M_WIN=true;
    if(SAVE_SCORE[0][0]==2)/*G WIN*/
        G_WIN=true;
    return;
}

void BAT_M(int Y, int X){
    if(YB == YBsave+DY){
        al_play_sample(ball_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        DY = Y;
        YB += DY;
        DX = X;
        XB += DX;
        M_BAT1=false, M_BAT2=false, M_BAT3=false;
        if(Serveball){
            if(!SCORE_G && !SCORE_M && x2<SCREEN_W/2+300){
                strcpy(warn, "Please stand behind serve line.");
                SCORE[0]++;
                SCORE_G=true;
            }
            Serveball=false;
        }
        else{
            if(BALLtime==2 || BALLtime==1 && !REALM)
                BALLtime=1, REALM=true;
            else if(!SCORE_G && !SCORE_M){
                SCORE[0]++;
                SCORE_G=true;
            }
        }
    }
    else
        YBsave=YB, YB += DY;
    return;
}
void BAT_G(int Y, int X){
    if(YB == YBsave+DY){
        al_play_sample(ball_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
        DY = Y;
        YB += DY;
        DX = X;
        XB += DX;
        G_BAT1=false, G_BAT2=false, G_BAT3=false;
        if(Serveball){
            if(!SCORE_G && !SCORE_M && x>SCREEN_W/2-469){
                strcpy(warn, "Please stand behind serve line.");
                SCORE[1]++;
                SCORE_M=true;
            }
            Serveball=false;
        }
        else{
            if(BALLtime==2 || BALLtime==1 && REALM)
                BALLtime=1, REALM=false;
            else if(!SCORE_G && !SCORE_M){
                SCORE[1]++;
                SCORE_M=true;
            }
        }
    }
    else
        YBsave=YB, YB += DY;
    return;
}

void abort_game(const char* message){
    printf("%s\n", message);
    exit(1);
}

void event_access(ALLEGRO_EVENT event){
    if (!M_WIN && !G_WIN) {
        /*BATS*/
            /*MOOMIN'S BAT*/
            if(event.type==ALLEGRO_EVENT_KEY_DOWN && !key_Q)
                switch(event.keyboard.keycode){
                    case ALLEGRO_KEY_L:
                        if(!key_bat2 && !key_bat3)
                            key_bat1=true;
                        break;
                    case ALLEGRO_KEY_DOWN:
                        if(y2==SCREEN_H-190 && !key_bat1 && !key_bat3)
                            key_bat2=true, Mjumpkeys=true, MDA=11, MDY=-30;
                        break;
                    case ALLEGRO_KEY_K:
                        if(!key_bat2 && !key_bat1)
                            key_bat3=true;
                        break;
                }
            if( x2 <= SCREEN_W/2 && y2==SCREEN_H-190)  key_bat3=false, key_bat1=false, TMbat1=0, BMbat1=0;
            /*GF'S BAT*/
            if(event.type==ALLEGRO_EVENT_KEY_DOWN && !key_E)
                switch(event.keyboard.keycode){
                    case ALLEGRO_KEY_Z:
                        if(!key_G_bat2 && !key_G_bat3)
                            key_G_bat1=true;
                        break;
                    case ALLEGRO_KEY_S:
                        if(y==SCREEN_H-190 && !key_G_bat1 && !key_G_bat3)
                            key_G_bat2=true, Gjumpkeys=true, GDA=11, GDY=-30;
                        break;
                    case ALLEGRO_KEY_X:
                        if(!key_G_bat2 && !key_G_bat1)
                            key_G_bat3=true;
                        break;
                }
            if( x >= SCREEN_W/2-169 && y==SCREEN_H-190)  key_G_bat3=false, key_G_bat1=false, TGbat1=0, BGbat1=0;
        /*BALL'S POSITION*/
            if(event.type==ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode==ALLEGRO_KEY_ENTER && key_Q && XB==x2+120)
                key_Q=!key_Q, DY=-25, DX=-3, Serveball=true, REALM=true;
            if(event.type==ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode==ALLEGRO_KEY_E && key_E && XB==x+20)
                key_E=!key_E, DY=-25, DX=3, Serveball=true, REALM=false;
        /*Moving*/
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) { /*Move the characters*/
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_A:
                        if (x >= 0)
                            keys[0]=true, TG=0, BG=0;
                        break;
                    case ALLEGRO_KEY_D:
                        if (x <= SCREEN_W/2-169)
                            keys[1]=true, TG=7, BG=0;
                        break;
                    case ALLEGRO_KEY_LEFT:
                        if (x2 >= SCREEN_W/2)
                            keys[2]=true, TM=0, BM=0;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        if (x2 <= SCREEN_W-169)
                            keys[3]=true, TM=7, BM=0;
                        break;
                    default:
                        break;
                }
            }
            /*Stop for leaving*/
            if (x-3 <= 0 && (keys[0] || Gdirect))
                keys[0]=false, TG=0, KG=0, BG=0, Gdirect = 0;
            if (x+3 >= SCREEN_W/2-169 && (keys[1] || Gdirect))
                keys[1]=false, TG=0, KG=0, BG=0, Gdirect = 0;
            if (x2-3 <= SCREEN_W/2 && (keys[2] || Mdirect))
                keys[2]=false, TM=0, KM=0, BM=0, Mdirect = 0;
            if (x2+3 >= SCREEN_W-169 && (keys[3] || Mdirect))
                keys[3]=false, TM=0, KM=0, BM=0, Mdirect = 0;
            if (event.type == ALLEGRO_EVENT_KEY_UP) { /*Stop moving them*/
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_A:
                        if (x >= 0)
                            keys[0]=false, TG=0, KG=0, BG=0;
                        break;
                    case ALLEGRO_KEY_D:
                        if (x <= SCREEN_W/2-169)
                            keys[1]=false, TG=0, KG=0, BG=0;
                        break;
                    case ALLEGRO_KEY_LEFT:
                        if (x2 >= SCREEN_W/2)
                            keys[2]=false, TM=0, KM=0, BM=0;
                        break;
                    case ALLEGRO_KEY_RIGHT:
                        if (x2 <= SCREEN_W-169)
                            keys[3]=false, TM=0, KM=0, BM=0;
                        break;
                }
            }
        /*Jumping*/
            /*GF'SJumping*/
            if(event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode==ALLEGRO_KEY_W && y==SCREEN_H-190){
                Gjumpkeys=true;
                if(keys[1]==true)  Gdirect=1;/*RUN's direction*/
                else if(keys[0]==true)  Gdirect=-1;
            }
            if((event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode==ALLEGRO_KEY_W) || GDA>10) Gjumpkeys=false;
            /*MOOMIN'SJumping*/
            if(event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode==ALLEGRO_KEY_UP && y2==SCREEN_H-190){
                Mjumpkeys=true;
                if(keys[3]==true)  Mdirect=1;/*RUN's direction*/
                else if(keys[2]==true)  Mdirect=-1;
            }
            if((event.type == ALLEGRO_EVENT_KEY_UP && event.keyboard.keycode==ALLEGRO_KEY_UP) || MDA>10) Mjumpkeys=false;
    }
    else if(rest==70){
        if(event.type==ALLEGRO_EVENT_KEY_DOWN)
            switch(event.keyboard.keycode){
                case ALLEGRO_KEY_LEFT:
                    al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    if(rx == SCREEN_W/2-105)
                        rx = SCREEN_W/2 + 5;
                    else rx = SCREEN_W/2-105;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                    if(rx == SCREEN_W/2-105)
                        rx = SCREEN_W/2 + 5;
                    else rx = SCREEN_W/2-105;
                    break;
                case ALLEGRO_KEY_ENTER:/*If you push enter*/
                    if ( rx == SCREEN_W/2-105 ) yes = true;
                    else if( rx == SCREEN_W/2 + 5 ) no=true;
                    break;
            }
        if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
                if (event.mouse.y > 100 && event.mouse.y < 140){
                    if(event.mouse.x<SCREEN_W/2-25 && event.mouse.x>SCREEN_W/2-105){
                        if(rx != SCREEN_W/2-105)
                            al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                        rx = SCREEN_W/2-105;
                    }
                    else if(event.mouse.x<SCREEN_W/2+85 && event.mouse.x>SCREEN_W/2+5){
                        if(rx != SCREEN_W/2 + 5)
                            al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                        rx = SCREEN_W/2 + 5;
                    }
                }
        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.y > 100 && event.mouse.y < 140){
            if ( event.mouse.x<SCREEN_W/2-25 && event.mouse.x>SCREEN_W/2-105 ) yes = true;
            else if( event.mouse.x<SCREEN_W/2+85 && event.mouse.x>SCREEN_W/2+5 ) no = true;
        }
    }
}

void event_process(){
    /*MOVE*/
        /*GF*/
        if(key_G_bat1 && y==SCREEN_H-190)/*GF's BAT1 MOVEMENT*/
            x += 6;
        else if(key_G_bat2 && x+6<=SCREEN_W/2-169)/*GF's BAT2 MOVEMENT*/
            x += 6;
        else if(key_G_bat3 && y==SCREEN_H-190)/*GF's BAT3 MOVEMENT*/
            x += 6;
        else if(y==SCREEN_H -190)
            x += keys[1]*5+keys[0]*(-5);
        else{/*GF'S JUMP*/
            if(Gdirect==1)
                x += 5;
            else if(Gdirect==-1)
                x -= 5;
        }
        /*MOOMIN*/
        if(key_bat1 && y2==SCREEN_H-190)/*MOOMIN's BAT1 MOVEMENT*/
            x2 -= 6;
        else if(key_bat2 && x2-6>=SCREEN_W/2)/*MOOMIN's BAT2 MOVEMENT*/
            x2 -= 6;
        else if(key_bat3 && y2==SCREEN_H-190)/*MOOMIN's BAT3 MOVEMENT*/
            x2 -= 6;
        else if(y2==SCREEN_H - 190)
            x2 += keys[3]*5+keys[2]*(-5);
        else{/*MOOMIN'S JUMP*/
            if(Mdirect==1)
                x2 += 5;
            else if(Mdirect==-1)
                x2 -= 5;
        }
    /*JUMP*/
        /*GF*/
        if(Gjumpkeys){
            GDY-=3, y+=GDY;
            GDA++;
        }
        else{
            if(y+GDY+3<=SCREEN_H-190)  GDY+=3, y+=GDY;
            else  y=SCREEN_H-190, GDA=1, GDY=0, Gdirect=0, Gjumpkeys=false;
        }
        /*MOOMIN*/
        if(Mjumpkeys){
            MDY-=3, y2+=MDY;
            MDA++;
        }
        else{
            if(y2+MDY+3<=SCREEN_H-190)  MDY+=3, y2+=MDY;
            else  y2=SCREEN_H-190, MDA=1, MDY=0, Mdirect=0, Mjumpkeys=false;
        }
}

