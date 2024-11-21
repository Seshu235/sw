#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>

int main() {
  int fd = open("/tmp/virtualcom0", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1) {
    perror("uart_open");
    return EXIT_FAILURE;
  }

  perror("uart_open");
  struct termios options = {0};
  
  // Baudrate setting
  cfsetispeed(&options, B115200);
  cfsetospeed(&options, B115200);

  // Set Character size
  options.c_cflag &= ~PARENB; //  No parity
  options.c_cflag &= ~CSTOPB; //  1 stop bit
  options.c_cflag &= ~CSIZE;  //  Clear current char size
  options.c_cflag |= CS8;     //  8 data bits

  options.c_cflag |= (CLOCAL | CREAD);  //  Ignore modem control lines and enable receiver

  // Apply the settings
  tcsetattr(fd, TCSANOW, &options);

  char tx_buffer[64] = {0};
  char rx_buffer[64] = {0};
  ssize_t tx_len = -1;
  ssize_t rx_len = -1;

  while (1)
  {
    rx_len = read(fd, rx_buffer, 64);
    if (rx_len > 0) {
      printf("Received: %s\n", rx_buffer);
      memset(rx_buffer, 0, rx_len);
      printf("Enter message\n");
      fgets(tx_buffer, 64, stdin);
      tx_buffer[strcspn(tx_buffer, "\n")] = '\0';
      tx_len = strlen(tx_buffer);
      write(fd, tx_buffer, tx_len);
      memset(tx_buffer, 0, tx_len);
    }
  }
  
}