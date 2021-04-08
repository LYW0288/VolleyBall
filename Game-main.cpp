#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "function.h"

void game_init(void)
{
    if (!al_init())
        abort_game("Failed to initialize allegro");

    if (!al_install_mouse())
        abort_game("Failed to initialize mouse");

    if (!al_install_audio())
        abort_game("Failed to initialize audio");

    if (!al_init_acodec_addon())
        abort_game("Failed to initialize acodec");

    if (!al_reserve_samples(3))
        abort_game("Failed to initialize sample");

    if (!al_install_keyboard())
        abort_game("Failed to install keyboard");

    timer = al_create_timer(1.0 / 30);
    if (!timer)
        abort_game("Failed to create timer");

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(SCREEN_W, SCREEN_H);
    if (!display)
        abort_game("Failed to create display");

    event_queue = al_create_event_queue();
    if (!event_queue)
        abort_game("Failed to create event queue");

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));


    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    done = false;
}

void game_destroy(void)
{
    if (timer)
        al_destroy_timer(timer);

    if (display)
        al_destroy_display(display);

    if (event_queue)
        al_destroy_event_queue(event_queue);
/*AUDIO*/
    if(title_song)
            al_destroy_sample(title_song);
    if(record_song)
            al_destroy_sample(record_song);
    if(game_song)
            al_destroy_sample(game_song);
    if(ball_song)
            al_destroy_sample(ball_song);
    if(cheer)
            al_destroy_sample(cheer);
    if(enter_song)
            al_destroy_sample(enter_song);
    if(move_song)
            al_destroy_sample(move_song);
/*TITLE*/
    /*BACK*/
        if (BLACK)
            al_destroy_bitmap(BLACK);
        if (TREE)
            al_destroy_bitmap(TREE);
    /*T_MOOMIN*/
        if (T_M_1)
            al_destroy_bitmap(T_M_1);
        if (T_M_2)
            al_destroy_bitmap(T_M_2);
        if (T_M_3)
            al_destroy_bitmap(T_M_3);
        if (T_M_4)
            al_destroy_bitmap(T_M_4);

/*DESTROY MOOMIN'S PICTURE*/
    if (RURU01)
        al_destroy_bitmap(RURU01);
    if (RURU02)
        al_destroy_bitmap(RURU02);
    if (RURU03)
        al_destroy_bitmap(RURU03);
    if (RURU04)
        al_destroy_bitmap(RURU04);
    /*DESTROY MOOMIN'S RUNNING PICTURE*/
        if (MOO_run_1)
            al_destroy_bitmap(MOO_run_1);
        if (MOO_run_2)
            al_destroy_bitmap(MOO_run_2);
        if (MOO_run_3)
            al_destroy_bitmap(MOO_run_3);
        if (MOO_run_4)
            al_destroy_bitmap(MOO_run_4);
        if (MOO_run_5)
            al_destroy_bitmap(MOO_run_5);
        if (MOO_run_6)
            al_destroy_bitmap(MOO_run_6);
        if (MOO_run_7)
            al_destroy_bitmap(MOO_run_7);
        if (MOO_run_8)
            al_destroy_bitmap(MOO_run_8);
    /*DESTROY MOOMIN'S BAT1 PICTURE*/
        if (MOO_bat1_1)
            al_destroy_bitmap(MOO_bat1_1);
        if (MOO_bat1_2)
            al_destroy_bitmap(MOO_bat1_2);
        if (MOO_bat1_3)
            al_destroy_bitmap(MOO_bat1_3);
        if (MOO_bat1_4)
            al_destroy_bitmap(MOO_bat1_4);
        if (MOO_bat1_5)
            al_destroy_bitmap(MOO_bat1_5);
        if (MOO_bat1_6)
            al_destroy_bitmap(MOO_bat1_6);
    /*DESTROY MOOMIN'S BAT2 PICTURE*/
        if (MOO_bat2_1)
            al_destroy_bitmap(MOO_bat2_1);
        if (MOO_bat2_2)
            al_destroy_bitmap(MOO_bat2_2);
        if (MOO_bat2_3)
            al_destroy_bitmap(MOO_bat2_3);
        if (MOO_bat2_4)
            al_destroy_bitmap(MOO_bat2_4);
        if (MOO_bat2_5)
            al_destroy_bitmap(MOO_bat2_5);
        if (MOO_bat2_6)
            al_destroy_bitmap(MOO_bat2_6);
    /*DESTROY MOOMIN'S BAT3 PICTURE*/
        if (MOO_bat3_1)
            al_destroy_bitmap(MOO_bat3_1);
        if (MOO_bat3_2)
            al_destroy_bitmap(MOO_bat3_2);
        if (MOO_bat3_3)
            al_destroy_bitmap(MOO_bat3_3);
        if (MOO_bat3_4)
            al_destroy_bitmap(MOO_bat3_4);
        if (MOO_bat3_5)
            al_destroy_bitmap(MOO_bat3_5);
/*DESTROY GF'S PICTURE*/
    if (GF_01)
        al_destroy_bitmap(GF_01);
    if (GF_02)
        al_destroy_bitmap(GF_02);
    if (GF_03)
        al_destroy_bitmap(GF_03);
    if (GF_04)
        al_destroy_bitmap(GF_04);
    /*DESTROY MOOMIN'S RUNNING PICTURE*/
        if (GF_run_1)
            al_destroy_bitmap(GF_run_1);
        if (GF_run_2)
            al_destroy_bitmap(GF_run_2);
        if (GF_run_3)
            al_destroy_bitmap(GF_run_3);
        if (GF_run_4)
            al_destroy_bitmap(GF_run_4);
        if (GF_run_5)
            al_destroy_bitmap(GF_run_5);
        if (GF_run_6)
            al_destroy_bitmap(GF_run_6);
        if (GF_run_7)
            al_destroy_bitmap(GF_run_7);
        if (GF_run_8)
            al_destroy_bitmap(GF_run_8);
    /*DESTROY GF'S BAT1 PICTURE*/
        if (GF_bat1_1)
            al_destroy_bitmap(GF_bat1_1);
        if (GF_bat1_2)
            al_destroy_bitmap(GF_bat1_2);
        if (GF_bat1_3)
            al_destroy_bitmap(GF_bat1_3);
        if (GF_bat1_4)
            al_destroy_bitmap(GF_bat1_4);
        if (GF_bat1_5)
            al_destroy_bitmap(GF_bat1_5);
        if (GF_bat1_6)
            al_destroy_bitmap(GF_bat1_6);
    /*DESTROY GF'S BAT2 PICTURE*/
        if (GF_bat2_1)
            al_destroy_bitmap(GF_bat2_1);
        if (GF_bat2_2)
            al_destroy_bitmap(GF_bat2_2);
        if (GF_bat2_3)
            al_destroy_bitmap(GF_bat2_3);
        if (GF_bat2_4)
            al_destroy_bitmap(GF_bat2_4);
        if (GF_bat2_5)
            al_destroy_bitmap(GF_bat2_5);
        if (GF_bat2_6)
            al_destroy_bitmap(GF_bat2_6);
    /*DESTROY GF'S BAT3 PICTURE*/
        if (GF_bat3_1)
            al_destroy_bitmap(GF_bat3_1);
        if (GF_bat3_2)
            al_destroy_bitmap(GF_bat3_2);
        if (GF_bat3_3)
            al_destroy_bitmap(GF_bat3_3);
        if (GF_bat3_4)
            al_destroy_bitmap(GF_bat3_4);
        if (GF_bat3_5)
            al_destroy_bitmap(GF_bat3_5);
/*DESTROY BACK*/
    if (back_01)
        al_destroy_bitmap(back_01);
    if (back_02)
        al_destroy_bitmap(back_02);
    if (COLUMN)
        al_destroy_bitmap(COLUMN);
/*DESTROY SHADOW*/
    if (SHADOW_M)
        al_destroy_bitmap(SHADOW_M);
    if (SHADOW_B)
        al_destroy_bitmap(SHADOW_B);
/*DESYROY BALL*/
    if(BALL)
        al_destroy_bitmap(BALL);
/*DESTROY TITLE*/
    if (title)
        al_destroy_font(title);
    if (title2)
        al_destroy_font(title2);
    if (title3)
        al_destroy_font(title3);
    if (title4)
        al_destroy_font(title4);
}
ALLEGRO_BITMAP *load_bitmap_at_size(const char *filename, int w, int h)
{
    ALLEGRO_BITMAP *resized_bmp, *loaded_bmp, *prev_target;

    resized_bmp = al_create_bitmap(w, h);
    if (!resized_bmp) return NULL;

    loaded_bmp = al_load_bitmap(filename);
    if (!loaded_bmp)
    {
        al_destroy_bitmap(resized_bmp);
        return NULL;
    }

    prev_target = al_get_target_bitmap();
    al_set_target_bitmap(resized_bmp);

    al_draw_scaled_bitmap(loaded_bmp,
                          0, 0,
                          al_get_bitmap_width(loaded_bmp),
                          al_get_bitmap_height(loaded_bmp),
                          0, 0,
                          w, h, 0 );

    al_set_target_bitmap(prev_target);
    al_destroy_bitmap(loaded_bmp);

    return resized_bmp;
}


