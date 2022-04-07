#include <kipr/wombat.h>
void move(int a, int b, int c);
void servo(int d, int e, int f);
void tl(int x, int y, int z);
void tr(int r, int t, int l);
int lth = 2000; //lth is line threshold
int main()
{
    create_connect();
    enable_servos();
    create_safe();
    shut_down_in(118);
    //wait_for_light(0);
    //msleep(5000);
    servo(2, 510, 350);
    servo(1, 1380, 500);
    move(200, 200, 2050);
    tr(-26, 200, -200);
    move(200, 200, 550);
    tr(-86, 200, -200);
    set_create_distance(0);

    while (get_create_distance() < 700)
    {
        if ( (get_create_lfcliff_amt() >= lth) && (get_create_rfcliff_amt() < lth) )
        {
            create_drive_direct(200, 200);
            printf("Found Line");
        }
        else
        {
            printf("I lost the line");
            create_drive_direct(90, 50);
        }
    }
    move(250, 250, 1000);
    tl(91, -200, 200);

    set_create_distance(0);
    while (get_create_distance() < 315)
    {
        if ( (get_create_lfcliff_amt() >= lth) && (get_create_rfcliff_amt() < lth) )
        {    
            create_drive_direct(115, 115);
        }
        else
        {
            create_drive_direct(50, 90);
        }
    }

    move(0, 0, 2000);
    servo(1, 1950, 500);
    move(-300, -300, 2500);
    create_full();

    tr(-96, 200, -200);
    //move(100, -200, 1200);
    create_safe();
    move(200, 190, 3000);
    servo(2, 1100, 300);
    servo(1, 1099, 300);
    disable_servos();
    create_disconnect();
    return 0;
}
void move(int a, int b, int c)
{
    create_drive_direct(a, b);
    msleep(c);
}
void tl(int x, int y, int z){
    set_create_total_angle(0);
    while(get_create_total_angle()<x)
    {
        create_drive_direct(y,z);
    }
}
void tr(int r, int t, int l){
    set_create_total_angle(0);
    while(get_create_total_angle()>r)
    {
        create_drive_direct(t,l);
    }
}
void servo(int d, int e, int f){
    set_servo_position(d, e);
    msleep(f);
}