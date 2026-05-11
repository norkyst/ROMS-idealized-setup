/*
** svn $Id: basin.h 8 2007-02-06 19:00:29Z arango $
*******************************************************************************
** Copyright (c) 2002-2007 The ROMS/TOMS Group
**
**   Licensed under a MIT/X style license
**
**   See License_ROMS.txt
**
*******************************************************************************
**
**  Options for ROMS
*/

#define PROFILE
#define DEFLATE
#define HDF5
#define NO_LBC_ATT
#undef  PARALLEL_IO
#undef  READ_WATER
#undef  WRITE_WATER

#undef  RST_SINGLE         /* define if single precision restart fields */
#undef  PERFECT_RESTART    /* use to include perfect restart variables */
#define CURVGRID           /* define if using  curvilinear coordinate grid*/

#undef  DIAGNOSTICS_UV     /* define if writing out dynamics to diagnostics file*/
#undef  DIAGNOSTICS_TS     /* define if writing out tracers  to diagnostics file*/

#define UV_ADV             /* turn ON or OFF advection terms */
#define UV_COR             /* turn ON or OFF Coriolis term */
#define UV_VIS2            /* turn ON or OFF Laplacian horizontal mixing */
#undef  UV_VIS4            /* turn ON or OFF biharmonic horizontal mixing */
#undef  UV_U3ADV_SPLIT     /* use 3rd-order upstream split momentum advection */
#define UV_U3HADVECTION    /* define if 3rd-order upstream horiz. advection */
#undef  UV_SADVECTION      /* turn ON or OFF splines vertical advection */
#undef  UV_C4HADVECTION    /* define if 4th-order centered horizontal advection */
#define UV_QDRAG           /* turn ON or OFF quadratic bottom friction */
#undef  UV_SMAGORINSKY

#undef  VISC_GRID          /* viscosity coefficient scaled by grid size */
#define NONLIN_EOS         /* define if using nonlinear equation of state */
#undef  WJ_GRADP           /* Weighted density Jacobian (Song, 1998) */
#define DJ_GRADPS          /* Splines density  Jacobian (Shchepetkin, 2000) */
#undef  DIFF_GRID          /* diffusion coefficient scaled by grid size */

#define TS_DIF2            /* turn ON or OFF Laplacian horizontal mixing */
#undef  TS_DIF4            /* turn ON or OFF biharmonic horizontal mixing */
#undef  TS_U3ADV_SPLIT     /* use 3rd-order upstream split tracer advection */
#define TS_U3HADVECTION    /* define if 3rd-order upstream horiz. advection */
#undef  TS_A4HADVECTION    /* define if 4th-order Akima horiz. advection */
#undef  TS_C4HADVECTION    /* define if 4th-order centered horizontal advection */

#undef  TS_MPDATA          /* define if recursive MPDATA 3D advection */

#undef  TS_A4VADVECTION    /* define if 4th-order Akima vertical advection */
#define TS_C4VADVECTION    /* define if 4th-order centered vertical advection */
#undef  TS_SVADVECTION     /* define if splines vertical advection */
#undef  TS_SMAGORINSKY     /* define if Smagorinsky-like diffusion */

#define  MIX_GEO_TS         /* mixing on geopotential (constant Z) surfaces */
#undef  MIX_GEO_UV         /* mixing on geopotential (constant Z) surfaces */
#define  MIX_S_UV           /* mixing along constant S-surfaces */
#undef  MIX_S_TS           /* mixing on constant S-surfaces */

#define RI_SPLINES         /* conservative, parabolic splines reconstruction */
#define SPLINES_VVISC
#define SPLINES_VDIFF

#define SALINITY           /* define if using salinity */
#define SOLVE3D            /* define if solving 3D primitive equations */
#undef  BODYFORCE          /* define if applying stresses as bodyforces */
#undef  SPLINES            /* turn ON or OFF parabolic splines reconstruction */
#define MASKING            /* define if there is land in the domain */
#define AVERAGES           /* define if writing out time-averaged data */
#undef  AVERAGES_DETIDE    /* use if writing out NLM time-averaged detided fields*/
#define AVERAGES_AKT       /* define if writing out time-averaged AKt*/
#define AVERAGES_AKS       /* define if writing out time-averaged AKs*/
#define AVERAGES_AKV       /* define if writing out time-averaged AKv */

#define QUICKSAVE

#undef  STATIONS           /* define if writing out station data */
#undef  STATIONS_CGRID     /* define if extracting data at native C-grid */

