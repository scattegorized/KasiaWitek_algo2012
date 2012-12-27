/*
 *  aubioAnalyzer.h
 *  emptyExample
 *
 *  Created by kasia witek on 12/26/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef _AUBIO_SOUND_PROCESSOR
#define _AUBIO_SOUND_PROCESSOR
#include "aubioAnalyzer.h"
#include "ofMain.h"

class aubioAnalyzer{
	
public:
	
	void setup();
	void processAudio(float * buffer, int bufferSize);		
	
	~aubioAnalyzer();
	
	float pitch;
	float amplitude;
	
	// ------------------------------------------------------------------
	// internal aubio variables
	
	unsigned int win_s;							/* window size */
	unsigned int hop_s;							/* hop size */
	unsigned int samplerate;						/* samplerate */
	unsigned int channels;	

	aubio_pitchdetection_mode mode;
	aubio_pitchdetection_type type;
	
	fvec_t * in;
	aubio_pitchdetection_t * pitch_output ;
	
	
		// ------------------------------------------------------------------
	
};

#endif	

