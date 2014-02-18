
void turn_right();
void turn_left();
#define cubeClaw 0
#define botguyClaw 1
#define leftHook 2
#define rightHook 3
#define hookDown 750
#define hookUp 1450
#define motor 1 
#define speed 500


void main(){
	enable_servos();
	set_servo_position(leftHook, hookDown);
	set_servo_position(rightHook, hookDown);
	create_connect();
	create_full();
	turn_left();
	set_create_distance(0);
	create_drive_straight(speed);
	while(get_create_distance()<100){
	}
	printf("done");
	
}

void turn_right() {
set_create_normalized_angle(0);
	create_spin_CW(100);
	while(get_create_distance()<90){
	}		
}

void turn_left() {
set_create_normalized_angle(0);
	create_spin_CCW(100);
	while(get_create_distance()<90){
	}		
}
