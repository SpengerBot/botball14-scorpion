void drive(int dist, int speed) {  //dist in mm, speed in mm/s   invertiert fuer create roboter
	create_write_byte(152);        // specifies start of script definition
	create_write_byte(13);         // specifies number of bytes to follow,(defining the script)
	create_write_byte(137);        // drive command (speed and turn radius in next 4 bytes)
	create_write_byte(speed >> 8); // send speed high byte (bits 8-15 shifted to 0-7)
	create_write_byte(speed);      // send speed low byte
	create_write_byte(128);        // send hex 80
	create_write_byte(0);          // send hex 00 (special case: turn radius hex 8000 or 7FFF is straight)
	create_write_byte(156);        // wait for distance done (in mm)
	create_write_byte(dist >> 8);  // send dist high byte
	create_write_byte(dist);       // send dist low byte
	create_write_byte(137);        // stop move by changing speed and radius to 0
	create_write_byte(0);          // send high byte (0 speed)
	create_write_byte(0);          // send low byte (0 speed)
	create_write_byte(0);          // null turn radius
	create_write_byte(0);          // null turn radius // end of script (13 bytes)
	create_write_byte(153);        //start script
}

void drive_wait(int dist, int speed) {  //dist in mm, speed in mm/s   invertiert fuer create roboter
	drive(dist, speed);
	msleep(dist/speed*1000);
}

void rotate(int speed, int angle) {  //angle: positiv --> rechts     negativ --> links
	int rad = 0xFFFF;
	angle = angle * -1;
	if(angle>0) {
		rad = 0x0001;
	}
	create_write_byte(152);        // specifies start of script definition
	create_write_byte(13);         // specifies number of bytes to follow,(defining the script)
	create_write_byte(137);        // drive command (speed and turn radius in next 4 bytes)
	create_write_byte(speed >> 8); // send speed high byte (bits 8-15 shifted to 0-7)
	create_write_byte(speed);      // send speed low byte
	create_write_byte(rad >> 8);   // send radius high byte (bits 8-15 shifted to 0-7)
	create_write_byte(rad);        // send radius low byte
	create_write_byte(157);        // wait for distance done (in mm)
	create_write_byte(angle >> 8); // send dist high byte
	create_write_byte(angle);      // send dist low byte
	create_write_byte(137);        // stop move by changing speed and radius to 0
	create_write_byte(0);          // send high byte (0 speed)
	create_write_byte(0);          // send low byte (0 speed)
	create_write_byte(0);          // null turn radius
	create_write_byte(0);          // null turn radius // end of script (13 bytes)
	create_write_byte(153);        //start script
}

void rotate_wait(int speed, int angle) {
	rotate(speed, angle);
	msleep(2268.9280275*angle/speed); //d*pi*angle/360		(d=260mm durchmesser rad zu rad) (260*pi/360=2,2689280275926284500007979990352 *1000=2268,9280275926284500007979990352 (genauigkeit 11 Stellen))
}
