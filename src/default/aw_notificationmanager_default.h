#ifndef __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_MANAGER_DEFAULT_H__
#define __AW_LOCAL_NOTIFICATIONS_NOTIFICATION_MANAGER_DEFAULT_H__

#include <localnotifications/aw_notificationmanager.h>

namespace LocalNotifications {
	class CNotificationManager_Default
		: public INotificationManager
	{
	private:
		bool initialize() override { return false; }
		void sendNotification(int id, const CNotification& notification) override {}
		void addListener(INotificationListener* listener) override {}
		void removeListener(INotificationListener* listener) override {}
		void clearAllListeners() override {}
	};
}

#endif
