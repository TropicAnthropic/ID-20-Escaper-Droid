#ifndef SONG_H
#define SONG_H

#include "atm_cmds.h"

#define Song const uint8_t PROGMEM

Song introMusic[] = {                // total song in bytes = 50
  //                            // setup bytes 13
  0x04,                         // Number of tracks
  0x00, 0x00,                   // Address of track 0
  0x03, 0x00,                   // Address of track 1
  0x0B, 0x00,                   // Address of track 2
  0x1C, 0x00,                   // Address of track 3
  
  0x01,                         // Channel 0 entry track (PULSE)
  ATM_STOP,                         // Channel 1 entry track (SQUARE)
  ATM_STOP,                         // Channel 2 entry track (TRIANGLE)
  ATM_STOP,                         // Channel 3 entry track (NOISE)

  //"Track 0"                   // ticks = 0 / bytes = 3
  ATM_VOL(0),                      // FX: SET VOLUME: volume = 0
  ATM_STOP_CHAN,                         // FX: STOP CURRENT CHANNEL

  //"Track 1"                   // ticks = 2048 / bytes = 8
  ATM_SET_TEMPO(160),                     // SET song tempo: value = 25
  ATM_VOL(48),                     // FX: SET VOLUME: volume = 48
  ATM_REPEAT(7, 2),                   // REPEAT: count = 7 + 1 / track = 2  (8 * 256 ticks)
  ATM_STOP_CHAN,                         // FX: STOP CURRENT CHANNEL

  //"Track 2"                   // ticks = 256 / bytes = 17
  ATM_GOTO(3),                      // GOTO: track = 3  (64 ticks)
  ATM_SET_TRA(-5),                     // FX: SET TRANSPOSITION: notes = -5
  ATM_GOTO(3),                      // GOTO: track = 3  (64 ticks)
  ATM_SET_TRA(-3),                     // FX: SET TRANSPOSITION: notes = -3
  ATM_GOTO(3),                      // GOTO: track = 3  (64 ticks)
  ATM_SET_TRA(-1),                     // FX: SET TRANSPOSITION: notes = -1
  ATM_GOTO(3),                      // GOTO: track = 3  (64 ticks)
  ATM_SET_TRA(0),                      // FX: SET TRANSPOSITION: notes = 0
  ATM_RETURN,                         // RETURN

  //"Track 3"                   // ticks = 64 / bytes = 9
  ATM_SL_VOL(-4),                     // FX: VOLUME SLIDE ON: steps = -4
  ATM_NOTE_C5,                    // NOTE ON: note = 37
  ATM_DELAY(16),                    // DELAY: ticks = 16
  ATM_NOTE_E5,                    // NOTE ON: note = 41
  ATM_DELAY(16),                    // DELAY: ticks = 16
  ATM_NOTE_G5,                    // NOTE ON: note = 44
  ATM_DELAY(16),                    // DELAY: ticks = 16
  ATM_RETURN,                         // RETURN
};

