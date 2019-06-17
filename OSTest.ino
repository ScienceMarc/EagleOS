#include <ArduinoSTL.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <vector>

#include <Adafruit_ST7735.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

static const PROGMEM uint16_t background[] = {
    0x20, 0x841, 0x861, 0x1082, 0x10a2, 0x18c3, 0x18e3, 0x2104, 0x2124, 0x2945, 0x2965, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x41e8, 0x4208, 0x4a29, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0x841, 0x841, 0x1062, 0x10a2, 0x18c3, 0x18c3, 0x2104, 0x2104, 0x2925, 0x2945, 0x3166, 0x3186, 0x31a6, 0x39c7, 0x41e8, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x7bef, 0x8430, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0x841, 0x1062, 0x1082, 0x18a3, 0x18c3, 0x20e4, 0x2104, 0x2124, 0x2945, 0x2965, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b4d, 0x738e, 0x73ae, 0x73ae, 0x7bcf, 0x8410, 0x8410, 0x8c51, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0x1062, 0x1082, 0x18a3, 0x18c3, 0x20e4, 0x2104, 0x2124, 0x2945, 0x2965, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5acb, 0x62ec, 0x632c, 0x6b2d, 0x6b6d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0x1082, 0x10a2, 0x18c3, 0x18e3, 0x2104, 0x2124, 0x2945, 0x2965, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a49, 0x4a69, 0x528a, 0x5aab, 0x5acb, 0x5aeb, 0x630c, 0x6b2d, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xa554, 0x10a2, 0x18c3, 0x18e3, 0x2104, 0x2124, 0x2945, 0x2965, 0x3166, 0x31a6, 0x39a7, 0x39e7, 0x4208, 0x4208, 0x4a29, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c51, 0x9492, 0x94b2, 0x94d2, 0x9cf3, 0x9d13, 0xa534, 0xa554, 0xad55, 0x18c3, 0x18c3, 0x2104, 0x2124, 0x2945, 0x2965, 0x3186, 0x3186, 0x39c7, 0x39c7, 0x41e8, 0x4208, 0x4a29, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x8c71, 0x94b2, 0x94d2, 0x9cf3, 0x9d13, 0xa514, 0xa554, 0xad55, 0xad75, 0x18c3, 0x20e4, 0x2104, 0x2925, 0x2945, 0x3166, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b2d, 0x6b4d, 0x738e, 0x73ae, 0x7bcf, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94d2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0x20e4, 0x2104, 0x2124, 0x2945, 0x2965, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5aab, 0x5acb, 0x62ec, 0x632c, 0x6b4d, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xa554, 0xad55, 0xb596, 0xb596, 0x2104, 0x2124, 0x2945, 0x2965, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5aab, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x94d2, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad55, 0xad75, 0xb5b6, 0xb5b6, 0x2124, 0x2925, 0x2965, 0x3186, 0x3186, 0x39a7, 0x39e7, 0x41e8, 0x4228, 0x4a29, 0x4a69, 0x528a, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0x9d13, 0xa514, 0xa554, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0x2925, 0x2945, 0x2965, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4a29, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8430, 0x8c71, 0x9492, 0x94b2, 0x94d2, 0x9cf3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0x2965, 0x2965, 0x3186, 0x39a7, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b2d, 0x6b4d, 0x738e, 0x73ae, 0x73ae, 0x7bcf, 0x8410, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0x2965, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5aab, 0x5acb, 0x630c, 0x632c, 0x6b2d, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xb5d6, 0xbdd7, 0xbe17, 0xc638, 0x3186, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a49, 0x528a, 0x528a, 0x5aab, 0x5acb, 0x62ec, 0x630c, 0x6b4d, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0x31a6, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x94d2, 0x9cf3, 0x9d13, 0xa534, 0xa554, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0xce59, 0x39c7, 0x39c7, 0x41e8, 0x4208, 0x4a29, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0xce59, 0xce79, 0x39c7, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b2d, 0x6b4d, 0x738e, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xb5d6, 0xbdf7, 0xc618, 0xc638, 0xc638, 0xce79, 0xce79, 0x39e7, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b4d, 0x6b6d, 0x73ae, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xb5d6, 0xbdf7, 0xbe17, 0xc638, 0xc638, 0xce59, 0xce99, 0xd69a, 0x4208, 0x4228, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5acb, 0x62ec, 0x630c, 0x6b2d, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0x9d13, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xb5b6, 0xbdd7, 0xbdf7, 0xc638, 0xc638, 0xce59, 0xce79, 0xd69a, 0xd6ba, 0x4228, 0x4a29, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0x9d13, 0xa514, 0xa554, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0xce59, 0xce79, 0xd69a, 0xd6ba, 0xdedb, 0x4a29, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x9492, 0x94b2, 0x9cf3, 0x9d13, 0xa534, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0xce59, 0xce79, 0xd69a, 0xd6ba, 0xdedb, 0xdefb, 0x4a49, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bcf, 0x8410, 0x8410, 0x8c51, 0x8c51, 0x9492, 0x94b2, 0x94b2, 0x9cd3, 0x9d13, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0xc658, 0xce79, 0xd69a, 0xd6ba, 0xd6da, 0xdefb, 0xdf1b, 0x4a69, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b2d, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xb5d6, 0xbdf7, 0xc618, 0xc638, 0xc638, 0xce59, 0xce99, 0xd6ba, 0xd6ba, 0xdedb, 0xdf1b, 0xe73c, 0x528a, 0x52aa, 0x5acb, 0x5aeb, 0x62ec, 0x630c, 0x6b2d, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xa554, 0xad75, 0xad75, 0xb5b6, 0xb5d6, 0xbdf7, 0xbe17, 0xc638, 0xc638, 0xce59, 0xce79, 0xd69a, 0xd6ba, 0xdedb, 0xdefb, 0xe71c, 0xe73c, 0x52aa, 0x52aa, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x9492, 0x94d2, 0x9cf3, 0x9cf3, 0xa514, 0xa554, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0xce59, 0xce79, 0xd69a, 0xd6ba, 0xdedb, 0xdefb, 0xdf1b, 0xe73c, 0xe75c, 0x5aab, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0xce59, 0xce79, 0xd69a, 0xd6ba, 0xdedb, 0xdefb, 0xdf1b, 0xe73c, 0xe75c, 0xef7d, 0x5acb, 0x5aeb, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8430, 0x8c51, 0x9492, 0x94b2, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0xce59, 0xce79, 0xce99, 0xd6ba, 0xd6da, 0xdefb, 0xdf1b, 0xe73c, 0xe75c, 0xef7d, 0xef9d, 0x5aeb, 0x62ec, 0x632c, 0x6b4d, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xad55, 0xad75, 0xb596, 0xb596, 0xbdd7, 0xbdf7, 0xbe17, 0xc638, 0xc658, 0xce79, 0xce99, 0xd69a, 0xd6ba, 0xdedb, 0xdefb, 0xe71c, 0xe73c, 0xef5d, 0xef7d, 0xf79e, 0x62ec, 0x630c, 0x6b2d, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0x9d13, 0xa534, 0xad55, 0xad55, 0xad75, 0xb5b6, 0xb5b6, 0xbdf7, 0xbdf7, 0xc618, 0xc638, 0xce59, 0xce79, 0xd69a, 0xd6ba, 0xdedb, 0xdefb, 0xe71c, 0xe73c, 0xef5d, 0xef7d, 0xf79e, 0xf7be, 0x630c, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8430, 0x8c51, 0x8c71, 0x9492, 0x94b2, 0x9cd3, 0x9cf3, 0xa514, 0xa534, 0xa554, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbe17, 0xc618, 0xc638, 0xce59, 0xce79, 0xd69a, 0xd6ba, 0xdedb, 0xdefb, 0xdf1b, 0xe73c, 0xef5d, 0xef7d, 0xef9d, 0xf7be, 0xf7de, 0x632c, 0x6b4d, 0x6b6d, 0x738e, 0x73ae, 0x7bcf, 0x7bef, 0x8410, 0x8410, 0x8430, 0x8c71, 0x9492, 0x9492, 0x94d2, 0x9cf3, 0x9d13, 0xa534, 0xa534, 0xad55, 0xad75, 0xb596, 0xb5b6, 0xbdd7, 0xbdf7, 0xc618, 0xc638, 0xce59, 0xce79, 0xd69a, 0xd6ba, 0xdedb, 0xdefb, 0xdf1b, 0xe73c, 0xe75c, 0xef7d, 0xef9d, 0xf7be, 0xf7de, 0xffff};
