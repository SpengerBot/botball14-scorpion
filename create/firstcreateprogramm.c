
void closeClaw();
void openClaw();
//servos
#define cubeClaw 0
#define botguyClawLifter 0
#define botguyClaw 2
#define botguyClawOpen 660
#define botguyClawClosed 1500
#define botguyClawLifterUp 1380
#define botguyClawLifterDown 170
//hooks
#define leftHook 3
#define rightHook 1
#define hookDown 750
#define hookUp_old 1450
#define hookUp 1650

//motoren
#define motor1 1 
#define speed 500
#define rotate_speed 250

//
#define line_sensor_left 0
#define line_sensor_right 1

void main() {
	set_servo_position(leftHook, hookDown);
	set_servo_position(rightHook, hookDown);
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
	rotate_wait(rotate_speed,80);
	printf("\njetzt nach hinten");
	drive_wait(-speed/2,-20);
	printf("jetzt nach vorne");
	drive_wait(speed, 540);
	printf("jetzt nach links");
	rotate_wait(rotate_speed,85);
	openClaw();
	drive_wait(-speed, -200);
	msleep(200);
	closeClaw();
	printf("I have got the cube!\n");
	drive_wait(-speed, -100);
	printf("nach rechts\n");
	rotate_wait(rotate_speed,80);
	printf("Botguy holen\n");
	drive_wait(speed, 100);
	set_servo_position(botguyClawLifter,botguyClawLifterDown);
	set_servo_position(botguyClaw,botguyClawOpen);
	drive_wait(-speed, -110);
	msleep(400);
	set_servo_position(botguyClaw,botguyClawClosed+0);
	printf("I have got the BUTTGAY!\n"); 
	msleep(700);
    set_servo_position(botguyClawLifter,botguyClawLifterUp);
	rotate_wait(rotate_speed,185);
		drive_wait(speed, 70);
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
