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
#include <Dio.h>
#include <bsp/bsp_dio.h> // board specific dio implementations

#include <Dio_cfg.h>


//  Returns the value of the specified DIO channel
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) {
	Dio_LevelType level = STD_LOW;

	if (ChannelId > MAX_PORT_ID) {
		// log error here
		return STD_LOW;
	}

	if (bsp_get_dio_input(ChannelId)) {
		level = STD_HIGH;
	}

	return level;
}


// Service to set a level of a channel
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
	Dio_PortType port_ch;
	if (ChannelId > MAX_PORT_ID) {
		// log error here
		return;
	}

	port_ch = DioChan2PortLookup[ChannelId];
	bsp_set_dio_output(port_ch, Level);
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

	// read the channel, flip it and return
	// TODO: Implement the function

	return level;
}


void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask) {
	// PortId = level & mask
	// TODO: Implement the function
}