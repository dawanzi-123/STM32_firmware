#include "usb_printf.h"
#include "usbd_cdc_if.h"
#include <stdarg.h>
#include <stdio.h>

void usb_printf(const char *format, ...)
{
    char buffer[256];
    va_list args;
    va_start(args, format);
    int length = vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    if (length > 0 && length < sizeof(buffer)) {
        CDC_Transmit_HS((uint8_t*)buffer, length);
    }
}
