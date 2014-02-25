
void closeClaw();
void openClaw();
//servos
#define cubeClaw 0
#define botguyClawLifter 0
#define botguyClaw 2
#define botguyClawOpen 500
#define botguyClawClosed 1500
#define leftHook 2
#define rightHook 3
#define hookDown 750
#define hookUp 1450
#define botguyClawLifterUp 2000
#define botguyClawLifterDown 1150

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
	closeClaw();
	set_servo_position(botguyClawLifter,botguyClawLifterUp);
	set_servo_position(botguyClaw,botguyClawClosed);
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
	openClaw();
	drive_wait(-speed, -200);
	closeClaw();
	printf("I have got the cube!\n");
	drive_wait(-speed, -100);
	rotate_wait(rotate_speed,85);
	drive_wait(speed, 100);
	set_servo_position(botguyClawLifter,botguyClawLifterDown);
	set_servo_position(botguyClaw,botguyClawOpen);
	drive_wait(-speed, -130);
	drive_wait(-60,-60);
	msleep(400);
	set_servo_position(botguyClaw,botguyClawClosed);
	msleep(300);
    set_servo_position(botguyClawLifter,botguyClawLifterUp);
	//drive_wait(speed, 100);
	//rotate_wait(rotate_speed,180);
	printf("done");
	msleep(1000);
	create_disconnect();

}
void closeClaw(){
	motor(cubeClaw,10);
	printf("\nzu");
	msleep(300);
	printf("\nwartZu");
	off(cubeClaw);
}
void openClaw(){
	motor(cubeClaw,-80);
	msleep(300);
	motor(cubeClaw,-30);
	printf("\nauf");
	msleep(450);
	printf("\nwartAuf");
	off(cubeClaw);
}
