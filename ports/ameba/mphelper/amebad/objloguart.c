/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Chester Tseng
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*****************************************************************************
 *                              Header includes
 * ***************************************************************************/
#include "objloguart.h"

serial_t log_uart_obj;
ringbuf_t *_rx_buffer;


STATIC const char *_parity_name[] = {"None", "1", "0"};

#if 0
STATIC log_uart_obj_t log_uart_obj = {
    .base.type      = &log_uart_type,
    .params = {
        .baudrate  = UART_DEFAULT_BAUDRATE,
        .data_bits = UART_DEFAULT_DATA_BITS,
        .parity    = UART_DEFAULT_PARITY,
        .stop_bits = UART_DEFAULT_STOP_BITS,
    },
    .tx = {
        .timeout_ms = UART_DEFAULT_TX_TIMEOUT,
    },
    .rx = {
        .timeout_ms = UART_DEFAULT_RX_TIMEOUT,
    },
    .irq_enabled = true,
    .irq_handler = mp_const_none,
};
#endif


#if 0
/*
 *  OBJLOG_UART Interrupt Service Handler
 */
void mp_obj_log_uart_irq_handler (log_uart_obj_t *self, LOG_UART_INT_ID event) {

    /*
     *  At last read one char from register to prevent from interrupt pending
     */

    if (event == RxIrq || event == IIR_CHAR_TIMEOUT) {

        char chr = (char)(serial_getc(&log_uart_obj));

        if (self->irq_handler != mp_const_none) {
            /*
             * Lock mpHeap to prevent from too many gc_alloc
             */
            gc_lock();
            nlr_buf_t nlr;
            if (nlr_push(&nlr) == 0) {
                mp_obj_array_t *arr = MP_OBJ_TO_PTR(MP_STATE_PORT(log_uart_rx_chr_obj));
                arr->items = (void *)&chr;
                arr->len = 1;
                mp_call_function_2(self->irq_handler, MP_OBJ_FROM_PTR(self),
                        MP_STATE_PORT(log_uart_rx_chr_obj));
                nlr_pop();
            } else {
                self->irq_handler = mp_const_none;
                mp_printf(&mp_plat_print, "Uncaught exception in callback handler, clear irq_handler to None\r\n");
                if (nlr.ret_val != MP_OBJ_NULL) {
                    mp_obj_print_exception(&mp_plat_print, nlr.ret_val);
                }
            }
            gc_unlock();
        }
    }
}

#endif


void mp_loguart_irq_handler(uint32_t id, SerialIrq event)
{
    char c;
    _rx_buffer = (ringbuf_t *)id;

    if (event == RxIrq) {
        c = (char)(serial_getc(&log_uart_obj));
        ringbuf_store_char(c);
    }
}

//loguart_init();
void loguart_init0(void) {
    // Do nothing here
#ifdef AMEBAD
    printf("inti log uart-0\n");
    ringbuf_init();
    //serial_init(&log_uart_obj, PA_7, PA_8);
    serial_init(&log_uart_obj, PB_19, PB_18);
    printf("inti log uart-1\n");
    serial_format(&log_uart_obj, 8, ParityNone, 1);
    printf("inti log uart-2\n");
    serial_baud(&log_uart_obj, 115200);
    printf("inti log uart-3\n");
    //serial_irq_handler(&log_uart_obj, mp_loguart_irq_handler, (uint32_t)_rx_buffer);
    printf("inti log uart-4\n");
    serial_irq_handler(&log_uart_obj, mp_loguart_irq_handler, (uint32_t)_rx_buffer);
    serial_irq_set(&log_uart_obj, RxIrq, 1);
    printf("inti log uart-5\n");
    printf("inti log uart-5\n");

#endif
    MP_STATE_PORT(log_uart_rx_chr_obj) = mp_obj_new_bytearray(1, "");
}

STATIC void log_uart_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind) {
    log_uart_obj_t *self = MP_OBJ_TO_PTR(self_in);
    mp_printf(print, "LOGUART(baudrate=%u, bits=%u, parity=%s, stop=%u, \
      tx_timeout=%u, rx_timeout=%u)",
        self->params.baudrate, self->params.data_bits,
        _parity_name[self->params.parity], self->params.stop_bits,
        self->tx.timeout_ms, self->rx.timeout_ms);
}

#if 0
STATIC mp_obj_t log_uart_make_new (const mp_obj_type_t *type, mp_uint_t n_args, mp_uint_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    return (mp_obj_t)&log_uart_obj;
}
#endif

