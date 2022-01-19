#include <iostream>
#include <memory>
#include "mcu.cpp"

Mcu *usb_connect()
{
  std::unique_ptr<Mcu> mcu;
  try
  {
    mcu = std::make_unique<Mcu>();
    std::string serial_port = "/temp";
    mcu->init(serial_port);
  }
  catch (std::exception &e)
  {
    std::cout << "exception in Mcu init" << std::endl;
    return nullptr;
  }
}

int main()
{
  std::cout << "setting up mcu daemon" << std::endl;
  // Mcu *mcu = usb_connect();
  Mcu mcu;
  std::string temp = "yooo";
  mcu.init(temp);

  // create message
  unsigned char msg[20] = "s170#";
  // mcu.usb_bulk_write(1, msg, 5, 5);
  mcu.usb_bulk_write(3, msg, 5, 0);

  return 0;
}

