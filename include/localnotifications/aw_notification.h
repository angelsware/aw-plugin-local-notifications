#ifndef __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_H__
#define __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_H__

#include <type/aw_string.h>
#include <type/aw_array.h>
#include <rendering/aw_color.h>

class CNotification
{
public:
	explicit CNotification(int id);

	CNotification& setTitle(const char* title);
	CNotification& setText(const char* text);
	CNotification& setLargeIcon(const char* filename);
	CNotification& setPriority(int priority);
	CNotification& setColor(const Rendering::CColor& color);
	CNotification& setAutoCancel(bool autoCancel);
	CNotification& setVibration(Type::CArray<long> pattern);
	CNotification& setPayload(const char* payload);

private:
	int mId;
	Type::CString mTitle;
	Type::CString mText;
	Type::CString mLargeIcon;
	int mPriority;
	Rendering::CColor mColor;
	Type::CArray<long> mVibrationPattern;
	Type::CString mPayload;
	bool mAutoCancel;
};

#endif
