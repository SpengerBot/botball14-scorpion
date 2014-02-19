//servos
#define cubeClaw 0
#define botguyClaw 1
#define leftHook 2
#define rightHook 3
#define claw_closed 1860
#define claw_opend 1111
#define hookDown 750
#define hookUp 1450

//motoren
#define motor 1 
#define speed 500
#define rotate_speed 250

//
#define line_sensor_left 0
#define line_sensor_right 1

void main() {
	enable_servos();
	set_servo_position(leftHook, hookDown);
	set_servo_position(rightHook, hookDown);
	set_servo_position(cubeClaw,claw_closed);
	create_connect();
	create_full();
	printf("start");
	rotate_wait(rotate_speed,90);
	printf("\njetzt nach hinten");
	drive_wait(-100,-20);
	printf("jetzt nach vorne");
	drive_wait(speed, 500);
	printf("jetzt nach links");
	rotate_wait(rotate_speed,65);
	set_servo_position(cubeClaw,claw_opend);
	drive_wait(-speed, -200);
	set_servo_position(cubeClaw,claw_closed);
	printf("done");
	create_disconnect();
}
