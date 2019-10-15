#ifndef __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_MANAGER_FACTORY_H__
#define __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_MANAGER_FACTORY_H__

namespace LocalNotifications {
	class INotificationManager;

	class CNotificationManagerFactory {
	public:
		static INotificationManager* create();
		static void destroy(INotificationManager* notificationManager);
	};
}

#endif
