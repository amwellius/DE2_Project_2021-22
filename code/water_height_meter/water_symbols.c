/*
 * water_symbols.c
 *
 * Created: 24. 11. 2021 11:46:40
 *  Author: gkaretka
 */ 

const unsigned char init_msg_1[] = {
    // 'init', 84x48px
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x1f, 0x1f,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0xe7, 0xe7, 0xe7, 0xe7, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x84, 0x84, 0x84, 0x84,
    0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87,
    0x87, 0x87, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x87, 0x87, 0x87, 0x87, 0x87,
    0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9,
    0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9,
    0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xf3, 0xcb,
    0xff, 0xe7, 0xdf, 0xfb, 0xfb, 0xff, 0x83, 0xab, 0x83, 0xbf, 0xfb, 0x81, 0xbb, 0xff, 0xfb, 0x81,
    0xbb, 0xff, 0xff, 0xa3, 0xab, 0xab, 0xef, 0xbb, 0x83, 0xbb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xab,
    0xab, 0xff, 0xfb, 0xf3, 0xeb, 0xdf, 0xfb, 0xfb, 0xff, 0xab, 0xab, 0xff, 0xfb, 0x81, 0xbb, 0xff,
    0xff, 0xa3, 0xab, 0xab, 0xef, 0xff, 0x83, 0xb7, 0xbb, 0x83, 0xbf, 0xbb, 0x83, 0xbf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

const unsigned char init_msg_3[] = {
    // 'init', 84x48px
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x1f, 0x1f,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0xe7, 0xe7, 0xe7, 0xe7, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x84, 0x84, 0x84, 0x84,
    0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87,
    0x87, 0x87, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x87, 0x87, 0x87, 0x87, 0x87,
    0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9,
    0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9,
    0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0xf3, 0xcb,
    0xff, 0xe7, 0xdf, 0xfb, 0xfb, 0xff, 0x83, 0xab, 0x83, 0xbf, 0xfb, 0x81, 0xbb, 0xff, 0xfb, 0x81,
    0xbb, 0xff, 0xff, 0xa3, 0xab, 0xab, 0xef, 0xbb, 0x83, 0xbb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xab,
    0xab, 0xff, 0xfb, 0xf3, 0xeb, 0xdf, 0xfb, 0xfb, 0xff, 0xab, 0xab, 0xff, 0xfb, 0x81, 0xbb, 0xff,
    0xff, 0xa3, 0xab, 0xab, 0xef, 0xff, 0x83, 0xb7, 0xbb, 0x83, 0xbf, 0xbb, 0x83, 0xbf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

const unsigned char init_msg_2[] = {
    // 'init', 84x48px
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x1f, 0x1f,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f,
    0x1f, 0x1f, 0x1f, 0x1f, 0xe7, 0xe7, 0xe7, 0xe7, 0xe0, 0xf8, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x84, 0x84, 0x84, 0x84,
    0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87, 0x87,
    0x87, 0x87, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x87, 0x87, 0x87, 0x87, 0x87,
    0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0x84, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f,
    0xf9, 0x79, 0x79, 0x79, 0x79, 0x79, 0x19, 0x79, 0x79, 0x79, 0x19, 0x79, 0x79, 0xf9, 0xf9, 0x79,
    0x79, 0x79, 0xf9, 0xf9, 0x79, 0x79, 0x79, 0xf9, 0xf9, 0xf9, 0x79, 0x79, 0x79, 0x79, 0x79, 0xf9,
    0xf9, 0xf9, 0x79, 0xf9, 0x79, 0x79, 0x79, 0x79, 0x79, 0x19, 0x79, 0x79, 0xf9, 0xf9, 0x79, 0x79,
    0x7f, 0xff, 0xff, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfd, 0xf3, 0xf8, 0xfc,
    0xf8, 0xf3, 0xfd, 0xfe, 0xff, 0xf3, 0xf5, 0xf5, 0xf0, 0xff, 0xf0, 0xf7, 0xf7, 0xff, 0xf0, 0xf7,
    0xf7, 0xff, 0xf8, 0xf5, 0xf5, 0xf5, 0xf4, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xf5,
    0xf5, 0xf3, 0xff, 0xd8, 0xe7, 0xf9, 0xfe, 0xff, 0xf6, 0xf5, 0xf5, 0xf3, 0xff, 0xf0, 0xf7, 0xf7,
    0xff, 0xf8, 0xf5, 0xf5, 0xf5, 0xf4, 0xff, 0xf0, 0xff, 0xff, 0xf7, 0xf0, 0xff, 0xff, 0xf0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

const unsigned char water_level_img[] = {
    // 'water_level', 44x8px
    0x10, 0x18, 0x0c, 0x04, 0x04, 0x18, 0x10, 0x30, 0x20, 0x20, 0x30, 0x1c, 0x04, 0x04, 0x04, 0x04,
    0x04, 0x0c, 0x18, 0x30, 0x20, 0x30, 0x10, 0x18, 0x04, 0x04, 0x04, 0x04, 0x08, 0x18, 0x30, 0x20,
    0x20, 0x20, 0x30, 0x10, 0x18, 0x08, 0x08, 0x08, 0x08, 0x08, 0x18, 0x30
};

const unsigned char water_level_default[] = {
    // 'water level default / 0 percentage', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x07
};    

const unsigned char water_level_error[] = {
    // 'water level ERRO', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0xc1, 0x61, 0x21, 0x21, 0x61, 0xc1, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x1f, 0xf0, 0x80, 0x80, 0xf0, 0x1f, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x30,
    0x33, 0x33, 0x30, 0x00, 0x00, 0x00, 0x00, 0xff, 0x07, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
    0x04, 0x04, 0x04, 0x04, 0x04, 0x07
};

const unsigned char water_level_10[] = {
    // 'water level 10%', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

const unsigned char water_level_20[] = {
    // 'water level 20%', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xf8, 0xf8, 0xf8, 0xf8,
    0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

const unsigned char water_level_30[] = {
    // 'water level 30%', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

const unsigned char water_level_40[] = {
    // 'water level 40%', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xe0, 0xe0,
    0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

const unsigned char water_level_50[] = {
    // 'water level 50%', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0xfe, 0xfe,
    0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

const unsigned char water_level_60[] = {
    // 'water level 60%', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

const unsigned char water_level_70[] = {
    // 'water level 70%', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

const unsigned char water_level_80[] = {
    // 'water level 80%', 14x35px
    0xfe, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xfe, 0xff, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

const unsigned char water_level_90[] = {
    // 'water level 90%', 14x35px
    0xfe, 0x01, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0xe1, 0x01, 0xfe, 0xff, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

const unsigned char water_level_100[] = {
    // 'water level 100%', 14x35px
    0xfe, 0x01, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0xfd, 0x01, 0xfe, 0xff, 0x00,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0xff, 0x07, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05,
    0x05, 0x05, 0x05, 0x05, 0x04, 0x07
};

