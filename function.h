#ifndef FUNCTION_H
#define FUNCTION_H

#define SCREEN_W 1160
#define SCREEN_H 590
#define TYB 1

extern FILE *fPtr;
extern char s[11];
extern int all[2];
extern bool done;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *timer;
extern ALLEGRO_DISPLAY *display;

/*AUDIO*/
    extern ALLEGRO_SAMPLE_ID *id;
    extern ALLEGRO_SAMPLE *title_song;
    extern ALLEGRO_SAMPLE *game_song;
    extern ALLEGRO_SAMPLE *record_song;
    extern ALLEGRO_SAMPLE *enter_song;
    extern ALLEGRO_SAMPLE *move_song;
    extern ALLEGRO_SAMPLE *ball_song;
    extern ALLEGRO_SAMPLE *cheer;
    extern ALLEGRO_SAMPLE *news_song;
/*TITLE*/
    /*TITLE BACK*/
        extern ALLEGRO_BITMAP *BLACK;
        extern ALLEGRO_BITMAP *TREE;
        extern ALLEGRO_BITMAP *littleball;
    /*TITLE MOOMIN*/
        extern ALLEGRO_BITMAP *T_M_1;
        extern ALLEGRO_BITMAP *T_M_2;
        extern ALLEGRO_BITMAP *T_M_3;
        extern ALLEGRO_BITMAP *T_M_4;
/*WIN*/
    extern ALLEGRO_BITMAP *MOOMIN_WIN;
    extern ALLEGRO_BITMAP *GF_WIN;
    extern ALLEGRO_BITMAP *MOOMIN_WIN2;
    extern ALLEGRO_BITMAP *GF_WIN2;
/*SHADOW*/
    extern ALLEGRO_BITMAP *SHADOW_M;
    extern ALLEGRO_BITMAP *SHADOW_B;
/*BALL*/
    extern ALLEGRO_BITMAP *BALL;
/*DECLARATION OF MOOMIN'S PICTURE*/
    extern ALLEGRO_BITMAP *RURU01;
    extern ALLEGRO_BITMAP *RURU02;
    extern ALLEGRO_BITMAP *RURU03;
    extern ALLEGRO_BITMAP *RURU04;
    /*DECLARATION OF MOOMIN'S RUNNING PICTURE*/
        extern ALLEGRO_BITMAP *MOO_run_1;
        extern ALLEGRO_BITMAP *MOO_run_2;
        extern ALLEGRO_BITMAP *MOO_run_3;
        extern ALLEGRO_BITMAP *MOO_run_4;
        extern ALLEGRO_BITMAP *MOO_run_5;
        extern ALLEGRO_BITMAP *MOO_run_6;
        extern ALLEGRO_BITMAP *MOO_run_7;
        extern ALLEGRO_BITMAP *MOO_run_8;
    /*DECLARATION OF MOOMIN'S BAT1 PICTURE*/
        extern ALLEGRO_BITMAP *MOO_bat1_1;
        extern ALLEGRO_BITMAP *MOO_bat1_2;
        extern ALLEGRO_BITMAP *MOO_bat1_3;
        extern ALLEGRO_BITMAP *MOO_bat1_4;
        extern ALLEGRO_BITMAP *MOO_bat1_5;
        extern ALLEGRO_BITMAP *MOO_bat1_6;
    /*DECLARATION OF MOOMIN'S BAT2 PICTURE*/
        extern ALLEGRO_BITMAP *MOO_bat2_1;
        extern ALLEGRO_BITMAP *MOO_bat2_2;
        extern ALLEGRO_BITMAP *MOO_bat2_3;
        extern ALLEGRO_BITMAP *MOO_bat2_4;
        extern ALLEGRO_BITMAP *MOO_bat2_5;
        extern ALLEGRO_BITMAP *MOO_bat2_6;
    /*DECLARATION OF MOOMIN'S BAT3 PICTURE*/
        extern ALLEGRO_BITMAP *MOO_bat3_1;
        extern ALLEGRO_BITMAP *MOO_bat3_2;
        extern ALLEGRO_BITMAP *MOO_bat3_3;
        extern ALLEGRO_BITMAP *MOO_bat3_4;
        extern ALLEGRO_BITMAP *MOO_bat3_5;

