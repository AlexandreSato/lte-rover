#include <string>
#include <fstream>

#include <linux/ioctl.h>
#include <linux/videodev2.h>

namespace params
{
  char CSID_SUBSYSTEM[] = "/dev/v4l-subdev3";
  char CSIPHY_SUBSYSTEM[] = "/dev/v4l-subdev0";
  char ISP_SUBSYSTEM[] = "/dev/v4l-subdev13";
  char ACTUATOR_SUBSYSTEM[] = "/dev/v4l-subdev7";
  char SENSOR_SUBSYSTEM[] = "/dev/v4l-subdev17";
  char MSM_SUBSYSTEM[] = "/dev/media0";
  char V4l_SUBSYSTEM[] = "/dev/video0";
  char ISPIF_SUBSYSTEM[] = "/dev/v4l-subdev15";
}

class Camera
{
  private:
    int csid_fd;
    int csiphy_fd;
    int isp_fd;
    int sensor_fd;
    int actuator_fd;

    int msm_fd;
    int v4l_fd;
    int ispif_fd;

    int BringUp();
    int Shutdown();

  public:
    void camera_init();
    void camera_open();
    void camera_run();
    void camera_start();
};