STATIC mp_obj_t log_uart_init0(size_t n_args, const mp_obj_t *args, mp_map_t *kw_args) {

    enum { ARG_baudrate, ARG_bits, ARG_parity, ARG_stop, ARG_tx_timeout, ARG_rx_timeout };

    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_baudrate,     MP_ARG_OBJ,  {.u_obj = MP_OBJ_NULL} },
        { MP_QSTR_bits,         MP_ARG_OBJ,  {.u_obj = MP_OBJ_NULL} },
        { MP_QSTR_parity,       MP_ARG_OBJ,  {.u_obj = MP_OBJ_NULL} },
        { MP_QSTR_stop,         MP_ARG_OBJ,  {.u_obj = MP_OBJ_NULL} },
        { MP_QSTR_tx_timeout,   MP_ARG_OBJ,  {.u_obj = MP_OBJ_NULL} },
        { MP_QSTR_rx_timeout,   MP_ARG_OBJ,  {.u_obj = MP_OBJ_NULL} },
    };
    mp_arg_val_t p_args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args - 1, args + 1, kw_args, MP_ARRAY_SIZE(allowed_args),
          allowed_args, p_args);

    log_uart_obj_t *self = MP_OBJ_TO_PTR(args[0]);

    if (p_args[ARG_baudrate].u_obj != MP_OBJ_NULL) {
        self->params.baudrate = mp_obj_get_int(p_args[ARG_baudrate].u_int);
    }

    if (p_args[ARG_bits].u_obj != MP_OBJ_NULL) {
        self->params.data_bits = mp_obj_get_int(p_args[ARG_bits].u_int);
    }

    if (p_args[ARG_parity].u_obj != MP_OBJ_NULL) {
        self->params.parity = mp_obj_get_int(p_args[ARG_parity].u_obj);;
    }

    if (p_args[ARG_stop].u_obj != MP_OBJ_NULL) {
        self->params.stop_bits = mp_obj_get_int(p_args[ARG_stop].u_int);
    }

    if (p_args[ARG_tx_timeout].u_obj != MP_OBJ_NULL) {
        self->tx.timeout_ms = mp_obj_get_int(p_args[ARG_tx_timeout].u_int);
    }

    if (p_args[ARG_rx_timeout].u_obj != MP_OBJ_NULL) {
        self->rx.timeout_ms = mp_obj_get_int(p_args[ARG_rx_timeout].u_int);
    }
    #ifdef AMEBA1
    if (log_uart_init(&(self->obj), self->params.baudrate,
                self->params.data_bits, self->params.parity, self->params.stop_bits) < 0) {
        mp_raise_ValueError("Invalid parameters");
    }
    #else
    printf("func: init loguart\n");
    //serial_init(&log_uart_obj, PA_7, PA_8);
    serial_init(&log_uart_obj, PB_19, PB_18);
    serial_format(&log_uart_obj, 8, ParityNone, 1);
    serial_baud(&log_uart_obj, 115200);
    #endif
    serial_irq_handler(&log_uart_obj, mp_loguart_irq_handler, (uint32_t)_rx_buffer);
    serial_irq_set(&log_uart_obj, RxIrq, 1);
    return mp_const_none;
}

STATIC MP_DEFINE_CONST_FUN_OBJ_KW(log_uart_init_obj, 1, log_uart_init0);

STATIC mp_obj_t log_uart_deinit(mp_obj_t *self_in) {
    log_uart_obj_t *self = MP_OBJ_TO_PTR(self_in);

    // clear any received data
    _rx_buffer->_iHead = _rx_buffer->_iTail;
    serial_free(&log_uart_obj);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(log_uart_deinit_obj, log_uart_deinit);

STATIC mp_obj_t log_uart_irq_enable(mp_uint_t n_args, const mp_obj_t *args) {
    log_uart_obj_t *self = args[0];
    if (n_args == 1) {
        // get the value
        return self->irq_enabled ? mp_const_true:mp_const_false;
    } else {
        // set the pin value
        if (mp_obj_is_true(args[1])) {
            self->irq_enabled = 1;
        } else {
            self->irq_enabled = 0;
        }
        serial_irq_set(&log_uart_obj, RxIrq, self->irq_enabled);
        return mp_const_none;
    }
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(log_uart_irq_enable_obj, 1, 2, log_uart_irq_enable);

STATIC mp_obj_t log_uart_irq_handler0(mp_obj_t self_in, mp_obj_t callback_in) {
    log_uart_obj_t *self = self_in;
    
    if (!MP_OBJ_IS_FUN(callback_in) && (callback_in != mp_const_none)) {
        mp_raise_ValueError("Error function type");
    }

    self->irq_handler = callback_in;
    serial_irq_handler(&log_uart_obj, mp_loguart_irq_handler, (uint32_t)_rx_buffer);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_2(log_uart_irq_handler_obj, log_uart_irq_handler0);

STATIC const mp_map_elem_t log_uart_locals_dict_table[] = {
    { MP_OBJ_NEW_QSTR(MP_QSTR_init),        MP_OBJ_FROM_PTR(&log_uart_init_obj) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_deinit),      MP_OBJ_FROM_PTR(&log_uart_deinit_obj) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_read),        MP_OBJ_FROM_PTR(&mp_stream_read_obj) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_readline),    MP_OBJ_FROM_PTR(&mp_stream_unbuffered_readline_obj) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_readinto),    MP_OBJ_FROM_PTR(&mp_stream_readinto_obj) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_write),       MP_OBJ_FROM_PTR(&mp_stream_write_obj) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_irq_enable),  MP_OBJ_FROM_PTR(&log_uart_irq_enable_obj) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_irq_handler), MP_OBJ_FROM_PTR(&log_uart_irq_handler_obj) },
};
STATIC MP_DEFINE_CONST_DICT(log_uart_locals_dict, log_uart_locals_dict_table);