static const PROGMEM uint16_t bird[] = {
    0x335e, 0xb7e, 0x800, 0x2, 0x20, 0x0, 0x1b9f, 0x2b3e, 0x1b7f, 0x1b7f, 0x800, 0xffff, 0x800, 0x20, 0x1b7f, 0x9452, 0x0, 0x40, 0x20, 0x1021, 0x800, 0x801, 0x844f, 0x20, 0x233f, 0x235f, 0x233f, 0x21, 0x800, 0x822, 0x1, 0x20, 0x237f, 0x1b7f, 0x235e, 0x0, 0x21, 0x20, 0x802, 0x9c73, 0x135f, 0x1b9c, 0x1b7f, 0x1002, 0x1, 0x820, 0x9491, 0x1b3e, 0x2b7d, 0x1b3e, 0x235f, 0x4ac8, 0x800, 0x20, 0x1b7e, 0x2b7f, 0x137f, 0x2b7f, 0x1b3e, 0x42a8, 0x5aa9, 0x2, 0x237f, 0x137f};
static const PROGMEM uint16_t file[] = {
    0x528a, 0xff90, 0xff90, 0xf794, 0x5a66, 0x5a69, 0x4a6a, 0x5269, 0x5249, 0x528a, 0x5a6a, 0x5a66, 0x4a6d, 0x4a4b, 0xff71, 0xff90, 0xf7b1, 0xf752, 0xf792, 0xef91, 0xf7b0, 0xf7b0, 0xf7b1, 0xf773, 0xf772, 0x52a9, 0x4a6a, 0xff91, 0xff70, 0xf771, 0xff72, 0xff71, 0xff52, 0xff72, 0xff72, 0xff71, 0xff72, 0xff92, 0x4a49, 0x52a9, 0xff71, 0xff71, 0xffd2, 0xff31, 0xff91, 0xff92, 0xff52, 0xff52, 0xff92, 0xff91, 0xf750, 0x5aab, 0x4a89, 0xff71, 0xff71, 0xf771, 0xff91, 0xff8f, 0xff90, 0xff91, 0xff70, 0xff90, 0xff6f, 0xffb0, 0x4a49, 0x4a69, 0xff92, 0xffb2, 0xf771, 0xff92, 0xff71, 0xf772, 0xff93, 0xff93, 0xf792, 0xff51, 0xffb2, 0x4a6a, 0x528a, 0xff51, 0xff50, 0xffb1, 0xff51, 0xffb1, 0xff91, 0xf770, 0xf770, 0xffb1, 0xff92, 0xf771, 0x5289, 0x4a6a, 0xff91, 0xff90, 0xff91, 0xff72, 0xff72, 0xff72, 0xff71, 0xff71, 0xff71, 0xff72, 0xff72, 0x5269, 0x4a69, 0x4a69, 0x4a69, 0x4a69, 0x4a69, 0x4a69, 0x4a69, 0x4a69, 0x4a69, 0x4a69, 0x4a69, 0x4a69, 0x4a69};
