void botguy_up();
void botguy_down();

//servos
#define cubeClaw 0
#define botguyClaw 2
#define cubeClawOpen 1000
#define cubeClawClosed 1900
#define botguyClawOpen 660
#define botguyClawClosed 1500
//hooks
#define leftHook 3
#define rightHook 1
#define hookDown 750
#define hookUp_old 1450
#define hookUp 1650

//motoren
#define botguyMotor 0
#define speed 500
#define rotate_speed 250

//sensors
#define BotguyClawIsUp 14

void main() {
	//set_servo_position(leftHook, hookDown);
	//set_servo_position(rightHook, hookDown);
	set_servo_position(cubeClaw,cubeClawClosed);
	set_servo_position(botguyClaw,botguyClawClosed);
	enable_servos();
	create_connect();
	create_full();
	printf("CREATE Connected :)\n");
	botguy_up();
	rotate_wait(rotate_speed,-90);
	printf("wait_for_light();\n");//wait_for_light();
	msleep(2000);
	printf("start\n");
	rotate_wait(rotate_speed,80);
	printf("jetzt nach hinten\n");
	drive_wait(-speed/2,-20);
	printf("jetzt nach vorne\n");
	drive_wait(speed, 540);
	printf("jetzt nach links\n");
	rotate_wait(rotate_speed,85);
	set_servo_position(cubeClaw,cubeClawOpen);
	drive_wait(-speed, -200);
	msleep(200);
	set_servo_position(cubeClaw,cubeClawClosed);
	printf("I have got the cube!\n");
	drive_wait(-speed, -100);
	printf("nach rechts\n");
	rotate_wait(rotate_speed,80);
	printf("Botguy holen\n");
	drive_wait(speed, 100);
	set_servo_position(botguyClaw,botguyClawOpen);
	botguy_down();
	drive_wait(-speed, -110);
	msleep(400);
	set_servo_position(botguyClaw,botguyClawClosed+0);
	printf("I have got the BUTTGAY!\n"); 
	msleep(700);
	botguy_up();
	rotate_wait(rotate_speed,185);
	drive_wait(speed, 70);
	printf("done");
	msleep(1000);
	create_disconnect();
	
}

void botguy_up() {
	motor(botguyMotor,100);
	while(!digital(BotguyClawIsUp)){}
	motor(botguyMotor,0);
}

void botguy_down() {
	motor(botguyMotor,-40);
	msleep(700);
	motor(botguyMotor,10);
}
