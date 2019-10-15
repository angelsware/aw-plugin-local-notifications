#ifndef __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_MANAGER_H__
#define __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_MANAGER_H__

namespace LocalNotifications {
	class INotificationListener;

	class INotificationManager
	{
	public:
		virtual ~INotificationManager() {}

		virtual bool initialize() = 0;
		virtual void sendNotification(int id, const CNotification& notification) override;
		virtual void addListener(INotificationListener* listener) = 0;
		virtual void removeListener(INotificationListener* listener) = 0;
		virtual void clearAllListeners() = 0;
	};
}

#endif
