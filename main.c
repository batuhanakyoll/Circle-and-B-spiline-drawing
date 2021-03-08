#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/alcompat.h>
#include<allegro5/allegro_primitives.h>
#define ScreenWidth 1200
#define ScreenHeight 1200
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
struct koordinat
{
    float x;
    float y;
} koordinatlar[30];

 int fact(int n){
 if(n==0)
    return 1;
else
    return n*fact(n-1);
 }

 int comb(int n,int r)
{
    return (fact(n)/(fact(n-r)*fact(r)));
}


int main()
{
    FILE *degerler = fopen("sayi.txt","r");//dosya acma
    int sayac=0,karakter=1;
    char ch;
    while(feof(degerler)==NULL)
    {
        ch=getc(degerler);
        if(ch=='\n')
        {
            sayac++;
        }
        karakter++;
    }
    printf("%d\n",karakter);
    printf("%d\n",sayac);
    fclose(degerler);
    FILE *f = fopen("sayi.txt","r");//dosya acma


    int a=0;
    if(f!=NULL)//dosya bos mu degil mi
    {
        while(!feof(f))
        {

            fscanf(f,"%f,%f",&koordinatlar[a].x,&koordinatlar[a].y);
            a++;
            if(a==sayac)
                break;
        }
    }
    else
    {
        printf("Dosya bos!");
    }
    for(int i=0; i<sayac; i++)
    {
        printf("%f,%f\n",koordinatlar[i].x,koordinatlar[i].y);
    }
    float minx,miny,maxx,maxy;
    minx=koordinatlar[0].x;
    for(int i=1;i<sayac;i++){
        if(minx>koordinatlar[i].x)
        {
            minx=koordinatlar[i].x;
        }
    }

    miny=koordinatlar[0].y;
    for(int i=1;i<sayac;i++){
        if(miny>koordinatlar[i].y)
        {
            miny=koordinatlar[i].y;
        }
    }

    maxx=koordinatlar[0].x;
    for(int i=1;i<sayac;i++){
        if(maxx<koordinatlar[i].x)
        {
            maxx=koordinatlar[i].x;
        }
    }

    maxy=koordinatlar[0].y;
    for(int i=1;i<sayac;i++){
        if(maxy<koordinatlar[i].y)
        {
            maxy=koordinatlar[i].y;
        }
    }

    if(!al_init())
    {
        al_show_native_message_box(NULL,NULL,NULL,"Allegro couldnt initialize",NULL,NULL);

        return -1;
    }
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    ALLEGRO_DISPLAY *display= al_create_display(ScreenWidth,ScreenHeight);
    al_set_window_position(display,200,100);
    al_set_window_title(display,"CodingMadeEasy");
    if(!display)
    {
        return -1;
    }
    al_init_primitives_addon();
    ALLEGRO_COLOR blue=al_map_rgb(51,73,255);

    al_draw_line(600,0,600,1200,blue,6.0);//y ekseni koordinati

    al_draw_line(0,600,1200,600,blue,6.0);//x ekseni koordinatı
    for(int i=0; i<=1200; i+=20)
    {

        al_draw_line(i,598,i,608,al_map_rgb(0,255,0),1.0);

    }
    for(int i=0; i<=1200; i+=20)
    {

        al_draw_line(608,i,593,i,al_map_rgb(0,255,0),1.0);

    }
    for(int i=0; i<=1200; i+=20)
    {
        al_draw_line(0,i,1200,i,al_map_rgb(128,128,128),1.0);

    }
    for(int i=0; i<=1200; i+=20)
    {

        al_draw_line(i,0,i,1200,al_map_rgb(128,128,128),1.0);

    }

    float r;
int boyut;
boyut=(sayac)*2;
int sayacspx=0;
int sayacspy=0;
float spline_dizi[boyut];
float cizdirspline[4];
    r=(sqrt((pow(maxx-minx,2)+pow(maxy-miny,2))));
    float yaricap;
    yaricap=r/2;
    float merkez_x;
    float merkez_y;

    merkez_x=(minx+maxx)/2;
    merkez_y=(miny+maxy)/2;
    al_draw_circle(600+((merkez_x)*20),(600-(merkez_y)*20),yaricap*20,al_map_rgb(150,75,200),1.0);



al_draw_circle(600+((merkez_x)*20),(600-(merkez_y)*20),1.0,al_map_rgb(255,255,255),8.0);
 al_draw_line(600+((merkez_x)*20),(600-(merkez_y)*20),600+(((merkez_x)*20)+(yaricap*20/sqrt(2))),(600-(((merkez_y)*20)+(yaricap*20/sqrt(2)))),al_map_rgb(255,100,100),2.0);

    for(int i=0; i<sayac; i++)

    {

        if(koordinatlar[i].x>0 && koordinatlar[i].y>0)
        {


            al_draw_circle((600+(koordinatlar[i].x)*20),(600-(koordinatlar[i].y)*20),1.0,al_map_rgb(255,0,0),5.0);


        }
        else if(koordinatlar[i].x<0 && koordinatlar[i].y>0)
        {

            al_draw_circle((600+(koordinatlar[i].x)*20),(600-(koordinatlar[i].y)*20),1.0,al_map_rgb(255,0,0),5.0);

        }
        else if(koordinatlar[i].x<0 && koordinatlar[i].y<0)
        {

            al_draw_circle((600+(koordinatlar[i].x)*20),(600-(koordinatlar[i].y)*20),1.0,al_map_rgb(255,0,0),5.0);

        }
        else if (koordinatlar[i].x>0 && koordinatlar[i].y<0)
        {


            al_draw_circle((600+(koordinatlar[i].x)*20),(600-(koordinatlar[i].y)*20),1.0,al_map_rgb(255,0,0),5.0);


}

    }

    float yt,xt;



for(float t=0.0;t<1;t+=0.0005)
{
xt=0,yt=0;
 for(int i=0;i<sayac;i++)
 {

  xt=xt+(comb(sayac-1,i)*(pow(t,i))*(pow(1-t,sayac-i-1))*(koordinatlar[i].x));
   yt=yt+(comb(sayac-1,i)*(pow(t,i))*(pow(1-t,sayac-i-1))*(koordinatlar[i].y));




 }
  al_draw_pixel((600+(xt)*20),(600-(yt)*20),al_map_rgb(255,0,0));


}

    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();
	al_init();


printf("merkez noktasi : %f, %f ",merkez_x,merkez_y);
 printf(" \n yaricap uzunlugu : %f",yaricap);

	al_draw_textf(al_load_font("arial.ttf",12,1),al_map_rgb(255,255,255),600+((merkez_x)*20)+5,(600-(merkez_y)*20)+15,1,"(%.1f,",merkez_x);
    al_draw_textf(al_load_font("arial.ttf",12,1),al_map_rgb(255,255,255),600+((merkez_x)*20)+45,(600-(merkez_y)*20)+15,1,"%.1f ) ,",merkez_y);
for(int i=0;i<sayac;i++)
{
    al_draw_textf(al_load_font("arial.ttf",12,1),al_map_rgb(255,255,255),(600+(koordinatlar[i].x)*20)+5,(600-(koordinatlar[i].y)*20)+10,1,"(%.1f,",(koordinatlar[i].x));
    al_draw_textf(al_load_font("arial.ttf",12,1),al_map_rgb(255,255,255),(600+(koordinatlar[i].x)*20)+40,(600-(koordinatlar[i].y)*20)+10,1,"%.1f ) ,",(koordinatlar[i].y));

}
	al_flip_display();

    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();


    int ba=30;
    for(int i=0; i<=600; i=i+20)
    {


        al_draw_textf(al_load_font("arial.ttf",12,9),al_map_rgb(255,0,0),i,613,5,"-%d ",(i/20)+ba);
        ba=ba-2;


    }
    int ab=30;
    for(int i=0; i<=600; i=i+20)
    {


        al_draw_textf(al_load_font("arial.ttf",12,9),al_map_rgb(255,0,0),613,i,5,"-%d ",(i/20)+ab);
        ab=ab-2;
    }
    for(int i=600; i<=1200; i+=20)
    {


        al_draw_textf(al_load_font("arial.ttf",12,9),al_map_rgb(255,0,0),613,i,5,"-%i ",(i%600)/20);





    }
    for(int i=600; i<=1200; i+=20)
    {


        al_draw_textf(al_load_font("arial.ttf",12,9),al_map_rgb(255,0,0),i,613,5,"%i ",(i%600)/20);



    }



    al_flip_display();

    system("pause");


    al_flip_display();
    al_rest(5.0);
    al_destroy_display(display);


    return 0;
}
