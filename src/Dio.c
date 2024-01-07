/*
 * Created on Fri Sep 09 2022 7:07:03 AM
 *
 * The MIT License (MIT)
 * Copyright (c) 2022 Aananth C N
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
 * TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <stddef.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h> // for LOG_DBG()

#include <Dio.h>
#include <Dio_cfg.h>

// Global variables
LOG_MODULE_REGISTER(Dio, LOG_LEVEL_DBG);

//  Returns the value of the specified DIO channel
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) {
	Dio_LevelType level = STD_LOW;
	const struct gpio_dt_spec *dt_spec;

	if (ChannelId > MAX_PORT_ID) {
		LOG_DBG("ERROR: %s invalid ChannelId = %d!", __func__, ChannelId);
		return 0xFF;
	}

	dt_spec = port_get_zephyr_dt_spec(ChannelId);
	level = gpio_pin_get_dt(dt_spec);

	return level;
}


// Service to set a level of a channel
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
	const struct gpio_dt_spec *dt_spec;

	if (ChannelId > MAX_PORT_ID) {
		LOG_DBG("ERROR: %s invalid ChannelId = %d!", __func__, ChannelId);
		return;
	}

	dt_spec = port_get_zephyr_dt_spec(ChannelId);
	gpio_pin_set_dt(dt_spec, Level);
}


// Returns the level of all channels of that port
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
	Dio_PortLevelType port_level = 0;

	// TODO: Implement the function
	return port_level;
}


void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level) {
	//bsp_set_port_output(port, level)
	// TODO: Implement the function
}


void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level) {
	// implement the channel group port write
	// TODO: Implement the function
}


void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo) {
	if (VersionInfo == NULL) {
		return;
	}

	VersionInfo->vendorID = 0x0000;
	VersionInfo->moduleID = 0x0000;
	VersionInfo->sw_major_version = 20;
	VersionInfo->sw_minor_version = 11;
	VersionInfo->sw_patch_version = 0;
}


Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId) {
	Dio_LevelType level = STD_LOW;
	const struct gpio_dt_spec *dt_spec;

	if (ChannelId > MAX_PORT_ID) {
		LOG_DBG("ERROR: %s invalid ChannelId = %d!", __func__, ChannelId);
		return 0xFF;
	}

	dt_spec = port_get_zephyr_dt_spec(ChannelId);
	gpio_pin_toggle_dt(dt_spec);
	level = gpio_pin_get_dt(dt_spec);

	return level;
}


void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask) {
	// PortId = level & mask
	// TODO: Implement the function
}