/*
 *              20231110 Version 1.0
 *              
  20231120 CLI_V1.0 Required to make a complete program - this file, CLI_V1.0,Quest_CLI.h, Quest_Flight.h,Quest_flight.cpp
                  cmd_takeSphot , cmd_takeSpiphoto, nophotophoto, nophoto30K --,clean up code for understanding.


*/

#include "Quest_RTClib.h"

#ifndef __QUEST_CLI_H__
#define __QUEST_CLI_H__

extern RTC_pcf85263 rtc;
extern char user_text_buf0[1024];

void flight_setup();
void flight_loop();
void addData(const char* format, ...);

void Flying();

void nophotophoto();
void nophoto30K();

void Chardelay();
void CameraCleanReturn();
void cli_init();
void dateTime(uint16_t* date, uint16_t* time, uint8_t* ms10);
byte decToBcd(byte value);
int execute();
void fill_text();
void getMissionClock();
void Hostinterupt();
void initQueue();
uint8_t Getchar();
void getPicture_callback(uint32_t pictureSize, uint16_t packetSize, uint32_t packetStartPosition, byte* packet);
void logit(uint8_t  x);
void logit_string();
void loop();
void my_cli();
void parse_line();
void printError(int x);
void Readmaster();
int ReadSetup();
void readAin();
void read_line();
void readPCF85263();
void RTCregW(uint8_t x, uint8_t y);
uint8_t RTCregR(uint8_t x);
void send_T_host(uint8_t x);
void setPCF85263();
int takeSPI();
void serial1Flush();
void SoftwareReset(void);
void softuartwrite(uint8_t data);
byte  softuartread();
void SPIgetPicture_callback(uint32_t pictureSize, uint16_t packetSize, uint32_t packetStartPosition, byte* packet);
void setup();
void  WriteText(void);

// Commands
int cmd_analog();
int cmd_bme680();
int cmd_DotStar();
int cmd_dir();
int cmd_dump();
int cmd_erase();
int cmd_exit();
int cmd_format();
int cmd_free();
int cmd_help();
int cmd_fram_init();
int cmd_fram_dump();
int cmd_fram_clear();
int cmd_io();
int cmd_led();
int cmd_mkdir();
int cmd_open();
int cmd_queue_init();
int cmd_queue_list();
int cmd_rmdir();
int cmd_rtcreg();
int cmd_sphoto();
int cmd_scani2c();
int cmd_settime();
int cmd_stackandheap();
int cmd_takeSphoto();
int cmd_takeSpiphoto();
int cmd_tdump();
int cmd_text();
int cmd_time();
int cmd_time_set();
int cmd_tc();
int cmd_trtc();
int cmd_upload();
int cmd_view();

// Legacy commands - do not use, these will be deprecated. See commands section for new commands
int cmd_initfram();
int cmd_initQueue();
int cmd_listQue();
int cmd_ana();
int fram_clear();
int framdump();
int fram_init();
int freeMemory();
int initSD();
int initfram();

// Help commands
void help_analog();
void help_bme680();
void help_dir();
void help_DotStar();
void help_dump();
void help_erase();
void help_exit();
void help_help();
void help_io();
void help_queue_init();
void help_queue_list();
void help_led();
void help_mkdir();
void help_open();
void help_rmdir();
void help_rtcreg();
void help_scani2c();
void help_settime();
void help_sphoto();
void help_stackandheap();
void help_takeSphoto();
void help_text();
void help_tdump();
void help_time();
void help_upload();
void help_view();

void help_time_set();
void help_trtc();
void help_format();
void help_free();
void help_takeSpiphoto();
void help_fram_dump();
void help_fram_init();
void help_fram_clear();
void help_SystemSetup();
void help_ReadSetup();
void help_enterTeamID();

// For testing with logic probes
void Pulse4(void);
void Pulse4high(void);
void Pulse4low(void);
void Pulse9(void);
void Pulse9high(void);
void Pulse9low(void);
void Pulse10(void);
void Pulse10high(void);
void Pulse10low(void);
void Pulse11(void);
void Pulse11high(void);
void Pulse11low(void);
void Pulse12(void);
void Pulse12high(void);
void Pulse12low(void);
void Pulse13(void);
void Pulse13high(void);
void Pulse13low(void);

#define LOG_FILENAME "syslog.txt"
#define DOTSTAR_DELAY 1500

#endif
