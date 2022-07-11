/*
** Character types.
** Donated to the public domain.
**
** This is intended to replace the problematic libc single-byte NLS functions.
** These just don't make sense anymore with UTF-8 locales becoming the norm
** on POSIX systems. It never worked too well on Windows systems since hardly
** anyone bothered to call setlocale().
**
** This table is hardcoded for ASCII. Identifiers include the characters
** 128-255, too. This allows for the use of all non-ASCII chars as identifiers
** in the lexer. This is a broad definition, but works well in practice
** for both UTF-8 locales and most single-byte locales (such as ISO-8859-*).
**
** If you really need proper character types for UTF-8 strings, please use
** an add-on library such as slnunicode: http://luaforge.net/projects/sln/
*/

#define lj_char_c
#define LUA_CORE

#include "lj_char.h"

LJ_DATADEF const uint8_t lj_char_bits[257] = {
    0,
//00 \0 soh stx etx eot enq ack \a  \b  \t  \n  \v  \f  \r   so  si
     1,  1,  1,  1,  1,  1,  1,  1,  1,  3,  3,  3,  3,  3,  1,  1,
//10 dle dc1 dc2 dc3 dc4 nak syn etb can em  sub esc fs  gs  rs  us
     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
//20 sp   !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /
     2,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
//30 0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?
   152,152,152,152,152,152,152,152,152,152,  4,  4,  4,  4,  4,  4,
// 152 = 0x98 = IDENT | XDIGIT | DIGIT

//40 @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
     4,176,176,176,176,176,176,160,160,160,160,160,160,160,160,160,
// 176 = 0xB0 = IDENT | UPPER | XDIGIT
// 160 = 0xA0 = IDENT | UPPER

//50 P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _
   160,160,160,160,160,160,160,160,160,160,160,  4,  4,  4,  4,132,  // 132 = 0x84 = IDENT | PUNCT

//60 `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
     4,208,208,208,208,208,208,192,192,192,192,192,192,192,192,192,
// 208 = 0xD0 = IDENT | LOWER | XDIGIT
// 192 = 0xC0 = IDENT | LOWER

//70 p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~  del
   192,192,192,192,192,192,192,192,192,192,192,  4,  4,  4,  4,  1,
//80~FF
   128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
   128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
   128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
   128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
   128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
   128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
   128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
   128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128
// 128 = 0x80 = IDENT
};

/*
//00 nul soh stx etx eot enq ack bel bs  ht  nl  vt  np  cr  so  si
//10 dle dc1 dc2 dc3 dc4 nak syn etb can em  sub esc fs  gs  rs  us
//20 sp   !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /
//30  0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?
//40  @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
//50  P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _
//60  `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
//70  p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~  del
*/