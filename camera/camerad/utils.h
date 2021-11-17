#include <sys/ioctl.h>
#include <sys/cdefs.h>
#include <errno.h>
#include <iostream>
#include <thread>

// __BEGIN_DECLS
// extern int * __error(void);
// #define errno (*__error())
// __END_DECLS

// keep trying if x gets interrupted by a signal
#define HANDLE_EINTR(x)                                       \
  ({                                                          \
    decltype(x) ret;                                          \
    int try_cnt = 0;                                          \
    do {                                                      \
      ret = (x);                                              \
    } while (ret == -1 && errno == EINTR && try_cnt++ < 100); \
    ret;                                                      \
  })

static int cam_ioctl(int fd, unsigned long int request, void *arg, const char *log_msg = nullptr) {
  int err = HANDLE_EINTR(ioctl(fd, request, arg));
  if (err != 0 && log_msg) {
    std::cout << log_msg << " : " << err << std::endl;
    if (errno == EBADF)
    {
      std::cout << "bad file descriptor" << std::endl;
    }
    else if (errno == EFAULT)
    {
      std::cout << "inaccessible memory" << std::endl;
    }
    else if (errno == EINVAL)
    {
      std::cout << "request or argp is not valid" << std::endl;
    }
    else if (errno == ENOTTY)
    {
      std::cout << "fd is not associated with a character special device" << std::endl;
    }
  }
  return err;
}

void sleep_for(const int milliseconds)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}