Song menuSong[] = {
0x18,                   // Number of tracks
0x00, 0x00,             // Address of track 0
0x05, 0x00,             // Address of track 1   5
0x10, 0x00,             // Address of track 2   16
0x1B, 0x00,             // Address of track 3   27
0x21, 0x00,             // Address of track 4   33
0x26, 0x00,             // Address of track 5   38
0x6C, 0x00,             // Address of track 6   108
0x74, 0x00,             // Address of track 7   116
0x7D, 0x00,             // Address of track 8   125
0x8C, 0x00,             // Address of track 9   140
0xA7, 0x00,             // Address of track 10  167
0xAC, 0x00,             // Address of track 11  172
0xB1, 0x00,             // Address of track 12  177
0xC0, 0x00,             // Address of track 13  192
0xCF, 0x00,             // Address of track 14  207
0xF0, 0x00,             // Address of track 15  240
0xF6, 0x00,             // Address of track 16  246
0xFC, 0x00,             // Address of track 17  252
0x0B, 0x01,             // Address of track 18  267
0x11, 0x01,             // Address of track 19  273
0x5A, 0x01,             // Address of track 20  346
0x62, 0x01,             // Address of track 21  354
0x66, 0x01,             // Address of track 22  358
0x6C, 0x01,             // Address of track 23  

0x06,                   // Channel 0 entry track
0x12,                   // Channel 1 entry track
ATM_STOP,                   // Channel 2 entry track
0x16,                   // Channel 3 entry track

//"Track 0"    
ATM_VOL(0),                // FX: SET VOLUME: volume = 0
ATM_SET_TEMPO(36),               // SET song tempo: value = 36
ATM_STOP_CHAN,                   // FX: STOP CURRENT CHANNEL
   
//"Track 1"   
ATM_SL_VOL(-6),               // FX: VOLUME SLIDE ON: steps = -6
ATM_NOTE_C3,              // NOTE ON: note = 13
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_SL_VOL(-12),              // FX: VOLUME SLIDE ON: steps = -12
ATM_NOTE_C4,              // NOTE ON: note = 25
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_G3,              // NOTE ON: note = 20
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_RETURN,                   // RETURN
    
//"Track 2"   
ATM_SL_VOL(-12),              // FX: VOLUME SLIDE ON: steps = -12
ATM_NOTE_C3,              // NOTE ON: note = 13
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_C3,              // NOTE ON: note = 13
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_G3,              // NOTE ON: note = 20
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_C4,              // NOTE ON: note = 25
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_RETURN,                   // RETURN
    
//"Track 3"   
ATM_REPEAT(2, 1),             // REPEAT: count = 2 + 1 / track = 1
ATM_GOTO(2),                // GOTO track 2
ATM_RETURN,                   // RETURN
    
//"Track 4"   
ATM_GOTO(1),                // GOTO track 1
ATM_GOTO(2),                // GOTO track 2
ATM_RETURN,                   // RETURN
        
//"Track 5" 
ATM_GOTO(2),                // GOTO track 2
ATM_REPEAT(1, 3),             // REPEAT: count = 1 + 1 / track = 3
ATM_GOTO(4),                // GOTO track 4
ATM_SET_TRA(-2),               // FX: ADD TRANSPOSITION: notes = -2
ATM_GOTO(4),                // GOTO track 4
ATM_SET_TRA(-4),               // FX: ADD TRANSPOSITION: notes = -4
ATM_GOTO(4),                // GOTO track 4
ATM_TRA_OFF,                   // FX: TRANSPOSITION OFF
ATM_GOTO(4),                // GOTO track 4
ATM_REPEAT(1, 3),             // REPEAT: count = 1 + 1 / track = 3
ATM_GOTO(4),                // GOTO track 4
ATM_SET_TRA(-2),               // FX: ADD TRANSPOSITION: notes = -2
ATM_GOTO(4),                // GOTO track 4
ATM_SET_TRA(-4),               // FX: ADD TRANSPOSITION: notes = -4
ATM_GOTO(4),                // GOTO track 4
ATM_SET_TRA(3),                // FX: ADD TRANSPOSITION: notes = 3
ATM_GOTO(4),                // GOTO track 4
ATM_REPEAT(1, 3),             // REPEAT: count = 1 + 1 / track = 3
ATM_SET_TRA(7),                // FX: ADD TRANSPOSITION: notes = 7
ATM_GOTO(4),                // GOTO track 4
ATM_SET_TRA(5),                // FX: ADD TRANSPOSITION: notes = 5
ATM_GOTO(4),                // GOTO track 4
ATM_SET_TRA(3),                // FX: ADD TRANSPOSITION: notes = 3
ATM_REPEAT(1, 4),             // REPEAT: count = 1 + 1 / track = 4
ATM_REPEAT(1, 3),             // REPEAT: count = 1 + 1 / track = 3
ATM_SET_TRA(7),                // FX: ADD TRANSPOSITION: notes = 7
ATM_GOTO(4),                // GOTO track 4
ATM_SET_TRA(5),                // FX: ADD TRANSPOSITION: notes = 5
ATM_GOTO(4),                // GOTO track 4
ATM_SET_TRA(3),                // FX: ADD TRANSPOSITION: notes = 3
ATM_GOTO(4),                // GOTO track 4
ATM_TRA_OFF,                   // FX: TRANSPOSITION OFF
ATM_GOTO(4),                // GOTO track 4
ATM_RETURN,                   // RETURN

//"Track 6"
ATM_VOL(48),               // FX: SET VOLUME: volume = 48     
ATM_REPEAT(2, 3),             // REPEAT: count = 2 + 1 / track = 3
ATM_REPEAT(2, 1),             // REPEAT: count = 2 + 1 / track = 1

//"Track 7"
ATM_GOTO_ADV(7, 19, 0, 23),     // FX: GOTO advanced
ATM_REPEAT(1, 5),             // REPEAT: count = 1 + 1 / track = 5
ATM_STOP_CHAN,                   // FX: STOP CURRENT CHANNEL



//"track 8"
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_A5_,              // NOTE ON: note = 47
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_G5,              // NOTE ON: note = 44
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D5_,              // NOTE ON: note = 40
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_G5,              // NOTE ON: note = 44
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C5,              // NOTE ON: note = 37
ATM_DELAY(16),              // DELAY: ticks = 16
ATM_RETURN,                   // RETURN

//"Track 9"
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_A5_,              // NOTE ON: note = 47
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_A5_,              // NOTE ON: note = 47
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_RETURN,                   // RETURN

//"Track 10"
ATM_NOTE_G5_,              // NOTE ON: note = 45
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(16),              // DELAY: ticks = 16
ATM_RETURN,                   // RETURN

//"Track 11"
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(16),              // DELAY: ticks = 16
ATM_RETURN,                   // RETURN

//"Track 12"
ATM_NOTE_G6,              // NOTE ON: note = 56
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_F6,              // NOTE ON: note = 54
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_G6,              // NOTE ON: note = 56
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_A5_,              // NOTE ON: note = 47
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_G5,              // NOTE ON: note = 44
ATM_DELAY(16),              // DELAY: ticks = 16
ATM_RETURN,                   // RETURN

//"Track 13"
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_A5_,              // NOTE ON: note = 47
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_G5,              // NOTE ON: note = 44
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D5_ ,              // NOTE ON: note = 40
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_G5,              // NOTE ON: note = 44
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C5,              // NOTE ON: note = 37
ATM_DELAY(20),              // DELAY: ticks = 20
ATM_RETURN,                   // RETURN

//"Track 14"
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_A5_,              // NOTE ON: note = 47
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_A5_,              // NOTE ON: note = 47
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_RETURN,                   // RETURN

//"Track 15"
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_G5_,              // NOTE ON: note = 45
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_C6,              // NOTE ON: note = 49
ATM_DELAY(16),              // DELAY: ticks = 16
ATM_RETURN,                   // RETURN

//"Track 16"
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_D6,              // NOTE ON: note = 51
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(16),              // DELAY: ticks = 16
ATM_RETURN,                   // RETURN


//"TRACK 17"
ATM_NOTE_G6,              // NOTE ON: note = 56
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_F6,              // NOTE ON: note = 54
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_G6,              // NOTE ON: note = 56
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_A5_,              // NOTE ON: note = 47
ATM_DELAY(4),               // DELAY: ticks = 4
ATM_NOTE_D6_,              // NOTE ON: note = 52
ATM_DELAY(8),               // DELAY: ticks = 8
ATM_NOTE_G5,              // NOTE ON: note = 44
ATM_DELAY(20),              // DELAY: ticks = 20
ATM_RETURN,                   // RETURN

//"Track 18"    
ATM_VOL(0),                // FX: SET VOLUME: volume = 0
ATM_DELAY(64),              // DELAY: ticks = 64
ATM_DELAY(64),              // DELAY: ticks = 64
ATM_DELAY(64),              // DELAY: ticks = 64
ATM_DELAY(48),              // DELAY: ticks = 48
    
//"Track 19"    
ATM_VOL(48),              // FX: SET VOLUME: volume = 48
ATM_SL_VOL(-24),              // FX: VOLUME SLIDE ON: steps = -24
ATM_REPEAT(1, 8),             // REPEAT: count = 1 + 1 / track = 8
ATM_GOTO(9),                // GOTO track 9
ATM_GOTO(10),               // GOTO track 10
ATM_REPEAT(1, 8),             // REPEAT: count = 1 + 1 / track = 8
ATM_GOTO(9),                // GOTO track 9
ATM_GOTO(11),               // GOTO track 11
ATM_REPEAT(1, 12),            // REPEAT: count = 1 + 1 / track = 12
ATM_SET_TRA(7),                // FX: ADD TRANSPOSITION: notes = 7
ATM_GOTO(9),                // GOTO track 9
ATM_GOTO(10),               // GOTO track 10
ATM_TRA_OFF,                   // FX: TRANSPOSITION OFF
ATM_REPEAT(1, 12),            // REPEAT: count = 1 + 1 / track = 12
ATM_SET_TRA(7),                // FX: ADD TRANSPOSITION: notes = 7
ATM_GOTO(9),                // GOTO track 9
ATM_GOTO(11),               // GOTO track 11
ATM_TRA_OFF,                   // FX: TRANSPOSITION OFF

ATM_REPEAT(1, 13),            // REPEAT: count = 1 + 1 / track = 13
ATM_GOTO(14),               // GOTO track 14
ATM_GOTO(15),               // GOTO track 15
ATM_REPEAT(1, 13),            // REPEAT: count = 1 + 1 / track = 13
ATM_GOTO(14),               // GOTO track 14
ATM_GOTO(16),               // GOTO track 16
ATM_REPEAT(1, 17),            // REPEAT: count = 1 + 1 / track = 17
ATM_SET_TRA(7),                // FX: ADD TRANSPOSITION: notes = 7
ATM_GOTO(14),               // GOTO track 14
ATM_GOTO(15),               // GOTO track 15
ATM_TRA_OFF,                   // FX: TRANSPOSITION OFF
ATM_REPEAT(1, 17),            // REPEAT: count = 1 + 1 / track = 17
ATM_SET_TRA(7),                // FX: ADD TRANSPOSITION: notes = 7
ATM_GOTO(14),               // GOTO track 14
ATM_GOTO(16),               // GOTO track 16
ATM_TRA_OFF,                   // FX: TRANSPOSITION OFF
ATM_STOP_CHAN,                 // FX: STOP CURRENT CHANNEL

//"Track 20"
ATM_NOISE(4 + 0),            // FX: RETRIG NOISE: point = 1 (*4) / speed = 0 (fastest)
ATM_VOL(32),               // FX: SET VOLUME: volume = 32
ATM_SL_VOL(-6),               // FX: VOLUME SLIDE ON: steps = -6
ATM_DELAY(16),              // DELAY: ticks = 16
ATM_RETURN,                   // RETURN

//"Track 21"
ATM_REPEAT(3, 20),            // REPEAT: count = 3 + 1 / track = 20
ATM_RETURN,                   // RETURN

//"Track 22"
ATM_REPEAT(2, 21),            // REPEAT: count = 2 + 1 / track = 21
ATM_REPEAT(2, 20),            // REPEAT: count = 2 + 1 / track = 20
    
//"Track 23"
ATM_GOTO(20),               // GOTO track 20
ATM_REPEAT(15, 21),           // REPEAT: count = 15 + 1 / track = 21
ATM_GOTO(20),               // GOTO track 20  
ATM_REPEAT(15, 21),           // REPEAT: count = 15 + 1 / track = 21
ATM_STOP_CHAN,                   // FX: STOP CURRENT CHANNEL
// DRUM END
    
};



#endif
