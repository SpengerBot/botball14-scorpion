//servos
#define cubeClaw 0
#define botguyClaw 1
#define leftHook 2
#define rightHook 3
#define claw_closed 1860
#define claw_opend 1111
#define botguyClawUP 2000
#define botguyClawDown 1000
#define hookDown 750
#define hookUp 1450

//motoren
#define motor 1 
#define speed 500
#define rotate_speed 250

void main() {
	enable_servos();
	set_servo_position(leftHook, hookDown);
	set_servo_position(rightHook, hookDown);
	set_servo_position(cubeClaw,claw_closed);
	create_connect();
	create_full();
	//würfel holen
	printf("start");
	rotate_wait(rotate_speed,65);
	printf("\n jetzt nach hinten");
	drive_wait(-100,-20);
	printf("jetzt nach vorne");
	drive_wait(speed, 500);
	printf("jetzt nach links");
	rotate_wait(rotate_speed,65);
	set_servo_position(cubeClaw,claw_opend);
	drive_wait(-speed, -250);
	set_servo_position(cubeClaw,claw_closed);
	printf("done");
	
	//botguy holen
	rotate_wait(rotate_speed,65);
	printf("\n jetzt nach hinten");
	set_servo_position(botguyClaw,botguyClawDown);
	drive_wait(-100,-20);
	set_servo_position(botguyClaw,botguyClawDown);
	rotate_wait(rotate_speed,-180);
	//harken aufhängen
}
