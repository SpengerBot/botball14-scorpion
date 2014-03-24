void tail_up();
void tail_down();
void botguy_up();
void botguy_down();

//servos
#define tailServoLeft 1
#define tailServoRight 0
#define tailServoLeftUp 
#define tailServoRightUp 
#define tailServoLeftDown 
#define tailServoRightDown 
#define botguyClaw 2
#define botguyClawOpen 660
#define botguyClawClosed 1500

//motors
#define tailMotor 0
#define tailMotorUpSpeed 10
#define botguyMotor 0
#define speed 500
#define rotate_speed 250

//sensors
#define botguyClawIsUp 14
#define tailUpSensor 8
#define tailDownSensor 9

void main() {
	
	left_claw_close();
	right_claw_close();
	down();
	enable_servos();
	
	while(!side_button()) {
		
		if(a_button()) {
			if(digital(tailUpSensor)) tail_down();
			else tail_up();
		} else if(b_button()) {
			if(digital(botguyClawIsUp)) botguy_down();
			else botguy_up();
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
	motor(tailMotor, -tailMotorUpSpeed);
	msleep(500);
	set_servo_position(tailServoLeft, tailServoLeftDown);
	set_servo_position(tailServoRight, tailServoRightDown);
	while(!digital(tailDownSensor)) {}
	freeze(tailMotor);
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
