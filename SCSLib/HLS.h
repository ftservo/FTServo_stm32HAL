/*
 * HLS.h
 * 飞特HLS系列串行舵机应用层程序
 * 日期: 2026.6.2
 * 作者: 
 */

#ifndef _HLS_H
#define _HLS_H

#include <stdint.h>

//内存表定义
//-------EPROM(只读)--------
#define HLS_MODEL_L 3
#define HLS_MODEL_H 4

//-------EPROM(读写)--------
#define HLS_ID 5
#define HLS_BAUD_RATE 6
#define HLS_MIN_ANGLE_LIMIT_L 9
#define HLS_MIN_ANGLE_LIMIT_H 10
#define HLS_MAX_ANGLE_LIMIT_L 11
#define HLS_MAX_ANGLE_LIMIT_H 12
#define HLS_CW_DEAD 26
#define HLS_CCW_DEAD 27
#define HLS_OFS_L 31
#define HLS_OFS_H 32
#define HLS_MODE 33

//-------SRAM(读写)--------
#define HLS_TORQUE_ENABLE 40
#define HLS_ACC 41
#define HLS_GOAL_POSITION_L 42
#define HLS_GOAL_POSITION_H 43
#define HLS_GOAL_ELE_L 44
#define HLS_GOAL_ELE_H 45
#define HLS_GOAL_SPEED_L 46
#define HLS_GOAL_SPEED_H 47
#define HLS_LOCK 55

//-------SRAM(只读)--------
#define HLS_PRESENT_POSITION_L 56
#define HLS_PRESENT_POSITION_H 57
#define HLS_PRESENT_SPEED_L 58
#define HLS_PRESENT_SPEED_H 59
#define HLS_PRESENT_LOAD_L 60
#define HLS_PRESENT_LOAD_H 61
#define HLS_PRESENT_VOLTAGE 62
#define HLS_PRESENT_TEMPERATURE 63
#define HLS_MOVING 66
#define HLS_PRESENT_CURRENT_L 69
#define HLS_PRESENT_CURRENT_H 70


extern int WritePosEx2(uint8_t ID, int16_t Position, uint16_t Speed, uint8_t ACC, uint16_t Torque);//普通写位置指令
extern int RegWritePosEx2(uint8_t ID, int16_t Position, uint16_t Speed, uint8_t ACC, uint16_t Torque);//异步写位置指令
extern void SyncWritePosEx2(uint8_t ID[], uint8_t IDN, int16_t Position[], uint16_t Speed[], uint8_t ACC[], uint16_t Torque[]);//同步写位置指令
extern int WriteSpeEx(uint8_t ID, int16_t Speed, uint8_t ACC, uint16_t Torque);//普通写恒速模式控制指令
extern int RegWriteSpeEx(uint8_t ID, int16_t Speed, uint8_t ACC, uint16_t Torque);//异步写恒速模式控制指令
extern void SyncWriteSpeEx(uint8_t ID[], uint8_t IDN, int16_t Speed[], uint8_t ACC[], uint16_t Torque[]);//同步写恒速模式控制指令
extern int EleMode(uint8_t ID);//恒流模式
extern int WriteEle(uint8_t ID, int16_t Torque);//普通恒流模式控制指令
extern int RegWriteEle(uint8_t ID, int16_t Torque);//异常恒流模式控制指令
extern void SyncWriteEle(uint8_t ID[], uint8_t IDN, int16_t Torque[]);//同步恒流模式控制指令
#endif
