#include <kipr/wombat.h>

void move(int a, int b, int c);
int lf_port_left = 0; //left tophat sensor
int lf_port_right = 1; //right (middle)
int lth = 1500; //lth is line threshold
int distance = 12700; //in ticks 13100
int main()

{
    enable_servos();
    set_servo_position(2, 1304);//start of preparing the robot code
    msleep(750);
    set_servo_position(3, 1325);
    msleep(750);
    set_servo_position(0, 2047);
    msleep(750);
    move(0, 0, 1250);//end of preparing the robot code
    move(94, 100, 540);//575
    set_servo_position(2, 213);
    msleep(750);
    move(94, -100, 825);//885
    move(94, 100, 395);
    move(0, 0, 1250);
    cmpc(0);

    while (gmpc(0) < distance)
    {

        if (analog(0) > analog(5))
        {
            printf("Middle Sensor on BLACK/n");
            motor(0, 95);
            motor(1, 100);

        }

        else
        {

            printf("Turn Left (Middle off BLACK/n)");
            motor(0, 100);
            motor(1, 68);
            //msleep(10);

        }


    }

    move(97, 100, 250);
    set_servo_position(0, 33);
    msleep(750);
    set_servo_position(3, 1294);
    move(0, 0, 2000);
    move(-94, -100, 575);
    set_servo_position(0, 29);
    msleep(1000);
    move(84, -90, 1900);
    move(94, 100, 300);
    move(-94, 100, 150);
    cmpc(0);
    move(0, 0, 1000);
    
    while (gmpc(0) < distance)
    {
        
        if (analog(0) > analog(5))
        {
            
            motor(0, 94);
            motor(1, 100);
            
        }
        
        else
        {
            
            motor(0, 100);
            motor(1, 55);
         
        }
        
    }








    return 0;

}
void move(int a, int b, int c)
{
    motor(1, a);
    motor(0, b);
    msleep(c);
}