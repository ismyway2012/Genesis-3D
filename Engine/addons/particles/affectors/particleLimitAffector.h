/****************************************************************************
Copyright (c) 2011-2013,WebJet Business Division,CYOU

http://www.genesis-3d.com.cn

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#ifndef __PARTICLE_DAMPEN_AFFECTOR_H__
#define __PARTICLE_DAMPEN_AFFECTOR_H__
#include "particles/particle_fwd_decl.h"
#include "particles/particleaffector.h"

namespace Particles
{
	class LimitAffector: public ParticleAffector
	{
		__DeclareSubClass( LimitAffector, ParticleAffector);

	public:		

	public:

		LimitAffector();
		virtual ~LimitAffector(){};	

		/**
		*/

		void SetSeparateAxis(bool separate);
		bool IsSeparateAxis(void) const;

		void _preProcessParticles(void);

		/** 
		*/
		virtual void _affect(Particle* particle);

		virtual Math::MinMaxCurve* getMinMaxCurve(ParticleCurveType axis);

		float LimitVelocity(float velocity, float _limit, float _value);

	protected:
		Math::MinMaxCurve									mLimitX;
		Math::MinMaxCurve									mLimitY;
		Math::MinMaxCurve									mLimitZ;
		Math::MinMaxCurve									mLimitValue;

		//Math::MinMaxCurve									mMagnitude;
		bool										mSeparateAxis;


	public:
		// @ISerialization::GetVersion. when change storage, must add SerializeSVersion count
		virtual Serialization::SVersion GetVersion() const;

		// @ISerialization::Load 
		virtual void Load( Serialization::SVersion ver, Serialization::SerializeReader* pReader, const Serialization::SerializationArgs* args );

		// @ISerialization::Save
		virtual void Save( Serialization::SerializeWriter* pWriter ) const;

		// copy 
		virtual void CopyFrom( const ParticleAffectorPtr& affector );

	};

	//--------------------------------------------------------------------------------
	inline void LimitAffector::SetSeparateAxis(bool separate)
	{
		mSeparateAxis = separate;
	}
	//--------------------------------------------------------------------------------
	inline bool LimitAffector::IsSeparateAxis(void) const
	{
		return mSeparateAxis;
	}
}
#endif