static const PROGMEM uint16_t text_editor[] = {
    0x139f, 0x235f, 0x237e, 0x237f, 0x1b7f, 0x1b5e, 0x239e, 0x139f, 0x233f, 0xf7f2, 0xfff3, 0xe7f4, 0xff93, 0xf7f3, 0x1bbf, 0x1b5f, 0x13be, 0xce72, 0xce50, 0xb66b, 0xc64d, 0xd62f, 0xb64c, 0x237f, 0x1b9d, 0xffb2, 0xf7f1, 0xfff1, 0xfff2, 0xf7d3, 0xffb3, 0x1b7f, 0x235e, 0x801, 0x800, 0x822, 0xce4d, 0xb64e, 0xb6ef, 0x135d, 0x1bbf, 0xeff2, 0x802, 0xefd2, 0xf7d3, 0xffd6, 0xfff2, 0x237f, 0x1b7f, 0xce2e, 0x1, 0xc64c, 0xd64e, 0xc68c, 0xc62e, 0x237f, 0x1b7e, 0x1b7f, 0x1bbf, 0x231f, 0x1b9f, 0x139f, 0x235f, 0x137f};
static const PROGMEM uint16_t text_file[] = {
    0x7411,0x7411,0x7411,0x7411,0x7411,0xad75,0x7411,0xffff,0xffff,0xffff,0xffff,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0xffff,0xffff,0xffff,0xffff,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0xffff,0xffff,0xffff,0xffff,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0xffff,0xffff,0xffff,0xffff,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411,0x7411};
