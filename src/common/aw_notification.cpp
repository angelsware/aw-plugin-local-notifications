#include <localnotifications/aw_notification.h>

namespace LocalNotifications {
	CNotification::CNotification(int id)
		: mId(id)
		, mPriority(0)
		, mColor(Rendering::CColor::BLACK)
		, mAutoCancel(true)
	{}

	CNotification& CNotification::setTitle(const char* title) {
		mTitle.reset(title);
		return *this;
	}

	CNotification& CNotification::setText(const char* text) {
		mText.reset(text);
		return *this;
	}

	CNotification& CNotification::setSmallIcon(const char* filename) {
		mSmallIcon.reset(filename);
		return *this;
	}

	CNotification& CNotification::setLargeIcon(const char* filename) {
		mLargeIcon.reset(filename);
		return *this;
	}

	CNotification& CNotification::setPriority(int priority) {
		mPriority = priority;
		return *this;
	}

	CNotification& CNotification::setColor(const Rendering::CColor& color) {
		mColor = color;
		return *this;
	}

	CNotification& CNotification::setAutoCancel(bool autoCancel) {
		mAutoCancel = autoCancel;
		return *this;
	}

	CNotification& CNotification::setVibration(const Type::CBuffer<long>& pattern) {
		unsigned int count = pattern.getCount();
		if (count > 0) {
			mVibrationPattern.reset(count);
			for (unsigned int i = 0; i < count; ++i) {
				mVibrationPattern[i] = pattern[i];
			}
		}
		return *this;
	}

	CNotification& CNotification::setPayload(const char* payload) {
		mPayload.reset(payload);
		return *this;
	}
}