void game_run(void)
{
    bool redraw = true;
    al_start_timer(timer);

    //AUDIO
        id = (ALLEGRO_SAMPLE_ID *)malloc(sizeof(ALLEGRO_SAMPLE_ID));
        title_song = al_load_sample("AUDIO/title_song.wav");
        game_song = al_load_sample("AUDIO/game_song.wav");
        record_song = al_load_sample("AUDIO/record_song.wav");
        ball_song = al_load_sample("AUDIO/ball_song.wav");
        cheer = al_load_sample("AUDIO/cheer.wav");
        enter_song = al_load_sample("AUDIO/enter_song.wav");
        move_song = al_load_sample("AUDIO/move_song.wav");
        news_song = al_load_sample("AUDIO/news_song.wav");

    //TITLE
        int TX_1=0, TX_2=SCREEN_W;
        //BACK
            BLACK = load_bitmap_at_size("TITLE/TITLE_BLACK.png", SCREEN_W, SCREEN_H);
            TREE = load_bitmap_at_size("TITLE/TREE.png", 1160, 174);
            littleball = load_bitmap_at_size("TITLE/T_BALL.png", 7, 7);
        //T_MOOMIN
            T_M_1 = load_bitmap_at_size("TITLE/TITLE MOOMIN/T_M_01.png", 50, 40);
            T_M_2 = load_bitmap_at_size("TITLE/TITLE MOOMIN/T_M_02.png", 50, 40);
            T_M_3 = load_bitmap_at_size("TITLE/TITLE MOOMIN/T_M_03.png", 50, 40);
            T_M_4 = load_bitmap_at_size("TITLE/TITLE MOOMIN/T_M_04.png", 50, 40);
    //WIN
        MOOMIN_WIN = load_bitmap_at_size("WIN/M_WIN.png", 105, 143);
        GF_WIN = load_bitmap_at_size("WIN/G_WIN.png", 105, 143);
        MOOMIN_WIN2 = load_bitmap_at_size("WIN/M_WIN2.png", 240, 185);
        GF_WIN2 = load_bitmap_at_size("WIN/G_WIN2.png", 240, 185);
    //MOOMIN
        RURU01 = load_bitmap_at_size("MOOMIN/STAND/RURU-01.png", 169, 140);
        RURU02 = load_bitmap_at_size("MOOMIN/STAND/RURU-02.png", 169, 140);
        RURU03 = load_bitmap_at_size("MOOMIN/STAND/RURU-03.png", 169, 140);
        RURU04 = load_bitmap_at_size("MOOMIN/STAND/RURU-04.png", 169, 140);
        //SHADOW
            SHADOW_M = load_bitmap_at_size("SHADOW.png", 84, 15);
        //MOOMIN'S RUN
            MOO_run_1 = load_bitmap_at_size("MOOMIN/RUN/MOO_RUN_01.png", 169, 140);
            MOO_run_2 = load_bitmap_at_size("MOOMIN/RUN/MOO_RUN_02.png", 169, 140);
            MOO_run_3 = load_bitmap_at_size("MOOMIN/RUN/MOO_RUN_03.png", 169, 140);
            MOO_run_4 = load_bitmap_at_size("MOOMIN/RUN/MOO_RUN_04.png", 169, 140);
            MOO_run_5 = load_bitmap_at_size("MOOMIN/RUN/MOO_RUN_05.png", 169, 140);
            MOO_run_6 = load_bitmap_at_size("MOOMIN/RUN/MOO_RUN_06.png", 169, 140);
            MOO_run_7 = load_bitmap_at_size("MOOMIN/RUN/MOO_RUN_07.png", 169, 140);
            MOO_run_8 = load_bitmap_at_size("MOOMIN/RUN/MOO_RUN_08.png", 169, 140);
        //MOOMIN'S BAT1
            MOO_bat1_1 = load_bitmap_at_size("MOOMIN/BAT/MOO_BAT1_01.png", 169, 140);
            MOO_bat1_2 = load_bitmap_at_size("MOOMIN/BAT/MOO_BAT1_02.png", 169, 140);
            MOO_bat1_3 = load_bitmap_at_size("MOOMIN/BAT/MOO_BAT1_03.png", 169, 140);
            MOO_bat1_4 = load_bitmap_at_size("MOOMIN/BAT/MOO_BAT1_04.png", 169, 140);
            MOO_bat1_5 = load_bitmap_at_size("MOOMIN/BAT/MOO_BAT1_05.png", 169, 140);
            MOO_bat1_6 = load_bitmap_at_size("MOOMIN/BAT/MOO_BAT1_06.png", 169, 140);
        //MOOMIN'S BAT2
            MOO_bat2_1 = load_bitmap_at_size("MOOMIN/BAT2/MOO_BAT2_01.png", 169, 140);
            MOO_bat2_2 = load_bitmap_at_size("MOOMIN/BAT2/MOO_BAT2_02.png", 169, 140);
            MOO_bat2_3 = load_bitmap_at_size("MOOMIN/BAT2/MOO_BAT2_03.png", 169, 140);
            MOO_bat2_4 = load_bitmap_at_size("MOOMIN/BAT2/MOO_BAT2_04.png", 169, 140);
            MOO_bat2_5 = load_bitmap_at_size("MOOMIN/BAT2/MOO_BAT2_05.png", 169, 140);
            MOO_bat2_6 = load_bitmap_at_size("MOOMIN/BAT2/MOO_BAT2_06.png", 169, 140);
        //MOOMIN'S BAT3
            MOO_bat3_1 = load_bitmap_at_size("MOOMIN/BAT3/MOO_BAT3_01.png", 169, 140);
            MOO_bat3_2 = load_bitmap_at_size("MOOMIN/BAT3/MOO_BAT3_02.png", 169, 140);
            MOO_bat3_3 = load_bitmap_at_size("MOOMIN/BAT3/MOO_BAT3_03.png", 169, 140);
            MOO_bat3_4 = load_bitmap_at_size("MOOMIN/BAT3/MOO_BAT3_04.png", 169, 140);
            MOO_bat3_5 = load_bitmap_at_size("MOOMIN/BAT3/MOO_BAT3_05.png", 169, 140);


    //MOOMIN'S GF
        GF_01 = load_bitmap_at_size("GF/STAND/GF_01.png", 169, 140);
        GF_02 = load_bitmap_at_size("GF/STAND/GF_02.png", 169, 140);
        GF_03 = load_bitmap_at_size("GF/STAND/GF_03.png", 169, 140);
        GF_04 = load_bitmap_at_size("GF/STAND/GF_04.png", 169, 140);
        //SHADOW
            SHADOW_B = load_bitmap_at_size("SHADOW_B.png", 42, 15);
        //GF'S RUN
            GF_run_1 = load_bitmap_at_size("GF/RUN/GF_RUN_01.png", 169, 140);
            GF_run_2 = load_bitmap_at_size("GF/RUN/GF_RUN_02.png", 169, 140);
            GF_run_3 = load_bitmap_at_size("GF/RUN/GF_RUN_03.png", 169, 140);
            GF_run_4 = load_bitmap_at_size("GF/RUN/GF_RUN_04.png", 169, 140);
            GF_run_5 = load_bitmap_at_size("GF/RUN/GF_RUN_05.png", 169, 140);
            GF_run_6 = load_bitmap_at_size("GF/RUN/GF_RUN_06.png", 169, 140);
            GF_run_7 = load_bitmap_at_size("GF/RUN/GF_RUN_07.png", 169, 140);
            GF_run_8 = load_bitmap_at_size("GF/RUN/GF_RUN_08.png", 169, 140);
        //GF'S BAT1
            GF_bat1_1 = load_bitmap_at_size("GF/BAT/GF_BAT1_01.png", 169, 140);
            GF_bat1_2 = load_bitmap_at_size("GF/BAT/GF_BAT1_02.png", 169, 140);
            GF_bat1_3 = load_bitmap_at_size("GF/BAT/GF_BAT1_03.png", 169, 140);
            GF_bat1_4 = load_bitmap_at_size("GF/BAT/GF_BAT1_04.png", 169, 140);
            GF_bat1_5 = load_bitmap_at_size("GF/BAT/GF_BAT1_05.png", 169, 140);
            GF_bat1_6 = load_bitmap_at_size("GF/BAT/GF_BAT1_06.png", 169, 140);
        //GF'S BAT2
            GF_bat2_1 = load_bitmap_at_size("GF/BAT2/GF_BAT2_01.png", 169, 140);
            GF_bat2_2 = load_bitmap_at_size("GF/BAT2/GF_BAT2_02.png", 169, 140);
            GF_bat2_3 = load_bitmap_at_size("GF/BAT2/GF_BAT2_03.png", 169, 140);
            GF_bat2_4 = load_bitmap_at_size("GF/BAT2/GF_BAT2_04.png", 169, 140);
            GF_bat2_5 = load_bitmap_at_size("GF/BAT2/GF_BAT2_05.png", 169, 140);
            GF_bat2_6 = load_bitmap_at_size("GF/BAT2/GF_BAT2_06.png", 169, 140);
        //GF'S BAT3
            GF_bat3_1 = load_bitmap_at_size("GF/BAT3/GF_BAT3_01.png", 169, 140);
            GF_bat3_2 = load_bitmap_at_size("GF/BAT3/GF_BAT3_02.png", 169, 140);
            GF_bat3_3 = load_bitmap_at_size("GF/BAT3/GF_BAT3_03.png", 169, 140);
            GF_bat3_4 = load_bitmap_at_size("GF/BAT3/GF_BAT3_04.png", 169, 140);
            GF_bat3_5 = load_bitmap_at_size("GF/BAT3/GF_BAT3_05.png", 169, 140);


    //Background
        int TB=0, KB=0;
        back_01  = al_load_bitmap("BACK/background_01.png");
        back_02  = al_load_bitmap("BACK/background_02.png");
        COLUMN  = al_load_bitmap("BACK/COLUMN.png");
    //BALL
        BALL = load_bitmap_at_size("BALL.png", 43, 43);
    //OPENING
        title = al_load_font("misaki_gothic.ttf", 25, NULL);
        title2 = al_load_font("misaki_gothic.ttf", 50, NULL);
        title3 = al_load_font("misaki_mincho.ttf", 75, NULL);
        title4 = al_load_font("misaki_mincho.ttf", 25, NULL);


    fPtr = fopen("score.txt", "r");
    fscanf(fPtr, "%s%d%d", s, &all[0], &all[1]);
    fclose(fPtr);
    al_play_sample(title_song, 1.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, id);

    while (!done) { /*DISPLAY*/

        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);

        if (event.type == ALLEGRO_EVENT_TIMER) redraw = true;
        if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) { /*ESC*/
            if (state==0) done = true;
            else init_title();
        }
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { /*X*/
            done = true;
            break;
        }
        if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_G) SAVE_SCORE[0][1]++;
        if (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_F) M_WIN=true;

        if(state == 0 ) { /*Opening*/
            if (!play_ani) event_title(event);
            if (redraw && al_is_event_queue_empty(event_queue)) { /*show the title*/
                redraw = false;

                if(TX_1==0) TX_2=SCREEN_W;
                if(TX_2==0) TX_1=SCREEN_W;
                al_draw_bitmap(TREE, TX_1, 103, 0);
                al_draw_bitmap(TREE, TX_2, 103, 0);
                if(TM==0){
                    al_draw_bitmap(T_M_1, SCREEN_W/2-25, 200, 0), KM++, TX_1-=1, TX_2-=1;
                    if(KM==4) TM++, KM=0;
                }
                else if(TM==1){
                    al_draw_bitmap(T_M_2, SCREEN_W/2-25, 200, 0), KM++, TX_1-=1, TX_2-=1;
                    if(KM==4) TM++, KM=0;
                }
                else if(TM==2){
                    al_draw_bitmap(T_M_3, SCREEN_W/2-25, 200, 0), KM++, TX_1-=1, TX_2-=1;
                    if(KM==4) TM++, KM=0;
                }
                else if(TM==3){
                    al_draw_bitmap(T_M_4, SCREEN_W/2-25, 200, 0), KM++, TX_1-=1, TX_2-=1;
                    if(KM==4) TM=0, KM=0;
                }
                al_draw_bitmap(BLACK, 0, 0, 0);
                al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2, ALLEGRO_ALIGN_CENTER, "Game start");
                al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2+20, ALLEGRO_ALIGN_CENTER, "Record");
                al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2, SCREEN_H/2+40, ALLEGRO_ALIGN_CENTER, "Exit");
                if(!cursor){
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W-30, SCREEN_H-30, ALLEGRO_ALIGN_CENTER, "?");
                    al_draw_rectangle(SCREEN_W-40, SCREEN_H-30, SCREEN_W-20, SCREEN_H-10, al_map_rgb(255, 255, 255), 3);
                }
                else {
                    al_draw_filled_rectangle(SCREEN_W-40-1.5, SCREEN_H-30-1.5, SCREEN_W-20+1.5, SCREEN_H-10+1.5, al_map_rgb(255, 255, 255));
                    al_draw_text(title, al_map_rgb(0,0,0), SCREEN_W-30, SCREEN_H-30, ALLEGRO_ALIGN_CENTER, "?");
                }
                if(about){
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2-200, SCREEN_H/2+100, ALLEGRO_ALIGN_CENTER, "For Player1");
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2-200, SCREEN_H/2+120, ALLEGRO_ALIGN_CENTER, "Press AD to move.");
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2-200, SCREEN_H/2+140, ALLEGRO_ALIGN_CENTER, "Press W to jump.");
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2-200, SCREEN_H/2+160, ALLEGRO_ALIGN_CENTER, "Press E to serve ball.");
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2-200, SCREEN_H/2+180, ALLEGRO_ALIGN_CENTER, "Press ZXS to stroke.");
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2+200, SCREEN_H/2+100, ALLEGRO_ALIGN_CENTER, "For Player2");
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2+200, SCREEN_H/2+120, ALLEGRO_ALIGN_CENTER, "Press left&right to move.");
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2+200, SCREEN_H/2+140, ALLEGRO_ALIGN_CENTER, "Press up to jump.");
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2+200, SCREEN_H/2+160, ALLEGRO_ALIGN_CENTER, "Press enter to serve ball.");
                    al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2+200, SCREEN_H/2+180, ALLEGRO_ALIGN_CENTER, "Press KL or down to stroke.");
                }
                al_draw_rectangle(rx-100, ry, rx+100, ry+20, al_map_rgb(255, 255, 255), 3);
                if(play_ani) init_play();
                al_flip_display();
            }
        }
        else if(state == 1) { /*Game start*/
            event_access(event);
            if (redraw && al_is_event_queue_empty(event_queue)) { /*Show the display*/
                redraw = false;
                event_process();
                {/*BACK*/
                if(TB==0){
                    al_draw_bitmap(back_01, 0, 0, 0), KB++;
                    if(KB==10) TB++, KB=0;
                }
                else{
                    al_draw_bitmap(back_02, 0, 0, 0), KB++;
                    if(KB==10) TB--, KB=0;
                }
                }
                al_draw_bitmap(SHADOW_M, x2+58, SCREEN_H - al_get_bitmap_height(RURU01)-65+140, 0);/*SHADOW_M*/
                al_draw_bitmap(SHADOW_M, x+25, SCREEN_H - al_get_bitmap_height(RURU01)-65+140, 0);/*SHADOW_G*/
                al_draw_bitmap(SHADOW_B, XB-21, SCREEN_H - al_get_bitmap_height(RURU01)-65+140, 0);/*SHADOW_B*/
                { /*MOOMIN's ANIMATION*/
                if((!keys[2] && !keys[3] && !key_bat1 && !key_bat2 && !key_bat3 || (keys[2]&&keys[3])) )
                    if(TM==0){
                        al_draw_bitmap(RURU01, x2, y2, 0);
                        BM++;
                        if(BM==5)
                            TM++, BM=0;
                        KM=0;
                    }
                    else if(TM==1){
                        al_draw_bitmap(RURU02, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==5)
                                TM++, BM=0;
                        }
                        else
                            if(BM==5)
                                TM--, BM=0;
                    }
                    else if(TM==2){
                        al_draw_bitmap(RURU03, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==5)
                                TM++, BM=0;
                        }
                        else
                            if(BM==5)
                                TM--, BM=0;
                    }
                    else{
                        al_draw_bitmap(RURU04, x2, y2, 0);
                        BM++;
                        if(BM==5)
                            TM--, BM=0;
                        KM=1;
                    }
                else if(!key_bat1 && !key_bat2 && !key_bat3){ /*When MOOMIN is running*/
                    if(keys[2])
                        KM=0;
                    else if(keys[3])
                        KM=1;
                    if(TM==0){
                        al_draw_bitmap(MOO_run_1, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==3)
                                TM++, BM=0;
                        }
                        else{
                            if(BM==3)
                                TM=7, BM=0;
                        }
                    }
                    else if(TM==1){
                        al_draw_bitmap(MOO_run_2, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==3)
                                TM++, BM=0;
                        }
                        else{
                            if(BM==3)
                                TM--, BM=0;
                        }
                    }
                    else if(TM==2){
                        al_draw_bitmap(MOO_run_3, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==3)
                                TM++, BM=0;
                        }
                        else{
                            if(BM==3)
                                TM--, BM=0;
                        }
                    }
                    else if(TM==3){
                        al_draw_bitmap(MOO_run_4, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==3)
                                TM++, BM=0;
                        }
                        else{
                            if(BM==3)
                                TM--, BM=0;
                        }
                    }
                    else if(TM==4){
                        al_draw_bitmap(MOO_run_5, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==3)
                                TM++, BM=0;
                        }
                        else{
                            if(BM==3)
                                TM--, BM=0;
                        }
                    }
                    else if(TM==5){
                        al_draw_bitmap(MOO_run_6, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==3)
                                TM++, BM=0;
                        }
                        else{
                            if(BM==3)
                                TM--, BM=0;
                        }
                    }
                    else if(TM==6){
                        al_draw_bitmap(MOO_run_7, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==3)
                                TM++, BM=0;
                        }
                        else{
                            if(BM==3)
                                TM--, BM=0;
                        }
                    }
                    else{
                        al_draw_bitmap(MOO_run_8, x2, y2, 0);
                        BM++;
                        if(KM==0){
                            if(BM==3)
                                TM=0, BM=0;
                        }
                        else{
                            if(BM==3)
                                TM--, BM=0;
                        }
                    }
                }
                else if(key_bat1){
                    if(TMbat1==0){
                        al_draw_bitmap(MOO_bat1_1, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==1)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==1){
                        al_draw_bitmap(MOO_bat1_2, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==1)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==2){
                        al_draw_bitmap(MOO_bat1_3, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==1)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==3){
                        al_draw_bitmap(MOO_bat1_4, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==5)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==4){
                        al_draw_bitmap(MOO_bat1_5, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==5)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==5){
                        al_draw_bitmap(MOO_bat1_6, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==2)
                                TMbat1=0, BMbat1=0, key_bat1=false;
                    }
                }
                else if(key_bat2){
                    if(TMbat1==0){
                        al_draw_bitmap(MOO_bat2_1, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==2)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==1){
                        al_draw_bitmap(MOO_bat2_2, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==2)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==2){
                        al_draw_bitmap(MOO_bat2_3, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==2)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==3){
                        al_draw_bitmap(MOO_bat2_4, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==2)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==4){
                        al_draw_bitmap(MOO_bat2_5, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==5)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==5){
                        al_draw_bitmap(MOO_bat2_6, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==2)
                                TMbat1=0, BMbat1=0, key_bat2=false;
                    }
                }
                else if(key_bat3){
                    if(TMbat1==0){
                        al_draw_bitmap(MOO_bat3_1, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==1)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==1){
                        al_draw_bitmap(MOO_bat3_2, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==1)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==2){
                        al_draw_bitmap(MOO_bat3_3, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==3)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==3){
                        al_draw_bitmap(MOO_bat3_4, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==5)
                                TMbat1++, BMbat1=0;
                    }
                    if(TMbat1==4){
                        al_draw_bitmap(MOO_bat3_5, x2, y2, 0);
                        BMbat1++;
                            if(BMbat1==2)
                                TMbat1=0, BMbat1=0, key_bat3=false;
                    }
                }
                }
                {/*GF'S ANIMATION*/
                if(!keys[0] && !keys[1] && !key_G_bat1 && !key_G_bat2 && !key_G_bat3 || (keys[0]&&keys[1]))
                    if(TG==0){
                        al_draw_bitmap(GF_01, x, y, 0);
                        BG++;
                        if(BG==5)
                            TG++, BG=0;
                        KG=0;
                    }
                    else if(TG==1){
                        al_draw_bitmap(GF_02, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==5)
                                TG++, BG=0;
                        }
                        else
                            if(BG==5)
                                TG--, BG=0;
                    }
                    else if(TG==2){
                        al_draw_bitmap(GF_03, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==5)
                                TG++, BG=0;
                        }
                        else
                            if(BG==5)
                                TG--, BG=0;
                    }
                    else{
                        al_draw_bitmap(GF_04, x, y, 0);
                        BG++;
                        if(BG==5)
                            TG--, BG=0;
                        KG=1;
                    }
                else if(!key_G_bat1 && !key_G_bat2 && !key_G_bat3){ /*When GF is running*/
                    if(keys[0])
                        KG=0;
                    else if(keys[1])
                        KG=1;
                    if(TG==0){
                        al_draw_bitmap(GF_run_1, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==3)
                                TG++, BG=0;
                        }
                        else{
                            if(BG==3)
                                TG=7, BG=0;
                        }
                    }
                    else if(TG==1){
                        al_draw_bitmap(GF_run_2, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==3)
                                TG++, BG=0;
                        }
                        else{
                            if(BG==3)
                                TG--, BG=0;
                        }
                    }
                    else if(TG==2){
                        al_draw_bitmap(GF_run_3, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==3)
                                TG++, BG=0;
                        }
                        else{
                            if(BG==3)
                                TG--, BG=0;
                        }
                    }
                    else if(TG==3){
                        al_draw_bitmap(GF_run_4, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==3)
                                TG++, BG=0;
                        }
                        else{
                            if(BG==3)
                                TG--, BG=0;
                        }
                    }
                    else if(TG==4){
                        al_draw_bitmap(GF_run_5, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==3)
                                TG++, BG=0;
                        }
                        else{
                            if(BG==3)
                                TG--, BG=0;
                        }
                    }
                    else if(TG==5){
                        al_draw_bitmap(GF_run_6, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==3)
                                TG++, BG=0;
                        }
                        else{
                            if(BG==3)
                                TG--, BG=0;
                        }
                    }
                    else if(TG==6){
                        al_draw_bitmap(GF_run_7, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==3)
                                TG++, BG=0;
                        }
                        else{
                            if(BG==3)
                                TG--, BG=0;
                        }
                    }
                    else{
                        al_draw_bitmap(GF_run_8, x, y, 0);
                        BG++;
                        if(KG==0){
                            if(BG==3)
                                TG=0, BG=0;
                        }
                        else{
                            if(BG==3)
                                TG--, BG=0;
                        }
                    }
                }
                else if(key_G_bat1){
                    if(TGbat1==0){
                        al_draw_bitmap(GF_bat1_1, x, y, 0);
                        BGbat1++;
                            if(BGbat1==1)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==1){
                        al_draw_bitmap(GF_bat1_2, x, y, 0);
                        BGbat1++;
                            if(BGbat1==1)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==2){
                        al_draw_bitmap(GF_bat1_3, x, y, 0);
                        BGbat1++;
                            if(BGbat1==1)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==3){
                        al_draw_bitmap(GF_bat1_4, x, y, 0);
                        BGbat1++;
                            if(BGbat1==5)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==4){
                        al_draw_bitmap(GF_bat1_5, x, y, 0);
                        BGbat1++;
                            if(BGbat1==5)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==5){
                        al_draw_bitmap(GF_bat1_6, x, y, 0);
                        BGbat1++;
                            if(BGbat1==2)
                                TGbat1=0, BGbat1=0, key_G_bat1=false;
                    }
                }
                else if(key_G_bat2){
                    if(TGbat1==0){
                        al_draw_bitmap(GF_bat2_1, x, y, 0);
                        BGbat1++;
                            if(BGbat1==2)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==1){
                        al_draw_bitmap(GF_bat2_2, x, y, 0);
                        BGbat1++;
                            if(BGbat1==2)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==2){
                        al_draw_bitmap(GF_bat2_3, x, y, 0);
                        BGbat1++;
                            if(BGbat1==2)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==3){
                        al_draw_bitmap(GF_bat2_4, x, y, 0);
                        BGbat1++;
                            if(BGbat1==2)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==4){
                        al_draw_bitmap(GF_bat2_5, x, y, 0);
                        BGbat1++;
                            if(BGbat1==5)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==5){
                        al_draw_bitmap(GF_bat2_6, x, y, 0);
                        BGbat1++;
                            if(BGbat1==2)
                                TGbat1=0, BGbat1=0, key_G_bat2=false;
                    }
                }
                else if(key_G_bat3){
                    if(TGbat1==0){
                        al_draw_bitmap(GF_bat3_1, x, y, 0);
                        BGbat1++;
                            if(BGbat1==1)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==1){
                        al_draw_bitmap(GF_bat3_2, x, y, 0);
                        BGbat1++;
                            if(BGbat1==1)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==2){
                        al_draw_bitmap(GF_bat3_3, x, y, 0);
                        BGbat1++;
                            if(BGbat1==3)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==3){
                        al_draw_bitmap(GF_bat3_4, x, y, 0);
                        BGbat1++;
                            if(BGbat1==5)
                                TGbat1++, BGbat1=0;
                    }
                    if(TGbat1==4){
                        al_draw_bitmap(GF_bat3_5, x, y, 0);
                        BGbat1++;
                            if(BGbat1==2)
                                TGbat1=0, BGbat1=0, key_G_bat3=false;
                    }
                }
                }
                {/*Ball's moving*/
                /*Ball's gravity*/
                XB += DX;
                if(YB+DY+TYB>y2+20 && YB+DY+TYB<y2+100 && XB>x2+20 && XB<x2+84 && TMbat1>2 && INIT){/*M_BAT'S INITIAL*/
                    if(key_bat1) M_BAT1=true, INIT=false;
                    else if(key_bat2) M_BAT2=true, INIT=false;
                    else if(key_bat3) M_BAT3=true, INIT=false;
                }
                if(YB+DY+TYB>y+20 && YB+DY+TYB<y+100 && XB<x+169-20 && XB>x+169-84 && TGbat1>2 && INIT){/*G_BAT1'S INITIAL*/
                    if(key_G_bat1) G_BAT1=true, INIT=false;
                    else if(key_G_bat2) G_BAT2=true, INIT=false;
                    else if(key_G_bat3) G_BAT3=true, INIT=false;
                }
                if(!key_G_bat2 && !key_G_bat1&& !key_G_bat3 && !key_bat2 && !key_bat1 && !key_bat3)
                    INIT=true;
                if(((XB<=SCREEN_W/2+5 && XB-DX>SCREEN_W/2+5) || (XB>=SCREEN_W/2-5 && XB-DX<SCREEN_W/2-5)) && YB+DY+TYB>=SCREEN_H-160)/*COLUMN'S INITIAL*/
                    keyball=true;
                if((SCREEN_H-65>YB+DY+TYB)&& !keyball && !M_BAT1 && !M_BAT2 && !M_BAT3 && !key_Q && !G_BAT1 && !G_BAT2 && !G_BAT3 && !key_E){
                    DY += TYB;
                    YB += DY;
                }
                else if(key_Q) XB = x2+120, YB = y2+100, DY=0, DX=0;
                else if(key_E) XB = x+20, YB = y+100, DY=0, DX=0;
                else if(M_BAT1) BAT_M(-25, -3);/*MOOMIN'S BAT1*/
                else if(M_BAT2) BAT_M(5, -20);/*MOOMIN'S BAT2*/
                else if(M_BAT3) BAT_M(-20, -15);/*MOOMIN'S BAT3*/
                else if(G_BAT1) BAT_G(-25, 3);/*GF'S BAT1*/
                else if(G_BAT2) BAT_G(5, 20);/*GF'S BAT2*/
                else if(G_BAT3) BAT_G(-20, 15);/*GF'S BAT3*/
                else if(keyball){/*COLUMN*/
                    if(XB<=SCREEN_W/2+5){
                        DX = -DX;
                        XB = SCREEN_W/2-5;
                        keyball=false;
                    }
                    else if(XB>=SCREEN_W/2-5){
                        DX = -DX;
                        XB = SCREEN_W/2+5;
                        keyball=false;
                    }
                }
                else if(SCREEN_H-65<=YB+DY+TYB && DY!=0){
                    if(YB == SCREEN_H-65){
                        YB = YBsave;
                        DY = -DY;
                    }
                    else
                        YBsave=YB, YB = SCREEN_H-65, BALLtime++;
                }
                }
                if(!SCORE_M && !SCORE_G) BALLcount();/*BALL TIME*/
                else BALLinit();/*SCORE*/

                al_draw_bitmap(BALL, XB-21, YB-21, 0);
                al_draw_filled_rectangle(50, 50, 300, 160, al_map_rgb(0, 0, 0));
                al_draw_bitmap(COLUMN, SCREEN_W/2-10, SCREEN_H-135, 0);/*COLUMN*/
                al_draw_textf(title4, al_map_rgb(255,255,255),150, 80, ALLEGRO_ALIGN_CENTER, "MOOMIN  %d %d %c%c"
                              , SAVE_SCORE[0][1], SAVE_SCORE[1][1], (char)((1-SCORE[1]/9)*(SCORE[1]/2 + SCORE[1] + '0')+ SCORE[1]/9*'A')
                              , (char)((1-SCORE[1]/9)*((SCORE[1]%2)*5 - SCORE[1]/3*5 + '0') + SCORE[1]/9*'d'));
                al_draw_textf(title4, al_map_rgb(255,255,255),150, 110, ALLEGRO_ALIGN_CENTER, "SNORK   %d %d %c%c"
                              , SAVE_SCORE[0][0], SAVE_SCORE[1][0], (char)((1-SCORE[0]/9)*(SCORE[0]/2 + SCORE[0] + '0')+ SCORE[0]/9*'A')
                              , (char)((1-SCORE[0]/9)*((SCORE[0]%2)*5 - SCORE[0]/3*5 + '0') + SCORE[0]/9*'d'));
                if (M_WIN) WIN(MOOMIN_WIN);
                else if (G_WIN) WIN(GF_WIN);
                al_flip_display();
            }
        }
        else if(state==3){
            if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
                if (event.mouse.x<rx+50 && event.mouse.x>rx-50){
                    if(event.mouse.y > 100 && event.mouse.y < 130){
                        if(ry != 100 )
                            al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                        ry = 100;
                    }
                    else if(event.mouse.y > 130 && event.mouse.y < 150){
                        if(ry != 130 )
                            al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
                        ry = 130;
                    }
                }
            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && event.mouse.x > rx-50 && event.mouse.x<rx+50){
                if ( event.mouse.y > 100 && event.mouse.y < 130) write();
                else if(event.mouse.y > 130 && event.mouse.y < 150) init_title();
            }
            if (event.type == ALLEGRO_EVENT_KEY_DOWN){ /*If you push up&down*/
                switch(event.keyboard.keycode){
                    case ALLEGRO_KEY_UP:
                        if ( ry == 100) al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL), ry = 130;
                        else al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL), ry = 100;
                        break;
                    case ALLEGRO_KEY_DOWN:
                        if ( ry== 100) al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL), ry = 130;
                        else al_play_sample(move_song, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL), ry = 100;
                        break;
                    case ALLEGRO_KEY_ENTER:/*If you push enter*/
                        if ( ry == 100) write();
                        else if( ry == 130 ) init_title();
                        break;
                }
            }

            if (redraw && al_is_event_queue_empty(event_queue)) { /*show the title*/
                redraw = false;
                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_text(title3, al_map_rgb(255,255, 255), SCREEN_W/2, 20, ALLEGRO_ALIGN_CENTER, "RECORD");
                al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2, 100, ALLEGRO_ALIGN_CENTER, "Clear");
                al_draw_text(title, al_map_rgb(255,255,255), SCREEN_W/2, 130, ALLEGRO_ALIGN_CENTER, "Back");
                al_draw_textf(title3, al_map_rgb(255,255, 255), SCREEN_W/2, SCREEN_H/6+70, ALLEGRO_ALIGN_CENTER, "%c : %c", s[0], s[1]);
                al_draw_textf(title3, al_map_rgb(255,255, 255), SCREEN_W/2, SCREEN_H*3/6, ALLEGRO_ALIGN_CENTER, "%c : %c", s[2], s[3]);
                al_draw_textf(title3, al_map_rgb(255,255, 255), SCREEN_W/2, SCREEN_H*5/6-70, ALLEGRO_ALIGN_CENTER, "%c : %c", s[4], s[5]);
                al_draw_textf(title3, al_map_rgb(255,255, 255), SCREEN_W/2, SCREEN_H-180, ALLEGRO_ALIGN_CENTER, "%d                     %d", all[0], all[1]);
                al_draw_rectangle(rx-50, ry, rx+50, ry+20, al_map_rgb(255, 255, 255), 3);
                al_draw_bitmap(GF_WIN2, 50, SCREEN_H/2-92.5, 0);
                al_draw_bitmap(MOOMIN_WIN2, SCREEN_W-290, SCREEN_H/2-92.5, 0);

                al_flip_display();
            }
        }
    }
}

int main(int argc, char* argv[]) {

    game_init();
    game_run();
    game_destroy();

    return 0;
}