#pragma GCC optimize("-O3")

//Input
#define RIGHT 7
bool lastRIGHTstate = false;
bool currentRIGHTstate = false;

#define LEFT 6
bool lastLEFTstate = false;
bool currentLEFTstate = false;

#define A 5
bool lastAstate = false;
bool currentAstate = false;

#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

struct Folder {
    String name;
    std::vector<String> contents{"[1.TXT]Hello World!", "[2.TXT]Hello World 2!"};  //! G O D I S D E A D
    Folder() {
        name = "!!!!";
    }
    Folder(String x) {
        name = x;
    };
    String getFileName(int index) {
        return contents[index].substring(contents[index].indexOf("[") + 1, contents[index].indexOf("]"));
    }
};
std::vector<Folder> folders{Folder("%SYS"), Folder("%DAT")};

void drawBMPCustom(uint16_t x, uint16_t y, uint16_t w, uint16_t sf, const uint16_t *bitmp, size_t len, uint16_t stp) {
    for (int i = 0; i < len / sizeof(pgm_read_word(bitmp)); i++) {
        tft.fillRect(x + (i % w) * sf, y + floor(i / w) * sf, sf, sf, pgm_read_word_near(bitmp + i));
        if (i > stp && stp > 0) {  //Break after stp pixels
            break;
        }
    }
}
void drawBackground(uint16_t stp) {
    drawBMPCustom(0, 2, 40, 4, background, sizeof(background), stp);  //Background

    /*drawBMPCustom(5, 20, 13, 2, file, sizeof(file), 0); //File icon
    tft.setCursor(11, 40);
    tft.print("File 1");*/
    for (int i = 0; i < folders.size(); i++) {
        drawBMPCustom(10 + (i % 4 * 18 * 2), 20 + 34 * floor(i / 4), 13, 2, file, sizeof(file), 0);  //Draw file icon
        tft.setCursor(11 + (i % 4 * 18 * 2), 40 + 32 * floor(i / 4));
        tft.print(folders[i].name);
    }
}
void drawTaskbar() {
    tft.fillRect(0, 120, 160, 8, 0x1B7F);                               //Task Bar
    drawBMPCustom(0, 120, 8, 1, bird, sizeof(bird), 0);                 //Bird Logo
    drawBMPCustom(10, 120, 8, 1, text_editor, sizeof(text_editor), 0);  //Txt editor icon
}
void fpsCounter(double fps) {
    tft.fillRect(0, 0, 38, 10, 0);
    tft.setCursor(2, 2);
    tft.print(fps);
    //Serial.println(fps);
}
void drawFileSelection(int num) {
    tft.drawFastVLine(7 + num % 4 * 18 * 2, 16 + 34 * floor(num / 4), 34, 0x8F5F);
    tft.drawFastVLine(37 + num % 4 * 18 * 2, 16 + 34 * floor(num / 4), 34, 0x8F5F);
    tft.drawFastHLine(7 + num % 4 * 18 * 2, 16 + 34 * floor(num / 4), 6, 0x8F5F);
    tft.drawFastHLine(36 + num % 4 * 18 * 2, 16 + 34 * floor(num / 4), -6, 0x8F5F);
    tft.drawFastHLine(7 + num % 4 * 18 * 2, 16 + 34 + 34 * floor(num / 4), 6, 0x8F5F);
    tft.drawFastHLine(36 + num % 4 * 18 * 2, 16 + 33 + 34 * floor(num / 4), -6, 0x8F5F);
}

