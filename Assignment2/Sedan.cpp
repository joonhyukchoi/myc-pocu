#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
		, mTr(nullptr)
	{
	}

	Sedan::Sedan(Sedan& bp)
		: Vehicle(bp.GetMaxPassengersCount())
	{
		unsigned int i;

		if (bp.mTr != nullptr)
		{
			mTr = new Trailer(*bp.mTr);
		}
		else
		{
			mTr = nullptr;
		}

		Set(bp.GetMaxPassengersCount(), bp.GetPassengersCount(), bp.GetSumWeight());

		for (i = 0; i < GetPassengersCount(); i++)
		{
			Set3(i, bp.GetPassenger(i));
		}
	}

	Sedan::~Sedan()
	{
		delete mTr;
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (mTr == nullptr)
		{
			mTr = trailer;

			return true;
		}
		
		return false;
	}

	bool Sedan::RemoveTrailer()
	{
		if (mTr != nullptr)
		{
			delete mTr;
			mTr = nullptr;

			return true;
		}

		return false;
	}

	unsigned int Sedan::GetDriveSpeed() const
	{
		unsigned int sum;
		unsigned int speed;

		sum = GetSumWeight();

		if (mTr != nullptr)
		{
			sum += mTr->GetWeight();
		}

		if (sum <= 80)
		{
			speed = 480;
		}
		else if (sum > 80 && sum <= 160)
		{
			speed = 458;
		}
		else if (sum > 160 && sum <= 260)
		{
			speed = 400;
		}
		else if (sum > 260 && sum <= 380)
		{
			speed = 380;
		}
		else
		{
			speed = 300;
		}

		return speed;
	}

	unsigned int Sedan::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	eTravelName Sedan::GetName() const
	{
		if (mTr != nullptr)
		{
			return SEDANT;
		}
		else
		{
			return SEDAN;
		}
	}

	Sedan Sedan::operator=(Sedan& bp)
	{
		if (*this == bp && this->mTr == bp.mTr)
		{
			return *this;
		}

		unsigned int i;

		if (this->mTr != nullptr)
		{
			delete mTr;
		}

		if (bp.mTr != nullptr)
		{
			this->mTr = bp.mTr;
		}
		
		InitializePassenger2();
		Set(bp.GetMaxPassengersCount(), bp.GetPassengersCount(), bp.GetSumWeight());

		for (i = 0; i < GetPassengersCount(); i++)
		{
			Set3(i, bp.GetPassenger(i));
		}

		return *this;
	}
}