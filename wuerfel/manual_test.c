//servos
#define clawRight 1
#define clawLeft 0
#define clawRightOpen 1300
#define clawLeftOpen 2000
#define clawRightClose 2000
#define clawLeftClose 1300

//motors
#define leftMotor 
#define rightMotor 
#define upMotor 0
#define upMotorSpeed 20

//sensors
#define downSensor 
int left_claw_state;
int right_claw_state;

void main() {
	
	extra_buttons_show();
	
	left_claw_close();
	right_claw_close();
	down();
	enable_servos();
	
	while(!side_button()) {
		
		if(a_button()) {
			if(digital(downSensor)) up();
			else down();
		} else if(x_button()) {
			if(left_claw_state) left_claw_open();
			else left_claw_close();
			msleep(500);
		} else if(z_button()) {
			if(right_claw_state) right_claw_open();
			else right_claw_close();
			msleep(500);
		}
	}
	stop();
}

void left_claw_open() {
	set_x_button_text("Close Left");
	set_servo_position(clawLeft, clawLeftOpen);
	left_claw_state = 0;
}

void left_claw_close() {
	set_x_button_text("Open Left");
	set_servo_position(clawLeft, clawLeftClose);
	left_claw_state = 1;
}

void right_claw_open() {
	set_z_button_text("Close Right");
	set_servo_position(clawRight, clawRightOpen);
	right_claw_state = 0;
}

void right_claw_close() {
	set_z_button_text("Open Right");
	set_servo_position(clawRight, clawRightClose);
	right_claw_state = 1;
}


void up() {
	set_a_button_text("Down");
	move_to_position(upMotor, upMotorSpeed, upMotorPosition);
	freeze(upMotor);
}

void down() {
	set_a_button_text("Up");
	
	motor(upMotor, -upMotorSpeed);
	while(!digital(downSensor)) {}
	freeze(upMotor);
	clear_motor_position_counter(upMotor);
}