/*DECLARATION OF MOOMIN'S GF'S PICTURE*/
    extern ALLEGRO_BITMAP *GF_01;
    extern ALLEGRO_BITMAP *GF_02;
    extern ALLEGRO_BITMAP *GF_03;
    extern ALLEGRO_BITMAP *GF_04;
    /*DECLARATION OF MOOMIN'S GF'S RUNNING PICTURE*/
        extern ALLEGRO_BITMAP *GF_run_1;
        extern ALLEGRO_BITMAP *GF_run_2;
        extern ALLEGRO_BITMAP *GF_run_3;
        extern ALLEGRO_BITMAP *GF_run_4;
        extern ALLEGRO_BITMAP *GF_run_5;
        extern ALLEGRO_BITMAP *GF_run_6;
        extern ALLEGRO_BITMAP *GF_run_7;
        extern ALLEGRO_BITMAP *GF_run_8;
    /*DECLARATION OF MOOMIN'S GF'S BAT1 PICTURE*/
        extern ALLEGRO_BITMAP *GF_bat1_1;
        extern ALLEGRO_BITMAP *GF_bat1_2;
        extern ALLEGRO_BITMAP *GF_bat1_3;
        extern ALLEGRO_BITMAP *GF_bat1_4;
        extern ALLEGRO_BITMAP *GF_bat1_5;
        extern ALLEGRO_BITMAP *GF_bat1_6;
    /*DECLARATION OF MOOMIN'S GF'S BAT2 PICTURE*/
        extern ALLEGRO_BITMAP *GF_bat2_1;
        extern ALLEGRO_BITMAP *GF_bat2_2;
        extern ALLEGRO_BITMAP *GF_bat2_3;
        extern ALLEGRO_BITMAP *GF_bat2_4;
        extern ALLEGRO_BITMAP *GF_bat2_5;
        extern ALLEGRO_BITMAP *GF_bat2_6;
    /*DECLARATION OF MOOMIN'S GF'S BAT3 PICTURE*/
        extern ALLEGRO_BITMAP *GF_bat3_1;
        extern ALLEGRO_BITMAP *GF_bat3_2;
        extern ALLEGRO_BITMAP *GF_bat3_3;
        extern ALLEGRO_BITMAP *GF_bat3_4;
        extern ALLEGRO_BITMAP *GF_bat3_5;
/*DECLARATION OF BACKGROUND*/
    extern ALLEGRO_BITMAP *COLUMN;
    extern ALLEGRO_BITMAP *back_01;
    extern ALLEGRO_BITMAP *back_02;

/*DECLARATION OF TITLE*/
    extern ALLEGRO_FONT *title;
    extern ALLEGRO_FONT *title2;
    extern ALLEGRO_FONT *title3;
extern ALLEGRO_FONT *title4;
extern int state;
extern char warn[31];
extern int rx, ry;
extern int y, y2;
extern int x2, x;
//MOOMIN'S RUN
    extern bool keys[4];
    extern int Mdirect;
    extern int Gdirect;
//MOOMIN'S JUMP
    extern int MDY, MDA;
    extern bool Mjumpkeys;
//GF'S JUMP
    extern int GDY, GDA;
    extern bool Gjumpkeys;
//SCORE
    extern int SCORE[2];
    extern int SAVE_SCORE[2][2];
    extern bool SCORE_M, SCORE_G;
    extern bool M_WIN, G_WIN;
/*little ball*/
    extern bool play_ani;
extern bool about;
extern bool cursor;
extern bool yes, no;
extern bool Serveball;
extern bool REALM;
extern bool key_Q, key_E;
extern bool M_BAT1, M_BAT2, M_BAT3;
extern bool G_BAT1, G_BAT2, G_BAT3;
extern int rest;
extern int BALLtime;
extern int STAY;
extern int XB, YB;
extern int XBsave, YBsave;
extern int DX, DY;
extern double scale;
/*MOOMIN*/
    extern int TM, KM, BM;
    extern int TMbat1, BMbat1;
    extern bool key_bat1;
    extern bool key_bat2;
    extern bool key_bat3;
/*GF*/
    extern int TG, KG, BG;
    extern int TGbat1, BGbat1;
    extern bool key_G_bat1;
    extern bool key_G_bat2;
    extern bool key_G_bat3;
/*BALL*/
    extern bool who;
    extern bool INIT;
    extern bool keyball;

extern void write();
extern void WIN(ALLEGRO_BITMAP *who);
extern void event_title(ALLEGRO_EVENT even);
extern void init_record();
extern void init_title();
extern void init_play();
extern void abort_game(const char* message);
extern void BALLcount();
extern void BALLinit();
extern void BAT_M(int Y, int X);
extern void BAT_G(int Y, int X);
extern void event_access(ALLEGRO_EVENT event);
extern void event_process();

#endif // FUNCTION_H
