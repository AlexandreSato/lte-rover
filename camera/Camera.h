#include <string>
#include <fstream>

#include <linux/ioctl.h>
#include <linux/videodev2.h>

namespace params
{
  char CSID_SUBSYSTEM[] = "/dev/v4l-subdev3";
  char CSIPHY_SUBSYSTEM[] = "/dev/v4l-subdev0";
  char SENSOR_SUBSYSTEM[] = "/dev/v4l-subdev13";
  char ACTUATOR_SUBSYSTEM[] = "/dev/v4l-subdev7";
}

class Camera
{
  private:
    int csi_fd;
    int csiphy_fd;
    int sensor_fd;
    int actuator_fd;

    int BringUp();
    int Shutdown();

  public:
    int Init();
};
