/*!
 * \file rtklib_rtkpos.h
 * \brief rtklib ppp-related functions
 * \authors <ul>
 *          <li> 2007-2013, T. Takasu
 *          <li> 2017, Javier Arribas
 *          <li> 2017, Carles Fernandez
 *          </ul>
 *
 * This is a derived work from RTKLIB http://www.rtklib.com/
 * The original source code at https://github.com/tomojitakasu/RTKLIB is
 * released under the BSD 2-clause license with an additional exclusive clause
 * that does not apply here. This additional clause is reproduced below:
 *
 * " The software package includes some companion executive binaries or shared
 * libraries necessary to execute APs on Windows. These licenses succeed to the
 * original ones of these software. "
 *
 * Neither the executive binaries nor the shared libraries are required by, used
 * or included in GNSS-SDR.
 *
 * -------------------------------------------------------------------------
 * Copyright (C) 2007-2013, T. Takasu
 * Copyright (C) 2017, Javier Arribas
 * Copyright (C) 2017, Carles Fernandez
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 *----------------------------------------------------------------------------*/

#ifndef GNSS_SDR_RTKLIB_RKTPOS_H_
#define GNSS_SDR_RTKLIB_RKTPOS_H_

#include "rtklib.h"

double varerr(const prcopt_t *opt, double el, int sys);
double gettgd(int sat, const nav_t *nav);
double prange(const obsd_t *obs, const nav_t *nav, const double *azel,
              int iter, const prcopt_t *opt, double *var);
int ionocorr(gtime_t time, const nav_t *nav, int sat, const double *pos,
             const double *azel, int ionoopt, double *ion, double *var);

int tropcorr(gtime_t time, const nav_t *nav, const double *pos,
             const double *azel, int tropopt, double *trp, double *var);

int rescode(int iter, const obsd_t *obs, int n, const double *rs,
            const double *dts, const double *vare, const int *svh,
            const nav_t *nav, const double *x, const prcopt_t *opt,
            double *v, double *H, double *var, double *azel, int *vsat,
            double *resp, int *ns);

int valsol(const double *azel, const int *vsat, int n,
           const prcopt_t *opt, const double *v, int nv, int nx,
           char *msg);

int estpos(const obsd_t *obs, int n, const double *rs, const double *dts,
           const double *vare, const int *svh, const nav_t *nav,
           const prcopt_t *opt, sol_t *sol, double *azel, int *vsat,
           double *resp, char *msg);

int raim_fde(const obsd_t *obs, int n, const double *rs,
             const double *dts, const double *vare, const int *svh,
             const nav_t *nav, const prcopt_t *opt, sol_t *sol,
             double *azel, int *vsat, double *resp, char *msg);

int resdop(const obsd_t *obs, int n, const double *rs, const double *dts,
           const nav_t *nav, const double *rr, const double *x,
           const double *azel, const int *vsat, double *v, double *H);

void estvel(const obsd_t *obs, int n, const double *rs, const double *dts,
            const nav_t *nav, const prcopt_t *opt, sol_t *sol,
            const double *azel, const int *vsat);

int pntpos(const obsd_t *obs, int n, const nav_t *nav,
           const prcopt_t *opt, sol_t *sol, double *azel, ssat_t *ssat,
           char *msg);

int lexioncorr(gtime_t time, const nav_t *nav, const double *pos,
               const double *azel, double *delay, double *var);

#endif