STATIC mp_uint_t log_uart_read(mp_obj_t self_in, char *buf_in, mp_uint_t size, int *errcode) {
    log_uart_obj_t *self = MP_OBJ_TO_PTR(self_in);
    
    // Directly return 0 when size = 0, to save the time
    if (size == 0) 
        return 0;

    buf_in = (char)_rx_buffer->_aucBuffer;

    // if the head isn't ahead of the tail, we don't have any characters
    if (_rx_buffer->_iHead == _rx_buffer->_iTail)
        return -1;

    uint8_t uc = buf_in[_rx_buffer->_iTail];
    _rx_buffer->_iTail = (unsigned int)(_rx_buffer->_iTail + 1) % SERIAL_BUFFER_SIZE;
    return uc;


    #if 0
    int32_t ret = 0;

    mp_uint_t start = mp_hal_ticks_ms();
    for (mp_uint_t i = 0; i < size; i++) {
        while (!serial_readable(&log_uart_obj)) {
            if ((mp_hal_ticks_ms() - start) > self->rx.timeout_ms) {
                *errcode = MP_ETIMEDOUT;
                goto ret;
            }
        }
        ret += 1;
        buf_in[i] = (char)(serial_getc(&log_uart_obj));
    }

ret:
    if (ret == 0) {
        return MP_STREAM_ERROR;
    } else {
        return ret;
    }
    #endif
}

STATIC mp_uint_t log_uart_write(mp_obj_t self_in, const char *buf_in, mp_uint_t size, int *errcode) {
    log_uart_obj_t *self = MP_OBJ_TO_PTR(self_in);

    int uc_data = (int)buf_in[0];
    serial_putc(&log_uart_obj, uc_data);
    return 1;

    #if 0
    int32_t ret = 0;

    mp_uint_t start = mp_hal_ticks_ms();
    for (mp_uint_t i = 0; i < size; i++) {
        while (!serial_writable(&log_uart_obj)) {
            if ((mp_hal_ticks_ms() - start) > self->tx.timeout_ms) {
                *errcode = MP_ETIMEDOUT;
                goto ret;
            }
        }
        ret += 1;
        serial_putc(&log_uart_obj, buf_in[i]);
        // A workaround, it seems log uart's FIFO is not working ...
        mp_hal_delay_us(250);
    }

ret:
    if (ret == 0) {
        return MP_STREAM_ERROR;
    } else {
        return ret;
    }
    #endif
}

STATIC mp_uint_t log_uart_ioctl(mp_obj_t self_in, mp_uint_t request, mp_uint_t arg, int *errcode) {
    log_uart_obj_t *self = self_in;
    mp_uint_t ret;
    if (request == MP_STREAM_POLL) {
        mp_uint_t flags = arg;
        ret = 0;
        mp_uint_t status = 0;
        // Only return none zero when RX FIFO is not empty
        status = serial_readable(&log_uart_obj);
        if ((flags & MP_STREAM_POLL_RD) && (status & true)) {
            ret |= MP_STREAM_POLL_RD;
        }

        // Only return none zero when TX FIFO is not full
        status = serial_writable(&log_uart_obj);
        if ((flags & MP_STREAM_POLL_WR) && (status & true)) {
            ret |= MP_STREAM_POLL_WR;
        }
    } else {
        *errcode = MP_EINVAL;
        ret = MP_STREAM_ERROR;
    }
    return ret;
}

STATIC const mp_stream_p_t log_uart_stream_p = {
    .read    = log_uart_read,
    .write   = log_uart_write,
    .ioctl   = log_uart_ioctl,
    .is_text = false,
};

const mp_obj_type_t log_uart_type = {
    { &mp_type_type },
    .name        = MP_QSTR_LOGUART,
    .print       = log_uart_print,
    //.make_new    = log_uart_make_new,
    .getiter     = mp_identity_getiter,
    .iternext    = mp_stream_unbuffered_iter,
    .protocol    = &log_uart_stream_p,
    .locals_dict = (mp_obj_dict_t *)&log_uart_locals_dict,
};