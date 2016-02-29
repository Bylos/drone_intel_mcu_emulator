/*
 * types.h
 *
 *  Created on: 21 d�c. 2015
 *      Author: Bylos
 */

#ifndef __MCU_TYPES_H
#define __MCU_TYPES_H

typedef enum {
	MCU_MODE_BOOT		= -1,
	MCU_MODE_UNARMED	= 0,
	MCU_MODE_ALEXKIDD	= 1,
	MCU_MODE_ARMED		= 2,
} mcu_mode_t;

/* Convenient structure types for inertial data, size is 18 bytes */
typedef struct {
	short x;
	short y;
	short z;
} vector_t;

typedef struct {
	vector_t gyro;
	vector_t accel;
	vector_t magn;
} inertial_t;

/* Convenient structure types for esc pwm data, size is 8 bytes */
typedef struct {
	unsigned short front_left;
	unsigned short front_right;
	unsigned short rear_right;
	unsigned short rear_left;
} esc_pwm_t;

/* Convenient structure types for joystick data, size is 8 bytes */
typedef struct {
	signed short x;
	signed short y;
} axe_t;

typedef struct {
	axe_t left;
	axe_t right;
} joystick_t;

#endif /* __MCU_TYPES_H */
