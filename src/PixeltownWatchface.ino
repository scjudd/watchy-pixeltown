#include <Watchy.h>
#include "settings.h"
#include "bitmaps.h"

#define SCREEN_WIDTH   200
#define SCREEN_HEIGHT  200
#define DIGIT_WIDTH    18
#define DIGIT_HEIGHT   18
#define DIGIT_PADDING  4
#define TIME_TOP       18
#define TIME_HOUR_TENS 78
#define TIME_HOUR_ONES (TIME_HOUR_TENS + DIGIT_WIDTH + DIGIT_PADDING)
#define TIME_COLON     (TIME_HOUR_ONES + DIGIT_WIDTH + DIGIT_PADDING)
#define TIME_MIN_TENS  (TIME_COLON     + DIGIT_WIDTH + DIGIT_PADDING)
#define TIME_MIN_ONES  (TIME_MIN_TENS  + DIGIT_WIDTH + DIGIT_PADDING)

class PixeltownWatchface : public Watchy {
  public:
    PixeltownWatchface(const watchySettings& s) : Watchy(s) {}

    void drawWatchFace() {
      display.fillScreen(GxEPD_WHITE);
      display.drawBitmap(0, 0, epd_bitmap_Watchy_Pixeltown, SCREEN_WIDTH, SCREEN_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      display.setCursor(0, 0);

      if (currentTime.Hour == 0 || currentTime.Hour == 12) {
        display.drawBitmap(TIME_HOUR_TENS, TIME_TOP, epd_bitmap_1, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_2, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 1 || currentTime.Hour == 13) {
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_1, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 2 || currentTime.Hour == 14) {
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_2, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 3 || currentTime.Hour == 15) {
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_3, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 4 || currentTime.Hour == 16) {
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_4, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 5 || currentTime.Hour == 17) {
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_5, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 6 || currentTime.Hour == 18) {
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_6, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 7 || currentTime.Hour == 19) {
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_7, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 8 || currentTime.Hour == 20) {
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_8, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 9 || currentTime.Hour == 21) {
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_9, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 10 || currentTime.Hour == 22) {
        display.drawBitmap(TIME_HOUR_TENS, TIME_TOP, epd_bitmap_1, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_0, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Hour == 11 || currentTime.Hour == 23) {
        display.drawBitmap(TIME_HOUR_TENS, TIME_TOP, epd_bitmap_1, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
        display.drawBitmap(TIME_HOUR_ONES, TIME_TOP, epd_bitmap_1, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      }

      display.drawBitmap(TIME_COLON, TIME_TOP, epd_bitmap_colon, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);

      if (currentTime.Minute / 10 == 0) {
        display.drawBitmap(TIME_MIN_TENS, TIME_TOP, epd_bitmap_0, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute / 10 == 1) {
        display.drawBitmap(TIME_MIN_TENS, TIME_TOP, epd_bitmap_1, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute / 10 == 2) {
        display.drawBitmap(TIME_MIN_TENS, TIME_TOP, epd_bitmap_2, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute / 10 == 3) {
        display.drawBitmap(TIME_MIN_TENS, TIME_TOP, epd_bitmap_3, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute / 10 == 4) {
        display.drawBitmap(TIME_MIN_TENS, TIME_TOP, epd_bitmap_4, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute / 10 == 5) {
        display.drawBitmap(TIME_MIN_TENS, TIME_TOP, epd_bitmap_5, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      }

      if (currentTime.Minute % 10 == 0) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_0, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute % 10 == 1) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_1, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute % 10 == 2) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_2, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute % 10 == 3) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_3, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute % 10 == 4) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_4, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute % 10 == 5) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_5, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute % 10 == 6) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_6, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute % 10 == 7) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_7, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute % 10 == 8) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_8, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      } else if (currentTime.Minute % 10 == 9) {
        display.drawBitmap(TIME_MIN_ONES, TIME_TOP, epd_bitmap_9, DIGIT_WIDTH, DIGIT_HEIGHT, GxEPD_WHITE, GxEPD_BLACK);
      }
    }
};

PixeltownWatchface watchy(settings);

void setup() {
  watchy.init();
}

void loop() {}