#undef  BVF_MIXING         /* define if Brunt_Vaisala frequency mixing */
#undef  LMD_MIXING         /* define if Large et al. (1994) interior closure */
#undef  MY25_MIXING        /* define if Mellor/Yamada level-2.5 mixing */
#define GLS_MIXING         /* Activate Generic Length-Scale mixing */

#ifdef GLS_MIXING
# define N2S2_HORAVG       /* Activate horizontal smoothing of buoyancy/shear */
# define CRAIG_BANNER
# undef  KANTHA_CLAYSON    /* Value for CLS_CMU0 and CLS_C3M vary with choise of stability function */
# define CANUTO_A           
# undef  CANUTO_B
# define CHARNOK
# define K_C4ADVECTION
#endif
#ifdef LMD_MIXING
# define  LMD_BKPP          /* use if bottom boundary layer KPP mixing */
# define  LMD_CONVEC        /* use to add convective mixing due to shear instability */
# define  LMD_DDMIX         /* use to add double-diffusive mixing */
# define  LMD_NONLOCAL      /* use if nonlocal transport */
# define  LMD_RIMIX         /* use to add diffusivity due to shear instability */
# define  LMD_SHAPIRO       /* use if Shapiro filtering boundary layer depth */
# define  LMD_SKPP          /* use if surface boundary layer KPP mixing */
#endif

#define ANA_BSFLUX         /* analytical bottom salinity flux */
#define ANA_BTFLUX         /* analytical bottom temperature flux */
#undef  ANA_GRID           /* analytical grid set-up */
#undef  ANA_INITIAL        /* analytical initial conditions */
#undef  ANA_MASK           /* analytical land/sea masking */
#undef  ANA_MEANRHO         
#undef  ANA_SSFLUX         /* analytical surface salinity flux */
#undef  ANA_STFLUX         /* analytical surface temperature flux */
#undef  ANA_SMFLUX         /* analytical surface momentum stress */

#undef  OBC_NUDGING
#define IMPLICIT_NUDGING   /* Implicit nudging term in momentum radiation conditions */
#define LIMIT_BSTRESS      /* Limit bottom stress to maintain bottom velocity direction */

#undef  WRF_COUPLING       /* coupling to WRF atmospheric model */

/* Sea Ice */
#define ICE_MODEL               /* to activate sea-ice model */
#ifdef ICE_MODEL
# define ICE_THERMO              /* if thermodynamic component                         */
# define ICE_MK                  /* if Mellor-Kantha thermodynamics (only choice)      */
# define ICE_ALBEDO              /* if computing surface albedo over water/snow/ice    */
# define ICE_ALB_EC92            /* if albedo computation from Ebert and Curry         */
# define ICE_MOMENTUM            /* if momentum component                              */
# define ICE_MOM_BULK            /* if alternate ice-water stress computation          */
# define ICE_EVP                 /* if elastic-viscous-plastic rheology                */
# define ICE_ADVECT              /* if advection of ice tracers                        */
# define ICE_SMOLAR              /* if MPDATA advection scheme                         */
# define ICE_UPWIND              /* if upwind advection scheme                         */
# define ICE_BULK_FLUXES         /* if ice part of bulk flux computation               */
# define ICE_CONVSNOW            /* if conversion of flooded snow to ice               */
# undef ICE_STRENGTH_QUAD       /* if quadratic ice strength, a function of thickness */
# undef NO_SCORRECTION_ICE      /* if no salinity correction under the ice            */
# undef OUTFLOW_MASK            /* if Hibler style outflow cells                      */
#endif

/* ATMOSPHERIC FORCING */
#define BULK_FLUXES        /* turn ON or OFF bulk fluxes computation */
#ifdef  BULK_FLUXES
# define EMINUSP           /* turn ON internal calculation of E-P */
# define ANA_SRFLUX        /* analytical surface shortwave radiation flux */
# define ALBEDO            /* use albedo equation for shortwave radiation */
# undef  LONGWAVE_OUT      /* compute outgoing longwave radiation */
# define LONGWAVE          /* Compute net longwave radiation internally */
# define COOL_SKIN         /* turn ON or OFF cool skin correction */
#endif

#define ATM_PRESS          /* use to impose atmospheric pressure onto sea surface */
#define SOLAR_SOURCE       /* define solar radiation source term */

/* TIDES */
#define SSH_TIDES          /* turn on computation of tidal elevation, default define */
#define UV_TIDES           /* turn on computation of tidal currents */
#define ADD_FSOBC          /* Add tidal elevation to processed OBC data, default define */
#define ADD_M2OBC          /* Add tidal currents  to processed OBC data */
#define ADD_INV_BARO_FLATHER
#undef  RAMP_TIDES         /* Spin up tidal forcing */

/* Boundary */
#define RADIATION_2D
/* --------------------------- */