void showDesktop() {
    drawBackground(0);
    drawTaskbar();
}

void drawFolderView(int insideFolder, int currentlySelected) {
    tft.fillScreen(0xAD55);
    for (int i = 0; i < folders[insideFolder].contents.size(); i++) {
        ////Serial.println(folders[insideFolder].getFileName(i).substring(folders[insideFolder].getFileName(i).indexOf(".") + 1, folders[insideFolder].getFileName(i).indexOf("]")));
        if (folders[insideFolder].getFileName(i).substring(folders[insideFolder].getFileName(i).indexOf(".") + 1, folders[insideFolder].getFileName(i).indexOf("]")) == "TXT") {  //! EXISTENCE IS PAIN
            drawBMPCustom(16 + (i % 4 * 18 * 2), 20 + 34 * floor(i / 4), 6, 2, text_file, sizeof(text_file), 0);                                                                  //Draw file icon
            tft.setCursor(11 + (i % 4 * 18 * 2), 40 + 32 * floor(i / 4));
            tft.print(folders[insideFolder].getFileName(i).substring(folders[insideFolder].getFileName(i).indexOf("[") + 1, folders[insideFolder].getFileName(i).indexOf(".")));
        }
        drawFileSelection(currentlySelected);
    }
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(230400);
    delay(500);
    tft.initR(INITR_BLACKTAB);  // Init ST7735S chip, black tab.

    Serial.println(F("Initialized"));
    tft.fillScreen(ST77XX_BLACK);
    tft.setRotation(1);

    tft.setTextColor(0xFFFF);
    tft.setTextWrap(true);
    tft.fillRect(0, 0, 160, 5, 0);
    for (int i = 0; i < 3; i++) {
        folders.push_back(Folder("File"));
    }

    drawBackground(0);
    drawTaskbar();
    drawFileSelection(0);

    pinMode(RIGHT, INPUT_PULLUP);
    pinMode(LEFT, INPUT_PULLUP);
    pinMode(A, INPUT_PULLUP);
}

int currentlySelected = 0;
int insideFolder = -1;

uint32_t execTime = 0;
void loop() {
    // put your main code here, to run repeatedly:
    execTime = millis();
    currentRIGHTstate = digitalRead(RIGHT);
    currentLEFTstate = digitalRead(LEFT);
    currentAstate = digitalRead(A);

    if (insideFolder >= 0) { //If this is true then we must be inside a folder
        if (currentRIGHTstate != lastRIGHTstate && !currentRIGHTstate && currentlySelected + 1 < folders[insideFolder].contents.size()) { //Move selection to the right
            currentlySelected++;
            drawFolderView(insideFolder,currentlySelected);
        }
        if (currentLEFTstate != lastLEFTstate && !currentLEFTstate && currentlySelected > 0) { //Move selection to the left
            currentlySelected--;
            drawFolderView(insideFolder,currentlySelected);
        }
    }
    else { //We must be on the desktop
        if (currentRIGHTstate != lastRIGHTstate && !currentRIGHTstate && currentlySelected + 1 < folders.size()) { //Move selection to the right
            currentlySelected++;
            showDesktop();
            drawFileSelection(currentlySelected);
        }
        if (currentLEFTstate != lastLEFTstate && !currentLEFTstate && currentlySelected > 0) { //Move selection to the left
            currentlySelected--;
            showDesktop();
            drawFileSelection(currentlySelected);
        }
        
    }
    if (currentAstate != lastAstate && !currentAstate && insideFolder == -1) { //Enter folder/open file
        insideFolder = currentlySelected;
        currentlySelected = 0;
        drawFolderView(insideFolder,currentlySelected);
    }

    lastRIGHTstate = currentRIGHTstate;
    lastLEFTstate = currentLEFTstate;
    lastAstate = currentAstate;
    ////Serial.println(folders[0].getFileName(0));
    double fps = pow(((millis() - execTime) * 0.001), -1);
    fpsCounter(fps);
    ////delay((millis() - execTime) * 2);  //* Wait for twice as long as it took to draw the frame.
}
