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
#define botguyClawOpen 1050
#define botguyClawClosed 300

//tail positions
#define tailServoLeftUp 2000	//highest position
#define tailServoRightUp 0
#define tailServoLeftDown 200	//down position for starting
#define tailServoRightDown 1800
#define tailServoLeftDownMid 1200	//mid position for moving down
#define tailServoRightDownMid 800
#define tailServoLeftBotguy 900		//position to not loose while getting botguy
#define tailServoRightBotguy 1100	//>DRIVE
#define tailServoLeftLoad 800		//load position for setup
#define tailServoRightLoad 1200
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

int botguyclaw = 0;

void main() {
	//create_connect();
	//create_full();
	set_c_button_text("Tail Load");
	set_a_button_text("Tail Down");
	set_b_button_text("Tail Up");
	set_x_button_text("Tail BotGuy");
	set_y_button_text("Botguy Down");
	set_z_button_text("Botguy Claw Open");
	extra_buttons_show();
	set_servo_position(botguyClaw,botguyClawClosed);
	enable_servos();
	botguy_up();
	while(!side_button()) {
		if(a_button()) {
			tail_down();
			msleep(500);
		} else if(b_button()) {
			tail_up();
			msleep(500);
		} else if(c_button()) {
			tail_load();
			msleep(500);
		} else if(x_button()) {
			tail_botguy();
			msleep(500);
		} else if(y_button()) {
			if(botguyClawIsUp) {
				botguy_down();
				set_y_button_text("Botguy Up");
			} else {
				botguy_up();
				set_y_button_text("Botguy Down");
			}
			msleep(500);
		} else if(z_button()) {
			if(botguyclaw) {
				set_servo_position(botguyClaw,botguyClawClosed);
				set_z_button_text("Botguy Claw Open");
				botguyclaw = 0;
			} else {
				set_servo_position(botguyClaw,botguyClawOpen);
				set_z_button_text("Botguy Claw Close");
				botguyclaw = 1;
			}
			msleep(500);
		}
	}
}

void botguy_up() {
	motor(botguyMotor,100);
	while(!digital(botguyClawIsUp)){}
	freeze(botguyMotor);
}

void botguy_down() {
	motor(botguyMotor,-40);
	msleep(720);
	freeze(botguyMotor);
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
	create_drive_distance_wait(-100,-250);
}

void tail_botguy(){
	motor(tailMotor, tailMotorUpSpeed);
	msleep(500);
	set_servo_position(tailServoLeft, tailServoLeftBotguy);
	set_servo_position(tailServoRight, tailServoRightBotguy);
	msleep(600);
	freeze(tailMotor);
}
