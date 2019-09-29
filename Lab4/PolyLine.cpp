#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
		: mCount(0)
	{	
		mArr = nullptr;
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		if (other.mArr != nullptr)
		{
			//unsigned int count = mCount;
			mCount = other.mCount;

			//for (unsigned int i = 0; i < count; i++)
			//{
			//	delete mArr[i];
			//} 

			delete[] mArr;

			mArr = new const Point * [mCount];

			for (unsigned int i = 0; i < mCount; i++)
			{
				mArr[i] = new Point(*(other.mArr[i]));
			}

		}
		else
		{
			mCount = 0;
			mArr = nullptr;
		}
	}

	PolyLine::~PolyLine()
	{
		//for (unsigned int i = 0; i < mCount; i++)
		//{
		//	delete mArr[i];
		//}

		delete[] mArr;
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mCount < 10)
		{
			if (mCount != 0)
			{
				const Point** arr = new const Point * [mCount];

				for (unsigned int i = 0; i < mCount; i++)
				{
					arr[i] = mArr[i];
					mArr[i] = nullptr;
				}

				//for (unsigned int i = 0; i < mCount; i++)
				//{
				//	delete mArr[i];
				//}

				delete[] mArr;
				mArr = new const Point * [mCount + 1];

				for (unsigned int i = 0; i < mCount; i++)
				{
					mArr[i] = arr[i];
					arr[i] = nullptr;
				}

				const Point* point = new Point(x, y);
				mArr[mCount] = point;
				mCount += 1;

				//for (unsigned int i = 0; i < mCount - 1; i++)
				//{
				//	delete arr[i];
				//}

				delete[] arr;

				point = nullptr;
				//delete point;

				return true;
			}
			else
			{
				mArr = new const Point * [mCount + 1];
				const Point* point = new Point(x, y);
				mArr[mCount] = point;
				mCount += 1;
				point = nullptr;
				//delete point;

				return true;
			}
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{

		if (point == nullptr)
		{
			return false;
		}

		for (unsigned int i = 0; i < mCount; i++)
		{
			if (mArr[i] == point)
			{
				return true;
			}
		}

		if (mCount < 10)
		{
			if (mCount != 0)
			{
				const Point** arr = new const Point * [mCount];

				for (unsigned int i = 0; i < mCount; i++)
				{
					arr[i] = mArr[i];
					mArr[i] = nullptr;
				}

				//for (unsigned int i = 0; i < mCount; i++)
				//{
				//	delete mArr[i];
				//}

				delete[] mArr;
				mArr = new const Point * [mCount + 1];

				for (unsigned int i = 0; i < mCount; i++)
				{
					mArr[i] = arr[i];
					arr[i] = nullptr;
				}

				mArr[mCount] = point;
				mCount += 1;
				point = nullptr;

				//for (unsigned int i = 0; i < mCount - 1; i++)
				//{
				//	delete arr[i];
				//}

				delete[] arr;
				delete point;

				return true;
			}
			else
			{
				delete[] mArr;
				mArr = new const Point * [mCount + 1];
				mArr[mCount] = point;
				mCount += 1;
				point = nullptr;
				delete point;

				return true;
			}
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{	
		if (i >= mCount || i < 0)
		{
			return false;
		}

		if (mCount == 1)
		{
			mCount -= 1;
			delete mArr[i];
			delete[] mArr;
			mArr = nullptr;
			return true;
		}
		else
		{
			const Point** arr = new const Point * [mCount];

			for (unsigned int j = 0; j < mCount; j++)
			{
				arr[j] = mArr[j];
				mArr[j] = nullptr;
			}

			//for (unsigned int i = 0; i < mCount; i++)
			//{
			//	delete mArr[i];
			//}

			delete[] mArr;

			mCount -= 1;
			mArr = new const Point * [mCount];

			for (unsigned int j = 0; j < mCount; j++)
			{
				if (j >= i)
				{
					mArr[j] = arr[j + 1];
				}
				else
				{
					mArr[j] = arr[j];
				}
				//remove로 해당 객체 삭제해야함. 따라서 지울 것.
				
				if (j != i)
				{
					arr[j] = nullptr;
				}
			}

			arr[mCount] = nullptr;

			//for (unsigned int i = 0; i < mCount + 1; i++)
			//{
			//	delete arr[i];
			//}

			delete[] arr;

			return true;
		}
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mCount == 0 || outMin == nullptr || outMax == nullptr)
		{
			return false;
		}

		Point px = *mArr[0];
		Point py = *mArr[0];
		float x = px.GetX();
		float y = py.GetY();

		float minx = px.GetX();
		float maxx = px.GetX();
		float miny = py.GetY();
		float maxy = py.GetY();

		for (unsigned int i = 0; i < mCount; i++)
		{
			px = *mArr[i];
			py = *mArr[i];
			x = px.GetX();
			y = py.GetY();

			if (minx > x)
			{
				minx = x;
			}

			if (maxx < x)
			{
				maxx = x;
			}

			if (miny > y)
			{
				miny = y;
			}

			if (maxy < y)
			{
				maxy = y;
			}
		}

		outMin->SetX(minx);
		outMax->SetX(maxx);
		outMin->SetY(miny);
		outMax->SetY(maxy);

		if (outMin->GetX() == outMax->GetX() && outMin->GetY() == outMax->GetY())
		{
			outMax = nullptr;
			outMin = nullptr;
			delete outMin;
			delete outMax;
			return true;
		}
		else if (outMin->GetX() == outMax->GetX() && outMin->GetY() != outMax->GetY())
		{
			outMax = nullptr;
			outMin = nullptr;
			delete outMin;
			delete outMax;
			return true;
		}
		else if (outMin->GetX() != outMax->GetX() && outMin->GetY() == outMax->GetY())
		{
			outMax = nullptr;
			outMin = nullptr;
			delete outMin;
			delete outMax;
			return true;
		}
		else
		{
			outMax = nullptr;
			outMin = nullptr;
			delete outMin;
			delete outMax;
			return true;
		}
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (mArr == nullptr || i >= 10 || mCount <= i)
		{
			return nullptr;
		}
		else
		{
			Point px = *mArr[i];
			Point py = *mArr[i];
			float x = px.GetX();
			float y = py.GetY();

			return new Point(x, y);
		}
	}

	PolyLine& PolyLine::operator=(const PolyLine& other)
	{
		if (this == &other)
		{
			return *this;
		}

		if (other.mArr != nullptr)
		{
			//unsigned int count = mCount;
			mCount = other.mCount;

			/*for (unsigned int i = 0; i < count; i++)
			{
				delete mArr[i];
			}*/

			delete[] mArr;
			mArr = new const Point * [mCount];

			for (unsigned int i = 0; i < mCount; i++)
			{
				mArr[i] = new Point(*(other.mArr[i]));
			}

			return *this;
			
		}
		else
		{
			mCount = 0;
			mArr = nullptr;
			return *this;
		}
	}



}