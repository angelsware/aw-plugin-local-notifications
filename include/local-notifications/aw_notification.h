#ifndef __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_H__
#define __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_H__

#include <type/aw_string.h>

class CNotification
{
public:
	explicit CNotification(int id);

	CNotification& setTitle(const char* title);
	CNotification& setText(const char* text);

private:
	int mId;
	Type::CString mTitle;
	Type::CString mText;
};

#endif
