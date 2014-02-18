#define RUN_SCRIPT create_write_byte(153) // macro to run the currently loaded script
void make_drive_script(int dist, int speed) {
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
   create_write_byte(0);          // null turn radius
   // end of script (13 bytes)
}
