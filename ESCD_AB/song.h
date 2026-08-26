#ifndef SONG_H
#define SONG_H
#define Song const uint8_t PROGMEM

Song introMusic[] = {                // total song in bytes = 50
  //                            // setup bytes 13
  0x04,                         // Number of tracks
  0x00, 0x00,                   // Address of track 0
  0x03, 0x00,                   // Address of track 1
  0x0B, 0x00,                   // Address of track 2
  0x1C, 0x00,                   // Address of track 3
  
  0x01,                         // Channel 0 entry track (PULSE)
  0x00,                         // Channel 1 entry track (SQUARE)
  0x00,                         // Channel 2 entry track (TRIANGLE)
  0x00,                         // Channel 3 entry track (NOISE)

  //"Track 0"                   // ticks = 0 / bytes = 3
  0x40, 0,                      // FX: SET VOLUME: volume = 0
  0x9F,                         // FX: STOP CURRENT CHANNEL

  //"Track 1"                   // ticks = 2048 / bytes = 8
  0x9D, 160,                     // SET song tempo: value = 25
  0x40, 48,                     // FX: SET VOLUME: volume = 48
  0xFD, 7, 2,                   // REPEAT: count = 7 + 1 / track = 2  (8 * 256 ticks)
  0x9F,                         // FX: STOP CURRENT CHANNEL

  //"Track 2"                   // ticks = 256 / bytes = 17
  0xFC, 3,                      // GOTO: track = 3  (64 ticks)
  0x4C, -5,                     // FX: SET TRANSPOSITION: notes = -5
  0xFC, 3,                      // GOTO: track = 3  (64 ticks)
  0x4C, -3,                     // FX: SET TRANSPOSITION: notes = -3
  0xFC, 3,                      // GOTO: track = 3  (64 ticks)
  0x4C, -1,                     // FX: SET TRANSPOSITION: notes = -1
  0xFC, 3,                      // GOTO: track = 3  (64 ticks)
  0x4C, 0,                      // FX: SET TRANSPOSITION: notes = 0
  0xFE,                         // RETURN

  //"Track 3"                   // ticks = 64 / bytes = 9
  0x41, -4,                     // FX: VOLUME SLIDE ON: steps = -4
  0x00 + 37,                    // NOTE ON: note = 37
  0x9F + 16,                    // DELAY: ticks = 16
  0x00 + 41,                    // NOTE ON: note = 41
  0x9F + 16,                    // DELAY: ticks = 16
  0x00 + 44,                    // NOTE ON: note = 44
  0x9F + 16,                    // DELAY: ticks = 16
  0xFE,                         // RETURN

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
0x00,                   // Channel 2 entry track
0x16,                   // Channel 3 entry track

//"Track 0"    
0x40, 0,                // FX: SET VOLUME: volume = 0
0x9D, 36,               // SET song tempo: value = 36
0x9F,                   // FX: STOP CURRENT CHANNEL
   
//"Track 1"   
0x41, -6,               // FX: VOLUME SLIDE ON: steps = -6
0x00 + 13,              // NOTE ON: note = 13
0x9F + 8,               // DELAY: ticks = 8
0x41, -12,              // FX: VOLUME SLIDE ON: steps = -12
0x00 + 25,              // NOTE ON: note = 25
0x9F + 4,               // DELAY: ticks = 4
0x00 + 20,              // NOTE ON: note = 20
0x9F + 4,               // DELAY: ticks = 4
0xFE,                   // RETURN
    
//"Track 2"   
0x41, -12,              // FX: VOLUME SLIDE ON: steps = -12
0x00 + 13,              // NOTE ON: note = 13
0x9F + 4,               // DELAY: ticks = 4
0x00 + 13,              // NOTE ON: note = 13
0x9F + 4,               // DELAY: ticks = 4
0x00 + 20,              // NOTE ON: note = 20
0x9F + 4,               // DELAY: ticks = 4
0x00 + 25,              // NOTE ON: note = 25
0x9F + 4,               // DELAY: ticks = 4
0xFE,                   // RETURN
    
//"Track 3"   
0xFD, 2, 1,             // REPEAT: count = 2 + 1 / track = 1
0xFC, 2,                // GOTO track 2
0xFE,                   // RETURN
    
//"Track 4"   
0xFC, 1,                // GOTO track 1
0xFC, 2,                // GOTO track 2
0xFE,                   // RETURN
        
//"Track 5" 
0xFC, 2,                // GOTO track 2
0xFD, 1, 3,             // REPEAT: count = 1 + 1 / track = 3
0xFC, 4,                // GOTO track 4
0x4C, -2,               // FX: ADD TRANSPOSITION: notes = -2
0xFC, 4,                // GOTO track 4
0x4C, -4,               // FX: ADD TRANSPOSITION: notes = -4
0xFC, 4,                // GOTO track 4
0x4D,                   // FX: TRANSPOSITION OFF
0xFC, 4,                // GOTO track 4
0xFD, 1, 3,             // REPEAT: count = 1 + 1 / track = 3
0xFC, 4,                // GOTO track 4
0x4C, -2,               // FX: ADD TRANSPOSITION: notes = -2
0xFC, 4,                // GOTO track 4
0x4C, -4,               // FX: ADD TRANSPOSITION: notes = -4
0xFC, 4,                // GOTO track 4
0x4C, 3,                // FX: ADD TRANSPOSITION: notes = 3
0xFC, 4,                // GOTO track 4
0xFD, 1, 3,             // REPEAT: count = 1 + 1 / track = 3
0x4C, 7,                // FX: ADD TRANSPOSITION: notes = 7
0xFC, 4,                // GOTO track 4
0x4C, 5,                // FX: ADD TRANSPOSITION: notes = 5
0xFC, 4,                // GOTO track 4
0x4C, 3,                // FX: ADD TRANSPOSITION: notes = 3
0xFD, 1, 4,             // REPEAT: count = 1 + 1 / track = 4
0xFD, 1, 3,             // REPEAT: count = 1 + 1 / track = 3
0x4C, 7,                // FX: ADD TRANSPOSITION: notes = 7
0xFC, 4,                // GOTO track 4
0x4C, 5,                // FX: ADD TRANSPOSITION: notes = 5
0xFC, 4,                // GOTO track 4
0x4C, 3,                // FX: ADD TRANSPOSITION: notes = 3
0xFC, 4,                // GOTO track 4
0x4D,                   // FX: TRANSPOSITION OFF
0xFC, 4,                // GOTO track 4
0xFE,                   // RETURN

//"Track 6"
0x40, 48,               // FX: SET VOLUME: volume = 48     
0xFD, 2, 3,             // REPEAT: count = 2 + 1 / track = 3
0xFD, 2, 1,             // REPEAT: count = 2 + 1 / track = 1

//"Track 7"
0x9E, 7, 19, 0, 23,     // FX: GOTO advanced
0xFD, 1, 5,             // REPEAT: count = 1 + 1 / track = 5
0x9F,                   // FX: STOP CURRENT CHANNEL



//"track 8"
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 47,              // NOTE ON: note = 47
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 44,              // NOTE ON: note = 44
0x9F + 8,               // DELAY: ticks = 8
0x00 + 40,              // NOTE ON: note = 40
0x9F + 8,               // DELAY: ticks = 8
0x00 + 44,              // NOTE ON: note = 44
0x9F + 8,               // DELAY: ticks = 8
0x00 + 37,              // NOTE ON: note = 37
0x9F + 16,              // DELAY: ticks = 16
0xFE,                   // RETURN

//"Track 9"
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 51,              // NOTE ON: note = 51
0x9F + 8,               // DELAY: ticks = 8
0x00 + 52,              // NOTE ON: note = 52
0x9F + 8,               // DELAY: ticks = 8
0x00 + 51,              // NOTE ON: note = 51
0x9F + 8,               // DELAY: ticks = 8
0x00 + 52,              // NOTE ON: note = 52
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 51,              // NOTE ON: note = 51
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 51,              // NOTE ON: note = 51
0x9F + 8,               // DELAY: ticks = 8
0x00 + 47,              // NOTE ON: note = 47
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 47,              // NOTE ON: note = 47
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0xFE,                   // RETURN

//"Track 10"
0x00 + 45,              // NOTE ON: note = 45
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 16,              // DELAY: ticks = 16
0xFE,                   // RETURN

//"Track 11"
0x00 + 51,              // NOTE ON: note = 51
0x9F + 8,               // DELAY: ticks = 8
0x00 + 52,              // NOTE ON: note = 52
0x9F + 16,              // DELAY: ticks = 16
0xFE,                   // RETURN

//"Track 12"
0x00 + 56,              // NOTE ON: note = 56
0x9F + 8,               // DELAY: ticks = 8
0x00 + 54,              // NOTE ON: note = 54
0x9F + 8,               // DELAY: ticks = 8
0x00 + 56,              // NOTE ON: note = 56
0x9F + 8,               // DELAY: ticks = 8
0x00 + 52,              // NOTE ON: note = 52
0x9F + 8,               // DELAY: ticks = 8
0x00 + 47,              // NOTE ON: note = 47
0x9F + 8,               // DELAY: ticks = 8
0x00 + 52,              // NOTE ON: note = 52
0x9F + 8,               // DELAY: ticks = 8
0x00 + 44,              // NOTE ON: note = 44
0x9F + 16,              // DELAY: ticks = 16
0xFE,                   // RETURN

//"Track 13"
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 47,              // NOTE ON: note = 47
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 44,              // NOTE ON: note = 44
0x9F + 8,               // DELAY: ticks = 8
0x00 + 40,              // NOTE ON: note = 40
0x9F + 4,               // DELAY: ticks = 4
0x00 + 44,              // NOTE ON: note = 44
0x9F + 8,               // DELAY: ticks = 8
0x00 + 37,              // NOTE ON: note = 37
0x9F + 20,              // DELAY: ticks = 20
0xFE,                   // RETURN

//"Track 14"
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 51,              // NOTE ON: note = 51
0x9F + 8,               // DELAY: ticks = 8
0x00 + 52,              // NOTE ON: note = 52
0x9F + 8,               // DELAY: ticks = 8
0x00 + 51,              // NOTE ON: note = 51
0x9F + 4,               // DELAY: ticks = 4
0x00 + 52,              // NOTE ON: note = 52
0x9F + 8,               // DELAY: ticks = 8
0x00 + 52,              // NOTE ON: note = 52
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 4,               // DELAY: ticks = 4
0x00 + 51,              // NOTE ON: note = 51
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 4,               // DELAY: ticks = 4
0x00 + 51,              // NOTE ON: note = 51
0x9F + 8,               // DELAY: ticks = 8
0x00 + 51,              // NOTE ON: note = 51
0x9F + 8,               // DELAY: ticks = 8
0x00 + 47,              // NOTE ON: note = 47
0x9F + 4,               // DELAY: ticks = 4
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 47,              // NOTE ON: note = 47
0x9F + 4,               // DELAY: ticks = 4
0x00 + 49,              // NOTE ON: note = 49
0x9F + 8,               // DELAY: ticks = 8
0x00 + 49,              // NOTE ON: note = 49
0x9F + 4,               // DELAY: ticks = 4
0xFE,                   // RETURN

//"Track 15"
0x9F + 4,               // DELAY: ticks = 4
0x00 + 45,              // NOTE ON: note = 45
0x9F + 4,               // DELAY: ticks = 4
0x00 + 49,              // NOTE ON: note = 49
0x9F + 16,              // DELAY: ticks = 16
0xFE,                   // RETURN

//"Track 16"
0x9F + 4,               // DELAY: ticks = 4
0x00 + 51,              // NOTE ON: note = 51
0x9F + 4,               // DELAY: ticks = 4
0x00 + 52,              // NOTE ON: note = 52
0x9F + 16,              // DELAY: ticks = 16
0xFE,                   // RETURN


//"TRACK 17"
0x00 + 56,              // NOTE ON: note = 56
0x9F + 8,               // DELAY: ticks = 8
0x00 + 54,              // NOTE ON: note = 54
0x9F + 8,               // DELAY: ticks = 8
0x00 + 56,              // NOTE ON: note = 56
0x9F + 8,               // DELAY: ticks = 8
0x00 + 52,              // NOTE ON: note = 52
0x9F + 8,               // DELAY: ticks = 8
0x00 + 47,              // NOTE ON: note = 47
0x9F + 4,               // DELAY: ticks = 4
0x00 + 52,              // NOTE ON: note = 52
0x9F + 8,               // DELAY: ticks = 8
0x00 + 44,              // NOTE ON: note = 44
0x9F + 20,              // DELAY: ticks = 20
0xFE,                   // RETURN

//"Track 18"    
0x40, 0,                // FX: SET VOLUME: volume = 0
0x9F + 64,              // DELAY: ticks = 64
0x9F + 64,              // DELAY: ticks = 64
0x9F + 64,              // DELAY: ticks = 64
0x9F + 48,              // DELAY: ticks = 48
    
//"Track 19"    
0x40, 48,               // FX: SET VOLUME: volume = 48
0x41, -24,              // FX: VOLUME SLIDE ON: steps = -24
0xFD, 1, 8,             // REPEAT: count = 1 + 1 / track = 8
0xFC, 9,                // GOTO track 9
0xFC, 10,               // GOTO track 10
0xFD, 1, 8,             // REPEAT: count = 1 + 1 / track = 8
0xFC, 9,                // GOTO track 9
0xFC, 11,               // GOTO track 11
0xFD, 1, 12,            // REPEAT: count = 1 + 1 / track = 12
0x4C, 7,                // FX: ADD TRANSPOSITION: notes = 7
0xFC, 9,                // GOTO track 9
0xFC, 10,               // GOTO track 10
0x4D,                   // FX: TRANSPOSITION OFF
0xFD, 1, 12,            // REPEAT: count = 1 + 1 / track = 12
0x4C, 7,                // FX: ADD TRANSPOSITION: notes = 7
0xFC, 9,                // GOTO track 9
0xFC, 11,               // GOTO track 11
0x4D,                   // FX: TRANSPOSITION OFF

0xFD, 1, 13,            // REPEAT: count = 1 + 1 / track = 13
0xFC, 14,               // GOTO track 14
0xFC, 15,               // GOTO track 15
0xFD, 1, 13,            // REPEAT: count = 1 + 1 / track = 13
0xFC, 14,               // GOTO track 14
0xFC, 16,               // GOTO track 16
0xFD, 1, 17,            // REPEAT: count = 1 + 1 / track = 17
0x4C, 7,                // FX: ADD TRANSPOSITION: notes = 7
0xFC, 14,               // GOTO track 14
0xFC, 15,               // GOTO track 15
0x4D,                   // FX: TRANSPOSITION OFF
0xFD, 1, 17,            // REPEAT: count = 1 + 1 / track = 17
0x4C, 7,                // FX: ADD TRANSPOSITION: notes = 7
0xFC, 14,               // GOTO track 14
0xFC, 16,               // GOTO track 16
0x4D,                   // FX: TRANSPOSITION OFF

0x9F,                   // FX: STOP CURRENT CHANNEL

//"Track 20"
0x49, 4 + 0,            // FX: RETRIG NOISE: point = 1 (*4) / speed = 0 (fastest)
0x40, 32,               // FX: SET VOLUME: volume = 32
0x41, -6,               // FX: VOLUME SLIDE ON: steps = -6
0x9F + 16,              // DELAY: ticks = 16
0xFE,                   // RETURN

//"Track 21"
0xFD, 3, 20,            // REPEAT: count = 3 + 1 / track = 20
0xFE,                   // RETURN

//"Track 22"
0xFD, 2, 21,            // REPEAT: count = 2 + 1 / track = 21
0xFD, 2, 20,            // REPEAT: count = 2 + 1 / track = 20
    
//"Track 23"
0xFC, 20,               // GOTO track 20
0xFD, 15, 21,           // REPEAT: count = 15 + 1 / track = 21
0xFC, 20,               // GOTO track 20  
0xFD, 15, 21,           // REPEAT: count = 15 + 1 / track = 21
0x9F,                   // FX: STOP CURRENT CHANNEL
// DRUM END
    
};



#endif
