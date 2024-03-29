#pragma once

#include "Kinect-win32.h"

namespace Kinect
{

	
	float const Kinect_MinDistance = -10;
	float const Kinect_DepthScaleFactor = .0021f;
	extern float Kinect_ColorScaleFactor;
	extern double Kinect_rgbxoffset;
	extern double Kinect_rgbyoffset;
	

	class KinectFrameHelper
	{
	public:
		KinectFrameHelper(Kinect *inKinect);
		virtual ~KinectFrameHelper();

		bool UpdateDepth();
		bool UpdateColor();

		
	};

	template <typename T> class V2
	{
	public:
		V2(T _x=0, T _y=0){x=_x;y=_y;};
		T x,y;
	};

	template <typename T> class V3
	{
	public:
		V3(T _x=0, T _y=0,T _z = 0){x=_x;y=_y;z=_z;};
		T x,y,z;
	};

	template <typename T> class V4
	{
	public:
		V4(T _x=0, T _y=0,T _z = 0,T _w = 0){x=_x;y=_y;z=_z;w=_w;};
		T x,y,z,w;
	};

	template <typename T> class Rect
	{
	public:
		Rect(){};
		Rect(V2<T> _tl, V2<T> _br){mTopLeft = _tl;mBottomRight=_br;};

		V2<T> mTopLeft;
		V2<T> mBottomRight;
	};


	template <typename T> class Box
	{
	public:
		Box(){};
		Box(V3<T> _tl, V3<T> _br){mTopLeftFront = _tl;mBottomRightBack=_br;};

		V3<T> mTopLeftFront;
		V3<T> mBottomRightBack;
	};

	template <typename T> class M33
	{
	public:
		M33()
		{
			V[0] = V[4] = V[8]= (T)1.0;
			V[1] = V[2] = V[3] = V[5] = V[6] = V[7] = 0;
		};
		T V[9];
	};

	template <typename T> class M44
	{
	public:
		M44()
		{
			V[0] = V[5] = V[10] = V[15] = (T)1.0;
			V[1] = V[2] = V[3] = V[4] = V[6] = V[7] = V[8] = V[9] = V[11] = V[12] = V[13] = V[14] = 0;
		};
		T V[16];
	};

	typedef V2<float> V2f; 
	typedef V3<float> V3f;
	typedef V4<float> V4f;
	typedef Rect<float> Rectf;
	typedef Box<float> Boxf;

	typedef V2<double> V2d;
	typedef V3<double> V3d;
	typedef V4<double> V4d;
	typedef Rect<double> Rectd;
	typedef Box<double> Boxd;

	typedef V2<int> V2i;
	typedef V3<int> V3i;
	typedef V4<int> V4i;
	typedef Rect<int> Recti;
	typedef Box<int> Boxi;

	typedef V2<unsigned char> V2ub;
	typedef V3<unsigned char> V3ub;
	typedef V4<unsigned char> V4ub;
	typedef Rect<unsigned char> Rectub;
	typedef Box<unsigned char> Boxub;
	
	void KinectDepthToWorld(float &x, float &y, float &z);
	void KinectWorldToRGBSpace(float &x, float &y, float z);
	void KinectDepthToWorld(V3<float> &v);
	
	float Kinect_DepthValueToZ(unsigned short Depth);
	bool Kinect_IsDepthValid(unsigned short Depth);
};