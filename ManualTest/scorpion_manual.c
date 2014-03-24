void tail_up();
void tail_load();
void tail_down();
void botguy_up();
void botguy_down();

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
#define botguyClaw 2
#define botguyClawOpen 660
#define botguyClawClosed 1500

//motors
#define tailMotor 1
#define tailMotorUpSpeed 40
#define tailMotorDownSpeed -1
#define tailMotorLoadSpeed 40
#define botguyMotor 0
#define speed 500
#define rotate_speed 250

//sensors
#define botguyClawIsUp 14
#define tailUpSensor 8
#define tailDownSensor 10

void main() {
	enable_servos();
	set_c_button_text("Tail Load");
	tail_load();
	set_a_button_text("Tail Down");
	//botguy_up();
	
	
	while(!side_button()) {
		
		if(a_button()) {
			if(digital(tailDownSensor)) tail_up();
			else tail_down();
			msleep(500);
		} else if(b_button()) {
			if(digital(botguyClawIsUp)) botguy_down();
			else botguy_up();
			msleep(500);
		} else if(c_button()) {
			tail_load();
			msleep(500);
		}
	}
}

void botguy_up() {
	set_b_button_text("Botguy Down");
	motor(botguyMotor,100);
	while(!digital(botguyClawIsUp)){}
	motor(botguyMotor,0);
}

void botguy_down() {
	set_b_button_text("Botguy Up");
	motor(botguyMotor,-40);
	msleep(700);
	motor(botguyMotor,10);
}

void tail_down() {
	set_a_button_text("Tail Up");
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
	set_a_button_text("Tail Down");
	motor(tailMotor, tailMotorUpSpeed);
	msleep(500);
	set_servo_position(tailServoLeft, tailServoLeftUp);
	set_servo_position(tailServoRight, tailServoRightUp);
	while(!digital(tailUpSensor)) {}
	freeze(tailMotor);
}

void tail_load() {
	motor(tailMotor, tailMotorLoadSpeed);
	msleep(500);
	set_servo_position(tailServoLeft, tailServoLeftLoad);
	set_servo_position(tailServoRight, tailServoRightLoad);
	while(!digital(tailUpSensor)) {}
	freeze(tailMotor);
}
