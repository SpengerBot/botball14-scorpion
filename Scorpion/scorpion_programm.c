void botguy_up();
void botguy_down();
void tail_load();
void botguy_slow_up();
void tail_drive();
void tail_down();
void tail_botguy();
//servos
#define tailServoLeft 1
#define tailServoRight 0
#define tailServoLeftUp 2000
#define tailServoRightUp 0
#define tailServoLeftDown 200
#define tailServoRightDown 1800

#define tailServoLeftDownMid 1200
#define tailServoRightDownMid 800

#define tailServoSlow 20
#define tailServoFast 40
#define tailServoLeftLoad 1000
#define tailServoRightLoad 1000
#define tailServoLeftDrive 700
#define tailServoRightDrive 1200
#define botguyClaw 2
#define botguyClawOpen 660
#define botguyClawClosed 1500

//motors
#define botguyMotor 0
#define speed 500
#define rotate_speed 250
#define tailMotor 1
#define tailMotorUpSpeed 40
#define tailMotorDownSpeed -1
#define tailMotorLoadSpeed 50

//sensors
#define botguyClawIsUp 14
#define tailUpSensor 8
#define tailDownSensor 10

void main() {
	set_servo_position(botguyClaw,botguyClawClosed);
	enable_servos();
	create_connect();
	create_full();
	printf("CREATE Connected :)\n");
	tail_load();
	botguy_up();
	create_spin_angle_wait(rotate_speed,-90);
	set_c_button_text("tail Loaded");
	while(!c_button()){}
	botguy_down();
	tail_down();
	printf("wait_for_light();\n");//wait_for_light();
	msleep(2000);
	tail_drive();
	msleep(300);
	botguy_up();
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
	tail_botguy();
	create_drive_distance_wait(speed,100);
	create_spin_angle_wait(rotate_speed,25);
	printf("Botguy holen\n");
	set_servo_position(botguyClaw,botguyClawOpen);
	create_drive_distance_wait(-speed, -100);
	msleep(400);
	set_servo_position(botguyClaw,botguyClawClosed);
	printf("I have got the BotGuy!\n"); 
	msleep(700);
	create_drive_distance_wait(speed, 200);
	create_spin_angle_wait(rotate_speed,65);
	create_drive_distance_wait(speed, 70);
	create_spin_angle_wait(rotate_speed,115);
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
	msleep(750);
	motor(botguyMotor,0);
}

void tail_load() {
	motor(tailMotor, tailMotorLoadSpeed);
	msleep(500);
	set_servo_position(tailServoLeft, tailServoLeftLoad);
	set_servo_position(tailServoRight, tailServoRightLoad);
	while(!digital(tailUpSensor)) {}
	freeze(tailMotor);
}
void tail_drive(){
	set_servo_position(tailServoLeft, tailServoLeftDrive);
	set_servo_position(tailServoRight, tailServoRightDrive);
	msleep(300);
}
void tail_down() {
	motor(tailMotor, tailMotorDownSpeed);
	while(!digital(tailDownSensor)) {}
	freeze(tailMotor);
	int left = get_servo_position(tailServoLeft);
	int right = get_servo_position(tailServoRight);
	while(left>=tailServoLeftDownMid&right<=tailServoRightDownMid) {
		set_servo_position(tailServoLeft, left);
		set_servo_position(tailServoRight, right);
		msleep(50);
		left = left - tailServoFast;
		right = right + tailServoFast;
	}
	while(left>=tailServoLeftDown&right<=tailServoRightDown) {
		set_servo_position(tailServoLeft, left);
		set_servo_position(tailServoRight, right);
		msleep(100);
		left = left - tailServoSlow;
		right = right + tailServoSlow;
	}
}

void tail_up() {
	motor(tailMotor, tailMotorUpSpeed);
	msleep(500);
	set_servo_position(tailServoLeft, tailServoLeftUp);
	set_servo_position(tailServoRight, tailServoRightUp);
	msleep(600);
	freeze(tailMotor);
	create_drive_distance_wait(-100,-250); //drive
}

void tail_botguy(){
	motor(tailMotor, tailMotorUpSpeed);
	msleep(500);
	set_servo_position(tailServoLeft, tailServoLeftBotguy);
	set_servo_position(tailServoRight, tailServoRightBotguy);
	msleep(600);
	freeze(tailMotor);
}
