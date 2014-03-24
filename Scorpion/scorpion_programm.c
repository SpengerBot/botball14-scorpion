void botguy_up();
void botguy_down();

//servos
#define botguyClaw 2
#define botguyClawOpen 660
#define botguyClawClosed 1500

//motors
#define botguyMotor 0
#define speed 500
#define rotate_speed 250

//sensors
#define botguyClawIsUp 14

void main() {
	set_servo_position(botguyClaw,botguyClawClosed);
	enable_servos();
	create_connect();
	create_full();
	printf("CREATE Connected :)\n");
	botguy_up();
	create_spin_angle_wait(rotate_speed,-90);
	printf("wait_for_light();\n");//wait_for_light();
	msleep(2000);
	printf("start\n");
	create_spin_angle_wait(rotate_speed,80);
	printf("jetzt nach hinten\n");
	create_drive_distance_wait(-speed/2,-20);
	printf("jetzt nach vorne\n");
	create_drive_distance_wait(speed, 540);
	printf("jetzt nach links\n");
	create_spin_angle_wait(rotate_speed,85);
	create_drive_distance_wait(-speed, -200);
	msleep(200);
	botguy_down();
	create_drive_distance_wait(-speed, -100);
	printf("I have got the cube!\n");
	create_spin_angle_wait(rotate_speed,45);
	create_drive_distance_wait(speed,100);
	create_spin_angle_wait(rotate_speed,15);
	printf("Botguy holen\n");
	set_servo_position(botguyClaw,botguyClawOpen);
	
	
	create_drive_distance_wait(-speed, -100);
	msleep(400);
	set_servo_position(botguyClaw,botguyClawClosed+0);
	printf("I have got the BotGuy!\n"); 
	msleep(700);
	create_drive_distance_wait(speed, 200);
	create_spin_angle_wait(rotate_speed,185);
	create_drive_distance_wait(speed, 70);
	printf("done");
	msleep(1000);
	create_disconnect();
	
}

void botguy_up() {
	motor(botguyMotor,100);
	while(!digital(botguyClawIsUp)){}
	motor(botguyMotor,0);
}

void botguy_down() {
	motor(botguyMotor,-40);
	msleep(700);
	motor(botguyMotor,10);
}