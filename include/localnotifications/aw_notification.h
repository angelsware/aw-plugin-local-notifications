#ifndef __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_H__
#define __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_H__

#include <type/aw_string.h>
#include <type/aw_buffer.h>
#include <rendering/aw_color.h>

namespace LocalNotifications {
	class CNotification
	{
	public:
		explicit CNotification(int id);

		CNotification& setTitle(const char* title);
		CNotification& setText(const char* text);
		CNotification& setSmallIcon(const char* filename);
		CNotification& setLargeIcon(const char* filename);
		CNotification& setPriority(int priority);
		CNotification& setColor(const Rendering::CColor& color);
		CNotification& setAutoCancel(bool autoCancel);
		CNotification& setVibration(const Type::CBuffer<long>& pattern);
		CNotification& setPayload(const char* payload);

		const char* getTitle() const { return mTitle.get(); }
		const char* getText() const { return mText.get(); }
		const char* getSmallIcon() const { return mSmallIcon.get(); }
		const char* getLargeIcon() const { return mLargeIcon.get(); }
		int getPriority(int priority) const { return mPriority; }
		int getColor(const Rendering::CColor& color) const { return mColor.toInt(); }
		bool getAutoCancel(bool autoCancel) const { return mAutoCancel; }
		const Type::CBuffer<long>& getVibration() const { return mVibrationPattern; }
		const char* getPayload() const { return mPayload.get(); }

	private:
		int mId;
		Type::CString mTitle;
		Type::CString mText;
		Type::CString mSmallIcon;
		Type::CString mLargeIcon;
		int mPriority;
		Rendering::CColor mColor;
		Type::CBuffer<long> mVibrationPattern;
		Type::CString mPayload;
		bool mAutoCancel;
	};
}

#endif
