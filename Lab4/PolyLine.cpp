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
		mCount = other.mCount;
		
		//�Ʒ��� ���� �����ϸ� ���� �ּҸ� ����Ű�� ������ ���X
		/*for (int i = 0; i < mCount; i++)
		{
			mArr[i] = other.mArr[i];
			mFlag[i] = other.mFlag[i];
		}*/
		delete[] mArr;
		mArr = new const Point * [mCount];

		//**(other.mArr).GetX�� �� �ȵǴ��� �𸣰���
		for (unsigned int i = 0; i < mCount; i++)
		{
			mArr[i] = new Point(*(other.mArr[i]));
		}
		
		//�Ʒ� �۵��ȵǴ� �ڵ�
		/*delete[] mArr;
		mArr = new Point[mCount];
		memcpy(mArr, other.mArr, mCount);*/


	}

	PolyLine::~PolyLine()
	{
		delete[] mArr;
	}

	bool PolyLine::AddPoint(float x, float y)
	{

		if (mCount < 10)
		{
			const Point** arr;
			arr = new const Point * [mCount];
			//arr = (Point*)malloc(sizeof(Point) * mCount);

			for (unsigned int i = 0; i < mCount; i++)
			{
				arr[i] = mArr[i];
				mArr[i] = nullptr;
			}

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

			delete arr;
	
			return true;
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

		if (mCount < 10)
		{
			const Point** arr;
			arr = new const Point * [mCount];
			//arr = (Point*)malloc(sizeof(Point) * mCount);

			for (unsigned int i = 0; i < mCount; i++)
			{
				arr[i] = mArr[i];
				mArr[i] = nullptr;
			}

			delete[] mArr;

			mArr = new const Point * [mCount + 1];

			for (unsigned int i = 0; i < mCount; i++)
			{
				mArr[i] = arr[i];
				arr[i] = nullptr;
			}

			mArr[mCount] = point;
			mCount += 1;
			delete arr;

			return true;
		}
		else
		{
			return false;
		}
	}

	//bool PolyLine::AddPoint(const Point point)
	//{
	//	float x = point.GetX();
	//	float y = point.GetY();

	//	if (mCount <= 10)
	//	{
	//		mArr[mCount] = new Point(x, y);
	//		mCount += mCount;
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}

	bool PolyLine::RemovePoint(unsigned int i)
	{	
		if (i >= mCount || i < 0)
		{
			return false;
		}

		const Point** arr;
		arr = new const Point * [mCount];

		for (unsigned int j = 0; j < mCount; j++)
		{
			arr[j] = mArr[j];
			mArr[j] = nullptr;
		}

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

			arr[j] = nullptr;
		}
		arr[mCount] = nullptr;

		delete arr;

		return true;

	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		if (mCount == 0 && outMin == nullptr || outMax == nullptr)
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

		return true;
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
		//���Կ����ڴ� ������ �ִ� �޸� ���� ���� ��
		mCount = other.mCount;

		delete[] mArr;

		mArr = new const Point * [mCount];

		//**(other.mArr).GetX�� �� �ȵǴ��� �𸣰���
		for (unsigned int i = 0; i < mCount; i++)
		{
			mArr[i] = new Point(*(other.mArr[i]));
		}

		return *this;
	}



}