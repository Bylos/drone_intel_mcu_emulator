/*
 * mode_alexkidd.c
 *
 *  Created on: 22 déc. 2015
 *      Author: Bylos
 */

#include "modes.h"
#include "drivers.h"

/*******************************************************************************
 * ALEXKID MODE
 *******************************************************************************/
void Mode_Armed_Init(void) {
	printf(" ---> Entering Armed State\n");
}

mcu_mode_t Mode_Armed_Run(cpu_mode_t cpu_mode) {
	mcu_mode_t next_mode = MCU_MODE_ARMED;
	/* Check for new sensors values */
	if (lsm_get_inertial_flag()) {
		/* Send to CPU */
		if (cpu_mode != CPU_MODE_UNKNOWN) {
			cpu_send_inertial(lsm_get_inertial_data());
		}
	}
	/* Check for new joystick values */
	if (xbee_get_joystick_flag()) {
		/* Send to CPU */
		if (cpu_mode != CPU_MODE_UNKNOWN) {
			cpu_send_joystick(xbee_get_joystick_data());
		}
	}
	/* Check for new esc values */
	if (cpu_get_esc_pwm_flag()) {
		/* Feed motors */
		esc_pwm_t pwm = cpu_get_esc_pwm_data();
		pca_channel_0_3(
				pwm.front_left,
				pwm.front_right,
				pwm.rear_right,
				pwm.rear_left);
	}
	/* Check for mode request */
	if (xbee_get_command_flag()) {
		uint8_t command = xbee_get_command();
		switch (command) {
		default:
			cpu_send_command(command);
			break;
		}
	}
	return next_mode;
}
