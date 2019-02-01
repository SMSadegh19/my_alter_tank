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

#define MUS_PATH "uncharted.wav"

static Uint32 wav_length; // length of our sample
static Uint8 *wav_buffer; // buffer containing our audio file
static SDL_AudioSpec wav_spec; // the specs of our piece of music

void my_audio_callback(void *userdata, Uint8 *stream, int len);

static Uint8 *audio_pos; // global pointer to the audio buffer to be played
static Uint32 audio_len; // remaining length of the sample we have to play

void firsttime() {
    SDL_CloseAudio();
    if( SDL_LoadWAV(MUS_PATH, &wav_spec, &wav_buffer, &wav_length) == NULL ){
        return 1;
    }
    wav_spec.callback = my_audio_callback;
    wav_spec.userdata = NULL;
    audio_pos = wav_buffer; // copy sound buffer
    audio_len = wav_length; // copy file length
    if ( SDL_OpenAudio(&wav_spec, NULL) < 0 ){
        fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError());
        exit(-1);
    }
    SDL_PauseAudio(0);

}

void my_audio_callback(void *userdata, Uint8 *stream, int len) {

    if (audio_len == 0)
        return;

    len = ( len > audio_len ? audio_len : len );
    SDL_memcpy(stream, audio_pos, len); 					// simply copy from one buffer into the other
    SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);// mix from one buffer into another

    audio_pos += len;
    audio_len -= len;
}