#ifndef __IMAGE_H__
#define __IMAGE_H__

typedef struct _image{
    int width;
    int height;
    const unsigned char *image_ptr;
} Image_TypeDef;

#endif