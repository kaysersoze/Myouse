#pragma once
#include <myo\cxx\DeviceListener.hpp>

namespace myouse
{
	class MyouseListener : public myo::DeviceListener
	{
	public:
		MyouseListener();
		~MyouseListener();

		virtual void onPair(myo::Myo * myo, uint64_t timestamp,
			myo::FirmwareVersion firmwareVersion);
		virtual void onUnpair(myo::Myo * myo, uint64_t timestamp);

		virtual void onConnect(myo::Myo * myo, uint64_t timestamp,
			myo::FirmwareVersion firmwareVersion);
		virtual void onDisconnect(myo::Myo * myo, uint64_t timestamp);

		virtual void onArmRecognized(myo::Myo * myo, uint64_t timestamp,
			myo::Arm arm, myo::XDirection xDirection);
		virtual void onArmLost(myo::Myo * myo, uint64_t timestamp);

		virtual void onPose(myo::Myo * myo, uint64_t timestamp, myo::Pose pose);

		virtual void onOrientationData(myo::Myo * myo, uint64_t timestamp,
			const myo::Quaternion<float> & rotation);

		virtual void onAccelerometerData(myo::Myo * myo, uint64_t timestamp,
			const myo::Vector3<float> & accel);

		virtual void onGyroscopeData(myo::Myo * myo, uint64_t timestamp,
			const myo::Vector3<float> & gyro);

		virtual void onRssi(myo::Myo * myo, uint64_t timestamp,
			int8_t rssi);

		virtual void onOpaqueEvent(libmyo_event_t);

	private:
		myo::Myo * myo;
		myo::XDirection xDir;

		bool isEnabled;
		bool isScrolling;
		bool leftDown;
		bool rightDown;
		bool middleDown;

		double rawRoll;
		double rawPitch;
		double rawYaw;

		double rollOffset;
		double pitchOffset;
		double yawOffset;

		int lastX;
		int lastY;

		void moveMouse(long x, long y);

		void clickLeft();
		void unclickLeft();
		
		void clickRight();
		void unclickRight();

		void clickMiddle();
		void unclickMiddle();

		void scroll(int speed);
	};
}