#include "Kinect-Utility.h"

namespace Kinect
{
	float Kinect_ColorScaleFactor = .0023f;
	double Kinect_rgbxoffset = -1.8;
	double Kinect_rgbyoffset = -2.4;

	bool Kinect_IsDepthValid(unsigned short Depth)
	{
		if (Depth>0 && Depth != 0x07ff) return true;
		return false;
	};

	float Kinect_DepthValueToZ(unsigned short Depth)
	{
		return 100.0f/(-0.00307f * (float)Depth + 3.33f);
	};

	void KinectDepthToWorld(V3<float> &v)
	{
		KinectDepthToWorld(v.x,v.y,v.z);
	};

	void KinectDepthToWorld(float &x, float &y, float &z)
	{
		float zz = z;
		float xx = (x - 320) * (zz + Kinect_MinDistance) * Kinect_DepthScaleFactor ;
		float yy = (y - 240) * (zz + Kinect_MinDistance) * Kinect_DepthScaleFactor ;
		
		zz-=200;
		zz*=-1;

		x = xx;
		y = yy;
		z = zz;
	};

	void KinectWorldToRGBSpace(float &x, float &y, float z)
	{
		z*=-1;
		z+=200;
		float ox,oy;
		ox = (float)((x + Kinect_rgbxoffset) / (Kinect_ColorScaleFactor))/ (z + Kinect_MinDistance);
		oy = (float)((y + Kinect_rgbyoffset) / (Kinect_ColorScaleFactor))/ (z + Kinect_MinDistance);

		ox+=320;
		oy+=240;

		x = __min(640,__max(0,ox));
		y = __min(480,__max(0,oy));
	};
/*

calibration data from nicolasburrus   (copied from http://www.youtube.com/watch?v=BVxKvZKKpds ) 

Color
fx 5.2921508098293293e+02
fy 5.2556393630057437e+02
cx 3.2894272028759258e+02
cy 2.6748068171871557e+02
k1 2.6451622333009589e-01
k2 -8.3990749424620825e-01
p1 -1.9922302173693159e-03
p2 1.4371995932897616e-03
k3 9.1192465078713847e-01

Depth
fx 5.9421434211923247e+02
fy 5.9104053696870778e+02
cx 3.3930780975300314e+02
cy 2.4273913761751615e+02
k1 -2.6386489753128833e-01
k2 9.9966832163729757e-01
p1 -7.6275862143610667e-04
p2 5.0350940090814270e-03
k3 -1.3053628089976321e+00

Relative transform between the sensors (rotation matrix and translation in meters, depth image is the reference)
R
[ 9.9984628826577793e-01, 1.2635359098409581e-03, -1.7487233004436643e-02, 
-1.4779096108364480e-03, 9.9992385683542895e-01, -1.2251380107679535e-02,
1.7470421412464927e-02, 1.2275341476520762e-02, 9.9977202419716948e-01 ]

T
[ 1.9985242312092553e-02, -7.4423738761617583e-04, -1.0916736334336222e-02 ]

*/
};