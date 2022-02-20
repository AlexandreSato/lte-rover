import serial
import curses
import time

throttle_index = "t";
steering_index = "s";
escape_char = "#";

# throttle
throttle = 90;
neutral = 90;
max_forward = 180;
max_backward = 0;

# steering
steering = 90;
center = 90;
max_left = 60;
max_right = 120;

def format_msg(prefix, value):
  str_msg = "{}{:05d}{}".format(prefix, value, escape_char)
  print(str_msg)
  return bytes(str_msg, 'UTF-8')

if __name__ == "__main__":
  stdscr = curses.initscr()
  ser = serial.Serial("/dev/cu.usbserial-1120", 115200);
  print("connected to serial port")
  while True:
    key = stdscr.getch()
    if key == ord('w'):
      throttle += 1
      print(throttle)
    if key == ord('s'):
      throttle -= 1
      print(throttle)
    if key == ord('d'):
      steering += 1
      print(steering)
    if key == ord('a'):
      steering -= 1
      print(steering)
    steering_msg = format_msg(steering_index, steering)
    throttle_msg = format_msg(throttle_index, throttle)
    
    time.sleep(0.01)
    ser.write(steering_msg)
    time.sleep(0.01)
    ser.write(throttle_msg)
    
