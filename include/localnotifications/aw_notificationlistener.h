#ifndef __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_LISTENER_H__
#define __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_LISTENER_H__

namespace LocalNotifications {
	class INotificationListener
	{
	public:
		virtual void onNotificationReceived(int id, const char* payload) = 0;

	protected:
		virtual ~INotificationListener() {}
	}
}

#endif
