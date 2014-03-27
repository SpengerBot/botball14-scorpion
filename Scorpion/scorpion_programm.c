void botguy_up();
void botguy_down();
void tail_load();
void tail_drive();
void tail_down();
void tail_botguy();
void tail_up();

//servos
#define tailServoLeft 1 		//moving up = higher values
#define tailServoRight 0		//moving up = lower values
#define tailServoSlow 20
#define tailServoFast 40
#define botguyClaw 2
#define botguyClawOpen 660
#define botguyClawClosed 1450
//tail positions
#define tailServoLeftUp 2000	//highest position
#define tailServoRightUp 0
#define tailServoLeftDown 200	//down position for starting
#define tailServoRightDown 1800
#define tailServoLeftDownMid 1200	//mid position for moving down
#define tailServoRightDownMid 800
#define tailServoLeftBotguy 1000	//position to not loose while getting botguy
#define tailServoRightBotguy 1000	//>DRIVE
#define tailServoLeftLoad 1000		//load position for setup
#define tailServoRightLoad 1000
#define tailServoLeftDrive 700		//position for save driving
#define tailServoRightDrive 1300

//motors
#define botguyMotor 0
#define speed 500
#define rotate_speed 250
#define tailMotor 1
#define tailMotorUpSpeed 40
#define tailMotorDownSpeed -1
#define tailMotorLoadSpeed 55

//sensors
#define botguyClawIsUp 14
#define tailUpSensor 8
#define tailDownSensor 10

void main() {
	set_a_button_text("");
	set_b_button_text("");
	set_c_button_text("");
	set_servo_position(botguyClaw,botguyClawClosed);
	enable_servos();
	printf("Waiting for Create\n");
	create_connect();
	create_full();
	printf("CREATE Connected :)\n");
	tail_load();
	botguy_up();
	create_spin_angle_wait(rotate_speed,-90);
	printf("Waiting for the Hangers\n");
	set_c_button_text("GO!");
	while(!c_button()){}
	botguy_down();
	tail_down();
	set_a_button_text("");
	set_b_button_text("");
	set_c_button_text("");
	printf("wait_for_light();\n");//wait_for_light();
	set_a_button_text("I'm the light!");
	while(!a_button()){}
	printf("Light is on!!!\n");
	msleep(2000);
	tail_drive();
	botguy_up();
	create_spin_angle_wait(rotate_speed,80);
	create_drive_distance_wait(-speed/3,-20);
	create_drive_distance_wait(speed, 540);
	create_spin_angle_wait(rotate_speed,85);
	create_drive_distance_wait(-speed, -200);
	msleep(200);
	botguy_down();
	create_drive_distance_wait(-speed, -100);
	printf("I have got the cube!\n");
	create_spin_angle_wait(rotate_speed,40);
	tail_botguy();
	create_drive_distance_wait(speed,100);
	create_spin_angle_wait(rotate_speed,20);
	printf("Get Botguy\n");
	set_servo_position(botguyClaw,botguyClawOpen);
	create_drive_distance_wait(-speed, -105);
	msleep(400);
	set_servo_position(botguyClaw,botguyClawClosed);
	printf("I have got the BotGuy!\n"); 
	create_drive_distance_wait(speed,117);
	create_spin_angle_wait(rotate_speed,-90);
	create_drive_distance_wait(-speed,-170);
	create_spin_angle_wait(rotate_speed,-75);
	create_drive_distance_wait(speed,250);
	tail_up();
	printf("Hooks are up\nBring Botguy!\n");
	create_spin_angle_wait(rotate_speed, 47);
	create_drive_distance_wait(-speed,-350);
		msleep(1000);
	botguy_up();
		msleep(1000);
	create_drive_distance_wait(-speed,-150);
		msleep(1000);
	create_drive_distance_wait(speed,70);
		msleep(3000);
	
	set_servo_position(botguyClaw,botguyClawOpen);
		msleep(1000);
	
	create_drive_distance_wait(speed,100);
	
	
	set_servo_position(botguyClaw,botguyClawClosed);//loeschen
	
	
	printf("done\n");
	create_disconnect();
}

void botguy_up() {
	motor(botguyMotor,100);
	while(!digital(botguyClawIsUp)){}
	freeze(botguyMotor);
}


void botguy_down() {
	motor(botguyMotor,-40);
	msleep(720);
	motor(botguyMotor,0);
}

void tail_load() {
	motor(tailMotor, tailMotorLoadSpeed+5);
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
	motor(tailMotor, 100);
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
