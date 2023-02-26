/*
 * File: "global.h"
 */

#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
//-----------------------------------------------------------------------------
#include "config.h"
#include "ABlink.h"
#include "ATicker.h"
#include "mrl.h"
//-----------------------------------------------------------------------------
extern int Verbose;         // verbose level (0, 1, 2 or 3)
extern ABlink Led;          // компонент для моргания светодиодом
extern ATicker Ticker;      // тикер с заданным периодом 
extern mrl_t Mrl;           // MicroRL object
extern unsigned long Ticks; // счётчик тиков
//-----------------------------------------------------------------------------
#endif // GLOBAL_H

/*** end of "global.h" file ***/


