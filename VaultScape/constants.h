//  Module:             Gameplay Programming
//  Assignment1:        School's Out!
//  Student Name:       Samuel Ong Jing Siang, Chua Yu Xuan Richeton, Lim Wei Jourdan, Chang Wee Siang Wilson
//  Student Number:     S10171663K, S10171533K, S10166869D, S10172123B

#ifndef _CONSTANTS_H            // Prevent multiple definitions if this 
#define _CONSTANTS_H            // file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include <windows.h>

//-----------------------------------------------
// Useful macros
//-----------------------------------------------
// Safely delete pointer referenced item
#define SAFE_DELETE(ptr)       { if (ptr) { delete (ptr); (ptr)=NULL; } }
// Safely release pointer referenced item
#define SAFE_RELEASE(ptr)      { if(ptr) { (ptr)->Release(); (ptr)=NULL; } }
// Safely delete pointer referenced array
#define SAFE_DELETE_ARRAY(ptr) { if(ptr) { delete [](ptr); (ptr)=NULL; } }
// Safely call onLostDevice
#define SAFE_ON_LOST_DEVICE(ptr)    { if(ptr) { ptr->onLostDevice(); } }
// Safely call onResetDevice
#define SAFE_ON_RESET_DEVICE(ptr)   { if(ptr) { ptr->onResetDevice(); } }
#define TRANSCOLOR  SETCOLOR_ARGB(255,255,0,255)  // transparent color (magenta)

//-----------------------------------------------
//                  Constants
//-----------------------------------------------

// window
const char CLASS_NAME[] = "VaultScape";
const char GAME_TITLE[] = "VaultScape";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_ORIGIN_X = 0;
const UINT GAME_ORIGIN_Y = 0;
const UINT GAME_WIDTH = 960;               // width of game in pixels
const UINT GAME_HEIGHT = 576;               // height of game in pixels


// game
const double PI = 3.14159265;
const float FRAME_RATE = 200.0f;                // the target frame rate (frames/sec)
const float MIN_FRAME_RATE = 10.0f;             // the minimum frame rate
const float MIN_FRAME_TIME = 1.0f / FRAME_RATE;   // minimum desired time for 1 frame
const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE; // maximum time used in calculations

// graphic images
const char MAIN_MENU_SCREEN[] = "pictures\\mainmenuscreen.png";
const char BUTTON_IMAGE[] = "pictures\\button.png";
const char MAP_SPRITES[] = "pictures\\map - Copy.png";
const char PAUSED_SCREEN[] = "pictures\\pausedscreen.png";
const char BULLET_IMAGE[] = "pictures\\bulletsprites.png";

// key mappings
// In this game simple constants are used for key mappings. If variables were used
// it would be possible to save and restore key mappings from a data file.
const UCHAR ESC_KEY = VK_ESCAPE;		// escape key
const UCHAR BACKSPACE_KEY = VK_BACK;		// space key
const UCHAR SPACE_KEY = VK_SPACE;		// space key
const UCHAR ALT_KEY = VK_MENU;			// alt key
const UCHAR ENTER_KEY = VK_RETURN;		// enter key


#endif
