//
// Created by sadegh on 1/27/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL_audio.h>
#include <string.h>
#include "structs.h"
#include "view.h"
#include "physics.h"
#include "logic.h"
#include "playwav.h"

#define MUS_PATH "khooz.wav"
#define MUS_PATH2 "hello.wav"


static Uint32 wav_length; // length of our sample
static Uint8 *wav_buffer; // buffer containing our audio file
static SDL_AudioSpec wav_spec; // the specs of our piece of music

static Uint32 wav_length2; // length of our sample
static Uint8 *wav_buffer2; // buffer containing our audio file
static SDL_AudioSpec wav_spec2; // the specs of our piece of music

// prototype for our audio callback
// see the implementation for more information
void my_audio_callback(void *userdata, Uint8 *stream, int len);
void my_audio_callback2(void *userdata, Uint8 *stream, int len);

// variable declarations
static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play

static Uint8 *audio_pos2; // global pointer to the audio buffer to be played
static Uint32 audio_len2; // remaining length of the sample we have to play


/*
** PLAYING A SOUND IS MUCH MORE COMPLICATED THAN IT SHOULD BE
*/
void firsttime() {
//    if( SDL_LoadWAV(MUS_PATH, &wav_spec, &wav_buffer, &wav_length) == NULL ){
//        return 1;
//    }
    if( SDL_LoadWAV(MUS_PATH2, &wav_spec2, &wav_buffer2, &wav_length2) == NULL ){
        return;
    }
//    wav_spec.callback = my_audio_callback;
//    wav_spec.userdata = NULL;
    wav_spec2.callback = my_audio_callback2;
    wav_spec2.userdata = NULL;
//    audio_pos = wav_buffer; // copy sound buffer
//    audio_len = wav_length; // copy file length
//    if ( SDL_OpenAudio(&wav_spec, NULL) < 0 ){
//        fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
//        exit(-1);
//    }
//    SDL_PauseAudio(0);

    if ( SDL_OpenAudio(&wav_spec2, NULL) < 0 ){
        fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
        exit(-1);
    }
}

int playingforme(){
//    SDL_CloseAudio();
//    SDL_FreeWAV(wav_buffer);
//    int argc, char* argv[]
    // Initialize SDL.
//    if (SDL_Init(SDL_INIT_AUDIO) < 0)
//        return 1;

    // local variables
//    static Uint32 wav_length; // length of our sample
//    static Uint8 *wav_buffer; // buffer containing our audio file
//    static SDL_AudioSpec wav_spec; // the specs of our piece of music


    /* Load the WAV */
    // the specs, length and buffer of our wav are filled
//    if( SDL_LoadWAV(MUS_PATH2, &wav_spec2, &wav_buffer2, &wav_length2) == NULL ){
//        return 1;
//    }
//    // set the callback function
//    wav_spec2.callback = my_audio_callback2;
//    wav_spec2.userdata = NULL;
    // set our global static variables
    audio_pos2 = wav_buffer2; // copy sound buffer
    audio_len2 = wav_length2; // copy file length

    /* Open the audio device */
//    if ( SDL_OpenAudio(&wav_spec2, NULL) < 0 ){
//        fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
//        exit(-1);
//    }

    /* Start playing */
    SDL_PauseAudio(0);

    // wait until we're don't playing
//    while ( audio_len > 0 ) {
//        SDL_Delay(0);
//    }

    // shut everything down
//    SDL_CloseAudio();
//    SDL_FreeWAV(wav_buffer);

    return 0;
}

// audio callback function
// here you have to copy the data of your audio buffer into the
// requesting audio buffer (stream)
// you should only copy as much as the requested length (len)
void my_audio_callback(void *userdata, Uint8 *stream, int len) {

    if (audio_len == 0)
        return;

    len = ( len > audio_len ? audio_len : len );
    SDL_memcpy(stream, audio_pos, len); 					// simply copy from one buffer into the other
    SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another

    audio_pos += len;
    audio_len -= len;
}

void my_audio_callback2(void *userdata, Uint8 *stream, int len) {

    if (audio_len2 == 0)
        return;

    len = ( len > audio_len2 ? audio_len2 : len );
    SDL_memcpy(stream, audio_pos2, len); 					// simply copy from one buffer into the other
//    SDL_MixAudio(stream, audio_pos2, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another

    audio_pos2 += len;
    audio_len2 -= len;
}