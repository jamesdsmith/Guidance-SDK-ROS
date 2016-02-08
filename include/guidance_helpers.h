/*
 * Copyright snip
 * Please contact the author(s) of this library if you have any questions.
 * Author: James Smith	 ( james.smith@berkeley.edu )
 */

#ifndef __GUIDANCE_HELPERS_H__
#define __GUIDANCE_HELPERS_H__

#include "DJI_guidance.h"

e_vbus_index get_default_camera_id() {
	return e_vbus1;
}

exposure_param get_default_exposure_param(int cameraID) {
	// JDS NOTE: The Guidance SDK example sets up these values by default and doesnt change
	// the default value in the constructor, but the m_exposure_time parameter DOES use the
	// default value in the constructor
	exposure_param para;
	para.m_is_auto_exposure = 1;
	para.m_step = 10;
	para.m_expected_brightness = 120;
    para.m_camera_pair_index = cameraID;
    return para;
}

exposure_param get_exposure_param(float step, float exposure_time, uint32_t expected_brightness, uint32_t is_auto_exposure, int camera_pair_index) {
	exposure_param para;
	para.m_step = step;
	para.m_exposure_time = exposure_time;
	para.m_is_auto_exposure = is_auto_exposure;
	para.m_expected_brightness = expected_brightness;
    para.m_camera_pair_index = camera_pair_index;
    return para;
}

#define RETURN_IF_ERR(err_code) { if( err_code ){ release_transfer(); \
std::cout << "Error: " << (e_sdk_err_code)err_code << " at " << __LINE__ << "," << __FILE__ << std::endl; return -1;}}

#endif