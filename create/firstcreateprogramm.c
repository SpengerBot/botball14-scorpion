//servos
#define cubeClaw 0
#define botguyClaw 1
#define leftHook 2
#define rightHook 3
#define claw_closed 1860
#define claw_opend 1111
#define hookDown 750
#define hookUp 1450
#define botguyClawUp 2000
#define botguyClawDown 950

//motoren
#define motor 1 
#define speed 500
#define rotate_speed 250

//
#define line_sensor_left 0
#define line_sensor_right 1

void main() {
	set_servo_position(leftHook, hookDown);
	set_servo_position(rightHook, hookDown);
	set_servo_position(cubeClaw,claw_closed);
	set_servo_position(botguyClaw,botguyClawUp);
	enable_servos();
	create_connect();
	create_full();
	printf("Initial Setup");
	rotate_wait(rotate_speed,-90);
	printf("wait_for_light();");//wait_for_light();
	msleep(2000);
	printf("start");
	rotate_wait(rotate_speed,90);
	printf("\njetzt nach hinten");
	drive_wait(-20,-50);
	printf("jetzt nach vorne");
	drive_wait(speed, 540);
	printf("jetzt nach links");
	rotate_wait(rotate_speed,85);
	set_servo_position(cubeClaw,claw_opend);
	drive_wait(-speed, -200);
	set_servo_position(cubeClaw,claw_closed);
	printf("I have got the cube!\n");
	drive_wait(-speed, -100);
	rotate_wait(rotate_speed,85);
	drive_wait(speed, 100);
	set_servo_position(botguyClaw,botguyClawDown);
	drive_wait(-speed, -70);
	drive_wait(-20,-120);
	msleep(400);
    set_servo_position(botguyClaw,botguyClawUp);
	//drive_wait(speed, 100);
	//rotate_wait(rotate_speed,180);
	printf("done");
	create_disconnect();
}
