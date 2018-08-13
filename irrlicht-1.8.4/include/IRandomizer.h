<<<<<<< HEAD
// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_RANDOMIZER_H_INCLUDED__
#define __I_RANDOMIZER_H_INCLUDED__

#include "IReferenceCounted.h"

namespace irr
{

//! Interface for generating random numbers
class IRandomizer : public virtual IReferenceCounted
{
public:
	//! resets the randomizer
	/** \param value Initialization value (seed) */
	virtual void reset(s32 value=0x0f0f0f0f) =0;

	//! generates a pseudo random number in the range 0..randMax()
	virtual s32 rand() const =0;

	//! generates a pseudo random number in the range 0..1
	virtual f32 frand() const =0;

	//! get maxmimum number generated by rand()
	virtual s32 randMax() const =0;
};

} // end namespace irr

#endif
=======
// Copyright (C) 2002-2012 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#ifndef __I_RANDOMIZER_H_INCLUDED__
#define __I_RANDOMIZER_H_INCLUDED__

#include "IReferenceCounted.h"

namespace irr
{

//! Interface for generating random numbers
class IRandomizer : public virtual IReferenceCounted
{
public:
	//! resets the randomizer
	/** \param value Initialization value (seed) */
	virtual void reset(s32 value=0x0f0f0f0f) =0;

	//! generates a pseudo random number in the range 0..randMax()
	virtual s32 rand() const =0;

	//! generates a pseudo random number in the range 0..1
	virtual f32 frand() const =0;

	//! get maxmimum number generated by rand()
	virtual s32 randMax() const =0;
};

} // end namespace irr

#endif
>>>>>>> b1408e684c5c46477537278bcd13e4812bb4e72a
